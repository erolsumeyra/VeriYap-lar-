#include<iostream>
#include<cstdio>
#include<sstream>
#include <algorithm>
#include <string>
#include <cstring>
#include<locale.h>
#include <cctype>

using namespace std;
using std::string;
/*
düðümüzü oluþturuyoruz içerisin de Bilgisayar Aðlaru Dersini alan
öðrencilerin numarasý,adý,soyadý bölümü verileri tutulacaktýr.
numara için int
ad,soyad,bölüm için string veri türü seçilir.
Dügüm* diye pointer tanýmlýyoruz.
bunlar public yani global deðiþken olup Liste sýnýfýndan eriþim saðlanacaktýr.
*/
class Dugum
{
	public:
			int numara;
			string ad;
			string soyad;
			string bolum;
			int almaDurum;
			Dugum* sonraki;
};


class DugumAK
{
	public:
			int numara;
			string ad;
			string soyad;
			string bolum;
			int almaDurum;
			DugumAK* sonraki;
};

class DugumLZ
{
		public:
			int numara;
			string ad;
			string soyad;
			string bolum;
			int almaDurum;
			DugumLZ* sonraki;
};

class AvlDugum
{
	public:
    	int numara;
    	string ad;
    	string soyad;
    	string bolum;
    	int almaDurum;
    	AvlDugum* sol;
    	AvlDugum* sag;
}*kok;
/*
Liste adý ile sýnýf oluþturuyoruz.
Ýçersine yapýcý ve yýkýcý metodlarý tanýmlýyoruz.
Baðlantýlý liste için gerekli olan iþlerimi yapacak metodlarý tanýmlýyoruz.
*/
class Islemler
{
	public:
		Islemler(void) //Yapýcý Sýnýf
		{
			basAK=NULL;
			basLZ=NULL;
			bas=NULL;
			kok = NULL;
		}
		
		~Islemler(void);//Yýkýcý Sýnýf
		
		//Baðlantýlý Liste Ýþlemleri
		void ListebosMu();
		Dugum* ListeEkleOgr(int sirasi ,int numarasi,string adi, string soyadi, string bolumu, int almaDurumu);
		int ListeBulOgrNo(string adi, string soyadi, string bolumu);
		void ListebulOgrNo(int numarasi);
		int ListesilOgr(int numarasi);
		void ListeSinifiListele(void);
		void ListebirdenFazlaBliste(void);
		
		//Avl Aðaçý Ýþlemleri
		int Yukseklik(AvlDugum *);
        int fark(AvlDugum *);
        AvlDugum *sag_sagDonus(AvlDugum *);
        AvlDugum *sol_solDonus(AvlDugum *);
        AvlDugum *sol_sagDonus(AvlDugum *);
        AvlDugum *sag_solDonus(AvlDugum *);
        AvlDugum* dengele(AvlDugum *);
        AvlDugum* AvlEkle(AvlDugum *, int numarasi, string adi, string soyadi, string bolumu, int almaDurumu);
        void AvlsinifiListele(AvlDugum *, int);
        void AvlicKok(AvlDugum *);
        void AvlonceKok(AvlDugum *);
        void AvlsonraKok(AvlDugum *);
        
        
		//2-A Þýkký
        void BirdenFazla(AvlDugum *agac);
      
       	
       	//2-B Þýkký
       	int BulDugumIndexi(int index);
       	AvlDugum* BulAvlNumara(AvlDugum *agackok, int aranan);
       	void SadeceBilgisayarAglari(AvlDugum *agacKok);
       	string DugumBulNumarayaGore(int numara);
       	
       	
       	//2-C Þýkký
        DugumAK* AKEkleOgr(int sirasi ,int numarasi,string adi, string soyadi, string bolumu, int almaDurumu);
		void AKSinifiListele(void);
		DugumLZ* LZEkleOgr(int sirasi ,int numarasi,string adi, string soyadi, string bolumu, int almaDurumu);
		void LZSinifiListele(void);
		void IkiyeBol(void);  
		 
		//2-D Þýkký 
		void ListeElektronikOgr(int numara);
		void AvlElektronikOgr(AvlDugum *);
		void ElektronikOgrencileri(AvlDugum *Kok);
		
		
		
		//Sýralama Ýþlemleri
		
