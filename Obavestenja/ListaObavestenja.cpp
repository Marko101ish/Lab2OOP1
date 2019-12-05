#include "ListaObavestenja.h"
#include "Obavestenje.h"

ListaObavestenja& ListaObavestenja::Dodaj(Obavestenje& obav)
{
	Elem* novi = new Elem;
	novi->ob = &obav;
	if (!head)
	{
		last = novi;
	}
	novi->next = head;
	head = novi;
	return *this;
}



void ListaObavestenja::operator!()
{
	Elem* pom = head;
	while (pom)
	{
		if (!pom->ob->isRead())
			pom->ob->Read();
		pom = pom->next;
	}
}

int ListaObavestenja::operator+() const
{
	int br = 0;
	Elem* pom = head;
	while (pom)
	{
		if (!pom->ob->isRead())
			br++;
		pom = pom->next;
	}
	return br;
}

void ListaObavestenja::operator~()
{
	while (head)
	{
		Elem *old = head;
		head = head->next;
		old->next = nullptr;
	}
	last = nullptr;
}


//Popravi za const
Obavestenje* ListaObavestenja::operator[](int index) const
{
	Elem* pom = head;
	int ind = 0;
	while (pom)
	{
		if (ind == index)
		{
			if (!pom->ob->isRead())
				return pom->ob;
			else
				break;
		}
		pom = pom->next;
		ind++;
	}
	return nullptr;
}



Obavestenje* ListaObavestenja::operator[](int index)
{
	Elem* pom = head;
	int ind = 0;
	while (pom)
	{
		if (ind == index)
		{
			if (!pom->ob->isRead())
				return pom->ob;
			else
				break;
		}
		pom = pom->next;
		ind++;
	}
	return nullptr;
}

void ListaObavestenja::Brisi()
{
	while (head)
	{
		Elem* old = head;
		head = head->next;
		delete old;
	}
	last = nullptr;
}

void ListaObavestenja::Ispis(std::ostream& os, bool pickRead) const
{
	Elem* pom = head;
	while (pom)
	{
		if (!pom->ob->isRead() || pickRead)
			os << *pom->ob << std::endl;
		pom = pom->next;
	}
}

void ListaObavestenja::operator()() const
{
	Ispis(std::cout, false);
}

std::ostream& operator<<(std::ostream&os, ListaObavestenja&lst)
{
	lst.Ispis(os, true);
	return os;
}
