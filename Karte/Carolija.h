#ifndef CAROLIJA_H
#define CAROLIJA_H

#include "Karta.h"

class Carolija:public Karta
{
public:
	Kategorija GetKategorija() const override
	{
		return CAROLIJA;
	}
};

#endif