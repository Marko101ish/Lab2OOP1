#ifndef ZBIRKA_H
#define ZBIRKA_H

#include "Karta.h"

struct Elem
{
	Karta *karta;
	Elem *next;
};

class Zbirka
{
public:

	Zbirka& PushEnd(Karta&);

#pragma region Konstruktori, destruktor i dodela

	Zbirka(const Zbirka&)=delete;
	Zbirka(Zbirka&& zb) { premesti(zb); }
	Zbirka& operator = (const Zbirka&) = delete;
	Zbirka& operator = (Zbirka&& zb) { premesti(zb); return *this;  }

	Zbirka()
	{
		head = nullptr;
		last = nullptr;
	}

	~Zbirka()
	{
		brisi();
	}


#pragma endregion

#pragma region Operatori
	Karta* operator [] (int index) const;

	//Brise element sa zadatim indeksom
	Karta* operator () (int index);
	//Brise element sa nasumicnim indeksom
	void operator ~ ();
	
#pragma endregion

	Karta* GetByID(int getid) const;
	Karta* DeleteByID(int getid);

	friend std::ostream& operator<< (std::ostream& os, Zbirka& zb);

	int GetTempNum() const;

	int GetLowest(); //dohvata indeks borca sa najmanjom snagom
private:

	void brisi();
	void premesti(Zbirka&);
	Elem *head, *last;
};

#endif
