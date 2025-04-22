#include <iostream>
#include <cmath>
using namespace std;
std::string decimalBinario(int num, int n) {
    // Implementa la conversión decimal a binario aquí y devuelve la cadena binaria
    int res;
	string aux = "";
	string bin = "";
	
	while (num!=0)
	{
		aux += (num % 2 == 0)? "0" : "1";
		num /= 2;
	}
	
	for(int i=n; i>=0; i--)
		bin += (i>aux.length())? '0' : aux[i];
		
	return bin;
}

int main() {
    int n = 4; // Cambia n al valor que necesites
    std::string elementos = "ABCD"; // Cambia esto a tus elementos
    std::string aux;

    for (int i = 0; i < pow(2, n); i++) {
        aux = decimalBinario(i, n);
        std::cout << "\t\t" << i << "\t" << aux << "\t   { ";

        for (int j = 0; j < n; j++) {
            if (aux[j] == '1') {
                std::cout << elementos[j];
                if (j < n - 1) {
                    std::cout << ",";
                }
            }
        }

        std::cout << " }" << std::endl;
    }

    return 0;
}
