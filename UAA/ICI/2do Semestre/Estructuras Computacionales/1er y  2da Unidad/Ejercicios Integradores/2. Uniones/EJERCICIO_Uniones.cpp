/*===================================================
  EJERCICIO. Uniones.
 --------------------------------------------------
  OBJETIVO:
	Escribir un programa donde supongamos que una
	aplicaci�n puede identificar a los usuarios 
	mediante uno de los siguientes posibles cinco 
	datos:
	� NIF: ocho d�gitos seguidos de una letra. 
	  (Normas de informaci�n financiera)
	� CIF: letra seguida de 8 d�gitos. (C�dula 
	  de identificaci�n fiscal)
	� Pasaporte: ocho letras y/o n�meros.
	� NIE: letra seguida de 7 d�gitos y una 
	  segunda letra. (N�mero de Identidad de 
	  Extranjero)
	� Nombre de usuario: cadena de texto de hasta 
	  16 letras. 
 --------------------------------------------------
  ELABORADORES:
	- Alejandro Castillo Mota
	- Luis Manuel Flores Jim�nez
	- Juan Francisco Gallo Ram�rez
 --------------------------------------------------
	17 de Febrero de 2023
	I.C.I. U.A.A.
====================================================*/
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
using namespace std;

// Se declaran las constantes necesarias.
#define USER 5
// Definimos constantes para el uso de la funci�n 'color()'.
const char C=2, F=16, FF=187;
const int neg=0, azu=1, ver=2, cel=3, roj=4, mor=5, ama=6, gri=7;
const int negc=8, azuc=9, verc=10, celc=11, rojc=12, morc=13, amac=14, gric=15;

//__________________ FUNCI�N DE APOYO PARA COLOR _____
/*----------------------------------------------------
	Funci�n que nos ayuda a modificar los colores 
	del texto en la consola.
  --------------------------------------------------*/
void color(int c_fondo,int c_texto)
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

//________ FUNCI�N DE APOYO PARA VALIDAR N�MEROS _____
/*----------------------------------------------------
	Funci�n que nos ayuda a validar n�meros mediante
	una comparaci�n del rango de caracteres. Retorna 
	error si la cadena no es num�rica.
  --------------------------------------------------*/
bool validacionNum(char *aux)
{
	for(;*aux;++aux)
	if( '0' > *aux || '9' < *aux )
	{
		return 1;
	}
	return 0;
}

//________ FUNCI�N DE APOYO PARA VALIDAR LETRAS ______
/*----------------------------------------------------
	Funci�n que nos ayuda a validar cadenas mediante
	una comparaci�n del rango de caracteres. Retorna 
	error si la cadena es num�rica.
  --------------------------------------------------*/
bool validacionCar(char *aux)
{
	for(;*aux;++aux)
	if( '0' < *aux && '9' > *aux )
	{
		return 1;
	}
	return 0;
}

//_______________________________ UNI�N "userId" _____
union userId
{
	struct NIF
	{
		unsigned int num;
		char ch[2];
	}nif;
	struct CIF
	{
		unsigned int num;
		char ch[2];
	}cif;
	struct PASAPORTE
	{
		char passport[9];
	}pass;
	struct NIE
	{
		char prefix[2];
		unsigned int number;
		char suffix[2];
	}nie;
	struct USERNAME
	{
		char usern[17];
	}username;
	
}user[USER];

