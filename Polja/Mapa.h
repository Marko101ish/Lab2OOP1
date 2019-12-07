#include "Polje.h"
#include "Types.h"
#include <iostream>

class PoljePut;
class PoljeSuma;

class Mapa
{
public:

#pragma region Konstruktori, destruktor i dodela

	Mapa(const int, const int);
	Mapa(const Mapa&);
	Mapa(Mapa&&);
	~Mapa();
	friend Mapa& operator += (Mapa&, int);
	friend Mapa& operator -= (Mapa&, int);
#pragma endregion

#pragma region ZAMENA I PROVERA

	//overload za f-ja zameni u zavisnosti od parametra
	void Zameni(int, int, VrstaPuta);
	void Zameni(int, int, unsigned int);

	//funkcija provera da li su prosledjeni parametri u opsegu indeksa vrsta i kolona
	bool proveri(int, int) const;

#pragma endregion

#pragma region Operatori

	friend std::ostream& operator <<(std::ostream&, const Mapa&);
	Mapa& operator=(const Mapa&);
	Mapa& operator=(Mapa&&);

#pragma endregion

private:
	//Alocira memoriju za smestanje matrice
	void Inicijalizuj(int, int);
	void Kopiraj(const Mapa&);
	void Premesti(Mapa&);
	void Brisi();

	Polje ***map_;
	int rows_, cols_;
};