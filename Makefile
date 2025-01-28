# Copyright (c) 2025 Nexbridge Inc. All Rights Reserved.

UTT=/G/data05/randall/utt

all: $(UTT) 64date

$(UTT): utt.c
	c99 -O0 -g -Wextensions -Wsystype=guardian utt.c -o $(UTT)

64date: 64date.c
	c99 -Wlp64 -O0 -g -Wextensions -Wsystype=oss 64date.c -o 64date

