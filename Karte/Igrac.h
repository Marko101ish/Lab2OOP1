#ifndef IGRAC_H
#define IGRAC_H

#include "Zbirka.h"

class Igrac
{
public:
	Igrac(std::string ime, int lifeEn, int magEn):ime_(ime), lifeEn_(lifeEn), magEn_(magEn) 
	{
		spil_ = new Zbirka();
		aktiv_ = new Zbirka();
		groblje_ = new Zbirka();
		ruka_ = new Zbirka();

	}
	
#pragma region Geteri

	std::string GetIme() const
	{
		return ime_;
	}
	int GetLife() const
	{
		return lifeEn_;
	}

	int GetMag() const
	{
		return magEn_;
	}

	Zbirka* GetSpil() const
	{
		return spil_;
	}

	Zbirka* GetRuka() const
	{
		return ruka_;
	}
	Zbirka* GetAktiv() const
	{
		return aktiv_;
	}
	Zbirka* GetGroblje() const
	{
		return groblje_;
	}
#pragma endregion


	void CngLife(const int pts)
	{
		lifeEn_ += pts;
	}
	void CngEn(const int pts)
	{
		magEn_ += pts;
	}

//Funkcija koja prebacuje zadati broj karata iz spila u ruku
	//void Izvuci(int brojKarata);
//Prebacuje kartu iz ruke u aktivne
	//void Aktviraj(...);

private:
	std::string ime_;
	int lifeEn_, magEn_;
	Zbirka *spil_, *ruka_, *aktiv_, *groblje_;
};

#endif