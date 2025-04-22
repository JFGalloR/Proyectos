/*==================================================
 EJERCICIO. Corredores.
 ------------------------------------------------
 OBJETIVO:
    Modificar el ejercicio de los corredores con 
	los siguientes supuestos.  
    Capturar la estructura para 6 corredores.
    Obtener las siguientes estadisticas:
        Numero de corredores mujeres
        Numero de corredores hombres
        Numero de clubes que participan
        Numero de corredores por club
        Numero de participantes por categoria
        Al final imprimir los datos de todos los 
		corredores
 ------------------------------------------------
 Juan Francisco Gallo Ramírez
 8/Febrero/2023
 I.C.I. 
==================================================*/
#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

void color(int c_fondo,int c_texto)//FUNCIÓN DE APOYO PARA COLOR
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

struct time
{
	float timestamp[3];
	float average;
};

struct runner {
    char name[30];
    char clubName[30];
    char category[12];
    char gender;
    int age;
    time _time;
}_runner[6];


int main()
{
    int veteran = 0, adult = 0, youth = 0;
    int womenRunners = 0, menRunners = 0;
    int members = 0;
    int totalClub = 0;
    int count=0;
    system("color F0");
    for (int i = 0; i < 1; i++)
    {
        system("cls");
        cout<<"---------------------------------------\n";
        color(0,15);cout<< "         Runner #" << i + 1<<"                     "<<endl;color(15,0);
        cout<<"---------------------------------------\n";
        cout << "\n\t> Name: ";
        cin >> _runner[i].name;
        cout << "\n\t> Club: ";
        cin >> _runner[i].clubName;
        cout << "\n\t> Gender (M or F): ";
        cin >> _runner[i].gender;
        cout << "\n\t> Age: ";
        cin >> _runner[i].age;
        cout << "\n\t> = TIMES = = = \n";
        for(int j=0;j<3;j++)
        {
        	cout << "\n\t- Time #" << j+1 << ": ";
        	cin >> _runner[i]._time.timestamp[j];
        	_runner[i]._time.average+=_runner[i]._time.timestamp[j];
		}
		_runner[i]._time.average/=3;
        if (_runner[i].gender == 'M' || _runner[i].gender == 'm')
        {
            menRunners++;
        }
        else if(_runner[i].gender == 'H' || _runner[i].gender == 'h')
		{
            womenRunners++;
        }
        if (_runner[i].age > 40)
        {
            strcpy(_runner[i].category, "Veterano");
            veteran++;
        }
        if (_runner[i].age >= 19 && _runner[i].age <= 40)
        {
            strcpy(_runner[i].category, "Adulto");
            adult++;
        }
        if (_runner[i].age < 19)
        {
            strcpy(_runner[i].category, "Juvenil");
            youth++;
        }
    }
    system("cls");
    color(0,15);cout<<"============== STATISTICS ==============\n\n";color(15,0);
    color(15,1);cout << "\n- Men Runners\t";color(15,0);cout<< menRunners;
    color(15,1);cout << "\n- Women Runners\t";color(15,0);cout<< womenRunners;
	color(15,4);cout << "\n\n CLUB\t\tMEMBERS\n";color(15,0);
    cout<<"---------------------------------\n";
    for (int i = 0; i < 6; i++)
    {
        totalClub = 0;
        members = 0;
        for (int j = i; j >= 0; j--)
        {
            if (strcmp(_runner[i].clubName, _runner[j].clubName) == 0)
            {
                totalClub++;
            }
        }
        if (totalClub == 1)
        {
            for (int k = 0; k < 6; k++)
            {
                if (strcmp(_runner[i].clubName, _runner[k].clubName) == 0)
                {
                    members++;
                }
            }
            color(15,1);cout << endl <<" "<<_runner[i].clubName << "\t\t";color(15,0);cout<< members;
            count++;
        }
    }
    cout << "\n\n- Total Clubs\t" << count;
    color(15,4);cout << "\n\n MEMBERS BY CATEGORY\n";color(15,0);
    cout<<"---------------------------------\n";
    color(15,1);cout << "\n- Veteran\t";color(15,0);cout<< veteran;
    color(15,1);cout << "\n- Adult\t\t";color(15,0);cout<< adult;
    color(15,1);cout << "\n- Youth\t\t";color(15,0);cout<< youth;
    for (int i = 0; i < 6; i++)
    {
    	cout<<"\n\n---------------------------------------\n";
        color(0,15);cout<< "         Runner #" << i + 1<<"                     ";color(15,0);cout<<endl;
        cout<<"---------------------------------------\n";
        color(15,1);cout << "\n\tName: \t\t";color(15,0);cout<< _runner[i].name;
        color(15,1);cout << "\n\tAge: \t\t";color(15,0);cout << _runner[i].age;
        color(15,1);cout << "\n\tGender: \t";color(15,0);cout << _runner[i].gender;
        color(15,1);cout << "\n\tCategory: \t";color(15,0);cout << _runner[i].category;
        color(15,1);cout << "\n\tClub Name: \t";color(15,0);cout << _runner[i].clubName;
        color(15,4);cout << "\n\n\t- TIMES - - - \t";color(15,0);
        for(int j=0;j<3;j++)
        {
        	color(15,6);cout << "\n\t > Time #1 \t";color(15,0);cout << _runner[i]._time.timestamp[j];
		}
		color(15,2);cout << "\n\t > Average: \t";color(15,0);cout << _runner[i]._time.average;
    }
        
    cout << endl << endl;
    return 0;
}

