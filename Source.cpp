#include "stdlib.h"
#include "iostream"
#include "VeriTabaniYoneticisi.h"
#include "Kisi.h"
#include "ctime"
using namespace std;

void hesapBilgiAl(Kisi kisi) {
	system("CLS");
	string adres = "C:\\Users\\Damla\\source\\repos\\BankAccount\\BankAccount\\" + kisi.alTcNo() + ".txt";

	ifstream file(adres, std::ios_base::app);

	string tcNumarasi;
	float miktar;
	float toplam = 0;
	while (file) {

		file >> tcNumarasi >> miktar;
		toplam = toplam + miktar;

		cout << tcNumarasi << " " << miktar << endl;
		
	}
	if (miktar < 0) {
		toplam = toplam + (miktar * (-1));


	}

	else {

		toplam = toplam + (miktar * (-1));
	}

	cout << "Bakiyeniz: " << toplam << endl;
	
	system("pause");


}


int bakiyeBilgiAl(Kisi kisi) {
	system("CLS");
	string yol = "C:\\Users\\Damla\\source\\repos\\BankAccount\\BankAccount\\" + kisi.alTcNo() + ".txt";

	ifstream file(yol, std::ios_base::app);

	string tcNumarasi;
	float miktar;
	float toplam = 0;
	while (file) {

		file >> tcNumarasi >> miktar;
		toplam = toplam + miktar;

		
	}
	

	if (miktar < 0) {
		toplam = toplam + (miktar * (-1));


	}

	else {

		toplam = toplam + (miktar * (-1));
	}
	return toplam;
}


void paraYatir(Kisi kisi) {

	float miktar;
	cout << "Yatirmak Istediginiz Miktari Giriniz: ";
	cin >> miktar;

	string yol = "C:\\Users\\Damla\\source\\repos\\BankAccount\\BankAccount\\" + kisi.alTcNo() + ".txt";


	ofstream file(yol, std::ios_base::app);

	file << endl << kisi.alTcNo() << " " << miktar;
	



}


void paraCek(Kisi kisi) {
	float miktar;
	cout << "Cekmek Istediginiz Miktari Giriniz: ";
	cin >> miktar;
	string yol = "C:\\Users\\Damla\\source\\repos\\BankAccount\\BankAccount\\" + kisi.alTcNo() + ".txt";
	ofstream file(yol, std::ios_base::app);

	file << endl << kisi.alTcNo() << " " << miktar*(-1);
	

}


void anaIslem(Kisi kisi) {
	system("CLS");

	VeriTabaniYoneticisi veritabaniyoneticisi = VeriTabaniYoneticisi();
	
	float ekranBakiye = bakiyeBilgiAl(kisi);

	float faizliBakiye = ekranBakiye;

	if (kisi.alHesapTuru() == "kisaVadeliHesap") {
		faizliBakiye = ekranBakiye * 8 / 100 + ekranBakiye;
	}

	else if (kisi.alHesapTuru() == "uzunVadeliHesap")
	{
		faizliBakiye = ekranBakiye * 14 / 100 + ekranBakiye;
	}

	else if (kisi.alHesapTuru() == "cariHesap")
	{
		//Bu hesap turunde faiz uygulanmamaktadir.
	}

	else if (kisi.alHesapTuru() == "vadesizHesap")
	{
		//Bu hesap turunde faiz uygulanmamaktadir.
	}

	else
	{
		cout << "Farkli Tanimli Bir Hesap Turu Yoktur \a";
	}

	cout << endl << "                                     ***HESABINIZA BASARIYLA GIRIS YAPTINIZ***" << endl << endl << endl;

	cout << "HOSGELDINIZ" << endl << kisi.alIsim() << " " << kisi.alSoyisim() << endl << endl;

	cout << "Hesap Turunuz: ";

	if (kisi.alHesapTuru() == "kisaVadeliHesap") 
	{
		cout << "Kisa Vadeli Hesap" << endl;
	}
	else if (kisi.alHesapTuru() == "uzunVadeliHesap")
	{
		cout << "Uzun Vadeli Hesap" << endl;
	}
	else if (kisi.alHesapTuru() == "cariHesap")
	{
		cout << "Cari Hesap" << endl;
		
		if (ekranBakiye < 0) 
		{
			cout << "Cari Hesap Borcunuz: ";
			double cariHesapBorcu = ekranBakiye *(-1);
			cout << cariHesapBorcu << endl;
		}
		else
		{
			cout << "Cari hesap borcunuz bulunmamaktadir. " << endl;
		}
		
	}
	else if (kisi.alHesapTuru() == "vadesizHesap")
	{
		cout << "Vadesiz Hesap" << endl;
	}


	cout << "Hesap Numaraniz: ";
	cout << kisi.alHesapNo() << endl;
	
	
	if (kisi.alHesapTuru() == "kisaVadeliHesap" || kisi.alHesapTuru() == "uzunVadeliHesap")
	{
		

		cout << endl <<"Faiz Eklenmis Bakiyeniz: ";
		cout << faizliBakiye << endl;

		if (kisi.alHesapTuru() == "kisaVadeliHesap")
				{
					double faizMiktari = ekranBakiye * 8 / 100;
					cout << "Uygulanan Faiz Miktari: " << faizMiktari << endl;
				}

		else
				{
					double faizMiktari = ekranBakiye * 14 / 100;
					cout << "Uygulanan Faiz Miktari: " << faizMiktari << endl;
				}

		cout << endl << endl;
	}

	else
	{
		cout << endl << "Bakiyeniz: ";
		cout << ekranBakiye << endl;
		cout << endl << endl;
	}


	int secim;
	while (true) {
		cout << endl << "                                 1. Para Cek " << endl;
		cout << endl << "                                 2. Para Yatir " << endl;
		cout << endl << "                                 3. Hesap Durumunu Goster " << endl;
		cout << endl << "                                 4. Hesabi Kilitle" << endl << endl;

		cout << "Yapmak Istediginiz Islemi Seciniz: ";
		cin >> secim;


		if (secim == 1) {
			paraCek(kisi);
		}
		else if (secim == 2) {
			paraYatir(kisi);
		}
		else if (secim == 3) {
			hesapBilgiAl(kisi);
		}
		else if (secim == 4) {
			exit(1);
		}
		else {
		}
		anaIslem(kisi);

	}


}


