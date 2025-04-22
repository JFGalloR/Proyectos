/*===================================================
 EJERCICIO #3. Estructuras Anidadas.
 --------------------------------------------------
 OBJETIVO:
  Realizar un programa que capture para 5 clientes 
  y 5 empleados  la siguiente estructura y obtener
   -El cliente con el mayor saldo.
   -El empleado con el menor salario.
 --------------------------------------------------
 Juan Francisco Gallo Ramírez
 9/Febrero/2023
 I.C.I. 
===================================================*/
#include <iostream>
#include <windows.h>

using namespace std;

void color(int c_fondo,int c_texto)
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

struct address {
    string _adress;
    string city;
    string province;
    int postalCode;
};

struct employee {
    string nameEmployee;
    address $address;
    float salary;
}_employee[5];

struct customer {
    string nameCustomer;
    address $address;
    float balance;
}_customer[5];

int main()
{
    float max=0, min;
    int aux=0, aux1=0;
    system("color F0");
    
	for (int i = 0; i < 5; i++)
    {
    	color(4,15);cout << "                EMPLOYEE DATA                \n";
        color(0,15);cout << "\n  Employee #" << i + 1 <<"  ";color(15,0);
        cout << "------------------------------\n";
        color(15,4);cout << "\n   > Name: ";
        color(15,0);cin >> _employee[i].nameEmployee;
        color(15,4);cout << "   > Adress: ";
        color(15,0);cin >> _employee[i].$address._adress;
        color(15,4);cout << "   > City: ";
        color(15,0);cin >> _employee[i].$address.city;
        color(15,4);cout << "   > Province: ";
        color(15,0);cin >> _employee[i].$address.province;
        color(15,4);cout << "   > Postal Code:";
        color(15,0);cin >> _employee[i].$address.postalCode;
        color(15,4);cout << "   > Salary: ";
        color(15,0);cin >> _employee[i].salary;
        system("cls");
    }
	for (int i = 0; i < 5; i++)
    {
    	color(1,15);cout << "                CUSTOMER DATA                \n";
    	color(0,15);cout << "\n  Customer #" << i + 1 <<"  ";color(15,0);
        cout << "------------------------------\n";
        color(15,1);cout << "\n   > Name: ";
        color(15,0);cin >> _customer[i].nameCustomer;
        color(15,1);cout << "   > Adress: ";
        color(15,0);cin >> _customer[i].$address._adress;
        color(15,1);cout << "   > City: ";
        color(15,0);cin >> _customer[i].$address.city;
        color(15,1);cout << "   > Province: ";
        color(15,0);cin >> _customer[i].$address.province;
        color(15,1);cout << "   > Postal Code:";
        color(15,0);cin >> _customer[i].$address.postalCode;
        color(15,1);cout << "   > Balance: ";
        color(15,0);cin >> _customer[i].balance;
        system("cls");
    }
    
    min = _employee[0].salary;
    for (int i = 0; i < 5; i++)
    {
        if (_employee[i].salary < min)
        {
            min = _employee[i].salary;
            aux1 = i;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (_customer[i].balance > max)
        {
            max = _customer[i].balance;
            aux = i;
        }
    }
	
	color(4,15);cout << "    LOWER EMPLOYEE SALARY    ";
    color(15,4);cout << "\n\n   > Name: ";
    color(15,0);cout << _employee[aux1].nameEmployee<<endl;
    color(15,4);cout << "   > Adress: ";
    color(15,0);cout << _employee[aux1].$address._adress<<endl;
    color(15,4);cout << "   > City: ";
    color(15,0);cout << _employee[aux1].$address.city<<endl;
    color(15,4);cout << "   > Province: ";
    color(15,0);cout << _employee[aux1].$address.province<<endl;
    color(15,4);cout << "   > Postal Code:";
    color(15,0);cout << _employee[aux1].$address.postalCode<<endl;
    color(15,4);cout << "   > Salary: ";
    color(15,0);cout << _employee[aux1].salary<<endl<<endl;
    
    color(1,15);cout << "   HIGHER CUSTOMER BALANCE   ";
    color(15,1);cout << "\n\n   > Name: ";
    color(15,0);cout << _customer[aux].nameCustomer<<endl;
    color(15,1);cout << "   > Adress: ";
    color(15,0);cout << _customer[aux].$address._adress<<endl;
    color(15,1);cout << "   > City: ";
    color(15,0);cout << _customer[aux].$address.city<<endl;
    color(15,1);cout << "   > Province: ";
    color(15,0);cout << _customer[aux].$address.province<<endl;
    color(15,1);cout << "   > Postal Code:";
    color(15,0);cout << _customer[aux].$address.postalCode<<endl;
    color(15,1);cout << "   > Salary: ";
    color(15,0);cout << _customer[aux].balance<<endl;

    system("pause");
    return 0;
}

