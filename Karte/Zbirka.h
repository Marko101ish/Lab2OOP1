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

#pragma region Konstruktori&destruktor

	Zbirka(const Zbirka&)=delete;
	Zbirka(Zbirka&&)=delete;


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

	Zbirka& operator = (const Zbirka&)=delete;
	Zbirka& operator = (Zbirka&&)=delete;
	Karta* operator [] (int index) const;

	//Brise element sa zadatim indeksom
	void operator () (int index);
	//Brise element sa nasumicnim indeksom
	void operator ~ ();
	
#pragma endregion

	Karta* GetByID(int getid) const;
	void DeleteByID(int getid);

	friend std::ostream& operator<< (std::ostream& os, Zbirka& zb);

	int GetTempNum() const;

	int GetLowest(); //dohvata indeks borca sa najmanjom snagom
private:

	void brisi();
	Elem *head, *last;
};

#endif
