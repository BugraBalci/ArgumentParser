#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int** argumentparser(int argc, char *argv[])
{
	int **val = NULL;
	int LastVal = 0;
	val = (int**)malloc(argc * sizeof(int*));

//Argümanda ki sayıları ayırıyoruz
	if(argc>=2) {
		for(int i = 1; i < argc; i++){

			char *str = NULL;
			str = malloc(strlen( argv[i] ) + 1);
			strcpy(str, argv[i]);

			if(str[0] == str[1] && str[0]=='-') {

				char *ret = NULL;
				ret = strchr(str, '=');

				if(ret != NULL) {
					ret++;
					val[LastVal] = malloc(sizeof(int));
					*val[LastVal] = atoi(ret);
					printf("%d\n",*val[LastVal]);
					LastVal++;
				}
			}
			free(str);
		}
	}
	val[LastVal] = NULL;
	return val;
}
