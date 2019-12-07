#include "Zbirka.h"
#include "Borac.h"
#include<cstdlib>


#pragma region Brisanje i premestanje

//Brise objekte potpuno
void Zbirka::brisi()
{
	Elem *pom;
	while (head)
	{
		pom = head;
		head = head->next;
		pom->next = nullptr;
		delete pom;
	}
}

//Samo premesta pokazivace, ne dira karte jer ne smeju da se kopiraju
void Zbirka::premesti(Zbirka &zb)
{
	head = zb.head;
	last = zb.last;
	zb.head = nullptr;
	zb.last = nullptr;
}
#pragma endregion


#pragma region Lista, bez operacija sa operatorima


Zbirka& Zbirka::PushEnd(Karta& novaKarta)
{
	Elem *novi = new Elem();
	novi->karta = &novaKarta;
	if (!head)
		head = novi;
	else
		last->next = novi;
	last = novi;
	return *this;
}

Karta * Zbirka::GetByID(int getid) const
{
	Elem *pom = head;
	while (pom)
	{
		if (pom->karta->GetID() == getid)
			return pom->karta;
		pom = pom->next;
	}
	return nullptr;
}

Karta* Zbirka::DeleteByID(int getid)
{
	Elem *pom = head;
	Elem *tek = nullptr;
	while (pom)
	{
		if (pom->karta->GetID() == getid)
		{
			if (pom == head)
			{
				head = head->next;
			}
			else
			{
				if (pom == last)
					last = tek;
				tek->next = pom->next;
			}
			pom->next = nullptr;
			return pom->karta;
		}
		tek = pom;
		pom = pom->next;
	}
	return nullptr;
}
//Dohvata broj karata u zbirci
int Zbirka::GetTempNum() const
{
	Elem *pom = head;
	int s = 0;
	while (pom)
	{
		s++;
		pom=pom->next;
	}
	return s;
}

//Dohvata borca sa najmanjom snagom
int Zbirka::GetLowest()
{
	int i = 0;
	int min, minind=-1;
	bool flagmin = false;
	Elem* temp = head;
	while (temp)
	{
		if (temp->karta->GetKategorija() == BORAC)
		{
			Borac *pomb = dynamic_cast<Borac*>(temp->karta);
			int tmpSnaga = pomb->GetSnaga();
			if (!flagmin || tmpSnaga<min)
			{
				min = tmpSnaga;
				minind = i;
				flagmin = true;
			}
		}
		i++;
		temp = temp->next;
	}
	return minind;
}

#pragma endregion


#pragma region Operatori

Karta* Zbirka::operator[](int index) const
{
	Elem *pom = head;
	int i = 0;
	while (pom)
	{
		if (i == index)
			return pom->karta;
		i++;
		pom = pom->next;
	}
	return nullptr;
}

Karta * Zbirka::operator[](int index)
{
	Elem *pom = head;
	int i = 0;
	while (pom)
	{
		if (i == index)
			return pom->karta;
		i++;
		pom = pom->next;
	}
	return nullptr;
}

Karta* Zbirka::operator()(int index)
{
	Elem *pom = head;
	Elem *tek = nullptr;
	int i = 0;
	while (pom)
	{
		if (i == index)
		{
			if (pom == head)
			{
				head = head->next;
			}
			else
			{
				if (pom == last)
					last = tek;
				tek->next = pom->next;
			}
			pom->next = nullptr;
			return pom->karta;
		}
		i++;
		tek = pom;
		pom = pom->next;
	}
	return nullptr;
}

void Zbirka::operator~()
{
	int i = 0;
	i = rand() % GetTempNum();
	(*this)(i);
}

std::ostream & operator<<(std::ostream & os, Zbirka & zb)
{
	Elem *pom = zb.head;
	while (pom)
	{
		os << *(pom->karta) << std::endl;
		pom = pom->next;
	}
	return os;
}

#pragma endregion