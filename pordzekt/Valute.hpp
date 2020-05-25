#ifndef VALUTE_HPP_INCLUDED
#define VALUTE_HPP_INCLUDED

class Valute {

protected:
    string ime;
    int vrednost;
    double kupovna;
    double prodajna;
public:
    static double kursEvra;
    Valute(string i, int v,double k,double p)
    {
        ime=i;
        vrednost=v;
        kupovna=k;
        prodajna=p;
        kursEvra=10;
    }
    ~Valute()
    {
        kursEvra=0;
    }
    friend ostream& operator<<(ostream& izlaz, const Valute &v);
    double getProdajna(){return prodajna;}
    double getKupovna(){return kupovna;}
    string getIme(){return ime;}
    void setVrednost(int v){vrednost=v;}
};

#endif // VALUTE_HPP_INCLUDED
