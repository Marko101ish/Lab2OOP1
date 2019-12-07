#ifndef BORAC_H
#define BORAC_H

#include "Karta.h"
#include "Igrac.h"
#include<iostream>


class Borac :public Karta
{
public:


	Borac(std::string ime, int magEn, int snaga) : snaga_(snaga), Karta(ime, magEn) {}

#pragma region Geteri

	int GetSnaga() const
	{
		return snaga_;
	}
	Kategorija GetKategorija() const override
	{
		return BORAC;
	}

#pragma endregion

#pragma region Operatori

	friend bool operator > (const Borac& b1, const Borac& b2);
	friend bool operator < (const Borac& b1, const Borac& b2);
	friend bool operator >= (const Borac& b1, const Borac& b2);
	friend bool operator <= (const Borac& b1, const Borac& b2);
	friend bool operator == (const Borac& b1, const Borac& b2);
	friend bool operator != (const Borac& b1, const Borac& b2);

#pragma endregion

	void pisi(std::ostream&) const override;

	void Upotrebi(Igrac*, Igrac*)=0;

protected:
	int snaga_;
	bool upotreba_ = false;
};

#endif