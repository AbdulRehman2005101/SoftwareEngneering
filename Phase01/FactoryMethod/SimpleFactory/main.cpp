#include<iostream>
using namespace std;

class Payment{
public:
    virtual void pay()=0;
};

class CardPayment: public Payment{
public:
    void pay() override{
        cout<<"Payment with card\n";
    }
};

class CryptoPayment: public Payment{
public:
    void pay() override{
        cout<<"Crypto Paid\n";
    }
};

class Factory{
public:
    Payment* createPayment(string method){
        if(method=="card"){
            return new CardPayment();
        }
        if(method == "crypto"){
            return new CryptoPayment();
        }
        return nullptr;
    }
};


int main(){
    string payment="crypto";
    Factory* getpayment=new Factory();

    Payment*P = getpayment->createPayment(payment);
    P->pay();
}