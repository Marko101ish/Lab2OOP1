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

	Zbirka zb1;
	Zbirka zb2;

	zb1.PushEnd(c3).PushEnd(c1).PushEnd(c2);
	zb2.PushEnd(c4).PushEnd(c6).PushEnd(c5);



	Igrac i1("Marko", 100, 5000, zb1);
	Igrac i2("Nikola", 200, 3300, zb2);

	i1.Izvuci();
	i2.Izvuci();

	std::cout << i1.GetRuka()<<std::endl;
	std::cout << i2.GetRuka()<<std::endl;

	//Aktiviranje prebacuje kartu iz RUKE u AKTIVNE
	i1.Aktiviraj(1);

	i2.Aktiviraj(0);
	i2.Aktiviraj(1);
	i2.Aktiviraj(3);

	std::cout << "AKTIVNE IGRAC 1:\n"<<i1.GetAktiv()<<"\n-----------\n";
	std::cout << "AKTIVNE IGRAC 2:\n" << i2.GetAktiv() << "\n-----------\n";

	//Prva aktivacija, nista se ne desava
	i1.GetAktiv()[0]->Upotrebi(&i1, &i2);

	//Druga aktivacija
	i1.GetAktiv()[0]->Upotrebi(&i1, &i2);

	std::cout << std::endl <<"AKTIVNE IGRAC 2:\n"<< i2.GetAktiv()<<std::endl<<"GROBLJE IGRAC 2!\n";

	std::cout << i2.GetGroblje()<<std::endl;

	//Karta ne sme da se kopira pa postoji samo premestanje kod zbirke i igraca
	system("pause");
	return 0;
}