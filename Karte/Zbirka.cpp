#include "Zbirka.h"
#include "Borac.h"
#include<cstdlib>

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

void Zbirka::DeleteByID(int getid)
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
			return;
		}
		tek = pom;
		pom = pom->next;
	}
}

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

void Zbirka::operator()(int index)
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
			return;
		}
		i++;
		tek = pom;
		pom = pom->next;
	}
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

