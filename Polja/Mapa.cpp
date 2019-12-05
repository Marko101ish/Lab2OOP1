#include "Mapa.h"
#include "Polje.h"
#include "PoljePut.h"
#include "PoljeSuma.h"

Mapa::Mapa(const int rows, const int cols)
{
	Inicijalizuj(rows, cols);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			map_[i][j] = new Polje;
		}
}

Mapa::Mapa(const Mapa &m1)
{
	Kopiraj(m1);
}

Mapa::Mapa(Mapa && m1)
{
	Premesti(m1);
}

Mapa::~Mapa()
{
	Brisi();
}

Mapa & Mapa::operator=(const Mapa &m1)
{
	Kopiraj(m1);
	return *this;
}

Mapa & Mapa::operator=(Mapa && m1)
{
	Premesti(m1);
	return *this;
}

#pragma region Zamene

void Mapa::Zameni(int x, int y, VrstaPuta vrsta)
{
	if (proveri(x, y))
	{
		int nepr = this->map_[x][y]->GetNeproh();
		Polje *old = this->map_[x][y];
		this->map_[x][y] = new PoljePut(nepr, vrsta);
		delete old;
	}
}

void Mapa::Zameni(int x, int y, unsigned int gust)
{
	if (proveri(x, y))
	{
		int nepr = this->map_[x][y]->GetNeproh();
		Polje *old = this->map_[x][y];
		this->map_[x][y] = new PoljeSuma(nepr, gust);
		delete old;
	}
}

#pragma endregion

bool Mapa::proveri(int x, int y) const
{
	if (x < rows_ && x >= 0 && y >= 0 && y < cols_)
		return true;
	return false;
}

#pragma region Funkcije za kop, prem i brisanje

void Mapa::Inicijalizuj(int rows, int cols)
{
	rows_ = rows;
	cols_ = cols;
	map_ = new Polje**[rows_];
	for (int i = 0; i < rows_; i++)
		map_[i] = new Polje*[cols_];
}

void Mapa::Kopiraj(const Mapa &m1)
{
	PoljeSuma *pom1;
	PoljePut *pom2;



	Inicijalizuj(m1.rows_, m1.cols_);
	for (int i = 0; i < m1.rows_; i++)
		for (int j = 0; j < m1.cols_; j++)
		{
			char o=m1.map_[i][j]->Oznaka();
			switch (o)
			{
			case 'P':
				map_[i][j] = new Polje(*m1.map_[i][j]);
				break;
			case 'S':
				pom1 = dynamic_cast<PoljeSuma*>(m1.map_[i][j]);
				map_[i][j] = new PoljeSuma(*pom1);
				break;
			case 'K':case 'Z':
				pom2 = dynamic_cast<PoljePut*>(m1.map_[i][j]);
				map_[i][j] = new PoljePut(*pom2);
				break;
			}
		}
}

void Mapa::Premesti(Mapa &m1)
{
	Inicijalizuj(m1.rows_, m1.cols_);
	for (int i = 0; i < rows_; i++)
		for (int j = 0; j < cols_; j++)
		{
			map_[i][j] = m1.map_[i][j];
			m1.map_[i][j]=nullptr;
		}
	rows_ = m1.rows_;
	cols_ = m1.cols_;
}

void Mapa::Brisi()
{
	for (int i = 0; i < rows_; i++)
		for (int j = 0; j < cols_; j++)
			delete map_[i][j];
	map_ = nullptr;
	rows_ = 0;
	cols_ = 0;
}
#pragma endregion


#pragma region Operatori

Mapa & operator+=(Mapa &m, int broj)
{
	if (broj > 0)
	{
		for (int i = 0; i < m.rows_; i++)
			for (int j = 0; j < m.cols_; j++)
			{
				int pom = broj;
				while (pom > 0)
				{
					(*m.map_[i][j])++;
					pom--;
				}
			}
	}
	return m;
}

Mapa & operator-=(Mapa &m, int broj)
{
	if (broj > 0)
	{
		for (int i = 0; i < m.rows_; i++)
			for (int j = 0; j < m.cols_; j++)
			{
				int pom = broj;
				while (pom > 0)
				{
					(*m.map_[i][j])--;
					pom--;
				}
			}
	}
	return m;
}

std::ostream & operator<<(std::ostream &os, const Mapa& m)
{
	Polje *pom;
	for (int i = 0; i<m.rows_; i++)
	{
		for (int j = 0; j<m.cols_; j++)
		{
			pom = m.map_[i][j];
			os << *pom << '\t';
		}
	os << std::endl;
	}
	return os;
}

#pragma endregion
