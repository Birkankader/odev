#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

typedef struct
{
 int harf;
 int adet;
} struct_harf;

int main()
{
    setlocale(LC_ALL,"tr_TR.UTF-8");

// HARFLERİN TANIMI //
    struct_harf dizi[29];
////////////////////////////
// İNGİLİZCE KARAKTERLER //

    dizi[0].harf = 'A';
    dizi[0].adet = 0;
    dizi[1].harf = 'B';
    dizi[1].adet = 0;
    dizi[2].harf = 'C';
    dizi[2].adet = 0;
    dizi[4].harf = 'D';
    dizi[4].adet = 0;
    dizi[5].harf = 'E';
    dizi[5].adet = 0;
    dizi[6].harf = 'F';
    dizi[6].adet = 0;
    dizi[7].harf = 'G';
    dizi[7].adet = 0;
    dizi[9].harf = 'H';
    dizi[9].adet = 0;
    dizi[10].harf = 'I';
    dizi[10].adet = 0;
    dizi[12].harf = 'J';
    dizi[12].adet = 0;
    dizi[13].harf = 'K';
    dizi[13].adet = 0;
    dizi[14].harf = 'L';
    dizi[14].adet = 0;
    dizi[15].harf = 'M';
    dizi[15].adet = 0;
    dizi[16].harf = 'N';
    dizi[16].adet = 0;
    dizi[17].harf = 'O';
    dizi[17].adet = 0;
    dizi[19].harf = 'P';
    dizi[19].adet = 0;
    dizi[20].harf = 'R';
    dizi[20].adet = 0;
    dizi[21].harf = 'S';
    dizi[21].adet = 0;
    dizi[23].harf = 'T';
    dizi[23].adet = 0;
    dizi[24].harf = 'U';
    dizi[24].adet = 0;
    dizi[26].harf = 'V';
    dizi[26].adet = 0;
    dizi[27].harf = 'Y';
    dizi[27].adet = 0;
    dizi[28].harf = 'Z';
    dizi[28].adet = 0;

////////////////////////////
// TÜRKÇE KARAKTERLER //

    dizi[3].harf = 128;//Ç
    dizi[3].adet = 0;
    dizi[8].harf = 166;//Ğ
    dizi[8].adet = 0;
    dizi[11].harf = 152;//İ
    dizi[11].adet = 0;
    dizi[18].harf = 153;//Ö
    dizi[18].adet = 0;
    dizi[22].harf = 158;//Ş
    dizi[22].adet = 0;
    dizi[25].harf = 154;//Ü
    dizi[25].adet = 0;
////////////////////////////////////////////////////
// DEĞİŞKEN TANIMLAMA //
    char cumle[10000];
  	FILE *fp;
    char *cumleptr;
    int gecici_harf;
    cumleptr = cumle;
	gets(cumleptr);
                                            //  printf("%s",cumleptr); DÜZGÜN ALINIYOR MU KONTROL.
// DOSYAYA YAZDIRMA MODÜLÜ //
	fp=fopen("dosya.txt","w");
	if(fp==NULL){
		printf("Dosya açılamadı");
		exit(1);
	}

	while(*cumleptr)
        {
        gecici_harf=*cumleptr;

//ASCII KODLARI REFERANS ADRESİ https://www.ascii-codes.com/cp857.html //

            if(gecici_harf == 105)//
                fputc(152,fp);              //  printf("%c",gecici_harf); İF - ELSE BLOGUNA GİRİŞ KONTROL.
            else if(gecici_harf == 167)//
                fputc(166,fp);
            else if(gecici_harf == 159)//
                fputc(158,fp);
            else if(gecici_harf == 148)//
                fputc(153,fp);
            else if(gecici_harf == 129)//
                fputc(154,fp);
            else if(gecici_harf == 135)//
                fputc(128,fp);
            else
                fputc(gecici_harf,fp);

            if(gecici_harf==EOF)
            {
                printf("Dosyaya yazma hatası!/n");
                exit(1);
            }

		cumleptr++;
	}
	fclose(fp);
////////////////////////////////////////////////////

// DOSYADAN OKUMA MODÜLÜ //

    int i,j,k,karakter;

	fp=fopen("dosya.txt","r");
    cumleptr=cumle;
//  HARF KONTROLÜ   //
	for(i=0;i<strlen(cumle);i++)
    {
        karakter=fgetc(fp);
       // printf("%c",karakter);
        k=toupper(karakter);

        for(j=0;j<29;j++)
        {
           if(dizi[j].harf==k)
                dizi[j].adet+=1;
        }
    }

    fclose(fp);

    int toplam=0;
    for(i=0;i<29;i++)
        toplam+=dizi[i].adet;

    printf("Toplam harf sayısı:%d\n",toplam);

    for(i=0;i<29;i++)
    {
        if(dizi[i].adet>0)
        {
            printf("%c --> %d\n",dizi[i].harf,dizi[i].adet);
        }
    }

   printf("%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c", 152,166,158,153,154,128,105,167,159,148,129,135);
    return 0;
}
