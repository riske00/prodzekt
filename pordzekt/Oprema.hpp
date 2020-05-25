#ifndef OPREMA_HPP_INCLUDED
#define OPREMA_HPP_INCLUDED
enum tip {kompjuter=1,Kamera,Stampac};
class Oprema{

protected:
    tip t1;
    bool garancija;

public:
    Oprema(tip t,bool g)
    {
        t1=t;
        garancija= g;
    }





};


#endif // OPREMA_HPP_INCLUDED
