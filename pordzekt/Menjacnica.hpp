#ifndef MENJACNICA_HPP_INCLUDED
#define MENJACNICA_HPP_INCLUDED
#include "Radnik.hpp"
#include "Direktor.hpp"

class Menjacnica{

protected:
    Radnik r;
    Direktor d;


public:
    Menjacnica (string n, string p, int bg, int pl ,int rs, bool x, string c, bool pol, string Naziv,string Prezime, int BrojGodina,int Plata, int RadniStaz,bool b,string c1)
    :r(n, p, bg, pl, rs, x, c), d(pol, Naziv, Prezime, BrojGodina, Plata, RadniStaz, b, c1)
    {

    }

};


#endif // MENJACNICA_HPP_INCLUDED
