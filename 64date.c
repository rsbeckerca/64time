/*
 Simple program to report dates. This is not really intended for integration.

 Copyright (c) 2025 Nexbridge Inc. All Rights Reserved.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

void Usage(const char *progname) {
	const char *s = strrchr(progname, '/');

	if (s)
		progname = s;
	fprintf(stderr, "usage: %s file\n", progname);
	exit(1);
}

int main(int argc, char **argv) {
	struct stat st;
	struct tm *timeptr;
	time_t whenever;

	if (argc != 2)
		Usage(argv[0]);

	if (stat(argv[1], &st)) {
		perror(argv[1]);
		Usage(argv[0]);
	}

	whenever = (time_t) st.st_mtime;
	timeptr = localtime(&whenever);
	printf("%s mtime is %s", argv[1], asctime(timeptr));
	return 0;
}

