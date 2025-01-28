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