		//Kümeleme Sýralama
		string adlar[100];
		int adlarAscii[100];
		int adlarSirala[100];
		int l=1;
		void HerIkiDers(AvlDugum *agacKok);
		void KumeleSiralama(void);
		void Build_MaxHeap(int dizi[], int a);
		void MaxHeapify(int dizi[], int i, int a);
		void HeapSort(int dizi[], int a);
		void yazSiraliAd(string ad);
		
		
		//Radiks Sýralama
		void RadiksSiralama(AvlDugum *agacKok);
		string DugumSoyadBul(int numara);
		void soyadlariGonder(AvlDugum *agacKok);
		int m=0;
		int numaralarSoyad[100];
		string soyisimler[100];
		int soyadlarAscii[100];
		int soyadlarSirala[100];
		int getMax(int dizi[],int a);
		void countSort(int dizi[], int a, int exp);
		void radixsort(int dizi[],int a);
		void yazSirali(string soyad);
		
		
		//Seçmeli Sýralama
		void SecmeliSiralama(AvlDugum *agacKok);
		void AvlNumaraGonder(AvlDugum *agacKok);
		void SecmeliYaz(AvlDugum *agacKok,int yazilacak);
		int n=0;
		int numaralar[100];

	private:
			Dugum* bas;
			DugumAK* basAK;
			DugumLZ* basLZ;		
};


//Yikici Metod
Islemler::~Islemler(void)
{
	Dugum* suankiDugum = bas, *sonrakiDugum=NULL;
	while(suankiDugum != NULL)
	{
		sonrakiDugum = suankiDugum->sonraki;
		delete suankiDugum;
		suankiDugum = sonrakiDugum;
	}
}



/*
EkleOgr adlý metodu oluþtururuz. Düðümüzün indexi ve içine alýnacak veriler parametre olarak gönderdik.
Düðüm sýrasýnýn 0 dan küçül olup olmama kontrolü yapýldý.
Düðümümüze gelecek olan ilk sýrayý 1 olarak aldýk.
Dugum oluþturuyoruz.
Düðümde veri varsa ve sýrasý þuanki sýradan büyükse düðümü bir sonraki düðüme baðlýyor.
sýrasý 0 dan büyük ve düðümde veri yoksa null deðeri dönderir.
Sýrasý 0 ise düðümün baþýna ekleniyor. Deðilse bir sonraki düðüme baðlanýp ekleniyor.
Yeni düðüm gönderilir.
*/
Dugum* Islemler::ListeEkleOgr(int sirasi ,int numarasi,string adi, string soyadi, string bolumu, int almaDurumu) 
{
	
	if (sirasi < 0) 
	{
		return NULL;	
	}
	int suankiSira	=	1;
	Dugum* suankiDugum	=	bas;
	while (suankiDugum && sirasi > suankiSira) 
	{
		suankiDugum	=	suankiDugum->sonraki;
		suankiSira++;
	
	}
	
	if (sirasi > 0 && suankiDugum == NULL) 
	{
		return NULL;
	}
	
	Dugum* yeniDugum	=	new	Dugum;
	yeniDugum->numara	=	numarasi;
	yeniDugum->ad		=	adi;
	yeniDugum->soyad	=	soyadi;
	yeniDugum->bolum	=	bolumu;
	yeniDugum->almaDurum = almaDurumu;
		
	if (sirasi == 0) 
	{
		yeniDugum->sonraki	=	bas;
		bas		=	yeniDugum;
	}
	else {
		yeniDugum->sonraki	=	suankiDugum->sonraki;
		suankiDugum->sonraki	=	yeniDugum;
		
	}
	
	return yeniDugum;
}

// Sinifta bulunan öðrencileri listeleniyor.
void Islemler::ListeSinifiListele()
{
   int num		=	0;
   Dugum* suankiDugum	=	bas;
   cout<< "\t\t****Sinif Listesi****\n\n"<<endl;
   while (suankiDugum != NULL)
   {
	cout << suankiDugum->numara <<" "<< suankiDugum->ad <<" "<< suankiDugum->soyad <<" "<< suankiDugum->bolum<<" "<<suankiDugum->almaDurum<<endl;
	
	suankiDugum	=	suankiDugum->sonraki;
	num++;
	
   }
   cout << "Sýnýf Mevcudu:" << num << endl;
}

//Düðümün boþ olup olmadýðý kontrol ediliyor 
void Islemler::ListebosMu()
{
	Dugum* suankiDugum=bas;
	if(bas==NULL)
	cout<<"Dugumde veri bulunamadi.";
	else
	cout<<"Dugumde veri vardir.";
}

