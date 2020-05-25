#ifndef CVRADNIKA_HPP_INCLUDED
#define CVRADNIKA_HPP_INCLUDED

class cvRadnika{

protected:
    bool staz;
    string opis;
public:
    cvRadnika(bool Staz,string Opis){
        staz=Staz;
        opis=Opis;
    }
    void Staz()
    {
        if(staz)
        {
            opis="Radio negde pre";
            cout<<opis<<endl;
        }
        else
            opis="Prvo radno iskustvo";
            cout<<opis<<endl;
    }
    void setStaz(bool s){staz=s;}
    void setOpis(string o){opis=o;}
    bool getStaz(){return staz;}
    string getOpis(){return opis;}



};

#endif // CVRADNIKA_HPP_INCLUDED
