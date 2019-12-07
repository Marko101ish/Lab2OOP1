#ifndef OBAVESTENJE_H
#define OBAVESTENJE_H

#include<ctime>
#include<iostream>
#include<string>

class Korisnik;

class Obavestenje
{
public:
	Obavestenje(Korisnik* korisnik);
	

#pragma region Geteri
	int GetID() const
	{
		return id_;
	}
	Korisnik* GetKorisnik() const
	{
		return korisnik_;
	}
	bool isRead() const
	{
		return read_;
	}
#pragma endregion

	void Read()
	{
		if (read_ == false)
		{
			read_ = true;
		}
	}

	friend std::ostream& operator << (std::ostream &os, const Obavestenje& ob);

protected:
	//Spec je ostavljen kao apstraktna metoda, ne moze da se napravi objekat tipa Obavestenje!
	virtual void Spec(std::ostream&) const =0;

private:
	static int ID;
	int id_ = ID++;
	time_t vreme_ = time(NULL);
	bool read_ = false;
	Korisnik* korisnik_;
};
#endif


