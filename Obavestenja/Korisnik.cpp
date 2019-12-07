#include "Korisnik.h"
#include "ListaObavestenja.h"
#include "Obavestenje.h"
#include "Objava.h"

#include<iostream>


Korisnik::Korisnik(std::string ime)
{
	ime_ = ime;
	inbox_ = new ListaObavestenja();
}

Korisnik::~Korisnik()
{
	delete inbox_;
	inbox_ = nullptr;
	ime_ = "";
}

//Korisnik salje obavestenje drugom korisniku
void Korisnik::Posalji(Korisnik& k2, Obavestenje &ob) const
{
	k2.Primi(ob);
}

void Korisnik::Primi(Obavestenje& ob)
{
	*inbox_ += ob;
}

std::ostream & operator<<(std::ostream&os, const Korisnik &kor)
{
	os << kor.ime_;
	kor.Spec(os);
	return os;
}
