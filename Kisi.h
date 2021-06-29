#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include <string>
using namespace std;
class Kisi
{
	string isim;
	string soyisim;
	string sifre;
	string tcNo;
	long int hesapNo;
	string hesapTuru;

public:

	Kisi(string isim, string soyisim, string sifre, string tcNo, long int hesapNo, string hesapTuru) {
		this->isim = isim;
		this->soyisim = soyisim;
		this->sifre = sifre;
		this->tcNo = tcNo;
		this->hesapNo = hesapNo;
		this->hesapTuru = hesapTuru;
	}

	Kisi(string sifre, string tcNo) {
		this->sifre = sifre;
		this->tcNo = tcNo;
	}


	string alHesapTuru()
	{
		return hesapTuru;
	}

	string alIsim()
	{
		return isim;
	}

	string alSoyisim()
	{
		return soyisim;
	}

	string alSifre()
	{
		return sifre;
	}

	long int alHesapNo()
	{
		return hesapNo;
	}

	string alTcNo()
	{
		return tcNo;
	}

};

