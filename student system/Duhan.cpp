#include <stdio.h>
#include <stdlib.h>

// CHAR DEÐÝÞKENLERÝ FONKSÝYONLARDA KULLANIRKAN ALINAN HATAYI BÝR TÜRLÜ DÜZELTEMEDÝM, OGRENCÝ ÝSÝM VE SOYÝSÝM YAZDIRILMADI
// HARFNOT fonksiyonunda en yüksek, en düþük ve ortalamayý hesaplýyorum ancak harfnot da bir char deðiþken olduðu için ayný þekilde onda da hata aldým
// Diðer fonksiyonlar sorunsuz çalýþýyor.

struct ogrenci {
	//verilerimiz
	int ogrno;
	char ogrisim[40];
	char ogrsoyisim[40];
	int vizenot, finalnot, projenot, odevnot;
	double ortnot;
	char harfnot[2];
	
	// pointerimiz
	struct ogrenci *next; // düðümde ileri gitmemizi saðlayan pointer.
	struct ogrenci *prev; // düðümde geri gitmemizi saðlayan pointer.
};

struct ogrenci *start = NULL; // Program ilk çalýþtýðýnda hiç veri olmadýðý için start yani baþlangýç NULL olmalý.


struct ogrenci *ogrEkle (int numara, int vize, int final, int proje, int odev, double ort) // ogrEkleme fonksiyonumuz
{
	struct ogrenci *yeniOgrenci = (struct ogrenci*)malloc(sizeof(struct ogrenci));
	//yeniOgrence->ogrisim = isim;
	//yeniOgrenci->ogrsoyisim = soyisim;
	yeniOgrenci->ogrno = numara;
	yeniOgrenci->vizenot = vize;
	yeniOgrenci->finalnot = final;
	yeniOgrenci->projenot = proje;
	yeniOgrenci->odevnot = odev;
	yeniOgrenci->ortnot = ort;
	//yeniOgrenci->harfnot = harf;
	
	yeniOgrenci->next = NULL;
	yeniOgrenci->prev = NULL;
	
	return yeniOgrenci;
}

void basaEkle (int numara, int vize, int final, int proje, int odev, double ort) // veriyi düðümün sol tarafýna (baþýna) ekler
{
	struct ogrenci *basaEklenecek = ogrEkle(numara, vize, final, proje, odev, ort);
	
	start->prev = basaEklenecek;
	basaEklenecek->next = start;
	start = basaEklenecek;
}

void sonaEkle(int numara, int vize, int final, int proje, int odev, double ort) // veriyi düðümün sað tarafýna (sonuna) ekler
{
	struct ogrenci *sonaEklenecek = ogrEkle(numara, vize, final, proje, odev, ort);
	
	if(start == NULL)
		start = sonaEklenecek;
	
	else
	{
		//traverse --> Traverse veriler arasýnda dolaþma iþlemine verilen isimdir. 
		struct ogrenci *temp = start; // Temp adýnda geçici bir deðiþken oluþturduk ve bunu start a atadýk.
		
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		
		sonaEklenecek->prev = temp;
		temp->next = sonaEklenecek;	
		
	}
}

void bastanSil() // düðümün baþýndaki verileri siler.
{
	if(start == NULL)
	{
		printf("\nKayitli ogrenci bulunmamaktadir.");
	}
	struct ogrenci *ikinciOgrenci = start->next;
	free(start);
	ikinciOgrenci->prev = NULL;
	start = ikinciOgrenci;
}

void sondanSil() // düðümün sonundaki verileri siler.
{
	struct ogrenci *temp = start;
	
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	
	struct ogrenci *onceki = temp->prev;
	free(temp);
	onceki->next = NULL;
}

void aradanSil(int silinecek) // düðümdeki istediðimiz bir veriyi siler.
{
	struct ogrenci *temp = start;
	while(temp->next != NULL)
	{
		if(temp->ogrno == silinecek)
			break;
		temp = temp->next;
	}
	struct ogrenci *sonraki = temp->next;
	struct ogrenci *onceki = temp->prev;
	free(temp);
	onceki->next = sonraki;
	sonraki->prev = onceki;
}

void yazdir() // Düðümdeki verileri topluca yazdýrýr.
{
	struct ogrenci *temp = start;
	
	while(temp!=NULL)
	{
		printf("Ogrenci NO: %d\nVize Notu: %d\nFinal Notu: %d\nProje Notu: %d\nOdev Notu: %d\nOrtalama Not: %.2f\n\n-----------------\n\n",temp->ogrno, temp->vizenot, temp->finalnot, temp->projenot, temp->odevnot, temp->ortnot);
		temp = temp->next;
	}
}

void ogrenciBul(int numara) // düðümde sadece yazdýrýlmasýný istediðimiz veriyi yazdýrýr.
{
	struct ogrenci *temp = start;
	while(temp->next!=NULL)
	{
		if(temp->ogrno = numara)
			break;
			
		temp = temp->next;
	}
	printf("Ogrenci NO: %d\nVize Notu: %d\nFinal Notu: %d\nProje Notu: %d\nOdev Notu: %d\nOrtalama Not: %.2f\n\n-----------------\n\n",temp->ogrno, temp->vizenot, temp->finalnot, temp->projenot, temp->odevnot, temp->ortnot);
}

