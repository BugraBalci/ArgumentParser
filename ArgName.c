#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char** ArgName(int argc, char *argv[]) {
	char** retStrings = NULL;
	int retCount = 0;


	// retstinrgse gelicek değerler için alan ayırıyoruz.
	retStrings = (char**)malloc(sizeof(char*) * argc);

	if (retStrings == NULL) {
		printf("Bellek yonteminde hata.\n");
		return NULL;
	}

	for (int i = 1; i < argc; i++) {
		char *str = argv[i];
		if (str[0] == '-' && str[0] == str[1]) {
			char* ret = strchr(str, '=');

			//retStrings değer ataması için
			if (ret != NULL) {
				str = str + 2;
				*ret = '\0';
				retStrings[retCount] = strdup(str);
				retCount++;
			}
		}
	}

	// retStrings de son string belirlemek için
	retStrings[retCount] = NULL;

	return retStrings;
}
