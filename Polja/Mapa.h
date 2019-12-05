#include "Polje.h"
#include "Types.h"
#include <iostream>

class PoljePut;
class PoljeSuma;

class Mapa
{
public:
	Mapa(const int, const int);
	Mapa(const Mapa&);
	Mapa(Mapa&&);
	~Mapa();


	//overload za f-ja zameni u zavisnosti od parametra
	void Zameni(int, int, VrstaPuta);
	void Zameni(int, int, unsigned int);

	//funkcija provera da li su prosledjeni parametri u opsegu indeksa vrsta i kolona
	bool proveri(int, int) const;

	friend Mapa& operator += (Mapa&, int);
	friend Mapa& operator -= (Mapa&, int);
	friend std::ostream& operator <<(std::ostream&, const Mapa&);
	Mapa& operator=(const Mapa&);
	Mapa& operator=(Mapa&&);

private:
	//Alocira memoriju za smestanje matrice
	void Inicijalizuj(int, int);

	void Kopiraj(const Mapa&);
	void Premesti(Mapa&);
	void Brisi();

	Polje ***map_;
	int rows_, cols_;
};