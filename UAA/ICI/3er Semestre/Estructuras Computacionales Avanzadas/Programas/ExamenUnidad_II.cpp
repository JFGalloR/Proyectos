/*==============================================================================
	EXÁMEN UNIDAD II
  ----------------------------------------------------------------------------
	Implementación del ejercicio propuesto en el exámen de una unidad II, el 
	cual consiste en modelar un problema de grafos según ofertas de alquilar
	un departamento, donde se buisca maximizar las ganancias en los días 
	propuestos.
  ----------------------------------------------------------------------------
	Juan Francisco Gallo Ramírez
	I.C.I 3er Semestre
==============================================================================*/
#include <iostream>
#include <vector>
#include <queue>
#include <windows.h>

using namespace std;

const char FF = 175;

const int NEG = 0, AZU = 1, VER = 2, CEL=3, ROJ = 4, MOR = 5, AMA = 6, GRI = 7;
const int NEGC = 8, AZUC = 9, VERC = 10, CELC = 11, ROJC = 12, MORC = 13, AMAC = 14, GRIC = 15;
// Constante que indica los días de verano, debido a que son 4 meses, serían aproximadamente 120 días.
const int DIAS = 121;


/*============================ FUNCIÓN PARA MANIPULAR EL COLOR DE LOS CARACTERES =======
	Función para dar diseño, meramente estética, sin funcionalidad en el problema 
	propuesto.
--------------------------------------------------------------------------------------*/
void color(int c_fondo,int c_texto)
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

/*============================ FUNCIÓN PARA VERIFICAR SI HAY CICLOS EN EL GRAFO ========
	### ESTA FUNCIÓN NO ESTABA EN MI ALGORITMO DE EXÁMEN ### pero es de utilidad para 
	obtener una expansión con el peso máximo.
--------------------------------------------------------------------------------------*/
bool verificarCiclos(vector<pair<int, int> > pares, int a, int b)
{
	// Recorremos los elementos de la lista para verificar el camino de cada nodo.
	for (int i = 0; i < pares.size(); i++)
    {
    	// Verifica que el segundo elemento de la lista es igual al seleccionado.
        if (pares[i].second == b)
        {
        	// Verifica que el primer elemento de la lista es igual al de inicio
            if (pares[i].first == a)
            {
            	// Si es así hay un ciclo.
                return true;
            }
        }
    }
    // Si no no hay un ciclo hasta el momento.
    return false;
}

/*=============== FUNCIÓN PARA VERIFICAR SI YA SE ENCUENTRA UN PAR EN EL CAMINO ========
	### ESTA FUNCIÓN NO ESTABA EN MI ALGORITMO DE EXÁMEN ### pero es de utilidad para 
	saber si un par ya esta en la lista. Se agregó toda esta función al algoritmo.
--------------------------------------------------------------------------------------*/
int verificarEnc(vector<pair<int, int> > pares, pair<int, int> par)
{
	for(int k=0; k<pares.size(); k++)
	{
		if(par == pares[k])
		{
			return true;
		}
	}
	return false;
}

/*=========== FUNCIÓN PARA VERIFICAR SI YA SE ENCUENTRA OCUPADO EL DEPARTAMENTO ========
	### ESTA FUNCIÓN NO ESTABA EN MI ALGORITMO DE EXÁMEN ### pero es de utilidad para 
	saber si un par ya esta en la lista. Se agregó toda esta función al algoritmo.
--------------------------------------------------------------------------------------*/
int verificarOc(vector<pair<int, int> > pares, int a, int b)
{
	for(int k=0; k<pares.size(); k++)
	{
		// Se pregunta si el elemento esta en el intervalo ocupado.
		if(a > pares[k].first && a < pares[k].second || b > pares[k].first && b < pares[k].second ||
		pares[k].first > a && pares[k].first < b || pares[k].second > a && pares[k].second < b)
		{
			return true;
		}
	}
	return false;
}