//Numarasý Girilen öðremcinin bilgileri ekranda gösteriliyor.
void Islemler::ListebulOgrNo(int numarasi)
{
	Dugum* suankiDugum=bas;
	int suankiSirasi=1;
	while(suankiDugum&&suankiDugum->numara!=numarasi)
	{
		suankiDugum=suankiDugum->sonraki;
		suankiSirasi++;
	}
	
	if(suankiDugum)
	{
		cout<<suankiDugum->numara<<" ";
		cout<<suankiDugum->ad<<" ";
		cout<<suankiDugum->soyad<<" ";
		cout<<suankiDugum->bolum<<" ";
		cout<<suankiDugum->almaDurum<<" ";
		cout<<endl;
	}
}

//Adý,Soyadý ve Bölümü girilen öðrencinin numrasý gönderiliyor.
int Islemler::ListeBulOgrNo(string adi, string soyadi, string bolumu)
{
	Dugum* suankiDugum = bas;
	int suankiSira = 1;
	while(suankiDugum && (suankiDugum->ad != adi && suankiDugum->soyad != soyadi && suankiDugum->bolum != bolumu ))
	{
		
		suankiDugum=suankiDugum->sonraki;
		suankiSira++;
	}
	if(suankiDugum && (suankiDugum->ad == adi && suankiDugum->soyad == soyadi && suankiDugum->bolum == bolumu)) 
	return suankiDugum->numara;
	return 0;
}

//Numarasý girilen öðrencinin bilgileri düðümden siliniyor.
int Islemler::ListesilOgr(int numarasi)
{
	Dugum*oncekiDugum=NULL;
	Dugum*suankiDugum=bas;
	int suankiSirasi=1;
	while(suankiDugum && suankiDugum->numara != numarasi)
	{
		oncekiDugum=suankiDugum;
		suankiDugum=suankiDugum->sonraki;
		suankiSirasi++;
	}
	if(suankiDugum)
	{
		if(oncekiDugum)
		{
			oncekiDugum->sonraki=suankiDugum->sonraki;
			delete suankiDugum;
		}
		else
		{
			bas=suankiDugum->sonraki;
			delete suankiDugum;
		}
		return suankiSirasi;
	}
	return 0;
}

int Islemler::Yukseklik(AvlDugum *gecici)
{
    int y = 0;
    if (gecici != NULL)
    {
        int l_yuk = Yukseklik (gecici->sol);
        int r_yuk = Yukseklik (gecici->sag);
        int max_yuk = max (l_yuk, r_yuk);
        y = max_yuk + 1;
    }
    return y;
}
 
int Islemler::fark(AvlDugum *gecici)
{
    int l_yuk = Yukseklik (gecici->sol);
    int r_yuk = Yukseklik (gecici->sag);
    int d_faktor= l_yuk - r_yuk;
    return d_faktor;
}
 
AvlDugum *Islemler::sag_sagDonus(AvlDugum *ata)
{
    AvlDugum *gecici;
    gecici = ata->sag;
    ata->sag = gecici->sol;
    gecici->sol = ata;
    return gecici;
}

AvlDugum *Islemler::sol_solDonus(AvlDugum *ata)
{
    AvlDugum *gecici;
    gecici = ata->sol;
    ata->sol = gecici->sag;
    gecici->sag = ata;
    return gecici;
}
 
AvlDugum *Islemler::sol_sagDonus(AvlDugum *ata)
{
    AvlDugum *gecici;
    gecici = ata->sol;
    ata->sol = sag_sagDonus (gecici);
    return sol_solDonus (ata);
}
AvlDugum *Islemler::sag_solDonus(AvlDugum *ata)
{
    AvlDugum *gecici;
    gecici = ata->sag;
    ata->sag = sol_solDonus (gecici);
    return sag_sagDonus (ata);
}
 

AvlDugum *Islemler::dengele(AvlDugum *gecici)
{
    int den_faktor = fark (gecici);
    if (den_faktor > 1)
    {
        if (fark (gecici->sol) > 0)
            gecici = sol_solDonus (gecici);
        else
            gecici = sol_sagDonus (gecici);
    }
    else if (den_faktor < -1)
    {
        if (fark (gecici->sag) > 0)
            gecici = sag_solDonus (gecici);
        else
            gecici = sag_sagDonus (gecici);
    }
    return gecici;
}
 

