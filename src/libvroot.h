# 1 "vroot.h"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 379 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "vroot.h" 2
# 21 "vroot.h"
 #ifndef VROOT_H
 #define VROOT_H






# 1 "/usr/share/SDKs/iPhoneOS.sdk/usr/include/Availability.h" 1 3 4
# 165 "/usr/share/SDKs/iPhoneOS.sdk/usr/include/Availability.h" 3 4
# 1 "/usr/share/SDKs/iPhoneOS.sdk/usr/include/AvailabilityVersions.h" 1 3 4
# 166 "/usr/share/SDKs/iPhoneOS.sdk/usr/include/Availability.h" 2 3 4
# 1 "/usr/share/SDKs/iPhoneOS.sdk/usr/include/AvailabilityInternal.h" 1 3 4
# 167 "/usr/share/SDKs/iPhoneOS.sdk/usr/include/Availability.h" 2 3 4
# 30 "vroot.h" 2






 #define dlsym vroot_dlsym

 #define dlopen vroot_dlopen

 #define dladdr vroot_dladdr

 #define posix_spawn vroot_posix_spawn



 #define posix_spawnp vroot_posix_spawnp


 #define posix_spawn_file_actions_addopen vroot_posix_spawn_file_actions_addopen



 #define posix_spawn_file_actions_addchdir_np vroot_posix_spawn_file_actions_addchdir_np





 #define open vroot_open

 #define openat vroot_openat

 #define creat vroot_creat
 #define fcntl vroot_fcntl

 #define openx_np vroot_openx_np
 #define open_dprotected_np vroot_open_dprotected_np





 #define getwd vroot_getwd
 #define getcwd vroot_getcwd

 #define acct vroot_acct
 #define access vroot_access
 #define chdir vroot_chdir
 #define chown vroot_chown

 #define pathconf vroot_pathconf
 #define rmdir vroot_rmdir
 #define unlink vroot_unlink
 #define chroot vroot_chroot
 #define lchown vroot_lchown
 #define readlink vroot_readlink
 #define truncate vroot_truncate

 #define link vroot_link

 #define symlink vroot_symlink

 #define mknod vroot_mknod

 #define mkdtemp vroot_mkdtemp
 #define mkstemp vroot_mkstemp
 #define mkstemps vroot_mkstemps

 #define mkostemp vroot_mkostemp
 #define mkostemps vroot_mkostemps


 #define undelete vroot_undelete


 #define getattrlist vroot_getattrlist

 #define setattrlist vroot_setattrlist


 #define exchangedata vroot_exchangedata

 #define searchfs vroot_searchfs

 #define fsctl vroot_fsctl

 #define sync_volume_np vroot_sync_volume_np


 #define mkpath_np vroot_mkpath_np
 #define mkpathat_np vroot_mkpathat_np


 #define mkstemp_dprotected_np vroot_mkstemp_dprotected_np

 #define mkdtempat_np vroot_mkdtempat_np
 #define mkstempsat_np vroot_mkstempsat_np
 #define mkostempsat_np vroot_mkostempsat_np

 #define execv vroot_execv

 #define execve vroot_execve

 #define execvP vroot_execvP

 #define execvp vroot_execvp

 #define execl vroot_execl

 #define execle vroot_execle

 #define execlp vroot_execlp



 #define opendir vroot_opendir
 #define scandir vroot_scandir


 #define scandir_b vroot_scandir_b


 #define __opendir2 vroot___opendir2
 #define readdir vroot_readdir
 #define readdir_r vroot_readdir_r



 #define utime vroot_utime

 #define utimes vroot_utimes
 #define lutimes vroot_lutimes


 #define fopen vroot_fopen
 #define freopen vroot_freopen
 #define fopen$DARWIN_EXTSN vroot_fopen$DARWIN_EXTSN
 #define remove vroot_remove
 #define rename vroot_rename
