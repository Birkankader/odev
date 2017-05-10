#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>


typedef struct
{
 int harf;
 int adet;
} struct_harf;

int main()
{
    setlocale(LC_ALL,"Turkish");


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


////////////////////////////////////////////////////
// DEĞİŞKEN TANIMLAMA //
  	FILE *fp;
    int i=0,j,k;
    char karakter[1000];
    char *karakterptr;
    karakterptr=karakter;
////////////////////////////////////////////////////

// DOSYADAN OKUMA MODÜLÜ //


	fp=fopen("dosya.txt","r");

    //  HARF KONTROLÜ   //

    for( ; ; )
    {
        *(karakterptr+i)=fgetc(fp);

            if(*(karakterptr+i)==105)       // Küçük "i" gelmesi durumunda onu büyük "İ" ile değiştirir.
                *(karakterptr+i)=221;
            else if(*(karakterptr+i)==253)
                *(karakterptr+i)=73;
            else if(*(karakterptr+i)==EOF)  // END OF File'a eşit olduğunda döngü sonlanır.
                break;

        k=toupper(*(karakterptr+i));        // İşaretçiden aldığı harfi büyütür ve k değişkenine atar.
                                                // printf("%c",k); UFAK SAĞLAMA SATIRI.

            for(j=0;j<29;j++)               // k değişkenine atanan harfler tanımlanan dizidekilerle karşılaştırılır.
            {
                if(dizi[j].harf==k)
                    dizi[j].adet+=1;
            }
        i++;
    }

    fclose(fp);

    int toplam=0;
    for(i=0;i<29;i++)
        toplam+=dizi[i].adet;

//BUBBLE SORT İLE SIRALAMA //

    int temp,tempharf;

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

// EKRANA BASTIRMA MODÜLÜ //

    printf("Toplam harf sayısı:%d\n",toplam);
    for(i=0;i<29;i++)
    {
        if(dizi[i].adet>0)
        {
          printf("%c --> %d\n",dizi[i].harf,dizi[i].adet);

        }
    }
    return 0;
}
