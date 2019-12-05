#ifndef POLJE_H
#define POLJE_H

#include<iostream>

class Polje
{
public:
	Polje(int=100);

	Polje operator ++(int);
	Polje operator --(int);
	friend std::ostream& operator << (std::ostream& os, const Polje& p);

	int GetNeproh() const { return neproh_; }

public:
	virtual char Oznaka() const { return 'P'; }

protected:
	virtual void Pisi(std::ostream&) const {};


protected:
	int neproh_;
};

#endif