/*==================================================
  EJERCICIO #1. Uniones.
 ------------------------------------------------
 OBJETIVO:
 Capturar datos de vehículos y dependiendo del
 tipo de vehíulo, capturar ciertos datos 
 específicos utilizando uniones.
 ------------------------------------------------
 Juan Francisco Gallo Ramírez
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

//___________________________ FUNCIÓN DE COLOR _____
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
//___________________________ FUNCIÓN PRINCIPAL _____
main()
{
	int i, error;
	system("color F0");
	setlocale(LC_ALL, "");
	
	for(i=0;i<CV;i++)
	{
		system("cls");
		color(6,15);cout<<"                     LOTE DE VEHÍCULOS                     \n\n";
		color(15,6);cout<<" "<<F<<" Vehículo #"<<i+1<<" "<<endl;
		color(15,8);cout<<"\n\t"<<FF<<" Ingresa serie del vehículo: ";
		color(15,0);cin>>vehiculo[i].serie;
		system("cls");
		color(6,15);cout<<"                     LOTE DE VEHÍCULOS                     \n\n";
		color(15,6);cout<<" "<<F<<" Vehículo #"<<i+1<<" "<<endl;
		color(15,8);cout<<"\n\t"<<FF<<" Ingresa modelo del vehículo: ";
		color(15,0);cin>>vehiculo[i].modelo;
		do
		{
			system("cls");error=0;
			color(6,15);cout<<"                     LOTE DE VEHÍCULOS                     \n\n";
			color(15,6);cout<<" "<<F<<" Vehículo #"<<i+1<<" "<<endl;
			color(15,8);cout<<"\n\t"<<FF<<" Ingresa tipo de vehículo: ";
			color(15,0);fflush(stdin);gets(vehiculo[i].tipo);
			strupr(vehiculo[i].tipo);
			if(strcmp(vehiculo[i].tipo, "AUTO")==0)
			{
				system("cls");
				color(6,15);cout<<"                     LOTE DE VEHÍCULOS                     \n\n";
				color(15,6);;cout<<" "<<F<<" Vehículo #"<<i+1<<" "<<endl;
				color(15,8);cout<<"\n\t"<<FF<<" Ingresa número de personas que transporta: ";
				color(15,0);cin>>vehiculo[i].adicional.num_per;
			}else if(strcmp(vehiculo[i].tipo, "CAMION")==0 || strcmp(vehiculo[i].tipo, "CAMIÓN")==0)
			{
				system("cls");
				color(6,15);cout<<"                     LOTE DE VEHÍCULOS                     \n\n";
				color(15,6);cout<<" "<<F<<" Vehículo #"<<i+1<<" "<<endl;
				color(15,8);cout<<"\n\t"<<FF<<" Ingresa capacidad de carga: ";
				color(15,0);cin>>vehiculo[i].adicional.cap_carga;
			}else
			{
				error=1;
				color(4,15);cout<<"\n\t # # # OPCIÓN INVÁLIDA # # # ";
				color(15,2);cout<<"\n\t (Ingresa 'Auto' ó 'Camión') ";
				getch();
			}
		}while(error==1);
	}
	system("cls");
	color(6,15);cout<<"                     LOTE DE VEHÍCULOS                     \n\n";
	color(15,6);cout<<"-----------------------------------------------------------\n";
	for(i=0;i<CV;i++)
	{
		color(15,0);cout<<" "<<F<<" Vehículo #"<<i+1<<" "<<endl;
		color(15,4);cout<<"\n\t Serie: \t";color(15,0);cout<<vehiculo[i].serie;
		color(15,4);cout<<"\n\t Modelo: \t";color(15,0);cout<<vehiculo[i].modelo;
		color(15,4);cout<<"\n\t Tipo:\t\t";color(15,2);cout<<vehiculo[i].tipo;
		if(strcmp(vehiculo[i].tipo, "AUTO")==0)
		{
			color(15,4);cout<<"\n\t No. pasajeros:\t";color(15,0);cout<<vehiculo[i].adicional.num_per;
		}else if(strcmp(vehiculo[i].tipo, "CAMION")==0 || strcmp(vehiculo[i].tipo, "CAMIÓN")==0)
		{
			color(15,4);cout<<"\n\t Cap. carga:\t";color(15,0);cout<<vehiculo[i].adicional.cap_carga;
		}
		color(15,6);cout<<"\n-----------------------------------------------------------\n";
	}

}
