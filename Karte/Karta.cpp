#include "Karta.h"

int Karta::ID = 1;

std::ostream & operator<<(std::ostream & os, const Karta & k)
{

	os << "[" << k.id_ << "] ''" << k.ime_ << "'' (cena: " << k.magEn_ << ")";
	k.pisi(os);
	return os;
}
