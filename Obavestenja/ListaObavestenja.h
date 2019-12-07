#ifndef LISTAOBAVESTENJA_H
#define LISTAOBAVESTENJA_H

#include "Obavestenje.h"

struct Elem
{
	Obavestenje* ob;
	Elem* next;
};
class ListaObavestenja
{
public:

#pragma region Konstruktori, destruktor i dodela

	ListaObavestenja() {}
	ListaObavestenja(const ListaObavestenja&) = delete;
	ListaObavestenja(ListaObavestenja&&) = delete;
	~ListaObavestenja();
	ListaObavestenja& operator=(const ListaObavestenja&) = delete;
	ListaObavestenja& operator=(ListaObavestenja&&) = delete;

#pragma endregion

#pragma region Operatori

	friend ListaObavestenja& operator +=(ListaObavestenja&tek, Obavestenje& ob) { return tek.Dodaj(ob); }
	void operator() () const;
	void operator! ();
	int operator+ () const;
	void operator~ ();
	friend std::ostream& operator<<(std::ostream&, const ListaObavestenja&);
	Obavestenje* operator[] (int) const;
	Obavestenje* operator[] (int);
#pragma endregion


private:
	//Dodavanje se vrsi na pocetak, trenutno nije potreban last!
	Elem* head=nullptr, *last=nullptr;

	ListaObavestenja& Dodaj(Obavestenje&);
	void Brisi();
	void Ispis(std::ostream&, bool) const;

};
#endif