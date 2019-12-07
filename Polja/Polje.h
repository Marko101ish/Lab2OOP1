#ifndef POLJE_H
#define POLJE_H

#include<iostream>

class Polje
{
public:
	Polje(int=100);

#pragma region Operatori

	Polje operator ++(int);
	Polje operator --(int);
	friend std::ostream& operator << (std::ostream& os, const Polje& p);

#pragma endregion

	int GetNeproh() const { return neproh_; }
	virtual char Oznaka() const { return 'P'; }

protected:
	virtual void Pisi(std::ostream&) const {};
	int neproh_;
};

#endif