//____________________________ FUNCI�N PRINCIPAL _____
main()
{
	// Se llama al,comando para uso de acentos, y se establece la consola con fondo blanco.
	setlocale(LC_ALL,"");system("color F0");
	// Se declaran la variable necesaria.
	string opc;
	char aux[18];
	bool error=false;
	int tipo[USER];
	// Ciclo que no ayuda a "reiniciar" la ejecuci�n.
	do
	{
		// Men� inicial.
		for(int i=0;i<USER;i++)
		{
			do
			{
				system("cls");error=false;
				color(roj,gric);cout<<"                    INFORMACI�N DE USUARIOS                   \n\n";color(gric,neg);
				color(gric,negc);cout<<"\t USUARIO #"<<i+1<<endl<<endl;color(gric,neg);
				color(gric,roj);cout<<"\t  a.";color(gric,neg);cout<<" NIF\n";
				color(gric,roj);cout<<"\t  b.";color(gric,neg);cout<<" CIF.\n";
				color(gric,roj);cout<<"\t  c.";color(gric,neg);cout<<" Pasaporte.\n";
				color(gric,roj);cout<<"\t  d.";color(gric,neg);cout<<" NIE.\n";
				color(gric,roj);cout<<"\t  e.";color(gric,neg);cout<<" Username.\n\n";
				color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa una opci�n: ";
				color(gric,roj);cin>>opc;
				if(opc!="a"&&opc!="b"&&opc!="c"&&opc!="d"&&opc!="e")
				{
					error=true;
					color(gric,roj);cout<<"\n\t# # # OPCION INV�LIDA # # # ";
					getch();
				}
			}while(error==true);
			if(opc=="a")//=============================================================================================
			{	// Se introducen datos, y se asigna el tipo de informaci�n seleccionada.
				tipo[i]=0;
				// Se valida el dato de los 8 d�gitos.
				do
				{
					system("cls");error=false;
					color(roj,gric);cout<<"                    INFORMACI�N DE USUARIOS                   \n\n";color(gric,neg);
					color(gric,negc);cout<<"\t USUARIO #"<<i+1<<endl<<endl;
					color(gric,ver);cout<<"\t NIF"<<endl<<endl;color(gric,neg);
					color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa 8 d�gitos: ";
					fflush(stdin);color(gric,roj);gets(aux);
					// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
					if(validacionNum(aux)==1)
					{
						// Se valida que sea una cadena n�merica.
						color(gric,roj);cout<<"\n\t# # # INGRESA D�GITOS NUM�RICOS # # # ";
						error=true;
						getch();
					}else
					if(strlen(aux)!=8)
					{
						// Se valida que sea de la longitud adecuada.
						color(gric,roj);cout<<"\n\t# # # INGRESA N�MERO DE 8 D�GITOS # # # ";
						error=true;
						getch();
					}else
					{
						// Finalmente, si se ingres� adecuadamente, se convierte a num�rica.
						user[i].nif.num=atoi(aux);
					}
				}while(error==true);
				// Se valida la letra.
				do
				{
					system("cls");error=false;
					color(roj,gric);cout<<"                    INFORMACI�N DE USUARIOS                   \n\n";color(gric,neg);
					color(gric,negc);cout<<"\t USUARIO #"<<i+1<<endl<<endl;
					color(gric,ver);cout<<"\t NIF"<<endl<<endl;color(gric,neg);
					color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa letra: ";
					fflush(stdin);color(gric,roj);gets(aux);
					// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
					if(validacionCar(aux)==1)
					{
						// Se valida que sea una letra.
						color(gric,roj);cout<<"\n\t# # # INGRESA LETRA # # # ";
						error=true;
						getch();
					}else
					if(strlen(aux)!=1)
					{
						// Se valida que sea de la longitud adecuada.
						color(gric,roj);cout<<"\n\t# # # INGRESA S�LO UNA LETRA # # # ";
						error=true;
						getch();
					}else
					{
						// Finalmente, si se ingres� adecuadamente, se asigna a cadena.
						strcpy(user[i].nif.ch,aux);
					}
				}while(error==true);
			}else
			if(opc=="b")//=============================================================================================
			{
				// Se introducen datos, y se asigna el tipo de informaci�n seleccionada.
				tipo[i]=1;
				// Se valida la letra.
				do
				{
					system("cls");error=false;
					color(roj,gric);cout<<"                    INFORMACI�N DE USUARIOS                   \n\n";color(gric,neg);
					color(gric,negc);cout<<"\t USUARIO #"<<i+1<<endl<<endl;
					color(gric,ver);cout<<"\t CIF"<<endl<<endl;color(gric,neg);
					color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa letra: ";
					fflush(stdin);color(gric,roj);gets(aux);
					// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
					if(validacionCar(aux)==1)
					{
						// Se valida que sea una letra.
						color(gric,roj);cout<<"\n\t# # # INGRESA LETRA # # # ";
						error=true;
						getch();
					}else
					if(strlen(aux)!=1)
					{
						// Se valida que sea de la longitud adecuada.
						color(gric,roj);cout<<"\n\t# # # INGRESA S�LO UNA LETRA # # # ";
						error=true;
						getch();
					}else
					{
						// Finalmente, si se ingres� adecuadamente, se asigna a cadena.
						strcpy(user[i].cif.ch,aux);
					}
				}while(error==true);
				// Se valida el dato de los 8 d�gitos.
				do
				{
					system("cls");error=false;
					color(roj,gric);cout<<"                    INFORMACI�N DE USUARIOS                   \n\n";color(gric,neg);
					color(gric,negc);cout<<"\t USUARIO #"<<i+1<<endl<<endl;
					color(gric,ver);cout<<"\t CIF"<<endl<<endl;color(gric,neg);
					color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa 8 d�gitos: ";
					fflush(stdin);color(gric,roj);gets(aux);
					// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
					if(validacionNum(aux)==1)
					{
						// Se valida que sea una cadena n�merica.
						color(gric,roj);cout<<"\n\t# # # INGRESA D�GITOS NUM�RICOS # # # ";
						error=true;
						getch();
					}else
					if(strlen(aux)!=8)
					{
						// Se valida que sea de la longitud adecuada.
						color(gric,roj);cout<<"\n\t# # # INGRESA N�MERO DE 8 D�GITOS # # # ";
						error=true;
						getch();
					}else
					{
						// Finalmente, si se ingres� adecuadamente, se convierte a num�rica.
						user[i].cif.num=atoi(aux);
					}
				}while(error==true);	
			}else
			if(opc=="c")//=============================================================================================
			{	
				// Se introducen datos, y se asigna el tipo de informaci�n seleccionada.
				tipo[i]=2;
				// Se validan los 8 caracteres.
				do
				{
					system("cls");error=false;
					color(roj,gric);cout<<"                    INFORMACI�N DE USUARIOS                   \n\n";color(gric,neg);
					color(gric,negc);cout<<"\t USUARIO #"<<i+1<<endl<<endl;
					color(gric,ver);cout<<"\t PASAPORTE"<<endl<<endl;color(gric,neg);
					color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa d�gitos alfanum�ricos: ";
					fflush(stdin);color(gric,roj);gets(aux);
					// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
					if(strlen(aux)!=8)
					{
						// Se valida que sea de la longitud adecuada.
						color(gric,roj);cout<<"\n\t# # # INGRESA S�LO 8 D�GITOS ALFANUM�RICOS # # # ";
						error=true;
						getch();
					}else
					{
						// Finalmente, si se ingres� adecuadamente, se asigna a cadena.
						strcpy(user[i].pass.passport,aux);
					}
				}while(error==true);
			}else
			if(opc=="d")//=============================================================================================
			{
				// Se introducen datos, y se asigna el tipo de informaci�n seleccionada.
				tipo[i]=3;
				// Se valida prefijo.
				do
				{
					system("cls");error=false;
					color(roj,gric);cout<<"                    INFORMACI�N DE USUARIOS                   \n\n";color(gric,neg);
					color(gric,negc);cout<<"\t USUARIO #"<<i+1<<endl<<endl;
					color(gric,ver);cout<<"\t NIE"<<endl<<endl;color(gric,neg);
					color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa prefijo: ";
					fflush(stdin);color(gric,roj);gets(aux);
					// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
					if(validacionCar(aux)==1)
					{
						// Se valida que sea una letra.
						color(gric,roj);cout<<"\n\t# # # INGRESA LETRA # # # ";
						error=true;
						getch();
					}else
					if(strlen(aux)!=1)
					{
						// Se valida que sea de la longitud adecuada.
						color(gric,roj);cout<<"\n\t# # # INGRESA S�LO UNA LETRA # # # ";
						error=true;
						getch();
					}else
					{
						// Finalmente, si se ingres� adecuadamente, se asigna a cadena.
						strcpy(user[i].nie.prefix,aux);
					}
				}while(error==true);
				// Se valida el dato de los 8 d�gitos.
				do
				{
					system("cls");error=false;
					color(roj,gric);cout<<"                    INFORMACI�N DE USUARIOS                   \n\n";color(gric,neg);
					color(gric,negc);cout<<"\t USUARIO #"<<i+1<<endl<<endl;
					color(gric,ver);cout<<"\t NIE"<<endl<<endl;color(gric,neg);
					color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa 8 d�gitos: ";
					fflush(stdin);color(gric,roj);gets(aux);
					// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
					if(validacionNum(aux)==1)
					{
						// Se valida que sea una cadena n�merica.
						color(gric,roj);cout<<"\n\t# # # INGRESA D�GITOS NUM�RICOS # # # ";
						error=true;
						getch();
					}else
					if(strlen(aux)!=8)
					{
						// Se valida que sea de la longitud adecuada.
						color(gric,roj);cout<<"\n\t# # # INGRESA N�MERO DE 8 D�GITOS # # # ";
						error=true;
						getch();
					}else
					{
						// Finalmente, si se ingres� adecuadamente, se convierte a num�rica.
						user[i].nie.number=atoi(aux);
					}
				}while(error==true);
				// Se valida sufijo.
				do
				{
					system("cls");error=false;
					color(roj,gric);cout<<"                    INFORMACI�N DE USUARIOS                   \n\n";color(gric,neg);
					color(gric,negc);cout<<"\t USUARIO #"<<i+1<<endl<<endl;
					color(gric,ver);cout<<"\t NIE"<<endl<<endl;color(gric,neg);
					color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa sufijo: ";
					fflush(stdin);color(gric,roj);gets(aux);
					// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
					if(validacionCar(aux)==1)
					{
						// Se valida que sea una letra.
						color(gric,roj);cout<<"\n\t# # # INGRESA LETRA # # # ";
						error=true;
						getch();
					}else
					if(strlen(aux)!=1)
					{
						// Se valida que sea de la longitud adecuada.
						color(gric,roj);cout<<"\n\t# # # INGRESA S�LO UNA LETRA # # # ";
						error=true;
						getch();
					}else
					{
						// Finalmente, si se ingres� adecuadamente, se asigna a cadena.
						strcpy(user[i].nie.suffix,aux);
					}
				}while(error==true);
			}else
			if(opc=="e")//=============================================================================================
			{
				// Se introducen datos, y se asigna el tipo de informaci�n seleccionada.
				tipo[i]=4;
				// Se validan los 8 caracteres.
				do
				{
					system("cls");error=false;
					color(roj,gric);cout<<"                    INFORMACI�N DE USUARIOS                   \n\n";color(gric,neg);
					color(gric,negc);cout<<"\t USUARIO #"<<i+1<<endl<<endl;
					color(gric,ver);cout<<"\t USERNAME"<<endl<<endl;color(gric,neg);
					color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa username: ";
					fflush(stdin);color(gric,roj);gets(aux);
					// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
					if(strlen(aux)>16)
					{
						// Se valida que sea de la longitud adecuada.
						color(gric,roj);cout<<"\n\t# # # INGRESA S�LO 16 D�GITOS ALFANUM�RICOS # # # ";
						error=true;
						getch();
					}else
					{
						// Finalmente, si se ingres� adecuadamente, se asigna a cadena.
						strcpy(user[i].username.usern,aux);
					}
				}while(error==true);
			}else
			{
				cout<<"\n\t# # # OPCI�N INV�LIDA # # #";getch();
			}
		}
		//=============================================================================================
		do
		{
			// Mostrando los datos ingresados.
			system("cls");
			color(roj,gric);cout<<"                    INFORMACI�N DE USUARIOS                   \n\n";color(gric,neg);
			color(gric,azu);cout<<"     No. Usuario\tIdentificaci�n\tDato de Indentificaci�n\n\n";
			for(int i=0;i<USER;i++)
			{
				color(gric,roj);cout<<"     Usuario #"<<i+1<<"\t";color(gric,negc);
				switch(tipo[i])
				{
					// Seg�n el valor del tipo es el tipo de dato que se us�.
					case 0:
						cout<<"\tNIF\t\t";color(gric,neg);
						cout<<user[i].nif.num<<user[i].nif.ch<<endl;
						break;
					case 1:
						cout<<"\tCIF\t\t";color(gric,neg);
						cout<<user[i].cif.ch<<user[i].cif.num<<endl;
						break;
					case 2:
						cout<<"\tPasaporte\t";color(gric,neg);
						cout<<user[i].pass.passport<<endl;
						break;
					case 3:
						cout<<"\tNIE\t\t";color(gric,neg);
						cout<<user[i].nie.prefix<<user[i].nie.number<<user[i].nie.suffix<<endl;
						break;
					case 4:
						cout<<"\tUsername\t";color(gric,neg);
						cout<<user[i].username.usern<<endl;
						break;
				}
			}
			cout<<endl<<endl;
			getch();
			// Pedimos ingresar que se desae hacer posteriormente.
			color(gric,roj);cout<<"\t  a.";color(gric,neg);cout<<" Volver a ejecutar.\n";
			color(gric,roj);cout<<"\t  b. <- Salir.\n\n";
			color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa una opci�n: ";
			cin>>opc;
			if(opc=="a")
			{
				
			}else
			if(opc=="b")
			{
				color(gric,ama);cout<<"\n\t  "<<C<<" EJECUCI�N FINALIZADA "<<C<<"  ";
			}else
			{
				cout<<"\n\t# # # OPCI�N INV�LIDA # # #";
			}
		}while(opc!="b"&&opc!="a");
	}while(opc!="b");
	// Fin del programa.	
}
