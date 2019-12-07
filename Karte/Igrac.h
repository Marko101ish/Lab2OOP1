#ifndef IGRAC_H
#define IGRAC_H

#include<iostream>

class Karta;
class Zbirka;

class Igrac
{
public:

#pragma region Konstruktori, destruktor i dodela

	Igrac(std::string ime, int lifeEn, int magEn, Zbirka &spil);
	Igrac(Igrac&& ig) { Premesti(ig); }
	Igrac(const Igrac&) = delete;
	~Igrac();
	Igrac& operator = (const Igrac&) = delete;
	Igrac& operator = (Igrac&& ig) { Premesti(ig); return *this; }

#pragma endregion

	
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

	Zbirka& GetSpil() const
	{
		return *spil_;
	}

	Zbirka& GetRuka() const
	{
		return *ruka_;
	}
	Zbirka& GetAktiv() const
	{
		return *aktiv_;
	}
	Zbirka& GetGroblje() const
	{
		return *groblje_;
	}
#pragma endregion


	void CngLife(const int pts);
	void CngEn(const int pts);


#pragma region Prebacivanje karata
	//Prebacuje kartu iz ruke na teren
	void Aktiviraj(int);
	//Karta koja izvlaci karte iz spila, trenutno samo u ruku premesta spil
	void Izvuci();

#pragma endregion

private:
	std::string ime_;
	int lifeEn_, magEn_;
	Zbirka *spil_, *ruka_, *aktiv_, *groblje_;

	void Premesti(Igrac &);
	void GameOver();
};

#endif