AvlDugum *Islemler::AvlEkle(AvlDugum *kok, int numarasi, string adi, string soyadi, string bolumu,int almaDurumu)
{
    if (kok == NULL)
    {
        kok = new AvlDugum;
        kok->numara = numarasi;
        kok->ad=adi;
        kok->soyad=soyadi;
        kok->bolum=bolumu;
        kok->almaDurum=almaDurumu;
        kok->sol = NULL;
        kok->sag = NULL;
        return kok;
    }
    else if (numarasi < kok->numara)
    {
        kok->sol = AvlEkle(kok->sol, numarasi, adi, soyadi, bolumu,almaDurumu);
        kok = dengele (kok);
    }
    else if (numarasi >= kok->numara)
    {
        kok->sag = AvlEkle(kok->sag, numarasi, adi, soyadi, bolumu,almaDurumu);
        kok = dengele (kok);
    }
    return kok;
}
 

void Islemler::AvlsinifiListele(AvlDugum *ptr, int seviye)
{
    int i;
    if (ptr!=NULL)
    {
        AvlsinifiListele(ptr->sag, seviye + 1);
        cout<<("\n");
        if (ptr == kok)
        cout<<"KOK -> ";
        for (i = 0; i < seviye && ptr != kok; i++)
            cout<<"        ";
        cout<<ptr->numara<<" "<<ptr->ad<<" "<<ptr->soyad<<" "<<ptr->bolum<<" "<<ptr->almaDurum;
        AvlsinifiListele(ptr->sol, seviye + 1);
    }
}


void Islemler::AvlicKok(AvlDugum *agac)
{
    if (agac == NULL)
        return;
    AvlicKok (agac->sol);
    	cout<<agac->numara<<" "<<agac->ad<<" "<<agac->soyad<<" "<<agac->bolum<<" "<<agac->almaDurum<<"\n";
    AvlicKok (agac->sag);
}

void Islemler::AvlonceKok(AvlDugum *agac)
{
    if (agac == NULL)
        return;
    cout<<agac->numara<<" "<<agac->ad<<" "<<agac->soyad<<" "<<agac->bolum<<" "<<agac->almaDurum<<"\n";
    AvlonceKok (agac->sol);
    AvlonceKok (agac->sag);
 
}
 

void Islemler::AvlsonraKok(AvlDugum *agac)
{
    if (agac == NULL)
        return;
    AvlsonraKok ( agac ->sol );
    AvlsonraKok ( agac ->sag );
    cout<<agac->numara<<" "<<agac->ad<<" "<<agac->soyad<<" "<<agac->bolum<<" "<<agac->almaDurum<<"\n";
}

 
 
//2. Sorunun Cevaplarý 

//2. Soru A Þýkký

 void Islemler::BirdenFazla(AvlDugum *agac)
 {
 	if(agac!=NULL)
    	{
    		Dugum* suankiDugum	=	bas;		
    		while (suankiDugum&&suankiDugum->numara!=agac->numara)
   			{
				suankiDugum	=	suankiDugum->sonraki;
   			}
   			
		   	if(suankiDugum)
			{
				if((suankiDugum->almaDurum>1)&&(agac->almaDurum>1))
				{
					cout<<suankiDugum->numara<<" ";
					cout<<suankiDugum->ad<<" ";
					cout<<suankiDugum->soyad<<" ";
					cout<<suankiDugum->bolum<<" ";
					cout<<endl;
				}
				
			}
   			BirdenFazla(agac->sol);
   			BirdenFazla(agac->sag);	
		}
 }
 
  //2. Soru B Þýkký
  
  
  void Islemler::SadeceBilgisayarAglari(AvlDugum *agacKok)
  {
  	int i = 0;
	int numara;
	AvlDugum *sonuc;
	
	while(1)
	{
		numara=BulDugumIndexi(i);
		
		if(numara==0)
			break;
		
		sonuc = BulAvlNumara(agacKok,numara);
		
		i++;
		
		if(sonuc!=0)
			continue;
		else
		{
			cout<<DugumBulNumarayaGore(numara)<<endl;
			
		}
	}
  }
  
  int Islemler::BulDugumIndexi(int index)
  {
  	Dugum* suankiDugum	=	bas;
  	int suankiIndex = 0;
  	while(suankiDugum && suankiIndex!=index)
  	{
  		suankiDugum	=	suankiDugum->sonraki;
  		suankiIndex++;
	}
	if(suankiDugum)
		return suankiDugum->numara;
				
	return 0;	
  }
  
  AvlDugum* Islemler::BulAvlNumara(AvlDugum *agackok, int aranan)
  {

	if (agackok!=NULL)
	{
		BulAvlNumara (agackok->sol,aranan);
	    if(agackok->numara==aranan)
	    {
	    	return agackok;
		}	
	    BulAvlNumara (agackok->sag,aranan);
	}
	else
		return NULL;	
  }
  
  string Islemler::DugumBulNumarayaGore(int numara)
  {
  	Dugum* suankiDugum	=	bas;
  	while(suankiDugum)
  	{
  		if(suankiDugum->numara==numara)
  		{
  			ostringstream nm;
  			nm<<suankiDugum->numara;
  			return nm.str()+" "+suankiDugum->ad+" "+suankiDugum->soyad+" "+suankiDugum->bolum;
  			break;
		}
		else
			suankiDugum=suankiDugum->sonraki;
	}
  }
  
  
  //2-C Þýkký
  DugumAK* Islemler::AKEkleOgr(int sirasi,int numarasi, string adi, string soyadi, string bolumu, int almaDurumu)
{
	if (sirasi < 0) 
	{
		return NULL;	
	}
	int suankiSira	=	1;
	DugumAK* suankiDugum	=	basAK;
	while (suankiDugum && sirasi > suankiSira) 
	{
		suankiDugum	=	suankiDugum->sonraki;
		suankiSira++;
	}
	
	if (sirasi > 0 && suankiDugum == NULL) 
	{
		return NULL;
	}
	
	DugumAK* yeniDugum	=	new	DugumAK;
	yeniDugum->numara	=	numarasi;
	yeniDugum->ad		=	adi;
	yeniDugum->soyad	=	soyadi;
	yeniDugum->bolum	=	bolumu;
	yeniDugum->almaDurum = almaDurumu;
		
	if (sirasi == 0) 
	{
		yeniDugum->sonraki	=	basAK;
		basAK		=	yeniDugum;
	}
	else 
	{
		yeniDugum->sonraki	=	suankiDugum->sonraki;
		suankiDugum->sonraki	=	yeniDugum;
	}
	return yeniDugum;
}
	
