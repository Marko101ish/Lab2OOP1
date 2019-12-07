#ifndef KARTA_H
#define KARTA_H

#include<string>
#include<iostream>


class Igrac;

enum Kategorija {CAROLIJA, BORAC};

// Karta ne sme da se kopira

class Karta
{
public:

#pragma region Konstruktori, destruktor i dodela

	//Karta ne sme da se kopira
	Karta(std::string ime, int magEn): ime_(ime), magEn_(magEn) {}
	Karta(const Karta&) = delete;
	Karta(Karta&&) = delete;
	Karta& operator= (const Karta&) = delete;
	Karta& operator= (Karta&&) = delete;


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
	//Ne moze da se instancira, jer je GETKATEGORIJA cisto virtuelna
	virtual Kategorija GetKategorija() const =0;

#pragma endregion

	//Ne moze da se instancira, jer su UPOTREBI i PISI cisto virtuelna
	virtual void Upotrebi(Igrac*, Igrac*) = 0;
	virtual void pisi(std::ostream&) const = 0;

#pragma region Operatori


	friend std::ostream& operator << (std::ostream &os, const Karta& k);

#pragma endregion


protected:
	int magEn_;

private:

	static int ID;
	int id_ = ID++;
	std::string ime_;

};



#endif