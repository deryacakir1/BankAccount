#pragma once
#include "Kisi.h"
#include <fstream>
#include "iostream"
using namespace std;

class VeriTabaniYoneticisi
{
public:
	FILE file;

	void kullaniciEkle(Kisi kisi) {

		ofstream file("C:\\Users\\Damla\\source\\repos\\BankAccount\\BankAccount\\data.txt", std::ios_base::app);

		file << endl << kisi.alIsim() << " " << kisi.alSoyisim() << " " << kisi.alSifre() << " " << kisi.alTcNo() << " " << kisi.alHesapNo()<< " " << kisi.alHesapTuru();
		exit(1);
	
	}


	Kisi kullaniciAl(Kisi kisi) {
		
		ifstream file("C:\\Users\\Damla\\source\\repos\\BankAccount\\BankAccount\\data.txt", std::ios_base::app);

		string isim;
		string soyisim;
		string tcNumarasi;
		string sifre;
		int hesapNo;
		string hesapTuru;
		
		while (file) {
			
			file >> isim >> soyisim >> sifre >> tcNumarasi >> hesapNo >> hesapTuru;
			
			if (kisi.alTcNo()._Equal(tcNumarasi) && kisi.alSifre()._Equal(sifre)) {
		
				return Kisi(isim, soyisim, sifre, tcNumarasi, hesapNo, hesapTuru);

			}

		}

		cout << "Böyle bir hesap bulunamadi."<<endl;
		system("pause");
		exit(1);
	}
};