void Islemler::AKSinifiListele()
{
   DugumAK* suankiDugum	=	basAK;
   cout<< "\n\n\t\t****A GRUBU****\n\n"<<endl;
   while (suankiDugum != NULL)
   {
	cout << suankiDugum->numara <<" "<< suankiDugum->ad <<" "<< suankiDugum->soyad <<" "<< suankiDugum->bolum<<" "<<suankiDugum->almaDurum<<endl;
	suankiDugum	=	suankiDugum->sonraki;
   }
}

DugumLZ* Islemler::LZEkleOgr(int sirasi,int numarasi, string adi, string soyadi, string bolumu, int almaDurumu)
{
	if (sirasi < 0) 
	{
		return NULL;	
	}
	int suankiSira	=	1;
	DugumLZ* suankiDugum	=	basLZ;
	while (suankiDugum && sirasi > suankiSira) 
	{
		suankiDugum	=	suankiDugum->sonraki;
		suankiSira++;
	}
	
	if (sirasi > 0 && suankiDugum == NULL) 
	{
		return NULL;
	}
	
	DugumLZ* yeniDugum	=	new	DugumLZ;
	yeniDugum->numara	=	numarasi;
	yeniDugum->ad		=	adi;
	yeniDugum->soyad	=	soyadi;
	yeniDugum->bolum	=	bolumu;
	yeniDugum->almaDurum = almaDurumu;
		
	if (sirasi == 0) 
	{
		yeniDugum->sonraki	=	basLZ;
		basLZ		=	yeniDugum;
	}
	else 
	{
		yeniDugum->sonraki	=	suankiDugum->sonraki;
		suankiDugum->sonraki	=	yeniDugum;
	}
	
	return yeniDugum;
}
	
void Islemler::LZSinifiListele()
{
   DugumLZ* suankiDugum	=	basLZ;
   cout<< "\n\n\t\t****B GRUBU****\n\n"<<endl;
   while (suankiDugum != NULL)
   {
	cout << suankiDugum->numara <<" "<< suankiDugum->ad <<" "<< suankiDugum->soyad <<" "<< suankiDugum->bolum<<" "<<suankiDugum->almaDurum<<endl;
	suankiDugum	=	suankiDugum->sonraki;
   }
}

