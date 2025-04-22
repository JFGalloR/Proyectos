/*===================================================
   PERMUTACIONES Y COMBINACIONES DE "n" ELEMENTOS
  ------------------------------------------------
    Programa que rdaliza las combinaciones y 
    permutaciones de "n" cantidad de elementos 
    otorgado por el usuario.
  ------------------------------------------------
   Juan Francisco Gallo Ram�rez
   10 de agosto de 2023
===================================================*/
#include <iostream>
using namespace std;

// Funci�n para obtener el factorial.
int fact(int r) 
{
    if (r == 0) return 1;
    else return r*fact(r-1);
}

// Funci�n para obtener las permutaciones.
int permutacion(int n, int r) 
{
    return fact(n) / fact(n - r);
}

// Funci�n para obtener las combinaciones.
int combinacion(int n, int r) 
{
    return fact(n) / (fact(n - r) * fact(r));
}

// Funci�n principal.
int main()
{
    int n;
    cout << "\t\t\tPERMUTACIONES Y COMBINACIONES" << endl;
    cout << "\t\t=============================================" << endl << endl;
    cout << " > Ingresa cantidad de elementos: ";
    cin >> n;
    cout << endl << "\t\t Valor 'r' | Permutaciones | Combinaciones" << endl; 
	cout <<         "\t\t-------------------------------------------" << endl;
	
    for(int i=0; i<n ; i++)
    {
    	cout << "\t\t     " << i << "\t\t  " << permutacion(n, i) << "\t\t  " << combinacion(n, i) << endl;
	}

}
/*===================================================
	APRENDIZAJES:
		He adquirido los aprendizajes de como 
		obtener las permutaciones y combinaciones 
		de "n" elementos por medio de su f�rmula, 
		as� como su implementaci�n en un algoritmo 
		en c++.
  ===================================================
	NIVEL DE ENTENDIMIENTO:
		Los temas han quedado claro, y han sido muy 
		bien entendido, desde la teor�a de 
		permutaciones y combinaciones, as� como la 
		implementaci�n en c�digo.
===================================================*/

