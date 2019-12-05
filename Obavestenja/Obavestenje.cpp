#include "Obavestenje.h"
#include "Korisnik.h"

int Obavestenje::ID = 1;

Obavestenje::Obavestenje(Korisnik* korisnik)
{
	korisnik_ = korisnik;
}

std::ostream& operator<<(std::ostream&os, const Obavestenje&ob)
{
	os << ob.id_ << " | " << ob.korisnik_->GetIme() << " - "<<std::endl;
	ob.Spec(os);
	return os;
}