void girisYap() {
	string tcNo;
	string sifre;

	cout << "T.C. Kimlik Numarasi: ";
	cin >> tcNo;

	cout << "Sifre: ";
	cin >> sifre;



	VeriTabaniYoneticisi veritabani = VeriTabaniYoneticisi(); 

	Kisi _kisi = veritabani.kullaniciAl(Kisi(sifre, tcNo));

	anaIslem(_kisi);



}


void kayitOl() {

	string isim;
	string soyisim;
	string tcNo;
	string sifre;

	

	cout << "Isim: ";
	cin >> isim;

	cout << "Soyisim: ";
	cin >> soyisim;

	while (true) {
		cout << "T.C. Kimlik Numaranizi Giriniz (11 haneli olacak sekilde): ";
		cin >> tcNo;
		if (tcNo.length() == 11) {
			break;
		}
		else
		{
			true;
		}
	}

	
	while (true) {
		cout << "Sifrenizi Giriniz (4 haneli olacak sekilde): ";
		cin >> sifre;
		if (sifre.length() == 4) {
			break;
		}
		else
		{
			true;
		}
	}
	cout << endl << endl;
	

	long int enAz = 100000;
	long int enFazla = 999999;

	srand(time(NULL));

	long int hesapNo = rand() % (enFazla - enAz + 1) + enAz;
	
	cout << "Hesap Numaraniz: ";
	cout << hesapNo;
	
	cout << endl << endl << "						 -----HESAP TURLERI-----" << endl;

	int secim;
	string hesapTuru;

	while (true) {

		cout << endl << "						 1. Uzun Vadeli Hesap " << endl;
		cout << endl << "						 2. Kisa Vadeli Hesap " << endl;
		cout << endl << "						 3. Vadesiz Hesap " << endl;
		cout << endl << "						 4. Cari Hesap " << endl;

		cout << "Hesap Turunuzu Seciniz: ";
		cin >> secim;

		if (secim == 1) {
			hesapTuru = "uzunVadeliHesap";

			VeriTabaniYoneticisi veritabani = VeriTabaniYoneticisi();
			veritabani.kullaniciEkle(Kisi(isim, soyisim, sifre, tcNo, hesapNo, hesapTuru));
		}
		else if (secim == 2) {
			hesapTuru = "kisaVadeliHesap";

			VeriTabaniYoneticisi veritabani = VeriTabaniYoneticisi();
			veritabani.kullaniciEkle(Kisi(isim, soyisim, sifre, tcNo, hesapNo, hesapTuru));

		}
		else if (secim == 3) {
			hesapTuru = "vadesizHesap";

			VeriTabaniYoneticisi veritabani = VeriTabaniYoneticisi();
			veritabani.kullaniciEkle(Kisi(isim, soyisim, sifre, tcNo, hesapNo, hesapTuru));

		}
		else if (secim == 4) {
			hesapTuru = "cariHesap";

			VeriTabaniYoneticisi veritabani = VeriTabaniYoneticisi();
			veritabani.kullaniciEkle(Kisi(isim, soyisim, sifre, tcNo, hesapNo, hesapTuru));

		}
		else {
			continue;
		}

	}
}


int main() {
	int secim;

	cout << "                                           *****BANKAYA HOSGELDINIZ*****" << endl << endl;


	cout << "						 1. Kayit ol" << endl;
	cout << "						 2. Giris yap" << endl;
	cout << "Yapacaginiz islemin numarasini giriniz: ";
	cin >> secim;



	while (true) {

		if (secim== 1) {
			kayitOl();
		}
		else if (secim == 2) {
			girisYap();
		}
		else {

			cout << "Hatali bir secim yaptiniz.";
			cout << "Lutfen tekrar deneyiniz: ";
			cin >> secim;

		}

	}

	system("pause");
}