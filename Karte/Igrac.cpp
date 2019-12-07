#include "Igrac.h"
#include "Zbirka.h"
#include "Karta.h"
#include<iostream>

#pragma region Konstruktor, destruktor i f-ja za premestanje

Igrac::Igrac(std::string ime, int lifeEn, int magEn, Zbirka &spil)
{
	ime_ = ime;
	if (lifeEn <= 0)
		lifeEn = 1;
	if (magEn <= 0)
		magEn = 1;
	lifeEn_ = lifeEn;
	magEn_ = magEn;
	spil_ = &spil;
	aktiv_ = new Zbirka();
	groblje_ = new Zbirka();
	ruka_ = new Zbirka();
}

Igrac::~Igrac()
{
	delete aktiv_;
	delete groblje_;
	//Ruka trenutno pokazuje na istu zbirku kao i spil pa se ne moze izbrisati odavde
	//delete ruka_;
	spil_ = aktiv_ = ruka_ = groblje_ = nullptr;
	magEn_ = 0;
	lifeEn_ = 0;
	ime_ = "";
}

void Igrac::Premesti(Igrac &ig)
{
	ime_ = ig.ime_;
	magEn_ = ig.magEn_;
	lifeEn_ = ig.lifeEn_;
	spil_ = ig.spil_;
	ruka_ = ig.ruka_;
	aktiv_ = ig.aktiv_;
	groblje_ = ig.groblje_;

	ig.groblje_ = ig.aktiv_ = ig.ruka_ = ig.spil_ = nullptr;
}

#pragma endregion



#pragma region Prebacivanje karata (aktivacija, izvlacenje,...)
void Igrac::Aktiviraj(int indRuka)
{
	if (indRuka < ruka_->GetTempNum())
	{
		int magEnKarte = (*ruka_)[indRuka]->GetMagEn();
		if (magEnKarte <= magEn_)
		{
			CngEn(-magEnKarte);
			aktiv_->PushEnd(*(*ruka_)(indRuka));
		}
	}
}

void Igrac::Izvuci()
{
	ruka_ = spil_;
}
#pragma endregion



void Igrac::CngLife(const int pts)
{
	int newLifePTS = lifeEn_ + pts;
	if (newLifePTS <= 0)
		GameOver();
	lifeEn_ = newLifePTS;
}

void Igrac::CngEn(const int pts)
{
	magEn_ += pts;
}


void Igrac::GameOver()
{
	std::cout << "Igrac: " << ime_ << " je porazen, igra je zavrsena!\n";
	system("pause");
	exit(0);
}

