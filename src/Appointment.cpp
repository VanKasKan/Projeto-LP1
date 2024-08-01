#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreorder"

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Appointment {
private:
    string Email, Name, Cpf, AppointmentType, Date;
    int Age, Time;
    double Income;
public:
    string getID(){return Email;}
    string getName(){return Name;}
    string getCpf(){return Cpf;}
    string getConsulta(){return AppointmentType;}
    string getData(){return Date;}
    int getHorario(){return Time;}
    int getAge(){return Age;}
    double getIncome(){return Income;}

    Appointment(string email, string name, string cpf, int age, string appointmentType, double income, string date, int time)
        :Email(email), Name(name), Cpf(cpf), Age(age), AppointmentType(appointmentType), Income(income), Date(date), Time(time){
    }
};

#pragma GCC diagnostic pop