void Islemler::IkiyeBol()
{
   Dugum* suankiDugum	=	bas;
   int numAK=0;
   int numLZ=0;
   while (suankiDugum != NULL)
   {	
   		if(tolower(suankiDugum->soyad[0])<'l')
   		{
   			AKEkleOgr(numAK,suankiDugum->numara,suankiDugum->ad,suankiDugum->soyad,suankiDugum->bolum,suankiDugum->almaDurum);
   			numAK++;
		}
		else
		{
			LZEkleOgr(numLZ,suankiDugum->numara,suankiDugum->ad,suankiDugum->soyad,suankiDugum->bolum,suankiDugum->almaDurum);
   			numLZ++;
		}	
	suankiDugum	=	suankiDugum->sonraki;
   }
}


//2-D ÞIKKI
void Islemler::ListeElektronikOgr(int numara)
{
   Dugum* suankiDugum	=	bas;
   while (suankiDugum != NULL)
   {
   	if((suankiDugum->numara==numara) && (suankiDugum->bolum == "elektronik mühendisliði"))
	   cout << suankiDugum->numara <<" "<< suankiDugum->ad <<" "<< suankiDugum->soyad <<" "<< suankiDugum->bolum<<endl;
	suankiDugum	=	suankiDugum->sonraki;	
   }
}

void Islemler::AvlElektronikOgr(AvlDugum *agac)
{
	if (agac !=NULL)
	{
		AvlElektronikOgr (agac->sol);
	    if(agac->bolum=="elektronik mühendisliði")
	    {
	    	cout<<agac->numara<<" "<<agac->ad<<" "<<agac->soyad<<" "<<agac->bolum<<"\n";
		}
	    AvlElektronikOgr (agac->sag);
	}
}

void Islemler::ElektronikOgrencileri(AvlDugum *Kok)
{
	AvlElektronikOgr(Kok);
	
	int i=0;
	int numara;
	AvlDugum *sonuc;
	
	while(1)
	{
		numara=BulDugumIndexi(i);
		
		if(numara==0)
			break;
		
		sonuc = BulAvlNumara(Kok,numara);
		
		i++;
		
		if(sonuc!=0)
			continue;
		else 
			ListeElektronikOgr(numara);		
	}
}




//Sýralama Algoritmalarý ile Sýralama


//Kümeleme Sýralama
void Islemler::KumeleSiralama()
{
	for(int i=1;i<l;i++)
		adlarSirala[i]=adlarAscii[i];
		
	Build_MaxHeap(adlarSirala,l-1);
	HeapSort(adlarSirala,l-1);
	
	for(int i=1;i<l;i++)
	{
		for(int j=1;j<l;j++)
		{
			if(toupper(adlar[j][0])==adlarSirala[i])
			{	
				yazSiraliAd(adlar[j]);
			}
		}		
	}	
}

void Islemler::yazSiraliAd(string ad)
{
	Dugum* suankiDugum=bas;

	while(suankiDugum&&suankiDugum->ad!=ad)
	{
		suankiDugum=suankiDugum->sonraki;

	}
	
	if(suankiDugum)
	{
		cout<<suankiDugum->numara<<" ";
		cout<<suankiDugum->ad<<" ";
		cout<<suankiDugum->soyad<<" ";
		cout<<suankiDugum->bolum<<" ";
		cout<<endl;
	}
}

void Islemler::HeapSort(int dizi[], int a)
{
	int i, temp;
	for(i=a;i>=2;i--)
	{
		temp=dizi[i];
		dizi[i]=dizi[1];
		dizi[1]=temp;
		MaxHeapify(dizi,1,i-1);
	}
}

void Islemler::HerIkiDers(AvlDugum *agacKok)
{
	if(agacKok!=NULL)
    	{
    		Dugum* suankiDugum	=	bas;
			HerIkiDers(agacKok->sol);
   			HerIkiDers(agacKok->sag);		
    		while (suankiDugum&&suankiDugum->numara!=agacKok->numara)
   			{
				suankiDugum	=	suankiDugum->sonraki;
   			}
		   	if(suankiDugum)
			{
					adlar[l]=suankiDugum->ad;
					adlarAscii[l]=toupper((suankiDugum->ad)[0]);
					l++;	
			}	
		}
}

void Islemler::Build_MaxHeap(int dizi[], int a)
{
	for(int i=a/2;i>=1;i--)
		MaxHeapify(dizi,i,a);	
}

void Islemler::MaxHeapify(int dizi[],int i, int a)
{
	int j,temp;
	temp=dizi[i];
	j=2*i;
	
	while(j<=a)
	{
		if(j<a && dizi[j+1]>dizi[j])
			j=j+1;
			
		if(temp>dizi[j])
			break;
		else if(temp <=dizi[j])
		{
			dizi[j/2]=dizi[j];
			j=2*j;
		}
	}
	dizi[j/2]=temp;
	return;
}



