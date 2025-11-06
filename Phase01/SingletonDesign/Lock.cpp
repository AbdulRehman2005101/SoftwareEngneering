#include<iostream>
using namespace std;
#include<mutex>

class DatabaseConnection{
private:
    static DatabaseConnection* instance;
    static mutex mtx;
    DatabaseConnection(){
        cout<<"Created once\n";
    }
public:
    static DatabaseConnection* getInstance(){
        if(instance ==nullptr){
            lock_guard<mutex>lock(mtx);   //put inside to avoid unusual lock
            if(instance==nullptr){        //if two threads enter then no need to reinitialize for the second one
                instance=new DatabaseConnection();
                return instance;
            }
        }
        cout<<"Already made instance\n";
        return instance;
    }
    void query(){
        cout<<"processed\n";
    }
};
DatabaseConnection* DatabaseConnection::instance=nullptr;
mutex DatabaseConnection::mtx;  //initialized mutex for all the classes

int main(){
    DatabaseConnection*d1=DatabaseConnection::getInstance();
    DatabaseConnection*d2=DatabaseConnection::getInstance();

    d1->query();
    d2->query();

}