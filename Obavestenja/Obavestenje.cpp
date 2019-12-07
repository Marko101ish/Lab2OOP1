#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "Obavestenje.h"
#include "Korisnik.h"
#include<ctime>
#include<iostream>

int Obavestenje::ID = 1;

Obavestenje::Obavestenje(Korisnik* korisnik)
{
	korisnik_ = korisnik;
}

std::ostream& operator << (std::ostream &os, const Obavestenje& ob)
{
	struct tm* vr = localtime(&ob.vreme_);
	os << ob.id_ << " | "<<ob.GetKorisnik()->GetIme()<<" - "<<vr->tm_hour<<":"<< vr->tm_min << ":"<<vr->tm_sec<<std::endl;
	ob.Spec(os);
	return os;
}
