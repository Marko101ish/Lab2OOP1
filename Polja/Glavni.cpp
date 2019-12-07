#include "Polje.h"
#include "PoljePut.h"
#include "PoljeSuma.h"
#include "Types.h"
#include "Mapa.h"
#include<iostream>

int main()
{
	Polje p(100);
	PoljePut p1(100, ZEMLJANI);
	PoljeSuma p2(100, 200);
	std::cout << p << std::endl;
	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl << std::endl;
	Mapa m1(3,4);
	std::cout << m1 << std::endl;

	Mapa m2(1,1);

	m2 = Mapa(2, 3);
	std::cout << m2<<std::endl;
	m1.Zameni(1, 0, ZEMLJANI);
	m1.Zameni(0, 1, 234);

	std::cout <<std::endl<< m1 << std:: endl;

	system("pause");
	return 0;
}