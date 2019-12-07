#ifndef CAROBNJAK_H
#define CAROBNJAK_H

#include "Borac.h"
#include "Igrac.h"
#include<iostream>


class Carobnjak:public Borac
{
public:
	Carobnjak(std::string ime, int magEn, int snaga) : Borac(ime, magEn, snaga) {}
	
	void pisi(std::ostream&) const override;


	//nije const jer ostavlja mogucnost da se nesto desava sa kartom koja je upotrebljena
	void Upotrebi(Igrac*, Igrac*) override;

};

#endif