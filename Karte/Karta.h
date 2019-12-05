#ifndef KARTA_H
#define KARTA_H

#include<string>
#include<iostream>


class Igrac;

enum Kategorija {CAROLIJA, BORAC};


class Karta
{
public:

#pragma region Konstruktori&destruktor

	Karta(std::string ime, int magEn): ime_(ime), magEn_(magEn) {}
	Karta(const Karta&) = delete;
	Karta(Karta&&) = delete;


#pragma endregion



#pragma region Geteri

	int GetMagEn() const
	{
		return magEn_;
	}

	int GetID() const
	{
		return id_;
	}

	std::string GetIme() const
	{
		return ime_;
	}

	virtual Kategorija GetKategorija() const =0;

#pragma endregion


	virtual void Upotrebi(Igrac*, Igrac*) = 0;

#pragma region Operatori

	Karta& operator= (const Karta&) = delete;
	Karta& operator= (Karta&&) = delete;
	friend std::ostream& operator << (std::ostream &os, const Karta& k);

#pragma endregion
	virtual void pisi(std::ostream&) const = 0;
private:

	static int ID;
	int id_ = ID++;
	std::string ime_;
	int magEn_;
};



#endif