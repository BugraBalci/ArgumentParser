#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char** argumentparser(int argc, char *argv[]);
char** ArgName(int argc, char *argv[]);
void freeStringArray(char** arr);
struct structWay* argumanOlustur(char *isim, char *deger ,int argSayisi);
struct structWay {
	char* key;
	char *value;
};
struct Arguments Argumanlar(char* value[], char* key[], int argc);
char * readFile(char *file)
{
	//printf("%s",a);
	FILE *fptr  = fopen(file,"r");
		if (fptr == NULL){
			printf("Dosya yolu okunamadi: %s\n", file);
			return NULL;
		}

		// Dosyanın boyutunu alır
		fseek(fptr, 0, SEEK_END);
		long dosya_boyutu = ftell(fptr);
		fseek(fptr, 0, SEEK_SET);

		// Dosya içeriğini tutmak için bellek tahsis edin ve dosya içeriğini okur
		char* dosya_icerigi = (char*)malloc(dosya_boyutu + 1);
		if (dosya_icerigi == NULL) {
			printf("Bellek tahsis hatası!\n");
			fclose(fptr);
			return NULL;
		}

		fread(dosya_icerigi, sizeof(char), dosya_boyutu, fptr);
		dosya_icerigi[dosya_boyutu] = '\0'; // Sonlandırıcı karakter ekler

		fclose(fptr);
		return dosya_icerigi;
}


int main(int argc, char* argv[])
{
	//hata kodları için
	char *str;
	char *ret;
	for(int i=1;i < argc; i++) {
		str = malloc(strlen(argv[i]) + 1);
		strcpy(str, argv[i]);
		ret = strchr(str, '=');

		if(ret == NULL)
			printf("Lutfen %s icin bir deger giriniz.\n", str);

		if(str[0] != str[1] || str[0] != '-')
			printf("Lutfen argumaninizin = %s basina -- koyunuz !\n", str);
		free(str);
	}



	char** value = argumentparser(argc, argv);
	char** name = ArgName(argc, argv);

	//Dosya yoluna sahip argümanları çıkartmak için
//	char *asd ="filepath";
//	for(int i=0; i < argc ; i++) {
//			if(strcmp(name[i],asd) == 0) {
//				char * data = readFile(value[i]);
//				printf("ah bedava sirke sen baldan tatlısın icerde %s\n",data);
//				free(data);
//				break ;
//			}
//	}

	for(int i =0;i<argc;i++){
		//struct için
		struct structWay* argumanlar= argumanOlustur(name[i],value[i],argc);
		printf(" Value %s\n",argumanlar->value);
		printf(" Key %s\n",argumanlar->key);
		free(argumanlar);
	}




	if (name != NULL) {
		for (int m = 0; name[m] != NULL && value[m] != NULL ; m++) {
			printf("String %s value: %s\n", name[m], value[m]);
		}
		freeStringArray(name);
		freeStringArray(value);
	}

	return 0;
}
