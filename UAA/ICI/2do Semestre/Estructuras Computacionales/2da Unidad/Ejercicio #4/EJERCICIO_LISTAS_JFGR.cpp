#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
using namespace std;

const char C=2, F=16, FF=187;
const int neg=0, azu=1, ver=2, cel=3, roj=4, mor=5, ama=6, gri=7;
const int negc=8, azuc=9, verc=10, celc=11, rojc=12, morc=13, amac=14, gric=15;

//========================================================== ESTRUCTURA "Nodo" =====
struct Nodo
{
	int dato;
	Nodo *anterior;
	Nodo *siguiente;
};

//================================================ FUNCIÓN DE APOYO PARA COLOR =====
void color(int c_fondo,int c_texto)
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

//================================================= FUNCIÓN PARA MOSTRAR LISTA =====
void mostrar(Nodo *&lista)
{
	Nodo *nodo = lista;
	
	color(gric,negc);cout<<"\n\t";
	color(gric,negc);cout<<"NULL";color(gric,neg);cout<<"->";
	while(nodo != NULL)
	{
		color(gric,negc);cout<<"|";color(gric,roj);cout<<nodo->dato;color(gric,negc);cout<<"|";
		nodo = nodo->siguiente;
		if(nodo==NULL)
		{
			color(gric,neg);cout<<"->";
		}else
		{
			color(gric,neg);cout<<"<->";
		}
	}
	color(gric,negc);cout<<"NULL";
	cout<<endl;
}

//=================================================== FUNCIÓN PARA CREAR LISTA =====
void crearLista(Nodo *&lista, bool &list)
{
	system("cls");
	color(roj,gric);cout<<"                            MENÚ LISTAS ENLAZADAS                            "<<endl<<endl;
	color(gric,neg);cout<<"\t"<<F<<" Crear lista."<<endl<<endl;
	if(!list)
	{
		lista = NULL;
		color(gric,ver);cout<<endl<<"\t+ + + LISTA CREADA + + +"<<endl;
		list=true;
	}else
	{
		color(gric,roj);cout<<endl<<"\t- - - LISTA YA EXISTENTE - - -"<<endl;
	}
	getch();
}

