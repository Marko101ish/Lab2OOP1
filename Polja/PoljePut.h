#ifndef POLJEPUT_H
#define POLJEPUT_H

#include"Types.h"
#include"Polje.h"

class PoljePut:public Polje
{
public:
	PoljePut(int neproh, VrstaPuta vrstPP) : vrstaPP_(vrstPP), Polje(neproh) {}

	char Oznaka() const override;
private:
	VrstaPuta vrstaPP_;
};

#endif