#include "Karta.h"
#include "Carolija.h"
#include "Borac.h"
#include "Carobnjak.h"
#include "Zbirka.h"
#include "Igrac.h"
#include<iostream>

int main()
{

//Trenutno RUKA i SPIL pokazuju na istu zbirku, 
//nakon uvodjenja metode za izvlacenje karata ovo treba promeniti

//Karta ne sme da se kopira pa postoji samo premestanje kod zbirke i igraca

#pragma region Kreacija KARATA, ZBIRKI i IGRACA

	Carobnjak c1("CarobnjakJedinica", 330, 210);
	Carobnjak c2("CarobnjakDvojka", 322, 100);
	Carobnjak c3("CarobnjakTrojka", 55, 23);
	Carobnjak c4("CarobnjakCetv", 800, 120);
	Carobnjak c5("CarobnjakPet", 275, 300);
	Carobnjak c6("CarobnjakSest", 133, 119);

	Zbirka zb1;
	Zbirka zb2;

	zb1.PushEnd(c3).PushEnd(c1).PushEnd(c2);
	zb2.PushEnd(c4).PushEnd(c6).PushEnd(c5);

	Igrac i1("Marko", 100, 5000, zb1);
	Igrac i2("Nikola", 200, 3300, zb2);
#pragma endregion

	i1.Izvuci();
	i2.Izvuci();



	std::cout<<"Ruka prvog igraca:----------------------\n" << i1.GetRuka()<<std::endl;
	std::cout <<"Ruka drugog igraca:----------------------\n" << i2.GetRuka()<<std::endl;

	//Aktiviranje prebacuje kartu iz RUKE u AKTIVNE
	std::cout << "Snaga prvog pre aktiviranja: " << i1.GetMag() << std::endl;
	i1.Aktiviraj(1);
	std::cout << "Snaga prvog posle aktiviranja: " << i1.GetMag() << std::endl;


	i2.Aktiviraj(0);
	i2.Aktiviraj(1);
	i2.Aktiviraj(3);

	std::cout << "AKTIVNE IGRAC 1:\n"<<i1.GetAktiv()<<"\n-----------\n";
	std::cout << "AKTIVNE IGRAC 2:\n" << i2.GetAktiv() << "\n-----------\n";

	//Prva aktivacija, nista se ne desava
	i1.GetAktiv()[0]->Upotrebi(&i1, &i2);
	std::cout << "Zivotna pre upotrebe: " << i2.GetLife() << std::endl;
	//Druga aktivacija
	i1.GetAktiv()[0]->Upotrebi(&i1, &i2);
	std::cout << "Zivotna pre upotrebe: " << i2.GetLife() << std::endl;

	std::cout << std::endl <<"AKTIVNE IGRAC 2:\n"<< i2.GetAktiv()<<std::endl<<"GROBLJE IGRAC 2!\n";

	std::cout << i2.GetGroblje()<<std::endl;



	system("pause");
	return 0;
}