//Radiks Sýralama
void Islemler::RadiksSiralama(AvlDugum *agacKok)
{
	radixsort(soyadlarSirala,m);
	cout<<"\n\n";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(toupper(soyisimler[j][0])==soyadlarSirala[i])
			{	
				yazSirali(soyisimler[j]);
			}
		}		
	}		
	
}

void Islemler::yazSirali(string soyad)
{
	Dugum* suankiDugum=bas;
	int suankiSirasi=1;
	while(suankiDugum&&suankiDugum->soyad!=soyad)
	{
		suankiDugum=suankiDugum->sonraki;
		suankiSirasi++;
	}
	
	if(suankiDugum)
	{
		cout<<suankiDugum->numara<<" ";
		cout<<suankiDugum->ad<<" ";
		cout<<suankiDugum->soyad<<" ";
		cout<<suankiDugum->bolum<<" ";
		cout<<endl;
	}
}

int Islemler::getMax(int dizi[],int a)
{
	int max=dizi[0];
		for(int i=1;i<a;i++)
			if(dizi[i]>max)
				max=dizi[i];
	return max;
}

void Islemler::countSort(int dizi[],int a, int exp)
{
	int output[a],i,count[10]={0};
	
	for(i=0;i<a;i++)
		count[(dizi[i]/exp)%10]++;
	
	for(i=1;i<10;i++)
		count[i]+=count[i-1];
	
	
	for(i=a-1;i>=0;i--)
	{
		output[count[(dizi[i]/exp)%10]-1]=dizi[i];
		count[dizi[i]/exp%10]--;
	}
	
	for(i=0;i<a;i++)
		dizi[i]=output[i];	
}

void Islemler::radixsort(int dizi[],int a)
{
	int exp ,b;
	b=getMax(dizi,a);
	for(exp=1;b/exp>0;exp*=10)
		countSort(dizi,a,exp);
	
}

void Islemler::soyadlariGonder(AvlDugum *agacKok)
{
	int i = 0;
	int numara;
	AvlDugum *sonuc;
	
	while(1)
	{
		numara=BulDugumIndexi(i);
		
		if(numara==0)
			break;
		
		sonuc = BulAvlNumara(agacKok,numara);
		
		i++;
		
		if(sonuc!=0)
			continue;
		else
		{
			numaralarSoyad[m] = numara;
			soyisimler[m]=DugumSoyadBul(numara);
			soyadlarAscii[m]=toupper(DugumSoyadBul(numara)[0]);
			m++;		
		}
	}
	
	for(int j=0;j<m;j++)
		soyadlarSirala[j]=soyadlarAscii[j];
	
}

string Islemler::DugumSoyadBul(int numara)
{
	Dugum* suankiDugum	=	bas;
  	while(suankiDugum)
  	{
  		if(suankiDugum->numara==numara)
  		{
  			return suankiDugum->soyad;
  			break;
		}
		else
			suankiDugum=suankiDugum->sonraki;
	}
}


// Seçmeli Sýralama
void Islemler::SecmeliSiralama(AvlDugum *agacKok)
{
		int numaralarSirali[100]={0};
		
		for(int a=0;a<n;a++)
		{
			numaralarSirali[a] = numaralar[a];
		}
		
		int numara;
        int yedek;
        int minIndex;
        for(int i=0; i<n-1; i++)
        {
              minIndex=i;
              for(int j=i; j<n; j++)
              {
              	if (numaralarSirali[j] < numaralarSirali[minIndex]) 
				  minIndex=j;
              }
              yedek=numaralarSirali[i];
              numaralarSirali[i]=numaralarSirali[minIndex];
              numaralarSirali[minIndex]=yedek;
        }
		for(int a=0;a<n;a++)
		{
			if(numaralarSirali[a] != 0)
				SecmeliYaz(agacKok,numaralarSirali[a]);
			else
				break;
		}	
}

void Islemler::SecmeliYaz(AvlDugum *agacKok,int yazilacak)
{
	if (agacKok!=NULL)
	{
		SecmeliYaz (agacKok->sol,yazilacak);
	    if(agacKok->numara==yazilacak)
	    {
	    	cout<<agacKok->numara<<" "<<agacKok->ad<<" "<<agacKok->soyad<<" "<<agacKok->bolum<<" "<<agacKok->almaDurum<<"\n";
		}	
	    SecmeliYaz (agacKok->sag,yazilacak);
	}
	
}

