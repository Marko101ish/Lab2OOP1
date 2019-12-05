#include<iostream>
#include "Korisnik.h"
#include "Obavestenje.h"
#include "Objava.h"
#include "ListaObavestenja.h"
int main()
{
	Korisnik k1("Miroslav");
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


	system("pause");
	return 0;
}