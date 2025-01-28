#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define HAVE_TIME64 1
#include "utime64.h"
#include "stat64.h"

void Usage(const char *progname) {
	const char *s = strrchr(progname, '.');

	if (s)
		progname = s;
	fprintf(stderr, "usage: %s file offset-value\n", progname);
	exit(1);
}

int main(int argc, char **argv) {
	struct utimbuf64 ut64;
	struct stat_64 st;
	int error;
	long long offset;
	char *endp;
	time_t now = time(NULL);

	if (argc != 3)
		Usage(argv[0]);
	offset = strtoll(argv[2], &endp, 10);
	if (*endp) {
		fprintf(stderr, "Bad offset\n");
		Usage(argv[0]);
	}

	if (stat_64(argv[1], &st)) {
		perror(argv[1]);
		Usage(argv[0]);
	}
	memset(&ut64, 0, sizeof(ut64));
	ut64.modtime = st.st_mtime + offset;
	ut64.actime = now;

	error = utime64(argv[1], &ut64);
	printf("Received error %d\n", error);
	if (error == 0) {
		printf("%s: was %lld, now %lld\n", argv[1], st.st_mtime, ut64.modtime);
	}
}

