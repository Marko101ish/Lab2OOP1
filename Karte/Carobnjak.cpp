#include "Borac.h"
#include "Carobnjak.h"
#include "Zbirka.h"

void Carobnjak::pisi(std::ostream& os) const
{
	Borac::pisi(os);
	os<< " - CAROBNJAK";
}

void Carobnjak::Upotrebi(Igrac *izad, Igrac *iprot)
{

	if (upotreba_)
	{
		Zbirka *aktiv = &iprot->GetAktiv();
		int index = aktiv->GetLowest();
		if (index > -1)
		{
			Borac *slabBorac = dynamic_cast<Borac *>((*aktiv)[index]);
			if (snaga_ <= slabBorac->GetSnaga())
				return;
			//Moglo bi da se doda da se Carobnjak unisti ako ima manju snagu
			//u tom slucaju prelazi na groblje i1, i brise se iz aktivnih igraca i1
			iprot->GetGroblje().PushEnd(*(*aktiv)(index));
			iprot->CngLife(-2 * snaga_);
		}
	}
	else
		upotreba_=true;

}
