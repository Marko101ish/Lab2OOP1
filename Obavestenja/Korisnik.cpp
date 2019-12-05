#include "Korisnik.h"
#include "ListaObavestenja.h"
#include "Obavestenje.h"
#include "Objava.h"

Korisnik::Korisnik(std::string ime)
{
	ime_ = ime;
	inbox_ = new ListaObavestenja();
}

//Korisnik salje obavestenje drugom korisniku sa zadatim tekstom
void Korisnik::Posalji(Korisnik& k2, std::string tekst) const
{
	Obavestenje* novo = new Objava(&k2, tekst);
	k2.Primi(*novo);
}

void Korisnik::Primi(Obavestenje& ob)
{
	*inbox_ += ob;
}

std::ostream& operator<<(std::ostream os, Korisnik& kor)
{
	os << kor.GetIme();
	kor.Spec(os);
	return os;
}
