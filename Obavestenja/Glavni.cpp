#include "Korisnik.h"
#include "Obavestenje.h"
#include "Objava.h"
#include "ListaObavestenja.h"
#include<string>
#include<iostream>

//Lista:
//+= dodaje na pocetak, () neprocitana
//+ broj neprocitanih, ! oznaci procitanim
//~brise sva obavestenja iz liste
//[id] dohvata neprocitano
int main()
{
	Korisnik k1("Miroslav");

	Korisnik k4("Nikola");

	Objava o1(&k1, "METALLICA!!!");
	Objava o2(&k1, "MEGADETH!!!");
	Objava o3(&k1, "SLAYER!!!");

	ListaObavestenja lstObav;

	lstObav += o1;
	lstObav += o2;
	lstObav += o3;
	std::cout << std::endl << "---------------------" << std::endl;
	lstObav();
	std::cout << +lstObav << std::endl;
	!lstObav;
	std::cout << +lstObav << std::endl;
	std::cout << std::endl << "---------------------" << std::endl;
	lstObav();
	std::cout << std::endl << "---------------------" << std::endl;
	std::cout << lstObav;



	Korisnik k2("Marko");
	k1.Posalji(k4, o2);

	system("pause");
	return 0;
}