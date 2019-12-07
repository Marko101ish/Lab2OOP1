#ifndef KORISNIK_H
#define KORISNIK_H

class ListaObavestenja;
class Obavestenje;
#include<iostream>


class Korisnik
{
public:
#pragma region Konstruktori, destruktor i dodela

	Korisnik(std::string ime);
	Korisnik(const Korisnik&) = delete;
	Korisnik(Korisnik&&) = delete;
	~Korisnik();
	Korisnik& operator=(const Korisnik&) = delete;
	Korisnik& operator=(Korisnik&&) = delete;

#pragma endregion

#pragma region Geteri

	std::string GetIme() const
	{
		return ime_;
	}
	const ListaObavestenja& GetInbox() const
	{
		return *inbox_;
	}

#pragma endregion


	void Posalji(Korisnik&, Obavestenje&) const;
	void Primi(Obavestenje&);

	friend std::ostream& operator << (std::ostream&, const Korisnik&);

	//Dodati specifican ispis
	void Spec(std::ostream&) const {}
private:
	std::string ime_;
	ListaObavestenja* inbox_;
};

#endif