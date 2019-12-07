#include "Borac.h"


#pragma region Operatori

bool operator>(const Borac & b1, const Borac & b2)
{
	if (b1.snaga_ > b2.snaga_)
		return true;
	return false;
}

bool operator<(const Borac & b1, const Borac & b2)
{
	if (b1.snaga_ < b2.snaga_)
		return true;
	return false;
}

bool operator>=(const Borac & b1, const Borac & b2)
{
	if (b1.snaga_ >= b2.snaga_)
		return true;
	return false;
}

bool operator<=(const Borac & b1, const Borac & b2)
{
	if (b1.snaga_ <= b2.snaga_)
		return true;
	return false;
}

bool operator==(const Borac & b1, const Borac & b2)
{
	if (b1.snaga_ == b2.snaga_)
		return true;
	return false;
}

bool operator!=(const Borac & b1, const Borac & b2)
{
	if (b1.snaga_ != b2.snaga_)
		return true;
	return false;
}

#pragma endregion

void Borac::pisi(std::ostream& os) const
{
	os<< "(snaga: " << snaga_ << ')';
}


