/*===================================================
   PERMUTACIONES Y COMBINACIONES DE "n" ELEMENTOS
  ------------------------------------------------
    Programa que rdaliza las combinaciones y 
    permutaciones de "n" cantidad de elementos 
    otorgado por el usuario.
  ------------------------------------------------
   Juan Francisco Gallo Ram�rez
   9 de agosto de 2023
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
void permutacion(int n) 
{
    for (int i = 1; i <= n; i++)
	cout << "\nN = " << i <<"\tR = " << i << "\tPermutaciones (" << n << "P" << i<< ")= " << fact(n) / fact(n - i);
}

// Funci�n para obtener las combinaciones.
void combinacion(int n) 
{
    for (int i = 1; i <= n; i++)
    cout << "\nN = " << i <<"\tR = " << i << "\tCombinaciones ("<<n<<"C"<<i<<")= " << fact(n) / (fact(n - i) * fact(i));
}

// Funci�n principal.
int main()
{
    int n;
    cout << "> Ingresa cantidad de elementos: \n";
    cin >> n;
    permutacion(n);
    cout << endl;
    combinacion(n);
    cout << endl;

}
/*===================================================
	APRENDIZAJES:
		He adquirido los aprendizajes de como 
		obtener las permutaciones y combinaciones 
		de "n" elementos por medio de su f�rmula, 
		as� como su implementaci�n en un algoritmo 
		en c++.
===================================================*/

