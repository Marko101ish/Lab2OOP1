#include "Borac.h"

bool operator>(const Borac & b1, const Borac & b2)
{
	if (b1.snaga_ > b2.snaga_)
		return true;
	return false;
}

void Borac::pisi(std::ostream& os) const
{
	os<< "(snaga: " << snaga_ << ')';
}

//void Borac::Upotrebi(Igrac &izad, Igrac &iprot)
//{
//	if (upotreba_ > 0)
//	{
//		upotreba_++;
//	}
//}

