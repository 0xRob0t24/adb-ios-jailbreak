/*
** Copyright (C) 2007, The Android Open Source Project
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h> // สำหรับ pid_t
#include "cutils/threads.h"

// ฟังก์ชันที่ใช้ดึง ID ของเธรดใน iOS
#ifndef __ANDROID__
pid_t gettid() {
#if defined(__APPLE__)
    // ใช้ pthread_self() เพื่อรับ ID ของเธรด
    return (pid_t)pthread_self(); // iOS
#elif defined(__linux__)
    return syscall(SYS_gettid); // Linux
#else
    return (pid_t)-1; // Unsupported platform
#endif
}
#endif  // __ANDROID__

#if !defined(_WIN32)

void* thread_store_get(thread_store_t* store) {
    if (!store->has_tls)
        return NULL;

    return pthread_getspecific(store->tls);
}

void thread_store_set(thread_store_t* store, void* value, thread_store_destruct_t destroy) {
    pthread_mutex_lock(&store->lock);
    if (!store->has_tls) {
        if (pthread_key_create(&store->tls, destroy) != 0) {
            pthread_mutex_unlock(&store->lock);
            return;
        }
        store->has_tls = 1;
    }
    pthread_mutex_unlock(&store->lock);

    pthread_setspecific(store->tls, value);
}

#else /* !defined(_WIN32) */

void* thread_store_get(thread_store_t* store) {
    if (!store->has_tls)
        return NULL;

    return (void*)TlsGetValue(store->tls);
}

void thread_store_set(thread_store_t* store, void* value, thread_store_destruct_t destroy) {
    /* XXX: can't use destructor on thread exit */
    if (!store->lock_init) {
        store->lock_init = -1;
        InitializeCriticalSection(&store->lock);
        store->lock_init = -2;
    } else while (store->lock_init != -2) {
        Sleep(10); /* 10ms */
    }

    EnterCriticalSection(&store->lock);
    if (!store->has_tls) {
        store->tls = TlsAlloc();
        if (store->tls == TLS_OUT_OF_INDEXES) {
            LeaveCriticalSection(&store->lock);
            return;
        }
        store->has_tls = 1;
    }
    LeaveCriticalSection(&store->lock);

    TlsSetValue(store->tls, value);
}
#endif /* !defined(_WIN32) */

