#include<iostream>
using namespace std;


class DataBaseConnection{
private:
    static DataBaseConnection* instance;  //we are going to make it nullptr first and remmeber to make to static as in static variable can be used inside static function of class
    DataBaseConnection(){
        cout<<"DB Instance Created\n";      //we made it private so no one can access the constructor
    }
public:
    static DataBaseConnection* getInstance(){
        if(instance==nullptr){
            instance = new DataBaseConnection();
            return instance;
        }
        cout<<"Using already made connection\n";
        return instance;        //if not null return the same instance
    }
    void query(){
        cout<<"processed\n";
    }
};

DataBaseConnection* DataBaseConnection:: instance =nullptr; //private static memers are allowed to accessed once outside the class

int main(){
  DataBaseConnection* db=DataBaseConnection::getInstance();
  DataBaseConnection* db1=DataBaseConnection::getInstance();
  
  db->query();
  db1->query();
}