/*
 * Tag01.c
 *
 *  Created on: 01.12.2022
 *      Author: mwegmann
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define BUFSZ 4096

void doDay01TaskA() {

	printf("Day 01");

	// Textdatei einlesen
	size_t n = 1;
	char buf[BUFSZ] = "";
	FILE* fp = fopen("src/Tag01/inputA.txt","r");

	while (fgets (buf, BUFSZ, fp)) {        /* read each line in file */
		size_t len = strlen (buf);          /* get buf length */
		if (len && buf[len-1] == '\n')      /* check last char is '\n' */
			buf[--len] = 0;                 /* overwrite with nul-character */
		else {   /* line too long or non-POSIX file end, handle as required */
			// Zeile enthaelt Zahl
			printf ("line[%2zu] : %s\n", n, buf);
			continue;
		}   /* output line (or "empty" if line was empty) */
		// Zeile ist leer
		printf ("line[%2zu] : %s\n", n++, len ? buf : "empty");
	}
	if (fp != stdin) fclose (fp);           /* close file if not stdin */
}

void doDay01TaskB() {

}
