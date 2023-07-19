#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void freeStringArray(char** arr,int** arr1) {
	if (arr == NULL)
		return;

	for (int i = 0; arr[i] != NULL; i++) {
		free(arr[i]);
	}

	free(arr);

	if (arr1 == NULL)
		return;

	for (int i = 0; arr1[i] != NULL; i++) {
		free(arr1[i]);
	}

	free(arr1);

}
