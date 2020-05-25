#ifndef OBEZBEDJENJE_HPP_INCLUDED
#define OBEZBEDJENJE_HPP_INCLUDED
#include "Radnik.hpp"
class Obezbedjenje:public Radnik{
protected:
    int BrojRadnika;
    vector <Radnik*> radnici;
public:
    Obezbedjenje(string ime, string prezime, int g, int p,int gs,bool d,string o,int x): Radnik(ime,prezime,g,p,gs,d,o)
    {
        BrojRadnika=x;
    }
void staz()
{
    Radnik::staz();
    cout<<" a broj radnika je "<<BrojRadnika<<endl;
}

void dodajUObezbedjenje(Radnik &r)
    {
        radnici.push_back(&r);
        cout<<"Radnik dodat!"<<endl;
    }
    void ispisObezbedjenja()
    {
        cout<<"Radnici koji su obezbedjenje su: "<<endl;
        for(auto it=radnici.begin(); it!=radnici.end(); it++)
        {
            cout<<**it<<endl;
            cout<<endl;
        }
    }
    int brojRadnika()
    {
        cout<<"Ukupan broj radnika je "<<radnici.size()<<endl;
        return radnici.size();
    }
    void otpustanje()
    {
        int x;
        cout<<"Unesite poziciju radnika kojeg zelite otpustiti: ";
        cin>>x;
        cout<<" Radnik se otpusta"<<endl;;
        radnici.erase (radnici.begin()+x);
    }
    void pretraga()
    {
        long long unsigned x;
        cout<<"Unesite poziciju radnika kojeg zelite ispisati: ";
        do
        {
            cin>>x;
            if(x>radnici.size() || x<0)
                cout<<"Broj pozicije mora biti manji od "<<radnici.size()<<" i veci od 0"<<endl;
        }while(x>radnici.size() || x<0);
        cout<<"Statistike radnika kojeg ste izabrali je: "<<endl<<*radnici.at(x);
    }
    void pretragaPoStazu(Radnik &r)
    {
        int x;
        cout<<"Unesite godine staza koje zelite naci kod nekog radnika: ";
        cin>>x;
        if(r.getStaz()==x)
        {
            cout<<"Staz pronadjen"<<endl;
            cout<<*radnici.at(x);
        }
        else
            cout<<"Ne postoji radnik sa tim brojem staza"<<endl;
    }

};






#endif // OBEZBEDJENJE_HPP_INCLUDED
