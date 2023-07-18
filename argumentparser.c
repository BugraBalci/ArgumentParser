#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int argumentparser(int argc, char *argv[], int *val)
{
	int LastVal = 0;
	char *ret;
	char *str;

//Argümanda ki sayıları ayırıyoruz
	if(argc>=2) {
		for(int i = 1; i < argc; i++){
			str = malloc(strlen( argv[i] ) + 1);
			strcpy(str, argv[i]);
			if(str[0] == str[1] && str[0]=='-'){

				ret = strchr(str, '=');
				if(ret != NULL) {
					ret++;
					val[LastVal] = atol(ret);
					LastVal++;
				}
			}
			free(str);
		}
	}
	return LastVal;
}
