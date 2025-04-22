/*=====================================================================
 INTRODUCIR PASSWORD 
=======================================================================
 OBJETIVO: Leer la contraseña de un usuario y marcar si es correcta
 o no, de no serlo continuar preguntando hasta que se ingrese 
 correctamente.
=======================================================================
 ENTRADAS: Usuario, contraseña establecida y contraseña a ingresar.
=======================================================================
 SALIDAS: Mensaje de error o de entrada correta.
=======================================================================
 TABLA DE CONSTANTES Y VARIABLES:
 ---------------------------------------------------------------------
 = Descripción = Identificador = Tipo = Variable = Constante = Valor =
 ---------------------------------------------------------------------
   Password        PASSWORD      Entero     -          x       12345
  establecida
    Usuario          user        Cadena     x          -         -
   Password a      password      Entero     x          -         -
   ingresar
 ---------------------------------------------------------------------
=======================================================================
 HERRAMIENTA DE PROGRAMACIÓN (Pseudocódigo):
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
		Escribir ("Ingresa contraseña")
		Leer (password)
		Si password != PASSWORD entonces
			Escrbir ("Contrseña incorreta")
		Fin_Si
	Hasta que password=PASWORD
	Escribir ("Contraseña correcta")
 FIN.
=======================================================================
 AUTOR: Juan Francisco Gallo Ramírez
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
		printf("- Ingresa contraseña: \n");
		scanf("%i", &password);
		system("cls");
		
		if(password!=PASSWORD)
		{
			printf("-----------------------------\n");
			printf("### CONTRASEÑA INCORRECTA ###\n");
			printf("-----------------------------\n");
		}
		system("cls");
	}
	while(password!=PASSWORD);
	
	printf("---------------------------\n");
	printf("+++ CONTRASEÑA CORRECTA +++\n");
	printf("---------------------------\n");
	
}
