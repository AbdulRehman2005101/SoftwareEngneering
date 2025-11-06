#include<iostream>
using namespace std;

class DBConnection{
private:
    DBConnection(){
        cout<<"Constructor Runs\n";
    }
public:
    DBConnection(const DBConnection&)=delete;
    DBConnection operator=(const DBConnection&)=delete;    //avoid coping as well
    static DBConnection& getInstance(){
        static DBConnection instance;    //only make a single instance and share that again and again
        return instance;
    }
    void query(){
        cout<<"Query Ran\n";
    }
};


int main(){
    DBConnection& d1=DBConnection::getInstance();
    DBConnection& d2=DBConnection::getInstance();

    d1.query();
    d2.query();
}