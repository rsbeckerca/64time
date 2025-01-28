#ifndef STAT_64
#define STAT_64

#if (_TANDEM_ARCH_ == 1 && __G_Series_RVU < 629 || \
     _TANDEM_ARCH_ == 2 && __H_Series_RVU < 606) && \
        (_FILE_OFFSET_BITS == 64 || _LARGEFILE64_SOURCE == 1)
   #error 64-bit functions not available for target RVU
#endif /* 64-bit functions requested when not available */

#ifndef __DIRFD_SUPPORTED__
#define __DIRFD_SUPPORTED__ \
 ( ( (_TANDEM_ARCH_ == 2 && defined(__J_Series_RVU) &&  \
        __J_Series_RVU >= 622) || \
     (_TANDEM_ARCH_ == 3 && defined(__L_Series_RVU) &&  \
        __L_Series_RVU >= 1802) || \
     (_TANDEM_ARCH_ > 3 ) ) && _XOPEN_SOURCE_EXTENDED == 1 )
#endif /* __DIRFD_SUPPORTED__ */

#ifdef __cplusplus
   extern "C" {
#endif

#ifndef _GUARDIAN_HOST
#include <sys/types.h>
#else
#include <systype.h>  nolist
#endif /* _GUARDIAN_HOST */

#ifdef __TANDEM
#pragma fieldalign platform stat_64
#endif
struct  stat_64 {
        dev_t   st_dev;
        ino_t   st_ino;
        mode_t  st_mode;
        nlink_t st_nlink;
        unsigned int st_acl:1;
        unsigned int __filler_1:7;
        unsigned int st_fileprivs:8;   /* File privileges */
        uid_t   st_uid;
        gid_t   st_gid;
        dev_t   st_rdev;
        off_t   st_size;
        int64_t st_atime;
        int64_t st_mtime;
        int64_t st_ctime;
        mode_t  st_basemode; /* ACL:  owning user and other permissions */
        int     st_reserved4;
        int64_t st_reserved8[3];
}; /* struct stat */

#if _LARGEFILE64_SOURCE == 1 && _TANDEM_ARCH_ != 0
#ifdef __TANDEM
#pragma fieldalign shared8 stat64
#endif
struct  stat_6464 {
        dev_t   st_dev;
        ino64_t st_ino;
        mode_t  st_mode;
        nlink_t st_nlink;
        unsigned int st_acl:1;
        unsigned int __filler_1:7;
        unsigned int st_fileprivs:8;   /* File privileges */
        uid_t   st_uid;
        gid_t   st_gid;
        dev_t   st_rdev;
        off64_t st_size;
        int64_t st_atime;
        int64_t st_mtime;
        int64_t st_ctime;
        mode_t  st_basemode;      /* ACL:  owning user and other permissions */
        int     st_reserved4;
        int64_t st_reserved8[3];
}; /* struct stat64 */
#endif /* _LARGEFILE64_SOURCE == 1 && _TANDEM_ARCH_ != 0 */

int    stat_64  (const char *, struct stat_64 *);

#pragma function stat_64     (alias("statLP64_"), unspecified)

#ifdef __cplusplus
   }
#endif

#endif  /* _SYS_STAT defined */