/*=============== FUNCIÓN PARA VERIFICAR SI YA SE ENCUENTRA UN PAR EN EL CAMINO ========
	### ESTA FUNCIÓN SÍ ESTABA EN MI ALGORITMO DE EXÁMEN ### pero se complementó.
--------------------------------------------------------------------------------------*/
void caminoGananciasMax(vector<vector<pair<int, float> > > &lis, int n) 
{
    priority_queue<float> cola;
    vector<pair<int, int> > camino;
    vector<float> monto;
    float acum = 0;
    
    // Se imprimen  todas las ofertas.
    system("cls");
	color(ROJ, GRIC); cout<< "                             RENTA DE DEPARTAMENTO                             " << endl << endl;
	color(GRIC, ROJ); cout << "    " << FF << " OFERTAS INICIALES " << endl << endl;
    color(AZU, GRIC); cout<< "\t  D. Ini   \t  D. Fin   \t  Monto  " << endl;
    
    // Esta parte fue agregada.
    for(int i=0; i<DIAS; i++)
    {
    	for(int j=0; j<lis[i].size(); j++)
	    {
	    	pair<int, float> elemento = lis[i][j];
	    	// Se pregunta si hay elemento en el día propuesto.
	    	if(elemento.first != 0)
	    	{
	    		// Si es así se agrega a la cola de prioridad.
	    		color(GRIC, NEG); cout<< "\t  " << i << "\t\t  " << elemento.first << "\t\t  $" << elemento.second << endl;
	    		cola.push(elemento.second);
			}
		}
	}
	
	// Esta parte se modificó y complemento.
	while(!cola.empty())
	{
		// Esta parte fue agregada
		for(int i=0; i<DIAS; i++)
	    {
	    	for(int j=0; j<lis[i].size(); j++)
		    {
		    	pair<int, float> elemento = lis[i][j];
		    	// Se busca la referencia de los días preguntando si el monto es igual al de la lista.
		    	// Se valora que no se haya agregado ya una oferta con los mismos días.
		    	if(elemento.second == cola.top() && !verificarEnc(camino, elemento))
		    	{
		    		// Si es así se valora que no generen ciclos, debido al algoritmo de Kruskal.
		    		if(!verificarCiclos(camino, i, elemento.first) && !verificarOc(camino, i, elemento.first))
		    		{
		    			// Se agrega a nuestra lista de caminos.
		    			camino.push_back(make_pair(i, elemento.first));
		    			monto.push_back(elemento.second);
					}
				}
			}
		}
		cola.pop();
	}
	
	// Se imprimen los valores de las ofertas seleccionadas.
	color(GRIC, ROJ); cout << endl << "    " << FF << " OFERTAS PARA MAXIMIZAR GANANCIAS " << endl << endl;
    color(VER, GRIC); cout<< "\t  D. Ini   \t  D. Fin   \t  Monto  " << endl;
    
	for(int i=0; i<camino.size(); i++)
	{
		color(GRIC, NEG); cout<< "\t  " << camino[i].first << "\t\t  " << camino[i].second << "\t\t  $" << monto[i] << endl;
		acum += monto[i];
	}
	color(GRIC, VER); cout << endl << "\tGANANCIAS TOTALES: "; color(GRIC, NEG); cout<< " $" << acum << endl;
}

/*=========================================================== FUNCIÓN PRINCIPAL ========
	### ESTA FUNCIÓN SÍ ESTABA EN MI ALGORITMO DE EXÁMEN ### pero se complementó.
--------------------------------------------------------------------------------------*/
int main() 
{
    int c_ofertas = 0;
    
    vector<vector<pair<int, float> > > l_ady(DIAS);

	system("color F0");
	color(ROJ, GRIC); cout<< "                             RENTA DE DEPARTAMENTO                             " << endl << endl;
    color(GRIC, ROJ); cout << "    " << FF; color(GRIC, NEG); cout << " Ingresa la cantidad de ofertas: ";
    color(GRIC, ROJ); cin >> c_ofertas;
    color(GRIC, NEG); cout << endl;
	
	// Limpiamos toda la lista.
    for (int i = 0; i < DIAS; i++) 
	{
        l_ady[i].clear();
    }

	// Se llena la lista de adyacencias.
    for (int i = 0; i < c_ofertas; i++) {
        int d_i, d_f;
        float m;

        cout << "  === OFERTA #" << (i + 1) << " ======================================================" << endl;
        color(GRIC, ROJ); cout << "     " << FF << " Ingresa el dia inicial (1 - 120) de la oferta: ";
        color(GRIC, NEG); cin >> d_i;

        color(GRIC, ROJ); cout << "     " << FF << " Ingresa el dia final (1 - 120) de la oferta: ";
        color(GRIC, NEG); cin >> d_f;

        color(GRIC, ROJ); cout << "     " << FF << " Ingresa el monto de la oferta #" << (i + 1) << ": ";
        color(GRIC, NEG); cin >> m;

        l_ady[d_i].push_back(make_pair(d_f, m));
    }
    
    // Se llama a la función para realizar el proceso.
    caminoGananciasMax(l_ady, c_ofertas);
}

