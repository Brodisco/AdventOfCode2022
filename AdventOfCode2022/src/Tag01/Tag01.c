/*
 * Tag01.c
 *
 *  Created on: 01.12.2022
 *      Author: mwegmann
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define BUFSZ 4096

char *getcwd(char *buf, size_t size);

void doDay01TaskA() {

	printf("Day 01");
	size_t n = 1;
	char buf[BUFSZ] = "";
	FILE* fp = fopen("src/Tag01/inputA.txt","r");


	while (fgets (buf, BUFSZ, fp)) {        /* read each line in file */
		size_t len = strlen (buf);          /* get buf length */
		if (len && buf[len-1] == '\n')      /* check last char is '\n' */
			buf[--len] = 0;                 /* overwrite with nul-character */
		else {   /* line too long or non-POSIX file end, handle as required */
			printf ("line[%2zu] : %s\n", n, buf);
			continue;
		}   /* output line (or "empty" if line was empty) */
		printf ("line[%2zu] : %s\n", n++, len ? buf : "empty");
	}
	if (fp != stdin) fclose (fp);           /* close file if not stdin */
	/*
	char cwd[PATH_MAX];
	   if (getcwd(cwd, sizeof(cwd)) != NULL) {
	       printf("Current working dir: %s\n", cwd);
	   } else {
	       perror("getcwd() error");
	   }
	   */
/*
	//FILE* pInput = fopen("/rzhome/mwegmann/git/AdventOfCode2022/AdventOfCode2022/src/Tag01//inputA.txt","r");
	FILE* pInput = fopen("src/Tag01/inputA.txt","r");

	int num = 0;
	printf("%p", pInput);

	//printf("%s", chdir());

	for (int i = 0; i < 20; i++) {
		fscanf(pInput,"%d", &num);
		printf("Zeile %d \n", num);
	}

	fclose(pInput);*/

}

void doDay01TaskB() {

}
