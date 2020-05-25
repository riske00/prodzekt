#ifndef RADNIK_HPP_INCLUDED
#define RADNIK_HPP_INCLUDED
#include "cvRadnika.hpp"

class Radnik{

protected:
    string naziv;
    string prezime;
    int brojGodina;
    int plata;
    int radniStaz;
    cvRadnika q;

public:

    Radnik(string Naziv,string Prezime, int BrojGodina,int Plata, int RadniStaz,bool b,string c):q(b,c)
    {

        naziv=Naziv;
        prezime=Prezime;
        brojGodina=BrojGodina;
        plata=Plata;
        radniStaz=RadniStaz;


    }

    string GetNaziv(){
        return naziv;
    }

    void SetNaziv(string Naziv){

        naziv=Naziv;

    }
    void iskustvo(cvRadnika &cv)
    {
        if(cv.getStaz()==false)
        {
            radniStaz=0;
        }
        if(brojGodina<=18)
        {
            radniStaz=0;
            cv.setStaz(false);
        }
    }
friend ostream& operator<<(ostream& izlaz, const Radnik &r);
virtual void staz()
{
    cout<<"Radni staz je "<<radniStaz;
}
    int getStaz(){return radniStaz;}
};

#endif // RADNIK_HPP_INCLUDED
