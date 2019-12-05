#ifndef KORISNIK_H
#define KORISNIK_H


class Korisnik
{
public:

	Korisnik(std::string ime) :ime_(ime) {}

	std::string GetIme() const
	{
		return ime_;
	}
private:
	std::string ime_;
};

#endif