void harfNot() // harf char deðiþken olduðu için isim ve soyisim gibi bunuda yazdýrýrken hata aldým.
{
	struct ogrenci *anaTemp = start;
		// HARF NOTU HESAPLAMA (Bu kýsýmdaki bilgileri online beykozdaki pdf den aldým)
	/* 
 Average Final Grade is calculated (Av). --> genelort
 Highest Final Grade is Calculated (Hi) --> buyukogr 
 Lowest Final Grade is Calculated (Lo) --> kucukogr
 
	*/
	double buyukogr=anaTemp->ortnot; // Hi
	ogrenci *buyukDugum;
	
	double kucukogr=anaTemp->ortnot; // Lo
	ogrenci *kucukDugum;
	
	double genelort; // Av
	
		printf("En yuksek ogrenci:%.2f\n ",buyukogr);
		
	
	// BU KISIM OLMASSA DÜZGÜN ÇALIÞIYOR!!!
		ogrenci *temps = start;
		
		while (temps!=NULL)
		{
			if(kucukogr > temps->ortnot)
			{
				kucukogr = temps->ortnot;
				kucukDugum = temps;
			}
			temps = temps->next;
		}
		
		printf("En kucuk ogrenci:%.2f\n ",kucukogr);
		
		double toplam =0;
		int sayac=0;
		ogrenci *tempss = anaTemp;
		
		while (tempss!=NULL)
		{
			toplam = toplam+tempss->ortnot;
			tempss = tempss->next;
			sayac++;
		}
		genelort=toplam/sayac;
		printf("Genel Ortalama: %.2f\n",genelort);
		
		
	double st1 = (buyukogr-genelort)/3;
	double st2 = (genelort-kucukogr)/2;
	
	if(anaTemp->ortnot<=100 && anaTemp->ortnot>100-st1)
	{
	//	anaTemp->harfnot = 'A';
	}
	else if (anaTemp->ortnot<=100-st1 && anaTemp->ortnot>100-2*st1)
	{
	//	ogr->harfnot = 'B';
	}
	else if(anaTemp->ortnot<=100-2*st1 && anaTemp->ortnot>2*st2+kucukogr)
	{
	//	ogr->harfnot = 'C';
	}
	else if(anaTemp->ortnot<=2*st2+kucukogr && anaTemp->ortnot>st2+kucukogr)
	{
	//	anaTemp->harfnot = 'D';
	}
	else if (anaTemp->ortnot<=st2+kucukogr)
	{
	//	ogr->harfnot = 'F';
	}
	else
	{
		printf("Girdiginiz not degerleri hatali.\n\n\n");
	}
}

int main()
{
	int secim, secim2, silinecek, bulunacak;
	int numara, vize, final, proje, odev;
	double ort;
	
	while(1)
	{
		printf("1) Ogrenci Ekleme\n2) Ogrenci Sil\n3) Ogrenci Listesini Goruntule\n4) Numara ile Ogrenci Bul\n5) Harf notlarini hesapla\n");
		printf("Seciminizi Yapin: ");
			scanf ("%d",&secim);
			
		switch(secim)
		{
			case 1:	
					printf("Ogrenci NO: ");
					scanf("%d",&numara);
				printf("Vize Notu: ");
					scanf("%d",&vize);
				printf("Final Notu: ");
					scanf("%d",&final);
				printf("Proje Notu: ");
					scanf("%d",&proje);
				printf("Odev Notu: ");
					scanf("%d",&odev);
				ort = 0.2*vize+0.2*odev+0.3*proje+0.3*final;
				
				for(int i=0; i<=50; i++)
					printf("*");
				printf("\n");
				
					printf("1) Sona Ekle(Listede hic ogrenci yoksa bunu seciniz)\n2)Basa Ekle\n");
						scanf("%d",&secim2);
					system("cls");
					printf("Ogrenci ekleme islemi basariyla gerceklesti.");
					printf("\n***********\n");
					
					switch(secim2)
					{
					case 1:
						sonaEkle(numara, vize, final, proje, odev, ort);
						//yazdir();
						break;
					case 2:
						basaEkle(numara, vize, final, proje, odev, ort);
						//yazdir();
						break;
					}
					
					break;
					
			case 2:
				printf("1)Bastan Sil\n2)Sondan Sil\n3)Aradan Sil\n\n");
					scanf("%d",&secim2);
				switch(secim2)
				{
				case 1:
					bastanSil();
					//yazdir();
					break;
				case 2:
					sondanSil();
					//yazdir();
				case 3:
					printf("Silinmesini istediginiz eleman: ");
						scanf("%d",&silinecek);
					aradanSil(silinecek);
					//yazdir();	
				}
				system("CLS");
				printf("Ogrenci Silme isleminiz basariyla gerceklesti.");
				printf("\n***********\n");
				break;
				
			case 3:
				system("CLS");
				yazdir();
				system("PAUSE");
				system("CLS");
				break;
			case 4:
				system("CLS");
				printf("Aradiginiz ogrencinin numarasini giriniz: ");
					scanf("%d",&bulunacak);
				printf("\n***********\n");
				ogrenciBul(bulunacak);
				system("PAUSE");
				system("CLS");
				break;
			case 5:
				system("CLS");
				harfNot();
				system("PAUSE");
				system("CLS");
			default:
				printf("Hatali islem sectiniz. Lutfen tekrar deneyiniz.");
				break;				
		}
	}
}





