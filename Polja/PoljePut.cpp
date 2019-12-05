#include "PoljePut.h"

char PoljePut::Oznaka() const
{
	if (vrstaPP_ == ZEMLJANI)
		return 'Z';
	else
		return 'K';
}
