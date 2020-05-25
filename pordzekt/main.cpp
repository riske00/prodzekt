#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <windows.h>
using namespace std;
#include "cvRadnika.hpp"
#include "Direktor.hpp"
#include "Kasa.hpp"
#include "Lokal.hpp"
#include "Menjacnica.hpp"
#include "Obezbedjenje.hpp"
#include "Oprema.hpp"
#include "Radnik.hpp"
#include "Reklama.hpp"
#include "Valute.hpp"

ostream& operator<<(ostream& izlaz, const Radnik &r){

    izlaz<<"Radnik - ispis"<<endl;
    izlaz<<"IME RADNIKA: "<<r.naziv<<endl;
    izlaz<<"PREZIME RADNIKA: "<<r.prezime<<endl;
    izlaz<<"BROJ GODINA: "<<r.brojGodina<<endl;
    izlaz<<"RADNI STAZ: "<<r.radniStaz<<endl;
    izlaz<<"PLATA: "<<r.plata<<endl<<endl;

return izlaz;
}
ostream& operator<<(ostream& izlaz, const Direktor &d){

    izlaz<<"Direktor - ispis"<<endl;
    izlaz<<"IME DIREKTORA: "<<d.naziv<<endl;
    izlaz<<"PREZIME DIREKTORA: "<<d.prezime<<endl;
    izlaz<<"BROJ GODINA: "<<d.brojGodina<<endl;
    izlaz<<"RADNI STAZ: "<<d.radniStaz<<endl;
    izlaz<<"POL: "<<d.pol<<endl;
    izlaz<<"PLATA: "<<d.plata<<endl<<endl;

return izlaz;
}
ostream& operator<<(ostream& izlaz, const Lokal &l){

    izlaz<<"Lokal - ispis"<<endl;
    izlaz<<"ULICA : "<<l.ulica<<endl;
    izlaz<<"BROJ : "<<l.broj<<endl;
    izlaz<<"GRAD: "<<l.grad<<endl;
    izlaz<<"KVART: "<<l.kvadratura<<endl<<endl;

return izlaz;
}
ostream& operator<<(ostream& izlaz, const Valute &v){
    izlaz<<"NAZIV : "<<v.ime<<endl;
    izlaz<<"KUPOVNA : "<<v.kupovna<<endl;
    izlaz<<"PRODAJNA : "<<v.prodajna<<endl<<endl;

return izlaz;
}

