/*====================================================================================
  == RECORRIDO DE GRAFO EN ANCHURA =================================================
  ----------------------------------------------------------------------------------
    	> Juan Francisco Gallo Ramírez I.C.I.
====================================================================================*/
#include <iostream>
#include <vector>
#include <queue>
#include <windows.h>
#include <locale.h>

using namespace std;

const char C = 2, FF = 187;

const int NEG = 0, AZU = 1, VER = 2, CEL=3, ROJ = 4, MOR = 5, AMA = 6, GRI = 7;
const int NEGC = 8, AZUC = 9, VERC = 10, CELC = 11, ROJC = 12, MORC = 13, AMAC = 14, GRIC = 15;

//---------------------------- FUNCIÓN PARA MANIPULAR EL COLOR DE LOS CARACTÉRES ---//
void color(int c_fondo,int c_texto)
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

//------------------------------------- FUNCIÓN PARA AGREGAR ELEMENTOS AL VECTOR ---//
void agregar(vector<vector<string> >&vec, int x)
{
	string nodo;
	
	color(GRIC, AZU); cout<<"\t------------------------------------------------------" << endl;
	color(GRIC, AZU); cout<<"\t   "<<FF<<" Ingresa el nodo " << x+1 << " (nombre): ";
	cin >> nodo;
	vec[x].push_back(nodo);
	do
	{
		color(GRIC, NEG); cout<<"\t     "<<FF<<" El nodo " << vec[x][0] << " conecta con ('-' para terminar): ";
		color(GRIC, AZU); cin >> nodo;
		if(nodo != "-")
		{
			vec[x].push_back(nodo);
		}
	}while(nodo != "-");
	
}

//-------------------------------------- FUNCIÓN IMPRIMIR LA LISTA DE ADYACENCIA ---//
void imprimirLista(vector<vector<string> >& vec) 
{
	system("cls");
	color(AZU, GRIC); cout<<"                          RECORRIDO DE GRAFO EN ANCHURA                          " << endl << endl;
	color(GRIC, AZU); cout<<"\t === LISTA DE ADYACENCIA ==================" << endl << endl;
    for (int i = 0; i < vec.size(); i++) 
	{
        color(GRIC, NEG); cout << "\t   Nodo " << vec[i][0] << ": ";
        for (int j = 1; j < vec[i].size(); j++) 
		{
            color(GRIC, AZU); cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

//----------------------- FUNCIÓN PARA DEVOLVER EL INDICE DE UN ELEMENTO BUSCADO ---//
int buscarNodo2(vector<vector<string> > vector, string nodo)
{
	for (int i = 0; i < vector.size(); i++) 
	{
        if(vector[i][0] == nodo)
        {
        	return i;
		}
    }
    return -1;
}

//----------------------- FUNCIÓN PARA DEVOLVER EL INDICE DE UN ELEMENTO BUSCADO ---//
int buscarNodo1(vector<string> vector, string nodo)
{
	for (int i = 0; i < vector.size(); i++) 
	{
        if(vector[i] == nodo)
        {
        	return i;
		}
    }
    return -1;
}

//---------------------------- FUNCIÓN PARA DOBTENER LA ANCHURA DE UN GRAFO DADO ---//
void obtenerAnchura(vector<vector<string> >& vec, queue<string> &cola, vector<string> &anchura)
{
	string nodo;
	int i_nodo;
	
	color(GRIC, AZU);cout<< endl << "\t -------------------------------------------" << endl << endl;
	color(GRIC, AZU); cout << "\t   " << FF; color(GRIC, NEG); cout << " Ingresa el nodo de partida (nombre): ";
	color(GRIC, AZU); cin >> nodo;
	i_nodo = buscarNodo2(vec, nodo);
	
	anchura.push_back(vec[i_nodo][0]);
	cola.push(vec[i_nodo][0]);
	
	while(!cola.empty())
	{
		cola.pop();
		i_nodo = buscarNodo2(vec, nodo);
		for(int i=1; i<vec[i_nodo].size(); i++)
		{
			if(buscarNodo1(anchura, vec[i_nodo][i]) == -1)
			{
				cola.push(vec[i_nodo][i]);
				anchura.push_back(vec[i_nodo][i]);
			}
		}
		if(!cola.empty())
			nodo = cola.front();
	}
	
	color(GRIC, AZU);cout << endl <<"\t === RECORRIDO EN ANCHURA =================" << endl << endl;
	for (int i = 0; i < anchura.size(); i++) 
	{
        color(GRIC, NEG); cout << "\t\t" << anchura[i] << endl; 
    }
}

//------------------------------------------------------------ FUNCIÓN PRINCIPAL ---//
int main()
{
	int cant_nod;
	queue<string> cola;
	vector<string> anchura;
	
	setlocale(LC_ALL, "");system("color F0");
	color(AZU, GRIC); cout<<"                          RECORRIDO DE GRAFO EN ANCHURA                          " << endl << endl;
	color(GRIC, AZU); cout << "\t" << FF; color(GRIC, NEG); cout << " Ingresa la cantidad de nodos del grafo: ";
	color(GRIC, AZU); cin >> cant_nod; cout << endl;
	
	//7 A - B H - C R - D B C - H A D T - R H - T -
	vector <vector<string> > vec(cant_nod);

	for(int i=0; i<cant_nod;i++)
	{
		agregar(vec, i);
		cout<<endl;
	}

	imprimirLista(vec);
	obtenerAnchura(vec, cola, anchura);
	
	return 0;
}
