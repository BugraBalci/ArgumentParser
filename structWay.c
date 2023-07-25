#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>

struct structWay {
	char* key;
	char *value;
};

struct structWay* argumanOlustur(char *isim, char *deger ,int argSayisi) {
	struct structWay* Argumanlar = (struct structWay*)malloc(argSayisi * sizeof(struct structWay));
	for(int i = 0; i < argSayisi; i++) {
		Argumanlar[i].key = &isim[i];
		Argumanlar[i].value = &deger[i];
	}
		return Argumanlar;
}
