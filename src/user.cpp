#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class User {
private:
    string Email, Name, Cpf;
public:
    string getEmail(){return Email;}
    string getName(){return Name;}
    string getCpf(){return Cpf;}

    User(string email, string name, string cpf)
        : Email(email), Name(name), Cpf(cpf){
    }
};
