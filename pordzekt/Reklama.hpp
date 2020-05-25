#ifndef REKLAMA_HPP_INCLUDED
#define REKLAMA_HPP_INCLUDED


class Reklama{

protected:
    string mesto;
    int velicina;
    bool osvetljenje;

public:
    Reklama(string m,int v,bool o)
{
    mesto=m;
    velicina=v;
    osvetljenje=o;
}

};

#endif // REKLAMA_HPP_INCLUDED
