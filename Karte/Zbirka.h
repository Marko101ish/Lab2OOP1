#ifndef ZBIRKA_H
#define ZBIRKA_H
#include "List.h"
#include "Karta.h"



class Zbirka
{
public:



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
	Karta* operator [] (int index);
	friend std::ostream& operator<< (std::ostream& os, Zbirka& zb);

	//Brise element sa zadatim indeksom
	Karta* operator () (int index);
	//Brise element sa nasumicnim indeksom
	void operator ~ ();
	
#pragma endregion


#pragma region Operacije sa listom bez operatora
	Zbirka& PushEnd(Karta&);
	Karta* GetByID(int getid) const;
	Karta* DeleteByID(int getid);
	int GetTempNum() const;
	int GetLowest(); //dohvata indeks borca sa najmanjom snagom
#pragma endregion


private:

	void brisi();
	void premesti(Zbirka&);
	Elem *head, *last;
};

#endif