void citaj(string nazivFajla)
{
    string linija;
    ifstream fajl (nazivFajla);
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            cout << linija << '\n';
        }
        fajl.close();
    }
    else
        cout << "Neuspesno otvoren fajl";

}
vector<string> splitSen(string str)
{
   string w = "";
   vector<string> v;
   for (auto rem : str)
   {
       if (rem==',')
       {
           v.push_back(w);
           w="";
       }
       else
       {
           w=w+rem;
       }
   }
   v.push_back(w);

   return v;
}
vector<Lokal> citajTxt(string nazivFajla)
{
    string linija;
    ifstream fajl (nazivFajla);
    vector<Lokal> lokali;
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            vector<string> rez;
            rez = splitSen(linija);
            Lokal l(rez[0], stoi(rez[1]), rez[2], stoi(rez[3]));
            lokali.push_back(l);
        }

        fajl.close();
        return lokali;

    }

    else
        cout << "Neuspesno otvoren fajl";

}
int ispis1(vector<Lokal> lokali)
{
    int a, a1=1;
    cout<<"Izaberite u kom lokalu zelite da izvrsite transakciju: "<<endl;
    for(auto it=lokali.begin(); it!=lokali.end(); it++)
    {
        cout<<"Broj "<<a1<<" za :"<<endl;
        cout<<*it<<endl;
        a1++;
    }
    cout<<"Ili ako ne zelite da izvrsite nikakvu transakciju, taster 0 za izlaz"<<endl;
    do
    {
        cin>>a;
        if(a!=3 &&a!=1 && a!=2 && a!=0)
            cout<<"Ne postoji taj lokal"<<endl;
            cout<<"Izabrali ste lokal u ulici "<<lokali.at(a-1).getUlica()<<endl;
    }while(a!=3 &&a!=1 && a!=2 && a!=0);

    return a;
}
void ispis2(vector<Valute> valute)
{
    int a=1;
    cout<<"Koju valutu imate? \n\n"<<endl;
    for(auto it=valute.begin(); it!=valute.end(); it++)
    {
        cout<<"Unesite broj "<<a<<" ako imate valutu "<<valute.at(a-1).getIme()<<endl;
        a++;
    }
}
int unosValute(int v)
{
    do{
    cin>>v;
    if(v!=1 && v!=2 && v!=3)
        cout<<"Unesite nesto od ponudjenog!"<<endl;
    switch(v)
    {
    case 1:
        cout<<"Imate valutu evro"<<endl;
        break;
    case 2:
        cout<<"Imate valutu dolar"<<endl;
        break;
    case 3:
        cout<<"Imate valutu funta"<<endl;
        break;
    }
    }while(v!=1 && v!=2 && v!=3);
    return v;
}
void dodavanjeValuteUFajl(string nazivFajla, Valute &v, char mode='w')
{
    ofstream fajl;
    if (mode=='a')
        fajl.open (nazivFajla, ios_base::app);
    else
        fajl.open (nazivFajla);
    fajl <<v<< endl;
    fajl.close();
}
int unosVrednosti(int v, vector<Valute> valute, int valuta)
{
    cout<<"Unesite kolicinu vase valute: ";
    cin>>v;
    valute.at(valuta-1).setVrednost(v);
    dodavanjeValuteUFajl("Rezultat.txt", valute.at(valuta-1));
    return v;

}
int provera(vector<Valute> valute, int v, int vrednost)
{
    int a;
    cout<<"Da li ste sigurni da zelite da vase pare pretvorimo u dinare?"<<endl;
    cout<<"Kupovna cena je "<<valute.at(v-1).getProdajna()<<endl;
    cout<<"Dobicete "<<(valute.at(v-1).getProdajna())*vrednost<<" dinara"<<endl;
    cout<<"Ako jeste, taster 1, ako niste, taster 0"<<endl;
    cin>>a;
    return a;
}
void spavanje()
{
    cout<<"Konverutjemo vam novac!"<<endl;
    cout<<"Sacekajte"<<endl;
    Sleep(3000);
}
int konverzija(vector<Valute> valute, int vrednost, int v)
{
    int x=(valute.at(v-1).getProdajna())*vrednost;
    cout<<"Na racunu vam je "<<x<<" dinara!"<<endl;
    cout<<"Prijatan dan!"<<endl;
    return x;
}
double Valute::kursEvra=0;
int main()
{
    int a, valuta, vrednost, pr, racun;
    //rokovi
    /*Radnik r1("Strahinja", "ris", 17, 5000, 0, false, "Nesto");
    Radnik r2("Stefan", "Kovanusic", 16, 4000, 1, true, "Nesto");
    Direktor d(true,"Strahinja", "ris", 17, 5000, 0, false, "Nesto");
    Lokal l("Ulica", 10, "Novi Sad", 5);
    Valute v(100, 115.4, 117.3);
    Obezbedjenje ob("Strahinja", "ris", 17, 5000, 0, false, "Nesto", 5);
    cout<<r1<<endl<<endl<<d<<endl<<endl<<l<<endl;
    citaj("Lokal.txt");
    Radnik* pom;
    pom=&ob;
    pom->staz();
    ob.dodajUObezbedjenje(r1);
    ob.dodajUObezbedjenje(r2);
    ob.brojRadnika();
    ob.otpustanje();
    ob.brojRadnika();
    ob.ispisObezbedjenja();
    ob.pretragaPoStazu(r1);*/
    //rokovi
    vector<Lokal> lokali=citajTxt("Lokal.txt");
    vector<Valute> valute;
    Valute v1("evro", 0, 117.4, 118.0);
    Valute v2("dolar", 0, 107.3, 107.7);
    Valute v3("funta", 0, 131.4, 131.7);
    valute.push_back(v1);
    valute.push_back(v2);
    valute.push_back(v3);
    a=ispis1(lokali);
    ispis2(valute);
    valuta=unosValute(valuta);
    vrednost=unosVrednosti(vrednost, valute, valuta);
    pr=provera(valute, valuta, vrednost);
    spavanje();
    racun=konverzija(valute, vrednost, valuta);

    //Predlog funkcionalnosti je da korisnik unese broj novca koji zeli konvertovati, unese valutu iz koje konvertuje i u koju zeli da bude konvertovano. Moze odustati nakon sto mu se prikaze kurs, a ako nastavi, pare mu se konvertuju
    return 0;
}
