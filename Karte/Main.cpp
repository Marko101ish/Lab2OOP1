#include "Karta.h"
#include "Carolija.h"
#include "Borac.h"
#include "Carobnjak.h"
#include "Zbirka.h"
#include "Igrac.h"
#include<iostream>

int main()
{

	Carobnjak c1("CarobnjakDvojka", 330, 210);
	Carobnjak c2("CarobnjakTrojka", 322, 100);
	Carobnjak c3("CarobnjakJedinica", 55, 23);


	Carobnjak c4("CarobnjakCetv", 800, 120);
	Carobnjak c5("CarobnjakPet", 275, 300);
	Carobnjak c6("CarobnjakSest", 133, 119);

	Igrac i1("Marko", 100, 5000);
	Igrac i2("Nikola", 200, 3300);


	(*i1.GetAktiv()).PushEnd(c3).PushEnd(c1).PushEnd(c2);
	(*i2.GetAktiv()).PushEnd(c4).PushEnd(c6).PushEnd(c5);

	//std::cout << *i1.GetAktiv()<<std::endl;
	//std::cout << *i2.GetAktiv()<<std::endl;

	//(*(i1.GetAktiv()))[1]->Upotrebi(&i1, &i2);

	//std::cout << std::endl << *i2.GetAktiv();

	//std::cout << *i2.GetGroblje();

	//(*(i1.GetAktiv()))[1]->Upotrebi(&i1, &i2);

	//std::cout <<std::endl<< *i2.GetAktiv()<<std::endl;

	//std::cout << *i2.GetGroblje();

	(*i2.GetAktiv())(2);

	std::cout << std::endl << *i2.GetAktiv() << std::endl;



	system("pause");
	return 0;
}