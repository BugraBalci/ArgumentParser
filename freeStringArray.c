#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void freeStringArray(char** arr) {
	if (arr == NULL)
		return;

	for (int i = 0; arr[i] != NULL; i++) {
		free(arr[i]);
	}

	free(arr);
}
