#ifndef OBJAVA_H
#define OBJAVA_H
#include "Obavestenje.h"
class Korisnik;

class Objava : public Obavestenje
{
public:
	Objava(Korisnik* korisnik, std::string tekst) : tekst_(tekst), Obavestenje(korisnik) {}
	void Spec(std::ostream&) const override;
private:
	std::string tekst_;
};
#endif