void Islemler::AvlNumaraGonder(AvlDugum *agacKok)
{
		if (agacKok!=NULL)
		{
			AvlNumaraGonder (agacKok->sol);
		    	numaralar[n] = agacKok->numara;
				n++;	
		    AvlNumaraGonder (agacKok->sag);
		}
}

int main(void) 
{
	setlocale(LC_ALL, "Turkish"); 
	Islemler islemler;
	int islem;
	islemler.ListeEkleOgr(0,127,"Deniz","Dunya","bilgisayar mühendisliði",1);
	islemler.ListeEkleOgr(1,121,"Beyzade","Mars","bilgisayar mühendisliði",2);
	islemler.ListeEkleOgr(2,124,"Kerem","Venus","endüstri mühendisliði",3);
	islemler.ListeEkleOgr(3,128,"Furkan","Merkür","bilgisayar mühendisliði",1);
	islemler.ListeEkleOgr(4,130,"Alperen","Saturn","bilgisayar mühendisliði",2);
	islemler.ListeEkleOgr(5,141,"Can","Jupiter","elektronik mühendisliði",5);
	islemler.ListeEkleOgr(6,170,"Pars","Gunes","endüstri mühendisliði",1);
    
    kok = islemler.AvlEkle(kok,121,"Ayla","Tara","bilgisayar mühendisliði",2);
    kok = islemler.AvlEkle(kok, 14,"Merve","Ak","elektronik mühendisliði",1);
    kok = islemler.AvlEkle(kok, 123,"Selin","Uzay","elektronik mühendisliði",1);
    kok = islemler.AvlEkle(kok, 124,"Kadir","Kara","endüstri mühendisliði",4);
    kok = islemler.AvlEkle(kok,130,"Tugba","Kuzu","bilgisayar mühendisliði",2);
    kok = islemler.AvlEkle(kok,141,"Mustafa","Albayrak","elektronik mühendisliði",1);
    kok = islemler.AvlEkle(kok,163,"Kahraman","Kaymaz","elektronik mühendisliði",1);
	cout<<"---------------------------MUHENDISLIK FAKULTESI OGRENCI BILGI SISTEMI---------------------------\n"<<endl;
		cout<<"\n1-)Birden Fazla Kez Her Iki Dersi de Alan Ögrencileri Sirala";
		cout<<"\n2-)Sadece Bilgisayar Aglari Dersini Alan Ögrencilei Sirala";
		cout<<"\n3-)Bilgisayar Aglari Dersi A ve B Grubu Ogrencilerini Sirala";
		cout<<"\n4-)Bilgisayar Aglari ve Bilgisayar Mimarisi Derslerininin En Az Birisini Alan Elektronik Muhendisligi Ögrencilerini Sirala";
		cout<<"\n5-)Her Iki Dersi de Alan Ogrencileri Adlarina Gore Sirala";
		cout<<"\n6-)Sadece Bilgisayar Aglari Dersini Ögrencileri Soyadlarýna Gore Sirala";
		cout<<"\n7-)Bilgisayar Mimarisi Dersi Ögrencileri Numaralarina Gore Sirala";
		cout<<"\nYapmak istediginiz islemi giriniz:\n";
		cin>>islem;
		switch(islem){
			case 1:
				cout<<"\nÖgrenciler Siralaniyor...\n";
				islemler.BirdenFazla(kok);
				break;
			case 2:
				cout<<"\nÖgrenciler Siralaniyor...\n";
				islemler.SadeceBilgisayarAglari(kok);
				break;
			case 3:
				cout<<"\nÖgrenciler Siralaniyor...\n";
				islemler.IkiyeBol();
				islemler.AKSinifiListele();  
				islemler.LZSinifiListele();
				break;
			case 4:
				cout<<"\nÖgrenciler Siralaniyor...\n";
				islemler.ElektronikOgrencileri(kok);
				break;
			case 5:
				cout<<"\nÖgrenciler Siralaniyor...\n";
				islemler.HerIkiDers(kok);
				islemler.KumeleSiralama();
				break;
			case 6:
				cout<<"\nÖgrenciler Siralaniyor...\n";
				islemler.soyadlariGonder(kok);
				islemler.RadiksSiralama(kok);
				break;
			case 7:
				cout<<"\nÖgrenciler Siralaniyor...\n";
				islemler.AvlNumaraGonder(kok);
				islemler.SecmeliSiralama(kok);
				break;
			default:
				cout<<"\nLutfen yukaridaki islemlerden birini giriniz!";
		}
    return 0;
}
