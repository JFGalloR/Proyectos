/*
Carrera: ICI                Fecha: 02/02/2023

Alumnos:
    Luis Pablo Esparza Terrones
    Juan Francisco Gallo Ramirez
    Luis Manuel Flores Jimenez

Objetivo:
    Realice un programa en C++, en donde se construya una solución para la jerarquía de clases (Herencia)
    de las clases Persona,  Empleado, Estudiante.

*/
#include <iostream>

using namespace std;

class Person
{
private:
    string name;
    int age;
public:
    Person(string, int);
    void showPerson();
};

class Student : public Person
{
private:
    int id;
    string carrer;
public:
    Student(string, int, int, string);
    void showStudent();

};

class Employee : public Person
{
private:
    string company;
    string department;
public:
    Employee(string, int, string, string);
    void showEmployee();
};

Person::Person(string _name, int _age)
{
    name = _name;
    age = _age;
}   

Student::Student(string _name, int _age, int _id, string _carrer): Person (_name,_age)
{
    id = _id;
    carrer = _carrer;
}

Employee::Employee(string _name, int _age, string _company, string _department) : Person(_name, _age)
{
    company = _company;
    department = _department;
}

void Person::showPerson() 
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}

void Student::showStudent()
{
    showPerson();
    cout << "ID: " << id << endl;
    cout << "Carrer: " << carrer << endl;
}

void Employee::showEmployee()
{
    showPerson();
    cout << "Company: " << company << endl;
    cout << "Department: " << department << endl;
}

int main()
{
    Student student_1("Gallo", 18, 1288, "ICI");
    student_1.showStudent();
    cout << endl;
    Employee employee_1("Rosalinda", 40, "UAA", "CIENCIAS BASICAS");
    employee_1.showEmployee();
    
}

