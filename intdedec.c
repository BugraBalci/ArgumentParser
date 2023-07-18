#include <stdio.h>
#include <string.h>
#include <ctype.h>

void intdedec(int arco, char* arse[])
{
	int a=0;
	int *cover;
	int count=arco;
	char** ptr=arse;
	char str[20];
	char* ret;
	if(count==1){
		printf("Lutfen deger giriniz.");
	}
	ptr++;
	if(count>=2){
		for(int i=1;i < count; i++){
			strcpy(str,*ptr);
			if(str[0]!=str[1] || str[0]!='-'){
				printf("Lutfen argumaninizin = %s basina -- koyunuz !\n",str);
			}
			else if(str[0] == str[1] || str[0] == '-'){
				ret = strchr(str,'=');
				printf("yazdığınız değer %s\n",ret);
			}
			ptr++;
		}
	}
}
