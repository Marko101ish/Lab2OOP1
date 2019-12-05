#ifndef POLJESUMA_H
#define POLJESUMA_H

#include "Polje.h"
#include<iostream>

class PoljeSuma : public Polje
{
public:
	PoljeSuma(int neproh, unsigned int gustina) : gustina_(gustina), Polje(neproh) {}

	char Oznaka() const override { return 'S'; }
	void Pisi(std::ostream&) const override;

private:
	unsigned int gustina_;
};

#endif