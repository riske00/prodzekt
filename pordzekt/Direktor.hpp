#ifndef DIREKTOR_HPP_INCLUDED
#define DIREKTOR_HPP_INCLUDED
#include "radnik.hpp"
class Direktor:public Radnik
{

protected:
    bool pol;


public:

    Direktor (bool p, string Naziv,string Prezime, int BrojGodina,int Plata, int RadniStaz,bool b,string c):Radnik(Naziv, Prezime, BrojGodina, Plata, RadniStaz, b, c)
    {
        pol=p;
    }
    friend ostream& operator<<(ostream& izlaz, const Direktor &d);
};


#endif // DIREKTOR_HPP_INCLUDED
