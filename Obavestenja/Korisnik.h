#ifndef KORISNIK_H
#define KORISNIK_H

class ListaObavestenja;
class Obavestenje;
#include<iostream>


class Korisnik
{
public:

	Korisnik(std::string ime);

	std::string GetIme() const
	{
		return ime_;
	}

	void Posalji(Korisnik&, std::string) const;
	void Primi(Obavestenje&);

	Korisnik(const Korisnik&) = delete;
	Korisnik(Korisnik&&) = delete;

	Korisnik& operator=(const Korisnik&) = delete;
	Korisnik& operator=(Korisnik&&) = delete;

	friend std::ostream& operator << (std::ostream, Korisnik&);
	void Spec(std::ostream&) const {}
private:
	std::string ime_;
	ListaObavestenja* inbox_;
};

#endif