/*==================================================
  EJERCICIO #1. Uniones.
 ------------------------------------------------
 OBJETIVO:
 Capturar datos de veh�culos y dependiendo del
 tipo de veh�ulo, capturar ciertos datos 
 espec�ficos utilizando uniones.
 ------------------------------------------------
 Juan Francisco Gallo Ram�rez
 16/Febrero/2023
 I.C.I. 
==================================================*/
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
using namespace std;

const char F=16, FF=187;
const int CV = 6;

//___________________________ FUNCI�N DE COLOR _____
void color(int c_fondo,int c_texto)
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}
//________________________________ UNION "info" _____
union info
{
	float cap_carga;
	int num_per;
};
//_______________________________ STRUCT "lote" _____
struct lote
{
	int serie;
	int modelo;
	char tipo[15];
	info adicional;
}vehiculo[CV];
//___________________________ FUNCI�N PRINCIPAL _____
main()
{
	int i, error;
	system("color F0");
	setlocale(LC_ALL, "");
	
	for(i=0;i<CV;i++)
	{
		system("cls");
		color(6,15);cout<<"                     LOTE DE VEH�CULOS                     \n\n";
		color(15,6);cout<<" "<<F<<" Veh�culo #"<<i+1<<" "<<endl;
		color(15,8);cout<<"\n\t"<<FF<<" Ingresa serie del veh�culo: ";
		color(15,0);cin>>vehiculo[i].serie;
		system("cls");
		color(6,15);cout<<"                     LOTE DE VEH�CULOS                     \n\n";
		color(15,6);cout<<" "<<F<<" Veh�culo #"<<i+1<<" "<<endl;
		color(15,8);cout<<"\n\t"<<FF<<" Ingresa modelo del veh�culo: ";
		color(15,0);cin>>vehiculo[i].modelo;
		do
		{
			system("cls");error=0;
			color(6,15);cout<<"                     LOTE DE VEH�CULOS                     \n\n";
			color(15,6);cout<<" "<<F<<" Veh�culo #"<<i+1<<" "<<endl;
			color(15,8);cout<<"\n\t"<<FF<<" Ingresa tipo de veh�culo: ";
			color(15,0);fflush(stdin);gets(vehiculo[i].tipo);
			strupr(vehiculo[i].tipo);
			if(strcmp(vehiculo[i].tipo, "AUTO")==0)
			{
				system("cls");
				color(6,15);cout<<"                     LOTE DE VEH�CULOS                     \n\n";
				color(15,6);;cout<<" "<<F<<" Veh�culo #"<<i+1<<" "<<endl;
				color(15,8);cout<<"\n\t"<<FF<<" Ingresa n�mero de personas que transporta: ";
				color(15,0);cin>>vehiculo[i].adicional.num_per;
			}else if(strcmp(vehiculo[i].tipo, "CAMION")==0 || strcmp(vehiculo[i].tipo, "CAMI�N")==0)
			{
				system("cls");
				color(6,15);cout<<"                     LOTE DE VEH�CULOS                     \n\n";
				color(15,6);cout<<" "<<F<<" Veh�culo #"<<i+1<<" "<<endl;
				color(15,8);cout<<"\n\t"<<FF<<" Ingresa capacidad de carga: ";
				color(15,0);cin>>vehiculo[i].adicional.cap_carga;
			}else
			{
				error=1;
				color(4,15);cout<<"\n\t # # # OPCI�N INV�LIDA # # # ";
				color(15,2);cout<<"\n\t (Ingresa 'Auto' � 'Cami�n') ";
				getch();
			}
		}while(error==1);
	}
	system("cls");
	color(6,15);cout<<"                     LOTE DE VEH�CULOS                     \n\n";
	color(15,6);cout<<"-----------------------------------------------------------\n";
	for(i=0;i<CV;i++)
	{
		color(15,0);cout<<" "<<F<<" Veh�culo #"<<i+1<<" "<<endl;
		color(15,4);cout<<"\n\t Serie: \t";color(15,0);cout<<vehiculo[i].serie;
		color(15,4);cout<<"\n\t Modelo: \t";color(15,0);cout<<vehiculo[i].modelo;
		color(15,4);cout<<"\n\t Tipo:\t\t";color(15,2);cout<<vehiculo[i].tipo;
		if(strcmp(vehiculo[i].tipo, "AUTO")==0)
		{
			color(15,4);cout<<"\n\t No. pasajeros:\t";color(15,0);cout<<vehiculo[i].adicional.num_per;
		}else if(strcmp(vehiculo[i].tipo, "CAMION")==0 || strcmp(vehiculo[i].tipo, "CAMI�N")==0)
		{
			color(15,4);cout<<"\n\t Cap. carga:\t";color(15,0);cout<<vehiculo[i].adicional.cap_carga;
		}
		color(15,6);cout<<"\n-----------------------------------------------------------\n";
	}

}