//============================================ FUNCIÓN PARA INSERTAR ELEMENTOS =====
void insertar(Nodo *&lista)
{
	Nodo *nodo = new Nodo;
	Nodo *aux1=lista, *aux2;
	
	system("cls");
	color(roj,gric);cout<<"                            MENÚ LISTAS ENLAZADAS                            "<<endl<<endl;
	color(gric,neg);cout<<"\t"<<F<<" Insertar en lista."<<endl<<endl;
	color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa dato: ";
	color(gric,roj);cin>>nodo->dato;                              
	
	while(aux1 != NULL && aux1->dato < nodo->dato)
	{
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	if(lista==aux1)
	{
		lista=nodo;
		nodo->anterior = NULL;
	}else
	{
		nodo->anterior = aux2;
		aux2->siguiente = nodo;
	}
	if(aux1!=NULL)
	{
		aux1->anterior = nodo;
	}
	nodo->siguiente = aux1;
	
	mostrar(lista);
	color(gric,ver);cout<<endl<<"\t(+) Número "<<nodo->dato<<" agregado correctamente a la lista..."<<endl<<endl;
	
	getch();
}

//======================================= FUNCIÓN PARA ELIMINAR ELEMENTOS LISTA =====
void eliminar(Nodo *&lista)
{
	Nodo *aux1=lista, *aux2 = aux1;
	int n;
	bool encontrado=false;
	
	system("cls");
	color(roj,gric);cout<<"                            MENÚ LISTAS ENLAZADAS                            "<<endl<<endl;
	color(gric,neg);cout<<"\t"<<F<<" Eliminar en lista."<<endl<<endl;
	color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa dato a eliminar: ";
	color(gric,roj);cin>>n;
	
	while(aux1 != NULL && !encontrado)
	{
		if(aux1->dato==n)
		{
			encontrado=true;
		}else
		{
			aux2 = aux1;
			aux1 = aux1->siguiente;	
		}
	}
	
	if(encontrado)
	{
		if(lista->dato==n)
		{
			lista = lista->siguiente;
		}
		if(aux1->siguiente!=NULL)
		{
			aux1->siguiente->anterior = aux2;
		}
		aux2->siguiente = aux1->siguiente;
		delete aux1;
		mostrar(lista);
		color(gric,roj);cout<<endl<<"\t(-) Número "<<n<<" eliminado correctamente de la lista..."<<endl<<endl;
	}else
	{
		mostrar(lista);
		color(gric,roj);cout<<endl<<"\t# # # NÚMERO "<<n<<" NO ENCONTRADO # # #"<<endl<<endl;
	}
	
	getch();
}

//=============================================== FUNCIÓN PARA ELIMINAR LISTA =====
void eliminarLista(Nodo *&lista)
{
	Nodo *aux=lista;
	
	system("cls");
	color(roj,gric);cout<<"                            MENÚ LISTAS ENLAZADAS                            "<<endl<<endl;
	color(gric,neg);cout<<"\t"<<F<<" Eliminar lista."<<endl<<endl;
	
	if(lista!=NULL)
	{
		color(gric,roj);cout<<endl<<"\t- - - ELEMENTOS DE LA LISTA ELIMINADOS - - -"<<endl<<endl;
		while(lista != NULL)
		{
			aux=lista->siguiente;
			delete lista;
			lista = aux;
		}
	}else
	{
		color(gric,roj);cout<<endl<<"\t# # # NO HAY ELEMENTOS QUE ELIMINAR # # #"<<endl<<endl;
	}
	
	getch();
}

//======================================== FUNCIÓN PARA BUSCAR ELEMENTOS LISTA =====
void buscar(Nodo *&lista)
{
	Nodo *aux1=lista;
	int n;
	bool encontrado=false;
	
	system("cls");
	color(roj,gric);cout<<"                            MENÚ LISTAS ENLAZADAS                            "<<endl<<endl;
	color(gric,neg);cout<<"\t"<<F<<" Buscar en lista."<<endl<<endl;
	color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa dato a buscar: ";
	color(gric,roj);cin>>n;
	
	while(aux1 != NULL && !encontrado)
	{
		if(aux1->dato==n)
		{
			encontrado=true;
		}else
		{
			aux1 = aux1->siguiente;	
		}
	}
	mostrar(lista);
	if(encontrado)
	{
		color(gric,ver);cout<<endl<<"\t> Número "<<n<<" encontrado en la lista..."<<endl<<endl;
	}else
	{
		color(gric,roj);cout<<endl<<"\t> Número "<<n<<" no encontrado en la lista..."<<endl<<endl;
	}
	
	getch();
}

//========================================= FUNCIÓN PARA BUSCAR RECORRER LISTA =====
void recorrer(Nodo *&lista)
{
	system("cls");
	color(roj,gric);cout<<"                            MENÚ LISTAS ENLAZADAS                            "<<endl<<endl;
	color(gric,neg);cout<<"\t"<<F<<" Recorrer lista."<<endl<<endl;
	mostrar(lista);
	
	getch();
}

//============================================== FUNCIÓN PARA VERIFICAR LISTA =====
void verificar(Nodo *&lista)
{
	system("cls");
	color(roj,gric);cout<<"                            MENÚ LISTAS ENLAZADAS                            "<<endl<<endl;
	color(gric,neg);cout<<"\t"<<F<<" Verificar lista."<<endl<<endl;
	
	if(lista!=NULL)
	{
		color(gric,ver);cout<<endl<<"\t>>> LISTA CON ELEMENTOS <<<"<<endl<<endl;
	}else
	{
		color(gric,roj);cout<<endl<<"\t>>> LISTA VACÍA <<<"<<endl<<endl;
	}
	
	getch();
}

//====================================== FUNCIÓN PARA ELEMENTOS MENORES A "n" =====
void elementosMenores(Nodo *&lista)
{
	Nodo *aux=lista;
	int n, c=0;
	
	system("cls");
	color(roj,gric);cout<<"                            MENÚ LISTAS ENLAZADAS                            "<<endl<<endl;
	color(gric,neg);cout<<"\t"<<F<<" Elementos menores a \"n\"."<<endl<<endl;
	color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa valor de \"n\": ";
	color(gric,roj);cin>>n;
	
	color(gric,negc);cout<<"\n\t";
	while(aux!=NULL)
	{
		if(aux->dato < n)
		{
			color(gric,negc);cout<<"|";color(gric,roj);cout<<aux->dato;color(gric,negc);cout<<"|";color(gric,neg);cout<<"->";
			c++;
		}
		aux = aux->siguiente;
	}
	if(c>0)
	{
		color(gric,ver);cout<<endl<<endl<<"\t> Se muestran elementos menores a "<<n<<"..."<<endl<<endl;
	}else
	{
		color(gric,roj);cout<<endl<<"\t# # # NO HAY ELEMENTOS MENORES A "<<n<<" # # #"<<endl<<endl;
	}
	cout<<endl;
	getch();
}

//========================================================= FUNCIÓN PRINCIPAL =====
main()
{
	Nodo *lista;
	bool list=false;
	int opc;
		
	setlocale(LC_ALL, "");system("color F0");
	do
	{
		system("cls");
		color(roj,gric);cout<<"                            MENÚ LISTAS ENLAZADAS                            "<<endl<<endl;
		color(gric,roj);cout<<"\t  1) ";color(gric,neg);cout<<"Crear lista."<<endl;
		color(gric,roj);cout<<"\t  2) ";color(gric,neg);cout<<"Insertar elemento."<<endl;
		color(gric,roj);cout<<"\t  3) ";color(gric,neg);cout<<"Eliminar elemento."<<endl;
		color(gric,roj);cout<<"\t  4) ";color(gric,neg);cout<<"Eliminar toda la lista."<<endl;
		color(gric,roj);cout<<"\t  5) ";color(gric,neg);cout<<"Buscar elemento."<<endl;
		color(gric,roj);cout<<"\t  6) ";color(gric,neg);cout<<"Recorrer lista."<<endl;
		color(gric,roj);cout<<"\t  7) ";color(gric,neg);cout<<"Verificación de lista."<<endl;
		color(gric,roj);cout<<"\t  8) ";color(gric,neg);cout<<"Elementos menores a \"n\"."<<endl;
		color(gric,roj);cout<<"\t  9) <- Salir."<<endl<<endl;
		color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa una opción: ";
		color(gric,roj);cin>>opc;
		switch(opc)
		{
			case 1:
				crearLista(lista, list);
				break;
			case 2:
				if(list)
				{
					insertar(lista);
				}else
				{
					color(gric,roj);cout<<"\n\t# # # LISTA NO CREADA # # #"<<endl;
					getch();
				}
				break;
			case 3:
				if(list)
				{
					eliminar(lista);
				}else
				{
					color(gric,roj);cout<<"\n\t# # # LISTA NO CREADA # # #"<<endl;
					getch();
				}
				break;
			case 4:
				if(list)
				{
					eliminarLista(lista);
				}else
				{
					color(gric,roj);cout<<"\n\t# # # LISTA NO CREADA # # #"<<endl;
					getch();
				}
				break;
			case 5:
				if(list)
				{
					buscar(lista);
				}else
				{
					color(gric,roj);cout<<"\n\t# # # LISTA NO CREADA # # #"<<endl;
					getch();
				}
				break;
			case 6:
				if(list)
				{
					recorrer(lista);
				}else
				{
					color(gric,roj);cout<<"\n\t# # # LISTA NO CREADA # # #"<<endl;
					getch();
				}
				break;
			case 7:
				if(list)
				{
					verificar(lista);
				}else
				{
					color(gric,roj);cout<<"\n\t# # # LISTA NO CREADA # # #"<<endl;
					getch();
				}
				break;
			case 8:
				if(list)
				{
					elementosMenores(lista);
				}else
				{
					color(gric,roj);cout<<"\n\t# # # LISTA NO CREADA # # #"<<endl;
					getch();
				}
				break;
			case 9:
				color(gric,ama);cout<<"\n\t  "<<C<<" EJECUCIÓN FINALIZADA "<<C<<"  ";getch();
				break;
			default:
				cout<<"\n\t# # # OPCIÓN INVÁLIDA # # #";getch();
				break;
				
		}
	}while(opc!=9);
	color(gric,gric);
}
