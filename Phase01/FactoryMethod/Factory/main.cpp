#include<iostream>
using namespace std;


class Burger{
public:
    virtual void buy()=0;
};

class Standard: public Burger{
public:
    void buy()override{
        cout<<"Stardard one\n";
    }
};

class Premium: public Burger{
public:
    void buy()override{
        cout<<"Premium one";
    }
};

class WheatStandard: public Burger{
public:
    void buy()override{
        cout<<"Wheat Stardard one\n";
    }
};

class WheatPremium: public Burger{
public:
    void buy()override{
        cout<<"Wheat Premium one";
    }
};

class Factory{
public:
    virtual Burger* getburger(string burger)=0;
};

class KingBurger: public Factory{
public:
    Burger* getburger(string burger)override{
        if(burger== "standard"){
            return new Standard();
        }
        if(burger=="premium"){
            return new Premium();
        }
        return nullptr;
    }
};

class SinghBurger: public Factory{
public:
    Burger* getburger(string burger)override{
        if(burger== "standardwheat"){
            return new WheatStandard();
        }
        if(burger=="premiumwheat"){
            return new WheatPremium();
        }
        return nullptr;
    }
};


int main(){
    string burger="premiumwheat";
    Factory* F=new SinghBurger();
    Burger*B = F->getburger(burger);
    B->buy();
    return 0;
}