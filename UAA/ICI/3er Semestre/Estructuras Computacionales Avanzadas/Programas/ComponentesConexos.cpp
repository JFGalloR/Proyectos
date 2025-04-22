/*====================================================================================
  == COPONENTES DE GRAFO CONEXO ====================================================
  ----------------------------------------------------------------------------------
    	> Juan Francisco Gallo Ramírez I.C.I.
====================================================================================*/
#include <iostream>
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

//------------------------------------- FUNCIÓN PARA AGREGAR ELEMENTOS AL LA MATRIZ ---//
void agregar(int **matriz, int n, string *aux)
{
	color(GRIC, AZU); cout<<"\t------------------------------------------------------" << endl;
	for(int i=0; i<n; i++)
	{
		color(GRIC, AZU); cout<<"\t   "<<FF<<" Ingresa el nodo " << i+1 << " (nombre): ";
		cin >> aux[i];
	}
	
	color(GRIC, AZU); cout<<"\t------------------------------------------------------" << endl;
	
	for(int i=0; i<n; i++)
	{
		string nodo;
		do
		{
			color(GRIC, NEG); cout<<"\t     "<<FF<<" El nodo " << aux[i] << " conecta con ('-' para terminar): ";
			color(GRIC, AZU); cin >> nodo;
			if(nodo != "-")
			{
				for(int j=0; j<n; j++)
				{
					if(nodo == aux[j])
						matriz[i][j] = 1;
				}
			}
		}while(nodo != "-");
		color(GRIC, AZU); cout<<"\t------------------------------------------------------" << endl;
	}
}

//--------------------------------------- FUNCIÓN PARA OBTENER LA MATRIZ DE CAMINOS ---//
void matrizCaminos(int **matriz, int n)
{
	bool cambio = true;
	for(int i=0; i<n; i++)
	{
		cambio = true;
		while(cambio)
		{
			cambio = false;
			for (int j = 0; j < n; j++)
			{
				if(matriz[i][j] == 1 && i!=j)
					for(int l=0; l<n; l++)
						if(matriz[j][l] == 1 && matriz[i][l]!=1)
						{
							cambio = true;
							matriz[i][l] = 1;
						}	
			}
		}
	}
}

//------------------------------------- FUNCIÓN PARA COPIAR ELEMENTOS DE FILA A OTRA ---//
void copiarF(int *destino, int *origen, int n)
{
    for (int i = 0; i < n; i++)
    {
        destino[i] = origen[i];
    }
}

//------------------------------------- FUNCIÓN PARA ORDENAR FILAS, Y ACOMODARLAS SEGUN EL ALGORITMO ---//
void ordenarMatriz(int **matriz, int n, string *aux)
{
	int matrizA[n][n];
    int auxN;
    int cont[n] = {};
    int auxE[n] = {};
    string cambio[n];
    string auxStr;
	
    for (int i = 0; i < n; i++)
	{
	    cambio[i] = aux[i];
	    for (int j = 0; j < n; j++)
	    {
	    	matrizA[i][j] = matriz[i][j];
	        cont[i] += matriz[i][j];
	    }
	}
	
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (cont[i] < cont[j])
            {
                auxN = cont[i];
                cont[i] = cont[j];
                cont[j] = auxN;
                copiarF(auxE, matrizA[i], n);
                copiarF(matrizA[i], matrizA[j], n);
                copiarF(matrizA[j], auxE, n);
                auxStr = cambio[i];
                cambio[i] = cambio[j];
                cambio[j] = auxStr;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(cambio[i] == aux[j])
            {
            	for(int k=0; k<n; k++)
            	{
            		matriz[k][i] = matrizA[k][j];
				}
            	break;
			}
        }
    }
    
    for(int i=0; i<n; i++)
    {
    	aux[i] = cambio[i];
	}
}

//------------------------------------- FUNCIÓN IMPRIMIR COMPONENTES CONEXOS ---//
void obtenerConexos(int **matriz, int n, string *aux)
{
	bool nuevo = true;
	bool coma = false;
	system("cls");
	color(AZU, GRIC); cout<<"                          COMPONENETES CONEXAS DE UN GRAFO                          " << endl << endl;
	color(GRIC, AZU); cout<<"\t === COMPONENTES CONEXOS ==================" << endl << endl;
	color(GRIC, NEG);
	
	for(int i=0; i<n; i++)
	{
		if(nuevo)
		{
			cout << "\t\t{ ";
		}
		if(i<n-1)
		{
			if(matriz[i+1][i] == 1)
			{
				if(coma)
					cout << ",";
				cout << aux[i];
				coma = true;
				nuevo = false;
			}else
			{
				if(coma)
					cout << ",";
				cout << aux[i] << " }"<< endl;
				coma = false;
				nuevo = true;
			}
		}
		else
		{
			if(coma)
					cout << ",";
				cout << aux[i] << " }"<< endl;
				coma = false;
				nuevo = true;
		}
			
	}
}

//------------------------------------- FUNCIÓN PRINCIPAL ---//
int main()
{
	int cant_nod;
	int** matriz;
	
	setlocale(LC_ALL, "");system("color F0");
	color(AZU, GRIC); cout<<"                          COMPONENETES CONEXAS DE UN GRAFO                          " << endl << endl;
	color(GRIC, AZU); cout << "\t" << FF; color(GRIC, NEG); cout << " Ingresa la cantidad de nodos del grafo: ";
	color(GRIC, AZU); cin >> cant_nod; cout << endl;
    
    matriz = new int*[cant_nod];
    string aux[cant_nod];
    
    for (int i = 0; i < cant_nod; i++) 
	{
        matriz[i] = new int[cant_nod];
        for (int j = 0; j < cant_nod; j++)
        {
        	if(i==j)
        	matriz[i][j] = 1;
        	else
        	matriz[i][j] = 0;
		}
    }
    
    //6 E B D C F A B C F - - A B C - F - E - D E - 
	agregar(matriz, cant_nod, aux);
	matrizCaminos(matriz, cant_nod);
	ordenarMatriz(matriz, cant_nod, aux);
	obtenerConexos(matriz, cant_nod, aux);
	
	return 0;
}
