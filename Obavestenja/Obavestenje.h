#ifndef OBAVESTENJE_H
#define OBAVESTENJE_H

#include<ctime>
#include<iostream>

class Korisnik;

class Obavestenje
{
public:
	Obavestenje(Korisnik* korisnik);
	
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
	void Read()
	{
		if (read_ == false)
		{
			read_ = true;
		}
	}

	friend std::ostream& operator << (std::ostream&, const Obavestenje &);

protected:
	//Spec je ostavljen kao apstraktna metoda, ne moze da se napravi objekat tipa Obavestenje!
	virtual void Spec(std::ostream&) const =0;
private:
	static int ID;
	int id_ = ID++;
	//time_t vreme_ = time_t();
	bool read_ = false;
	Korisnik* korisnik_;
};
#endif


