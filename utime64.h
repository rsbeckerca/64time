/*
 This file is derived from HPE NonStop headers. You must have permission
 to use this file on your system via a license agreement with HPE to even
 look in this file.

 This file has significant and relevant modifications compared to utime.h
 which make this all possible.

 Copyright (c) 2025 Nexbridge Inc. All Rights Reserved.
 Copyright (c) 2014 Hewlett-Packard Company LLC. All Rights Reserved.
*/
#ifndef UTIME_64
#define UTIME_64

#ifdef __cplusplus
   extern "C" {
#endif

#ifndef HAVE_TIME64
typedef long long time64_t;
#endif
#ifdef __TANDEM
#pragma fieldalign platform utimbuf64
#endif
struct utimbuf64 {
        time64_t  actime;               /* access time */
        time64_t  modtime;              /* modification time */
};

int     utime64(const char *, const struct utimbuf64 *);

#if _TANDEM_ARCH_ >= 2
   #pragma function utime64  (alias("utimeLP64_"), unspecified)
#endif

#ifdef __cplusplus
   }
#endif

#endif  /* UTIME_64 defined */