# 178 "vroot.h"
 #define chmod vroot_chmod
 #define lstat vroot_lstat
 #define mkdir vroot_mkdir
 #define mkfifo vroot_mkfifo
 #define stat vroot_stat


 #define fchmodat vroot_fchmodat
 #define fstatat vroot_fstatat
 #define mkdirat vroot_mkdirat

 #define mkfifoat vroot_mkfifoat
 #define mknodat vroot_mknodat


 #define utimensat vroot_utimensat


 #define chmodx_np vroot_chmodx_np

 #define chflags vroot_chflags
 #define lchflags vroot_lchflags
 #define lchmod vroot_lchmod
 #define lstatx_np vroot_lstatx_np
 #define mkdirx_np vroot_mkdirx_np
 #define mkfifox_np vroot_mkfifox_np
 #define statx_np vroot_statx_np
 #define lstat64 vroot_lstat64
 #define stat64 vroot_stat64




 #define realpath vroot_realpath
 #define realpath$DARWIN_EXTSN vroot_realpath$DARWIN_EXTSN





 #define getattrlistat vroot_getattrlistat

 #define setattrlistat vroot_setattrlistat


 #define freadlink vroot_freadlink


 #define faccessat vroot_faccessat
 #define fchownat vroot_fchownat
 #define readlinkat vroot_readlinkat
 #define unlinkat vroot_unlinkat

 #define linkat vroot_linkat

 #define symlinkat vroot_symlinkat



 #define mount vroot_mount

 #define statfs vroot_statfs
 #define statfs64 vroot_statfs64
 #define unmount vroot_unmount


 #define getmntinfo vroot_getmntinfo
 #define getmntinfo_r_np vroot_getmntinfo_r_np
 #define getfsstat vroot_getfsstat
 #define getfsstat64 vroot_getfsstat64


 #define shm_open vroot_shm_open

 #define shm_unlink vroot_shm_unlink


 #define sem_open vroot_sem_open

 #define sem_unlink vroot_sem_unlink


 #define copyfile vroot_copyfile


 #define renameat vroot_renameat

 #define renamex_np vroot_renamex_np

 #define renameatx_np vroot_renameatx_np


 #define dbopen vroot_dbopen

 #define __bt_open vroot___bt_open
 #define __hash_open vroot___hash_open
 #define __rec_open vroot___rec_open


 #define statvfs vroot_statvfs





 #define _ZNSt3__113basic_filebufIcNS_11char_traitsIcEEE4openEPKcj vroot__ZNSt3__113basic_filebufIcNS_11char_traitsIcEEE4openEPKcj

 #define _ZNSt3__114basic_ifstreamIcNS_11char_traitsIcEEE4openEPKcj vroot__ZNSt3__114basic_ifstreamIcNS_11char_traitsIcEEE4openEPKcj

 #define _ZNSt3__114basic_ifstreamIcNS_11char_traitsIcEEE4openERKNS_12basic_stringIcS2_NS_9allocatorIcEEEEj vroot__ZNSt3__114basic_ifstreamIcNS_11char_traitsIcEEE4openERKNS_12basic_stringIcS2_NS_9allocatorIcEEEEj

 #define _ZNSt3__114basic_ofstreamIcNS_11char_traitsIcEEE4openEPKcj vroot__ZNSt3__114basic_ofstreamIcNS_11char_traitsIcEEE4openEPKcj

 #define _ZNSt3__114basic_ofstreamIcNS_11char_traitsIcEEE4openERKNS_12basic_stringIcS2_NS_9allocatorIcEEEEj vroot__ZNSt3__114basic_ofstreamIcNS_11char_traitsIcEEE4openERKNS_12basic_stringIcS2_NS_9allocatorIcEEEEj


 #define bind vroot_bind
 #define connect vroot_connect
 #define getpeername vroot_getpeername
 #define getsockname vroot_getsockname



 #define ftw vroot_ftw
 #define nftw vroot_nftw


 #define fts_open vroot_fts_open
 #define fts_open_b vroot_fts_open_b


 #define getxattr vroot_getxattr
 #define setxattr vroot_setxattr
 #define removexattr vroot_removexattr
 #define listxattr vroot_listxattr


 #define glob vroot_glob
 #define glob_b vroot_glob_b





 #define _NSGetExecutablePath vroot__NSGetExecutablePath


 #define acl_valid_file_np vroot_acl_valid_file_np

 #define acl_delete_def_file vroot_acl_delete_def_file
 #define acl_get_file vroot_acl_get_file
 #define acl_get_link_np vroot_acl_get_link_np
 #define acl_set_file vroot_acl_set_file
 #define acl_set_link_np vroot_acl_set_link_np


 #define catopen vroot_catopen
# 345 "vroot.h"
 #endif
