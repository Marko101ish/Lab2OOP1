#include "Polje.h"

Polje::Polje(int neproh)
{

	if (neproh > 1000)
		neproh_ = 1000;
	else if (neproh < 0)
		neproh_ = 0;
	else
		neproh_ = neproh;
}

#pragma region Operatori

Polje Polje::operator++(int)
{
	Polje tmp = *this;
	if(this->neproh_<1000)
		this->neproh_++;
	return tmp;
}

Polje Polje::operator--(int)
{
	Polje tmp = *this;
	if (this->neproh_ > 0)
		this->neproh_--;
	return tmp;
}

std::ostream & operator<<(std::ostream & os, const Polje & p)
{
	os << p.Oznaka() << '_' << p.neproh_;
	p.Pisi(os);
	return os;
}

#pragma endregion