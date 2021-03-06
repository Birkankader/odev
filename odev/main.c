﻿#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
 int harf;
 int adet;
} struct_harf;

int i;
struct_harf dizi[29];


void HarfTanimla(struct_harf dizi[])
{
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

//ASCII KODLARI REFERANS ADRESİ https://msdn.microsoft.com/en-us/library/cc195056.aspx // <<-- SETLOCALE TURKİSH
//ASCII KODLARI REFERANS ADRESİ https://www.ascii-codes.com/cp857.html // <<-- SETLOCALE tr.TR.UTF-8

////////////////////////////
// TÜRKÇE KARAKTERLER //

    dizi[3].harf = 199;//Ç
    dizi[3].adet = 0;
    dizi[8].harf = 208;//Ğ
    dizi[8].adet = 0;
    dizi[11].harf = 221;//İ
    dizi[11].adet = 0;
    dizi[18].harf = 214;//Ö
    dizi[18].adet = 0;
    dizi[22].harf = 222;//Ş
    dizi[22].adet = 0;
    dizi[25].harf = 220;//Ü
    dizi[25].adet = 0;

}

int main()
{
    setlocale(LC_ALL,"Turkish");
    HarfTanimla(dizi);
    HarfKontrol(dizi);
    Siralama(dizi);
    Yazdir(dizi);
    return 0;
}

void Siralama(struct_harf dizi[])
{
     int temp,tempharf;
     int j;

            for (i=1; i<29; i++)
            {
                for (j=0; j<29-i; j++)
                {
                    if(dizi[j].adet < dizi[j+1].adet)
                    {
                        temp = dizi [j].adet;               // dizi[j].adet içindeki değer yer değiştirilmek üzere temp'in içine atıldı.
                        dizi [j].adet = dizi [j+1].adet;    // dizi[j+1].adet içindeki değer dizi[j].adet içine atıldı.
                        dizi [j+1].adet = temp;             // temp'in içindeki dizi[j].adet değeri dizi[j+1].adet içine atıldı.

                        tempharf = dizi [j].harf;           // Sayılarla birlikte harflerin de yerinin değişmesi istendiği için aynı işlemler harf için yapıldı.
                        dizi [j].harf = dizi [j+1].harf;
                        dizi [j+1].harf = tempharf;
                    }
                }
            }
}

void HarfKontrol(struct_harf dizi[])
{
    FILE *fp;
    int karakter,buyukkarakter;
    fp=fopen("dosya.txt","r");

    if(fp==NULL)
    {
     printf("Dosya okuma hatası");
     exit(1);
    }

    for( ; ; )
    {
            karakter=fgetc(fp);

            if(karakter==105)       // "i" gelmesi durumunda onu "İ" ile değiştirir.
                karakter=221;
            else if(karakter==253)  // "ı" gelmesi durumunda onu "I" ile değiştirir.
                karakter=73;
            else if(karakter==EOF)  // END OF File'a eşit olduğunda döngü sonlanır.
                break;

        buyukkarakter=toupper(karakter);

            for(i=0;i<29;i++)
            {
                if(dizi[i].harf==buyukkarakter)
                    dizi[i].adet+=1;
            }
    }

    fclose(fp);
}
int ToplamHarf(struct_harf dizi[])
{
    int toplam=0;
    for(i=0;i<29;i++)
        toplam+=dizi[i].adet;
    return(toplam);
}

void Yazdir(struct_harf dizi[])
{
    printf("Toplam harf say%cs%c:%d\n",253,253,ToplamHarf(dizi));
    for(i=0;i<29;i++)
    {
        if(dizi[i].adet>0)
        {
          printf("%c --> %d\n",dizi[i].harf,dizi[i].adet);
        }
    }
}
