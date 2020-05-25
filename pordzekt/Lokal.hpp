#ifndef LOKAL_HPP_INCLUDED
#define LOKAL_HPP_INCLUDED

class Lokal{

protected:
    string ulica;
    int broj;
    string grad;
    int kvadratura;

public:
    Lokal(string a,int br,string gr,int k)
    {
        ulica =a;
        broj= br;
        grad = gr;
        kvadratura= k;
    }
    friend ostream& operator<<(ostream& izlaz, const Lokal &l);
    string getUlica(){return ulica;}
};




#endif // LOKAL_HPP_INCLUDE
