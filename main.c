#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int argumentparser(int argc, char *argv[],int *val );
char** ArgName(int argc, char *argv[]);
void freeStringArray(char** arr);


int main(int argc, char* argv[])
{
	//hata kodları için
	char *str;
	char *ret;
	for(int i=1;i < argc; i++) {
		str = malloc(strlen( argv[i] ) + 1);
		strcpy(str, argv[i]);
		ret = strchr(str, '=');
		if(ret == NULL)
			printf("Lutfen %s icin bir deger giriniz.\n", str);
		if(str[0] != str[1] || str[0] != '-')
			printf("Lutfen argumaninizin = %s basina -- koyunuz !\n", str);
		free(str);
	}
	//yazma için şurayı halletmek lazım

	int* n;
	n = malloc(argc * sizeof(int));
	argumentparser(argc, argv, n);
	char** result = ArgName(argc, argv);

	if (result != NULL) {
		for (int i = 0; result[i] != NULL; i++) {
			printf("String %s value: %d\n", result[i],n[i]);
		}

		freeStringArray(result);
	}
	free(n);
	return 0;
}
