/*=====================================================================
 INTRODUCIR PASSWORD 
=======================================================================
 OBJETIVO: Leer la contrase�a de un usuario y marcar si es correcta
 o no, de no serlo continuar preguntando hasta que se ingrese 
 correctamente.
=======================================================================
 ENTRADAS: Usuario, contrase�a establecida y contrase�a a ingresar.
=======================================================================
 SALIDAS: Mensaje de error o de entrada correta.
=======================================================================
 TABLA DE CONSTANTES Y VARIABLES:
 ---------------------------------------------------------------------
 = Descripci�n = Identificador = Tipo = Variable = Constante = Valor =
 ---------------------------------------------------------------------
   Password        PASSWORD      Entero     -          x       12345
  establecida
    Usuario          user        Cadena     x          -         -
   Password a      password      Entero     x          -         -
   ingresar
 ---------------------------------------------------------------------
=======================================================================
 HERRAMIENTA DE PROGRAMACI�N (Pseudoc�digo):
 -------------------------------------------
 INICIO.
	Var: 
		Enteras: password
		Cadena: user
	Const:
		Enteras: PASSWORD
	Escribir ("Ingresa usuario: ")
	Leer (user)
	Repetir
		Escribir ("Usuario: ", user)
		Escribir ("Ingresa contrase�a")
		Leer (password)
		Si password != PASSWORD entonces
			Escrbir ("Contrse�a incorreta")
		Fin_Si
	Hasta que password=PASWORD
	Escribir ("Contrase�a correcta")
 FIN.
=======================================================================
 AUTOR: Juan Francisco Gallo Ram�rez
 28/09/2022 I.C.I.
=====================================================================*/


#include <stdio.h>
#include <locale.h>

int main ()
{
	#define PASSWORD 12345
	
	char user[10];
	int password;
	
	setlocale(LC_ALL ,"");
	
	printf("========== SISTEMA ==========\n");
	printf("- Ingresa usuario: \n");
	scanf("%s", user);
	printf("============================\n");
	system("cls");
	do
	{
		printf("======= USUARIO: %s =======\n", user);
		printf("- Ingresa contrase�a: \n");
		scanf("%i", &password);
		system("cls");
		
		if(password!=PASSWORD)
		{
			printf("-----------------------------\n");
			printf("### CONTRASE�A INCORRECTA ###\n");
			printf("-----------------------------\n");
		}
		system("cls");
	}
	while(password!=PASSWORD);
	
	printf("---------------------------\n");
	printf("+++ CONTRASE�A CORRECTA +++\n");
	printf("---------------------------\n");
	
}
