/*=========================================================
 PROYECTO FINAL.
-----------------------------------------------------------
 OBJETIVO:
 
 Crear un arreglo de 10 registros, que contenga la clave 
 del trabajador y que sea numérica entero de 4 posiciones,
 Después crear un arreglo de 10 registros, que contenga el 
 Nombre de personas que sea alfanumérico con Nombre, 
 Apellido Paterno y Apellido Materno, finalmente crear un 
 arreglo de 10 registros que contenga el salario del 
 trabajador y que sea numérico real.Estos arreglos deben 
 ser generados aleatoriamente. 

 Una vez creados los tres arreglos, el programa deberá 
 presentarle al usuario un menú con las siguientes 
 opciones:
 
 a) Mostrar todos los contactos (El contenido de los tres 
	arreglos con su respectiva información de cada 
	trabajador).
 b) Buscar un registro dando como parámetro el nombre o 
	la clave del trabajador. (Por las dos formas).
 c) Ordenar alfabéticamente por clave, nombre o salario.
 d) Insertar nuevos registros. 
 f) Eliminar un registro por clave o nombre (Por las dos 
	formas).
 g) Modificar la clave, el nombre o el salario de algún 
	trabajador. (Por las 3 formas, pero debe elegir cual 
	de ellas)
-----------------------------------------------------------
 AUTOR:
 -Juan Francisco Gallo Ramírez
 I.C.I. 1er Semestre.
 21/11/2022
=========================================================*/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define MAX 50
#define TRB 10


const int neg=0, azu=1, ver=2, cel=3, roj=4, mor=5, ama=6, gri=7;
const int negc=8, azuc=9, verc=10, celc=11, rojc=12, morc=13, amac=14, gric=15;

void gotoxy(int x,int y)//FUNCIÓN PARA ACOMODAR EN INTERFAZ
{
	/*----------------------------------------------------------------
	 La función gotoxy es bien conocida, nos ayuda a poder colocar
	 texto en la oantalla de ejecución en las coordenadas que 
	 establezcamos.
	----------------------------------------------------------------*/
	HANDLE hcon;  
	hcon=GetStdHandle(STD_OUTPUT_HANDLE);  
	COORD dwPos;  
	dwPos.X = x;  
	dwPos.Y= y;  
	SetConsoleCursorPosition(hcon,dwPos);  
}
void color(int c_fondo,int c_texto)//FUNCIÓN DE APOYO PARA COLOR
{
	/*----------------------------------------------------------------
	 Esta función nos ayuda a personalizar facilmente el fondo y
	 color de texto.
	----------------------------------------------------------------*/
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}
void pixel(int linea,int desde,int hasta,int c_fondo,int c_texto)//FUNCIÓN DE APOYO PARA GENERAR PIXELES
{
	/*----------------------------------------------------------------
	 Mediante esta función nos es posible generar patrones de colores 
	 estilo pixel art, gracias al uso de un caracter determinado,
	 esta función es de suma utilidad, ya que nos ahorra una cantidad
	 inmensa de trabajo de programación, solo basta con poner la 
	 línea donde se quieren los pixeles, y desde y hasta donde queremos
	 generar dichos pixeles, además del color de fondo y del caracter.
	----------------------------------------------------------------*/
	int i;
	
	color(c_fondo,c_texto);
	for(i=desde;i<=hasta;i++)
	{
		gotoxy(i,linea);printf("%c", 223);
	}
}
void p_inicial()//PANTALLA INICIAL
{
	/*----------------------------------------------------------------
	 Mediante esta función nos es más facil imprimir la portada del
	 programa, podeos ver que en lugar de copiar y pegar las 435 
	 líneas que posee esta función, solo utilizamos una al llamar la
	 función.
	----------------------------------------------------------------*/
	system("color F0");
	//Línea 1
	pixel(0,0,1,ama,ama);pixel(0,2,10,roj,ama);pixel(0,11,16,ama,ama);pixel(0,17,20,roj,ama);pixel(0,21,21,roj,roj);
	pixel(0,22,25,ama,ama);pixel(0,26,26,roj,roj);pixel(0,27,30,roj,ama);pixel(0,31,31,ama,ama);pixel(0,32,32,roj,roj);
	pixel(0,33,33,neg,neg);pixel(0,34,36,ver,ver);pixel(0,37,37,neg,ver);pixel(0,38,40,ver,ver);pixel(0,41,41,neg,ver);
	pixel(0,42,44,ver,ver);pixel(0,45,45,neg,ver);pixel(0,46,49,ver,ver);pixel(0,50,50,negc,ver);pixel(0,51,53,ver,ver);
	pixel(0,54,54,negc,ver);pixel(0,55,60,ver,ver);pixel(0,61,62,neg,ver);pixel(0,63,64,azu,neg);pixel(0,65,65,azu,azu);
	pixel(0,66,86,mor,mor);pixel(0,87,87,neg,neg);pixel(0,88,118,gric,gric);
	//Línea 2
	pixel(1,0,0,roj,roj);pixel(1,1,2,neg,roj);pixel(1,3,7,gri,neg);pixel(1,8,8,negc,neg);pixel(1,9,9,gri,neg);
	pixel(1,10,11,neg,roj);pixel(1,12,12,roj,roj);pixel(1,13,14,roj,ama);pixel(1,15,16,ama,ama);pixel(1,17,17,ama,roj);
	pixel(1,18,18,roj,roj);pixel(1,19,19,roj,ama);pixel(1,20,27,ama,ama);pixel(1,28,28,roj,ama);pixel(1,29,29,roj,roj);
	pixel(1,30,30,ama,roj);pixel(1,31,31,roj,ama);pixel(1,32,32,roj,roj);pixel(1,33,33,neg,neg);pixel(1,34,35,ver,ver);
	pixel(1,36,36,ver,neg);pixel(1,37,37,neg,negc);pixel(1,38,38,ver,neg);pixel(1,39,39,ver,ver);pixel(1,40,40,ver,neg);
	pixel(1,41,41,neg,negc);pixel(1,42,42,ver,neg);pixel(1,43,43,ver,ver);pixel(1,44,44,ver,neg);pixel(1,45,45,neg,negc);
	pixel(1,46,46,ver,neg);pixel(1,47,47,ver,ver);pixel(1,48,48,ama,ama);pixel(1,49,56,ver,ver);pixel(1,57,58,neg,ver);
	pixel(1,59,60,azu,neg);pixel(1,61,63,azu,azu);pixel(1,64,67,azu,mor);pixel(1,68,85,mor,mor);pixel(1,86,86,neg,neg);
	pixel(1,87,118,gric,gric);
	//Línea 3
	pixel(2,0,0,gri,neg);pixel(2,1,7,gri,gri);pixel(2,8,8,negc,negc);pixel(2,9,9,gri,gri);pixel(2,10,11,gric,gric);
	pixel(2,12,13,gric,neg);pixel(2,14,14,neg,roj);pixel(2,15,15,roj,roj);pixel(2,16,17,roj,ama);pixel(2,18,18,ama,ama);
	pixel(2,19,19,ama,roj);pixel(2,20,20,roj,roj);pixel(2,21,21,roj,ama);pixel(2,22,25,ama,ama);pixel(2,26,26,roj,ama);
	pixel(2,27,27,roj,roj);pixel(2,28,28,ama,roj);pixel(2,29,30,ama,ama);pixel(2,31,31,roj,roj);pixel(2,32,32,neg,neg);
	pixel(2,33,36,ver,ver);pixel(2,37,37,verc,verc);pixel(2,38,40,ver,ver);pixel(2,41,41,verc,verc);pixel(2,42,44,ver,ver);
	pixel(2,45,45,verc,verc);pixel(2,46,47,ver,ver);pixel(2,48,48,verc,verc);pixel(2,49,50,ver,ver);pixel(2,51,51,ver,ama);
	pixel(2,52,52,ver,negc);pixel(2,53,54,ver,ver);pixel(2,55,55,neg,ver);pixel(2,56,56,azu,neg);pixel(2,57,57,azu,azu);
	pixel(2,58,59,mor,azu);pixel(2,60,61,mor,mor);pixel(2,62,62,azu,azu);pixel(2,63,63,negc,negc);pixel(2,64,66,gri,gri);
	pixel(2,67,67,gri,azu);pixel(2,68,68,azu,azu);pixel(2,69,69,azu,mor);pixel(2,70,85,mor,mor);pixel(2,86,86,neg,neg);
	pixel(2,87,118,gric,gric);
	//Línea 4
	pixel(3,0,7,gri,gri);pixel(3,8,8,negc,negc);pixel(3,9,9,gri,gri);pixel(3,10,14,gric,gric);pixel(3,15,16,gric,neg);
	pixel(3,17,17,neg,roj);pixel(3,18,18,roj,roj);pixel(3,19,19,roj,ama);pixel(3,20,20,ama,ama);pixel(3,21,21,ama,roj);
	pixel(3,22,22,roj,roj);pixel(3,23,24,roj,ama);pixel(3,25,25,roj,roj);pixel(3,26,26,ama,roj);pixel(3,27,29,ama,ama);
	pixel(3,30,30,roj,ama);pixel(3,31,31,roj,roj);pixel(3,32,32,neg,neg);pixel(3,33,35,ver,ver);pixel(3,36,36,ama,ver);
	pixel(3,37,37,verc,verc);pixel(3,38,40,verc,ver);pixel(3,41,41,verc,verc);pixel(3,42,44,verc,ver);pixel(3,45,45,verc,verc);
	pixel(3,46,46,verc,ver);pixel(3,47,47,ver,verc);pixel(3,48,52,ver,ver);pixel(3,53,53,neg,ver);pixel(3,54,54,azu,neg);
	pixel(3,55,55,azu,azu);pixel(3,56,56,mor,azu);pixel(3,57,57,mor,mor);pixel(3,58,61,azu,mor);pixel(3,62,62,azu,azu);
	pixel(3,63,63,azu,negc);pixel(3,64,64,negc,negc);pixel(3,65,68,gri,gri);pixel(3,69,69,gri,azu);pixel(3,70,70,azu,azu);
	pixel(3,71,71,azu,mor);pixel(3,72,72,mor,mor);pixel(3,73,73,azu,azu);pixel(3,74,80,negc,azu);pixel(3,81,81,azu,azu);
	pixel(3,82,82,azu,mor);pixel(3,83,84,mor,mor);pixel(3,85,85,neg,mor);pixel(3,86,86,gric,neg);pixel(3,87,118,gric,gric);
	
	//Línea 5
	pixel(4,0,0,negc,gri);pixel(4,1,1,gri,gri);pixel(4,2,2,negc,negc);pixel(4,3,7,gri,gri);pixel(4,8,8,negc,negc);
	pixel(4,9,9,gri,gri);pixel(4,10,10,gric,gric);pixel(4,11,11,neg,neg);pixel(4,12,12,cel,neg);pixel(4,13,14,neg,gric);
	pixel(4,15,17,gric,gric);pixel(4,18,18,neg,neg);pixel(4,19,19,roj,roj);pixel(4,20,28,ama,ama);pixel(4,29,29,roj,ama);
	pixel(4,30,30,roj,roj);pixel(4,31,31,neg,neg);pixel(4,32,33,ver,ver);pixel(4,34,34,negc,ver);pixel(4,35,48,ver,ver);
	pixel(4,49,49,verc,verc);pixel(4,50,51,ver,verc);pixel(4,52,52,neg,verc);pixel(4,53,53,azu,neg);pixel(4,54,54,azu,azu);
	pixel(4,55,55,mor,mor);pixel(4,56,56,azu,mor);pixel(4,57,57,azu,azu);pixel(4,58,58,negc,azu);pixel(4,59,59,gri,negc);
	pixel(4,60,63,gri,gri);pixel(4,64,64,gri,negc);pixel(4,65,65,negc,negc);pixel(4,66,66,negc,gri);pixel(4,67,70,gri,gri);
	pixel(4,71,71,azu,azu);pixel(4,72,72,mor,mor);pixel(4,73,73,azu,azu);pixel(4,74,74,azu,negc);pixel(4,75,75,negc,gri);
	pixel(4,76,78,gri,gri);pixel(4,79,79,gri,negc);pixel(4,80,80,negc,gri);pixel(4,81,81,gri,negc);pixel(4,82,82,negc,azu);
	pixel(4,83,83,azu,azu);pixel(4,84,84,neg,neg);pixel(4,85,118,gric,gric);
	//Línea 6
	pixel(5,0,0,negc,negc);pixel(5,1,1,gri,gri);pixel(5,2,2,negc,negc);pixel(5,3,7,gri,gri);pixel(5,8,8,negc,negc);
	pixel(5,9,9,gri,gri);pixel(5,10,10,gric,gric);pixel(5,11,11,neg,neg);pixel(5,12,12,azu,azu);pixel(5,13,14,cel,cel);
	pixel(5,15,15,cel,neg);pixel(5,16,16,neg,neg);pixel(5,17,17,gric,gric);pixel(5,18,18,neg,neg);pixel(5,19,19,roj,roj);
	pixel(5,20,28,ama,roj);pixel(5,29,29,roj,roj);pixel(5,30,30,neg,roj);pixel(5,31,31,ver,neg);pixel(5,32,34,ver,ver);
	pixel(5,35,35,ver,negc);pixel(5,36,36,ver,ver);pixel(5,37,37,verc,verc);pixel(5,38,39,ver,verc);pixel(5,40,40,verc,verc);
	pixel(5,41,42,ver,ver);pixel(5,43,43,verc,verc);pixel(5,44,48,ver,verc);pixel(5,49,49,verc,verc);pixel(5,50,51,ver,ver);
	pixel(5,52,52,neg,neg);pixel(5,53,53,azu,azu);pixel(5,54,54,mor,mor);pixel(5,55,55,azu,azu);pixel(5,56,56,negc,azu);
	pixel(5,57,57,negc,negc);pixel(5,58,64,gri,gri);pixel(5,65,65,gri,negc);pixel(5,66,70,azu,negc);pixel(5,71,72,azu,azu);
	pixel(5,73,73,azu,mor);pixel(5,74,74,mor,azu);pixel(5,75,75,azu,azu);pixel(5,76,76,azu,negc);pixel(5,77,77,negc,gri);
	pixel(5,78,80,gri,gri);pixel(5,81,81,negc,negc);pixel(5,82,82,gri,gri);pixel(5,83,83,negc,negc);pixel(5,84,84,neg,neg);
	pixel(5,85,118,gric,gric);
	//Línea 7
	pixel(6,0,0,negc,negc);pixel(6,1,1,gri,gri);pixel(6,2,2,negc,negc);pixel(6,3,7,gri,gri);pixel(6,8,8,negc,negc);
	pixel(6,9,9,gri,gri);pixel(6,10,10,gric,gric);pixel(6,11,11,neg,neg);pixel(6,12,12,azu,azu);pixel(6,13,15,cel,cel);
	pixel(6,16,16,neg,neg);pixel(6,17,17,gric,gric);pixel(6,18,18,neg,neg);pixel(6,19,19,roj,roj);pixel(6,20,27,ama,ama);
	pixel(6,28,28,roj,roj);pixel(6,29,29,neg,roj);pixel(6,30,30,ver,neg);pixel(6,31,31,ver,ver);pixel(6,32,32,verc,verc);
	pixel(6,33,33,ver,verc);pixel(6,34,34,ver,gri);pixel(6,35,36,neg,ver);pixel(6,37,37,ver,gri);pixel(6,38,39,ver,ver);
	pixel(6,40,40,ver,gri);pixel(6,41,42,neg,ver);pixel(6,43,43,ver,gri);pixel(6,44,45,ver,ver);pixel(6,46,46,negc,negc);
	pixel(6,47,48,ver,ver);pixel(6,49,49,verc,verc);pixel(6,50,50,ver,ver);pixel(6,51,51,neg,neg);pixel(6,52,52,azu,azu);
	pixel(6,53,53,mor,azu);pixel(6,54,54,mor,mor);pixel(6,55,55,azu,azu);pixel(6,56,56,negc,negc);pixel(6,57,63,gri,gri);
	pixel(6,64,64,negc,gri);pixel(6,65,65,ama,azu);pixel(6,66,66,azu,azu);pixel(6,67,67,azu,mor);pixel(6,68,68,azu,azu);
	pixel(6,69,69,negc,negc);pixel(6,70,70,gri,negc);pixel(6,71,72,negc,negc);pixel(6,73,73,negc,azu);pixel(6,74,74,azu,azu);
	pixel(6,75,75,azu,mor);pixel(6,76,76,azu,azu);pixel(6,77,77,negc,negc);pixel(6,78,80,gri,gri);pixel(6,81,81,negc,negc);
	pixel(6,82,82,gri,gri);pixel(6,83,83,negc,negc);pixel(6,84,84,neg,neg);pixel(6,85,118,gric,gric);
	//Línea 8
	pixel(7,0,0,negc,negc);pixel(7,1,1,gri,gri);pixel(7,2,2,negc,negc);pixel(7,3,7,gri,gri);pixel(7,8,8,negc,negc);
	pixel(7,9,9,gri,gri);pixel(7,10,10,gric,gric);pixel(7,11,11,neg,neg);pixel(7,12,13,azu,azu);pixel(7,14,15,cel,cel);
	pixel(7,16,16,neg,neg);pixel(7,17,17,gric,gric);pixel(7,18,18,neg,neg);pixel(7,19,19,roj,roj);pixel(7,20,26,ama,roj);
	pixel(7,27,28,roj,roj);pixel(7,29,29,neg,neg);pixel(7,30,31,ver,ver);pixel(7,32,32,verc,verc);pixel(7,33,33,ver,ver);
	pixel(7,34,34,gri,ver);pixel(7,35,36,ver,neg);pixel(7,37,37, gri,ver);pixel(7,38,39,ver,ver);pixel(7,40,40,gri,ver);
	pixel(7,41,42,ver,neg);pixel(7,43,43,gri,ver);pixel(7,44,45,ver,ver);pixel(7,46,46,ver,negc);pixel(7,47,48,ver,ver);
	pixel(7,49,49,verc,verc);pixel(7,50,50,ver,ver);pixel(7,51,51,neg,neg);pixel(7,52,52,azu,azu);pixel(7,53,54,mor,mor);
	pixel(7,55,55,azu,azu);pixel(7,56,56,negc,negc);pixel(7,57,61,gri,gri);pixel(7,62,62,negc,gri);pixel(7,63,63,ama,negc);
	pixel(7,64,65,ama,ama);pixel(7,66,66,amac,amac);pixel(7,67,67,amac,azu);pixel(7,68,68,azu,azu);pixel(7,69,69,negc,negc);
	pixel(7,70,71,gri,gri);pixel(7,72,72,gri,negc);pixel(7,73,74,negc,negc);pixel(7,75,76,negc,azu);pixel(7,77,77,negc,negc);
	pixel(7,78,80,gri,gri);pixel(7,81,81,negc,negc);pixel(7,82,82,gri,gri);pixel(7,83,83,negc,negc);pixel(7,84,84,neg,neg);
	pixel(7,85,118,gric,gric);
	//Línea 9
	pixel(8,0,0,gri,negc);pixel(8,1,1,gri,gri);pixel(8,2,2,gri,negc);pixel(8,3,7,gri,gri);pixel(8,8,8,negc,negc);
	pixel(8,9,9,gri,gri);pixel(8,10,10,gric,gric);pixel(8,11,11,neg,neg);pixel(8,12,13,azu,azu);pixel(8,14,15,cel,cel);
	pixel(8,16,16,neg,neg);pixel(8,17,17,gric,gric);pixel(8,18,18,neg,neg);pixel(8,19,19,roj,roj);pixel(8,20,25,ama,ama);
	pixel(8,26,26,roj,ama);pixel(8,27,27,roj,roj);pixel(8,28,28,neg,neg);pixel(8,29,31,ver,ver);pixel(8,32,32,verc,verc);
	pixel(8,33,33,ver,ver);pixel(8,34,34,verc,verc);pixel(8,35,36,ver,ver);pixel(8,37,37,verc,verc);pixel(8,38,38,verc,ver);
	pixel(8,39,41,ver,ver);pixel(8,42,43,verc,ver);pixel(8,44,45,ama,ver);pixel(8,46,46,verc,ver);pixel(8,47,48,ver,ver);
	pixel(8,49,49,verc,verc);pixel(8,50,50,ver,ver);pixel(8,51,51,neg,neg);pixel(8,52,52,azu,azu);pixel(8,53,54,mor,mor);
	pixel(8,55,55,azu,azu);pixel(8,56,56,negc,negc);pixel(8,57,59,gri,gri);pixel(8,60,60,azu,gri);pixel(8,61,61,azu,negc);
	pixel(8,62,65,ama,ama);pixel(8,66,66,ama,amac);pixel(8,67,68,amac,amac);pixel(8,69,69,amac,negc);pixel(8,70,70,negc,gri);
	pixel(8,71,81,gri,gri);pixel(8,82,82,gri,negc);pixel(8,83,83,neg,neg);pixel(8,84,84,gric,neg);pixel(8,85,118,gric,gric);
	//Línea 10
	pixel(9,0,0,negc,gri);pixel(9,1,1,gri,gri);pixel(9,2,2,negc,gri);pixel(9,3,7,gri,gri);pixel(9,8,8,negc,negc);
	pixel(9,9,9,gri,gri);pixel(9,10,10,gric,gric);pixel(9,11,11,neg,neg);pixel(9,12,13,azu,azu);pixel(9,14,14,azu,cel);
	pixel(9,15,15,cel,cel);pixel(9,16,16,neg,neg);pixel(9,17,17,gric,gric);pixel(9,18,18,neg,neg);pixel(9,19,19,roj,roj);
	pixel(9,20,25,ama,roj);pixel(9,26,26,roj,roj);pixel(9,27,27,neg,neg);pixel(9,28,28,ver,verc);pixel(9,29,29,verc,ver);
	pixel(9,30,31,ver,ver);pixel(9,32,32,verc,verc);pixel(9,33,33,ver,ver);pixel(9,34,34,verc,verc);pixel(9,35,36,verc,ver);
	pixel(9,37,37,ver,ver);pixel(9,38,38,verc,verc);pixel(9,39,41,ver,ver);pixel(9,42,42,verc,verc);pixel(9,43,45,ver,ver);
	pixel(9,46,46,verc,verc);pixel(9,47,48,ver,ver);pixel(9,49,49,verc,verc);pixel(9,50,50,ver,ver);pixel(9,51,51,neg,neg);
	pixel(9,52,52,azu,azu);pixel(9,53,53,azu,mor);pixel(9,54,54,mor,mor);pixel(9,55,55,azu,azu);pixel(9,56,56,negc,negc);
	pixel(9,57,57,gri,gri);pixel(9,58,58,negc,gri);pixel(9,59,60,azu,azu);pixel(9,61,61,azu,mor);pixel(9,62,62,azu,azu);
	pixel(9,63,63,azu,ama);pixel(9,64,66,ama,ama);pixel(9,67,67,ama,amac);pixel(9,68,70,amac,amac);pixel(9,71,71,amac,negc);
	pixel(9,72,77,negc,gri);pixel(9,78,79,gri,gri);pixel(9,80,81,negc,negc);pixel(9,82,82,negc,gri);pixel(9,83,83,neg,neg);
	pixel(9,84,118,gric,gric);
	//Linea 11
	pixel(10,0,0,negc,negc);pixel(10,1,1,gri,gri);pixel(10,2,2,negc,negc);pixel(10,3,7,gri,gri);pixel(10,8,8,negc,negc);
	pixel(10,9,9,gri,gri);pixel(10,10,10,gric,gric);pixel(10,11,11,neg,neg);pixel(10,12,14,azu,azu);pixel(10,15,15,cel,cel);
	pixel(10,16,16,neg,neg);pixel(10,17,17,gric,gric);pixel(10,18,18,neg,neg);pixel(10,19,19,roj,roj);pixel(10,20,24,ama,ama);
	pixel(10,25,25,roj,roj);pixel(10,26,26,neg,roj);pixel(10,27,27,ver,neg);pixel(10,28,28,ver,ver);pixel(10,29,29,negc,ver);
	pixel(10,30,31,ver,verc);pixel(10,32,32,verc,verc);pixel(10,33,33,ver,ver);pixel(10,34,34,negc,ver);pixel(10,35,35,ver,ver);
	pixel(10,36,36,verc,verc);pixel(10,37,37,ver,ver);pixel(10,38,38,verc,verc);pixel(10,39,40,verc,ver);pixel(10,41,41,ver,ver);
	pixel(10,42,42,verc,verc);pixel(10,43,44,ver,ver);pixel(10,45,45,verc,ver);pixel(10,46,46,ver,verc);pixel(10,47,48,ver,ver);
	pixel(10,49,49,verc,verc);pixel(10,50,51,ver,ver);pixel(10,52,52,neg,neg);pixel(10,53,53,azu,azu);pixel(10,54,54,mor,mor);
	pixel(10,55,55,azu,azu);pixel(10,56,56,negc,negc);pixel(10,57,57,gri,gri);pixel(10,58,58,negc,negc);pixel(10,59,59,azu,azu);
	pixel(10,60,61,negc,negc);pixel(10,62,62,gri,negc);pixel(10,63,63,negc,azu);pixel(10,64,64,azu,azu);pixel(10,65,65,azu,ama);
	pixel(10,66,67,ama,ama);pixel(10,68,68,ama,amac);pixel(10,69,73,amac,amac);pixel(10,74,74,amac,azu);pixel(10,75,77,azu,azu);
	pixel(10,78,78,azu,negc);pixel(10,79,79,negc,gri);pixel(10,80,80,gri,gri);pixel(10,81,81,gri,negc);pixel(10,82,82,negc,negc);
	pixel(10,83,83,neg,neg);pixel(10,84,118,gric,gric);
	//Línea 12
	pixel(11,0,0,gri,negc);pixel(11,1,1,gri,gri);pixel(11,2,2,gri,negc);pixel(11,3,7,gri,gri);pixel(11,8,8,negc,negc);
	pixel(11,9,9,gri,gri);pixel(11,10,10,gric,gric);pixel(11,11,11,neg,neg);pixel(11,12,14,azu,azu);pixel(11,15,15,cel,cel);
	pixel(11,16,16,neg,neg);pixel(11,17,17,gric,gric);pixel(11,18,18,neg,neg);pixel(11,19,19,roj,roj);pixel(11,20,23,ama,roj);
	pixel(11,24,24,roj,roj);pixel(11,25,25,neg,roj);pixel(11,26,26,ver,neg);pixel(11,27,28,ver,ver);pixel(11,29,29,negc,ver);
	pixel(11,30,31,ver,ver);pixel(11,32,32,verc,verc);pixel(11,33,35,ver,ver);pixel(11,36,36,gri,verc);pixel(11,37,37,ver,ver);
	pixel(11,38,38,gri,verc);pixel(11,39,39,ver,ver);pixel(11,40,40,gri,verc);pixel(11,41,41,ver,ver);pixel(11,42,42,gri,verc);
	pixel(11,43,43,ver,ver);pixel(11,44,44,gri,verc);pixel(11,45,47,ver,ver);pixel(11,48,48,verc,ver);pixel(11,49,49,ver,verc);
	pixel(11,50,51,ver,ver);pixel(11,52,52,neg,neg);pixel(11,53,53,azu,azu);pixel(11,54,54,mor,mor);pixel(11,55,55,azu,azu);
	pixel(11,56,57,negc,negc);pixel(11,58,58,azu,negc);pixel(11,59,59,azu,azu);pixel(11,60,60,negc,negc);pixel(11,61,61,gri,gri);
	pixel(11,62,62,gri,negc);pixel(11,63,63,gri,gri);pixel(11,64,64,gri,negc);pixel(11,65,66,negc,azu);pixel(11,67,67,azu,ama);
	pixel(11,68,69,ama,ama);pixel(11,70,70,ama,amac);pixel(11,71,75,amac,amac);pixel(11,76,77,amac,azu);pixel(11,78,79,azu,azu);
	pixel(11,80,80,azu,negc);pixel(11,81,81,negc,gri);pixel(11,82,82,gri,gri);pixel(11,83,83,neg,neg);pixel(11,84,118,gric,gric);
	//Línea 13
	pixel(12,0,7,gri,gri);pixel(12,8,8,negc,negc);pixel(12,9,9,gri,gri);pixel(12,10,10,gric,gric);pixel(12,11,11,neg,neg);
	pixel(12,12,15,azu,azu);pixel(12,16,16,neg,neg);pixel(12,17,17,gric,gric);pixel(12,18,18,neg,neg);pixel(12,19,19,roj,roj);
	pixel(12,20,22,ama,ama);pixel(12,23,23,roj,ama);pixel(12,24,24,roj,roj);pixel(12,25,25,neg,neg);pixel(12,26,26,ver,ver);
	pixel(12,27,27,ama,ver);pixel(12,28,31,ver,ver);pixel(12,32,32,verc,verc);pixel(12,33,33,verc,ver);pixel(12,34,34,gri,ver);
	pixel(12,35,36,neg,neg);pixel(12,37,43,negc,neg);pixel(12,44,45,neg,neg);pixel(12,46,46,gri,ver);pixel(12,47,47,ver,verc);
	pixel(12,48,48,ver,ver);pixel(12,49,49,negc,ver);pixel(12,50,51,ver,ver);pixel(12,52,52,ver,neg);pixel(12,53,53,neg,azu);
	pixel(12,54,54,azu,azu);pixel(12,55,59,mor,azu);pixel(12,60,60,azu,azu);pixel(12,61,62,azu,gri);pixel(12,63,63,negc,gri);
	pixel(12,64,66,gri,gri);pixel(12,67,67,gri,negc);pixel(12,68,68,negc,azu);pixel(12,69,69,negc,ama);pixel(12,70,70,azu,ama);
	pixel(12,71,71,ama,ama);pixel(12,72,72,ama,amac);pixel(12,73,78,amac,amac);pixel(12,79,79,amac,azu);pixel(12,80,81,azu,azu);
	pixel(12,82,82,azu,negc);pixel(12,83,83,neg,neg);pixel(12,84,118,gric,gric);
	//Linea 14
	pixel(13,0,7,gri,gri);pixel(13,8,8,negc,negc);pixel(13,9,9,gri,gri);pixel(13,10,10,gric,gric);pixel(13,11,11,neg,neg);
	pixel(13,12,14,azu,azu);pixel(13,15,15,neg,azu);pixel(13,16,16,neg,neg);pixel(13,17,17,gric,gric);pixel(13,18,18,neg,neg);
	pixel(13,19,19,roj,roj);pixel(13,20,22,ama,roj);pixel(13,23,23,roj,roj);pixel(13,24,24,neg,neg);pixel(13,25,26,ver,ver);
	pixel(13,27,27,verc,ama);pixel(13,28,33,verc,ver);pixel(13,34,34,gri,ver);pixel(13,35,35,neg,neg);pixel(13,36,36,negc,negc);
	pixel(13,37,37,gri,negc);pixel(13,38,40,negc,gri);pixel(13,41,44,negc,negc);pixel(13,45,45,neg,neg);pixel(13,46,46,gri,ver);
	pixel(13,47,49,verc,ver);pixel(13,50,50,ama,ver);pixel(13,51,51,neg,ver);pixel(13,52,52,ver,ver);pixel(13,53,53,neg,neg);
	pixel(13,54,54,azu,azu);pixel(13,55,55,azu,mor);pixel(13,56,61,mor,mor);pixel(13,62,62,mor,azu);pixel(13,63,63,azu,azu);
	pixel(13,64,65,azu,negc);pixel(13,66,66,negc,gri);pixel(13,67,69,gri,gri);pixel(13,70,70,gri,negc);pixel(13,71,71,negc,azu);
	pixel(13,72,72,negc,ama);pixel(13,73,73,ama,ama);pixel(13,74,74,ama,amac);pixel(13,75,76,amac,amac);pixel(13,77,77,ver,ver);
	pixel(13,78,78,verc,ver);pixel(13,79,79,ver,ver);pixel(13,80,81,amac,amac);pixel(13,82,82,amac,azu);pixel(13,83,83,neg,neg);
	pixel(13,84,118,gric,gric);
	//Línea 15
	pixel(14,0,7,gri,gri);pixel(14,8,8,negc,negc);pixel(14,9,9,gri,gri);pixel(14,10,10,gric,gric);pixel(14,11,11,neg,neg);
	pixel(14,12,12,neg,azu);pixel(14,13,14,gric,neg);pixel(14,15,17,gric,gric);pixel(14,18,18,neg,neg);pixel(14,19,19,roj,roj);
	pixel(14,20,21,ama,ama);pixel(14,22,22,roj,roj);pixel(14,23,23,neg,roj);pixel(14,24,24,ver,neg);pixel(14,25,26,ver,ver);
	pixel(14,27,33,verc,ver);pixel(14,34,34,gri,ver);pixel(14,35,35,neg,neg);pixel(14,36,36,negc,negc);pixel(14,37,37,gri,gri);
	pixel(14,38,42,negc,negc);pixel(14,43,43,gri,negc);pixel(14,44,44,negc,negc);pixel(14,45,45,neg,neg);pixel(14,46,46,gri,ver);
	pixel(14,47,49,verc,ver);pixel(14,50,50,ama,ver);pixel(14,51,51,neg,ver);pixel(14,52,53,ver,ver);pixel(14,54,54,neg,neg);
	pixel(14,55,55,azu,azu);pixel(14,56,64,mor,mor);pixel(14,65,65,mor,azu);pixel(14,66,66,azu,azu);pixel(14,67,68,azu,negc);
	pixel(14,69,69,negc,gri);pixel(14,70,72,gri,gri);pixel(14,73,73,gri,negc);pixel(14,74,75,negc,ama);pixel(14,76,76,ver,amac);
	pixel(14,77,77,verc,ver);pixel(14,78,78,verc,verc);pixel(14,79,79,verc,ver);pixel(14,80,80,ver,amac);pixel(14,81,82,amac,amac);
	pixel(14,83,83,neg,neg);pixel(14,84,118,gric,gric);
	//Línea 16
	pixel(15,0,7,gri,gri);pixel(15,8,8,negc,negc);pixel(15,9,9,gri,gri);pixel(15,10,11,gric,gric);pixel(15,12,12,roj,gric);
	pixel(15,13,15,gric,gric);pixel(15,16,16,neg,gric);pixel(15,17,17,roj,neg);pixel(15,18,19,roj,roj);pixel(15,20,20,ama,roj);
	pixel(15,21,22,roj,roj);pixel(15,23,23,neg,neg);pixel(15,24,26,ver,ver);pixel(15,27,27,ama,ama);pixel(15,28,30,ver,ver);
	pixel(15,31,33,verc,ver);pixel(15,34,34,gri,ver);pixel(15,35,35,neg,neg);pixel(15,36,36,negc,negc);pixel(15,37,37,gri,gri);
	pixel(15,38,42,negc,negc);pixel(15,43,43,gri,gri);pixel(15,44,44,negc,negc);pixel(15,45,45,neg,neg);pixel(15,46,46,gri,ver);
	pixel(15,47,49,verc,ver);pixel(15,50,50,ama,ver);pixel(15,51,51,neg,ver);pixel(15,52,53,ver,ver);pixel(15,54,54,ver,neg);
	pixel(15,55,55,neg,azu);pixel(15,56,56,azu,azu);pixel(15,57,67,mor,mor);pixel(15,68,68,mor,azu);pixel(15,69,69,azu,azu);
	pixel(15,70,71,azu,negc);pixel(15,72,72,negc,gri);pixel(15,73,74,gri,gri);pixel(15,75,75,ver,ver);pixel(15,76,80,verc,verc);
	pixel(15,81,82,verc,ver);pixel(15,83,83,neg,neg);pixel(15,84,118,gric,gric);
	//Línea 17
	pixel(16,0,7,gri,gri);pixel(16,8,8,negc,negc);pixel(16,9,9,gri,gri);pixel(16,10,12,gric,gric);pixel(16,13,14,neg,gric);
	pixel(16,15,15,gri,neg);pixel(16,16,16,gric,neg);pixel(16,17,17,neg,neg);pixel(16,18,18,neg,roj);pixel(16,19,19,roj,roj);
	pixel(16,20,20,ama,ama);pixel(16,21,21,roj,roj);pixel(16,22,22,neg,neg);pixel(16,23,26,ver,ver);pixel(16,27,30,verc,ver);
	pixel(16,31,31,verc,verc);pixel(16,32,33,verc,ver);pixel(16,34,34,gri,ver);pixel(16,35,35,neg,neg);pixel(16,36,36,neg,negc);
	pixel(16,37,37,negc,negc);pixel(16,38,42,negc,gri);pixel(16,43,43,negc,negc);pixel(16,44,44,neg,negc);pixel(16,45,45,neg,neg);
	pixel(16,46,46,gri,ver);pixel(16,47,47,verc,ver);pixel(16,48,54,ver,ver);pixel(16,55,55,neg,neg);pixel(16,56,56,azu,azu);
	pixel(16,57,57,azu,mor);pixel(16,58,70,mor,mor);pixel(16,71,71,mor,azu);pixel(16,72,72,azu,azu);pixel(16,73,73,azu,negc);
	pixel(16,74,74,ver,negc);pixel(16,75,75,verc,ver);pixel(16,76,77,verc,verc);pixel(16,78,80,ver,ver);pixel(16,81,81,ver,verc);
	pixel(16,82,82,verc,verc);pixel(16,83,83,neg,neg);pixel(16,84,118,gric,gric);
	//Línea 18
	pixel(17,0,10,negc,neg);pixel(17,11,11,neg,neg);pixel(17,12,12,gri,neg);pixel(17,13,14,gric,gri);pixel(17,15,15,neg,gric);
	pixel(17,16,16,gric,neg);pixel(17,17,17,gric,gric);pixel(17,18,18,neg,neg);pixel(17,19,20,roj,roj);pixel(17,21,21,neg,roj);
	pixel(17,22,22,ver,neg);pixel(17,23,23,ver,ver);pixel(17,24,24,verc,verc);pixel(17,25,26,ver,verc);pixel(17,27,27,verc,verc);
	pixel(17,28,34,ver,ver);pixel(17,35,35,ver,neg);pixel(17,36,36,gri,neg);pixel(17,37,37,ver,neg);pixel(17,38,38,gri,neg);
	pixel(17,39,39,ver,neg);pixel(17,40,40,gri,neg);pixel(17,41,41,ver,neg);pixel(17,42,42,gri,neg);pixel(17,43,43,ver,neg);
	pixel(17,44,44,gri,neg);pixel(17,45,45,ver,neg);pixel(17,46,47,ver,ver);pixel(17,48,48,ver,verc);pixel(17,49,49,verc,ver);
	pixel(17,50,51,ver,ver);pixel(17,52,52,ver,negc);pixel(17,53,55,ver,ver);pixel(17,56,56,neg,neg);pixel(17,57,57,azu,azu);
	pixel(17,58,61,mor,mor);pixel(17,62,62,azu,mor);pixel(17,63,63,azu,azu);pixel(17,64,67,neg,azu);pixel(17,68,68,azu,azu);
	pixel(17,69,69,azu,mor);pixel(17,70,71,mor,mor);pixel(17,72,72,azu,azu);pixel(17,73,73,ver,azu);pixel(17,74,74,verc,ver);
	pixel(17,75,75,verc,verc);pixel(17,76,76,ver,verc);pixel(17,77,78,verc,verc);pixel(17,79,79,verc,ver);pixel(17,80,82,ver,ver);
	pixel(17,83,83,neg,neg);pixel(17,84,118,gric,gric);
	//Línea 19
	pixel(18,0,8,neg,negc);pixel(18,9,10,gri,neg);pixel(18,11,11,gric,gri);pixel(18,12,12,neg,gric);pixel(18,13,14,gric,neg);
	pixel(18,15,15,neg,gric);pixel(18,16,16,gric,neg);pixel(18,17,17,gric,gric);pixel(18,18,18,neg,neg);pixel(18,19,20,roj,roj);
	pixel(18,21,21,neg,neg);pixel(18,22,23,ver,ver);pixel(18,24,24,verc,verc);pixel(18,25,26,ver,ver);pixel(18,27,28,amac,negc);
	pixel(18,29,30,ver,ver);pixel(18,31,31,ver,negc);pixel(18,32,34,ver,ver);pixel(18,35,35,verc,ver);pixel(18,36,36,ver,verc);
	pixel(18,37,37,ver,ver);pixel(18,38,38,verc,verc);pixel(18,39,39,ver,ver);pixel(18,40,42,ver,verc);pixel(18,43,43,ver,ver);
	pixel(18,44,44,verc,verc);pixel(18,45,49,ver,ver);pixel(18,50,50,ver,verc);pixel(18,51,51,verc,ver);pixel(18,52,55,ver,ver);
	pixel(18,56,56,ver,neg);pixel(18,57,57,neg,azu);pixel(18,58,58,azu,azu);pixel(18,59,60,mor,mor);pixel(18,61,61,azu,azu);
	pixel(18,62,62,neg,azu);pixel(18,63,68,neg,neg);pixel(18,69,69,neg,azu);pixel(18,70,70,azu,azu);pixel(18,71,71,mor,mor);
	pixel(18,72,72,azu,azu);pixel(18,73,73,ver,ver);pixel(18,74,74,ver,verc);pixel(18,75,75,ver,ver);pixel(18,76,76,azu,azu);
	pixel(18,77,77,azu,ver);pixel(18,78,79,ver,verc);pixel(18,80,81,verc,verc);pixel(18,82,82,verc,ver);pixel(18,83,83,neg,neg);
	pixel(18,84,118,gric,gric);
	//Línea 20
	pixel(19,0,8,neg,gri);pixel(19,9,9,gri,gri);pixel(19,10,10,neg,gric);pixel(19,11,11,gric,neg);pixel(19,12,12,gric,gric);
	pixel(19,13,13,neg,gric);pixel(19,14,14,gric,neg);pixel(19,15,15,neg,gric);pixel(19,16,16,gric,gric);pixel(19,17,17,neg,gric);
	pixel(19,18,18,roj,neg);pixel(19,19,20,roj,roj);pixel(19,21,21,neg,neg);pixel(19,22,23,ver,ver);pixel(19,24,24,verc,verc);
	pixel(19,25,26,ver,ver);pixel(19,27,28,negc,amac);pixel(19,29,29,ver,ver);pixel(19,30,33,verc,ver);pixel(19,34,34,ver,verc);
	pixel(19,35,36,ver,ver);pixel(19,37,37,verc,ver);pixel(19,38,38,ver,verc);pixel(19,39,40,ver,ver);pixel(19,41,41,verc,verc);
	pixel(19,42,43,ver,ama);pixel(19,44,44,ver,verc);pixel(19,45,45,ver,ver);pixel(19,46,47,verc,ver);pixel(19,48,49,ama,ver);
	pixel(19,50,51,ver,ver);pixel(19,52,52,verc,verc);pixel(19,53,56,ver,ver);pixel(19,57,57,ver,neg);pixel(19,58,58,neg,azu);
	pixel(19,59,59,azu,azu);pixel(19,60,60,mor,mor);pixel(19,61,61,azu,azu);pixel(19,62,69,neg,neg);pixel(19,70,73,azu,azu);
	pixel(19,74,77,neg,azu);pixel(19,78,79,azu,azu);pixel(19,80,81,azu,ver);pixel(19,82,83,ver,verc);pixel(19,84,84,neg,neg);
	pixel(19,85,118,gric,gric);
	//Línea 21
	pixel(20,0,9,gri,gri);pixel(20,10,10,neg,neg);pixel(20,11,11,gric,gric);pixel(20,12,12,gri,neg);pixel(20,13,13,neg,gric);
	pixel(20,14,14,gric,neg);pixel(20,15,15,gric,gric);pixel(20,16,16,neg,gric);pixel(20,17,17,roj,neg);pixel(20,18,19,roj,roj);
	pixel(20,20,20,neg,neg);pixel(20,21,23,verc,ver);pixel(20,24,24,verc,verc);pixel(20,25,29,ver,ver);pixel(20,30,30,neg,gri);
	pixel(20,31,31,neg,ver);pixel(20,32,32,neg,gri);pixel(20,33,34,ver,ver);pixel(20,35,35,neg,gri);pixel(20,36,36,neg,ver);
	pixel(20,37,37,neg,gri);pixel(20,38,38,neg,ver);pixel(20,39,39,neg,gri);pixel(20,40,40,neg,ver);pixel(20,41,41,neg,gri);
	pixel(20,42,44,ver,ver);pixel(20,45,45,verc,verc);pixel(20,46,46,ver,ver);pixel(20,47,47,verc,ver);pixel(20,48,49,ama,ver);
	pixel(20,50,51,ver,ver);pixel(20,52,52,verc,verc);pixel(20,53,54,ver,ver);pixel(20,55,55,ver,negc);pixel(20,56,57,ver,ver);
	pixel(20,58,58,neg,neg);pixel(20,59,59,azu,azu);pixel(20,60,60,azu,mor);pixel(20,61,61,azu,azu);pixel(20,62,62,azu,neg);
	pixel(20,63,68,neg,neg);pixel(20,69,69,azu,neg);pixel(20,70,71,azu,azu);pixel(20,72,72,neg,azu);pixel(20,73,78,neg,neg);
	pixel(20,79,79,neg,azu);pixel(20,80,80,azu,azu);pixel(20,81,83,mor,azu);pixel(20,84,84,neg,neg);pixel(20,85,118,gric,gric);
	//Línea 22	
	pixel(21,0,9,gri,gri);pixel(21,10,10,neg,neg);pixel(21,11,11,gric,gric);pixel(21,12,12,gri,neg);pixel(21,13,13,gric,gric);
	pixel(21,14,14,neg,gric);pixel(21,15,15,roj,neg);pixel(21,16,19,roj,roj);pixel(21,20,20,neg,neg);pixel(21,21,23,ver,ver);
	pixel(21,24,24,verc,verc);pixel(21,25,26,ver,verc);pixel(21,27,27,ver,negc);pixel(21,28,29,ver,ver);pixel(21,30,30,gri,neg);
	pixel(21,31,31,ver,neg);pixel(21,32,32,gri,neg);pixel(21,33,34,ver,ver);pixel(21,35,35,gri,neg);pixel(21,36,36,ver,neg);
	pixel(21,37,37,gri,neg);pixel(21,38,38,ver,neg);pixel(21,39,39,gri,neg);pixel(21,40,40,ver,neg);pixel(21,41,41,gri,neg);
	pixel(21,42,44,ver,ver);pixel(21,45,45,gri,verc);pixel(21,46,46,ver,ver);pixel(21,47,47,gri,verc);pixel(21,48,51,ver,ver);
	pixel(21,52,52,verc,verc);pixel(21,53,58,ver,ver);pixel(21,59,59,neg,neg);pixel(21,60,61,azu,azu);pixel(21,62,63,neg,azu);
	pixel(21,64,64,gric,azu);pixel(21,65,66,celc,azu);pixel(21,67,67,gric,azu);pixel(21,68,69,neg,azu);pixel(21,70,71,azu,azu);
	pixel(21,72,79,neg,neg);pixel(21,80,80,azu,azu);pixel(21,81,83,mor,mor);pixel(21,84,84,neg,neg);pixel(21,85,118,gric,gric);
	//Línea 23
	pixel(22,0,9,gri,gri);pixel(22,10,10,neg,neg);pixel(22,11,11,gric,gric);pixel(22,12,12,neg,gric);pixel(22,13,13,roj,neg);
	pixel(22,14,19,roj,roj);pixel(22,20,20,neg,neg);pixel(22,21,21,ver,ver);pixel(22,22,22,negc,ver);pixel(22,23,23,ver,ver);
	pixel(22,24,24,verc,verc);pixel(22,25,25,ver,ver);pixel(22,26,26,ama,ver);pixel(22,27,27,ver,ver);pixel(22,28,28,ama,ver);
	pixel(22,29,29,ver,ver);pixel(22,30,30,ama,ver);pixel(22,31,31,ver,ver);pixel(22,32,32,ama,ver);pixel(22,33,33,ver,ver);
	pixel(22,34,34,ama,ver);pixel(22,35,42,ver,ver);pixel(22,43,43,gri,ver);pixel(22,44,44,neg,neg);pixel(22,45,45,negc,neg);
	pixel(22,46,48,neg,neg);pixel(22,49,49,gri,ver);pixel(22,50,51,verc,ver);pixel(22,52,52,verc,verc);pixel(22,53,54,verc,ver);
	pixel(22,55,55,verc,negc);pixel(22,56,57,verc,ver);pixel(22,58,58,ver,verc);pixel(22,59,59,ver,ver);pixel(22,60,60,neg,neg);
	pixel(22,61,62,azu,azu);pixel(22,63,63,azu,neg);pixel(22,64,64,neg,gric);pixel(22,65,66,celc,celc);pixel(22,67,67,neg,gric);
	pixel(22,68,68,azu,neg);pixel(22,69,69,azu,azu);pixel(22,70,70,mor,azu);pixel(22,71,71,azu,azu);pixel(22,72,72,azu,neg);
	pixel(22,73,78,neg,neg);pixel(22,79,79,azu,neg);pixel(22,80,80,azu,azu);pixel(22,81,83,mor,mor);pixel(22,84,84,mor,neg);
	pixel(22,85,85,neg,gric);pixel(22,86,118,gric,gric);
	//Línea 24
	pixel(23,0,2,roj,neg);pixel(23,3,3,ama,neg);pixel(23,4,4,roj,neg);pixel(23,5,5,ama,neg);pixel(23,6,6,roj,neg);
	pixel(23,7,7,ama,neg);pixel(23,8,11,roj,neg);pixel(23,12,19,roj,roj);pixel(23,20,20,neg,neg);pixel(23,21,23,ver,ver);
	pixel(23,24,24,verc,verc);pixel(23,25,25,ver,ver);pixel(23,26,26,verc,ama);pixel(23,27,27,ver,ver);pixel(23,28,28,verc,ama);
	pixel(23,29,29,ver,ver);pixel(23,30,30,verc,ama);pixel(23,31,31,ver,ver);pixel(23,32,32,verc,ama);pixel(23,33,33,ver,ver);
	pixel(23,34,34,verc,ama);pixel(23,35,38,ver,ver);pixel(23,39,42,verc,ver);pixel(23,43,43,gri,ver);pixel(23,44,44,neg,neg);
	pixel(23,45,45,negc,negc);pixel(23,46,47,negc,neg);pixel(23,48,48,neg,neg);pixel(23,49,49,gri,ver);pixel(23,50,51,verc,ver);
	pixel(23,52,59,ver,ver);pixel(23,60,60,ver,neg);pixel(23,61,61,neg,azu);pixel(23,62,62,azu,azu);pixel(23,63,65,mor,azu);
	pixel(23,66,67,azu,azu);pixel(23,68,71,neg,azu);pixel(23,72,73,azu,azu);pixel(23,74,74,gric,azu);pixel(23,75,75,mor,azu);
	pixel(23,76,80,azu,azu);pixel(23,81,81,azu,mor);pixel(23,82,84,mor,mor);pixel(23,85,85,neg,neg);pixel(23,86,118,gric,gric);
	
	//Línea 25
	pixel(24,0,2,roj,roj);pixel(24,3,3,ama,ama);pixel(24,4,4,roj,roj);pixel(24,5,5,ama,ama);pixel(24,6,6,roj,roj);
	pixel(24,7,7,ama,ama);pixel(24,8,12,roj,roj);pixel(24,13,13,ama,roj);pixel(24,14,16,roj,ama);pixel(24,17,17,ama,ama);
	pixel(24,18,20,roj,ama);pixel(24,21,21,neg,neg);pixel(24,22,23,ver,ver);pixel(24,24,39,ver,verc);pixel(24,40,43,ver,ver);
	pixel(24,44,44,ver,neg);pixel(24,45,45,gri,neg);pixel(24,46,46,ver,neg);pixel(24,47,47,gri,neg);pixel(24,48,48,ver,neg);
	pixel(24,49,50,ver,ver);pixel(24,51,51,verc,verc);pixel(24,52,54,ver,ver);pixel(24,55,56,neg,ver);pixel(24,57,58,ver,ver);
	pixel(24,59,59,ama,negc);pixel(24,60,60,ver,ver);pixel(24,61,61,ver,neg);pixel(24,62,62,neg,azu);pixel(24,63,63,azu,azu);
	pixel(24,64,64,mor,mor);pixel(24,65,65,azu,azu);pixel(24,66,66,neg,azu);pixel(24,67,72,neg,neg);pixel(24,73,73,neg,azu);
	pixel(24,74,75,azu,azu);pixel(24,76,76,neg,azu);pixel(24,77,80,neg,neg);pixel(24,81,81,neg,azu);pixel(24,82,82,azu,azu);
	pixel(24,83,83,azu,mor);pixel(24,84,84,mor,mor);pixel(24,85,85,neg,neg);pixel(24,86,118,gric,gric);
	//Línea 26
	pixel(25,0,2,roj,roj);pixel(25,3,3,ama,ama);pixel(25,4,4,roj,roj);pixel(25,5,5,ama,ama);pixel(25,6,6,roj,roj);
	pixel(25,7,7,ama,ama);pixel(25,8,10,roj,roj);pixel(25,11,11,ama,roj);pixel(25,12,12,roj,ama);pixel(25,13,17,roj,roj);
	pixel(25,18,18,roj,ama);pixel(25,19,19,ama,roj);pixel(25,20,20,roj,roj);pixel(25,21,21,roj,neg);pixel(25,22,22,neg,ver);
	pixel(25,23,23,ver,ver);pixel(25,24,24,negc,ama);pixel(25,25,26,ver,ver);pixel(25,27,27,negc,ama);pixel(25,28,29,ver,ver);
	pixel(25,30,30,negc,ama);pixel(25,31,31,ver,ver);pixel(25,32,32,negc,ver);pixel(25,33,34,amac,ver);pixel(25,35,35,negc,ver);
	pixel(25,36,39,verc,ver);pixel(25,40,40,ver,ver);pixel(25,41,41,ver,negc);pixel(25,42,42,ver,ver);pixel(25,43,43,ver,negc);
	pixel(25,44,44,ver,ver);pixel(25,45,45,verc,verc);pixel(25,46,46,ver,ver);pixel(25,47,52,ver,verc);pixel(25,53,53,ver,gri);
	pixel(25,54,54,neg,neg);pixel(25,55,56,negc,negc);pixel(25,57,57,neg,neg);pixel(25,58,61,ver,ver);pixel(25,62,62,neg,neg);
	pixel(25,63,63,azu,azu);pixel(25,64,64,azu,mor);pixel(25,65,65,azu,azu);pixel(25,66,73,neg,neg);pixel(25,74,74,azu,azu);
	pixel(25,75,82,neg,neg);pixel(25,83,83,azu,azu);pixel(25,84,84,mor,mor);pixel(25,85,85,mor,neg);pixel(25,86,86,neg,gric);
	pixel(25,87,118,gric,gric);
	//Línea 27
	pixel(26,0,2,roj,roj);pixel(26,3,3,ama,ama);pixel(26,4,4,roj,roj);pixel(26,5,5,ama,ama);pixel(26,6,6,roj,roj);
	pixel(26,7,7,ama,ama);pixel(26,8,10,roj,ama);pixel(26,11,11,ama,roj);pixel(26,12,19,roj,roj);pixel(26,20,21,roj,ama);
	pixel(26,22,22,roj,neg);pixel(26,23,23,neg,ver);pixel(26,24,29,ver,ver);pixel(26,30,30,ama,ver);pixel(26,31,31,ver,ver);
	pixel(26,32,32,negc,ver);pixel(26,33,34,amac,ver);pixel(26,35,35,negc,ver);pixel(26,36,38,verc,ver);pixel(26,39,39,verc,verc);
	pixel(26,40,44,verc,ver);pixel(26,45,45,verc,verc);pixel(26,46,54,ver,ver);pixel(26,55,56,ver,neg);pixel(26,57,62,ver,ver);
	pixel(26,63,63,neg,neg);pixel(26,64,65,azu,azu);pixel(26,66,66,azu,neg);pixel(26,67,72,neg,neg);pixel(26,73,73,azu,neg);
	pixel(26,74,74,azu,azu);pixel(26,75,82,neg,neg);pixel(26,83,83,azu,azu);pixel(26,84,85,mor,mor);pixel(26,86,86,neg,neg);
	pixel(26,87,118,gric,gric);
	//Línea 28
	pixel(27,0,1,roj,roj);pixel(27,2,2,ama,roj);pixel(27,3,3,roj,ama);pixel(27,4,4,roj,roj);pixel(27,5,5,ama,ama);
	pixel(27,6,6,roj,roj);pixel(27,7,7,ama,ama);pixel(27,8,11,roj,roj);pixel(27,12,12,roj,ama);pixel(27,13,13,ama,roj);
	pixel(27,14,15,roj,roj);pixel(27,16,16,ama,roj);pixel(27,17,23,roj,ama);pixel(27,24,24,roj,neg);pixel(27,25,25,neg,ver);
	pixel(27,26,26,ver,ver);pixel(27,27,27,ver,negc);pixel(27,28,29,ver,ver);pixel(27,30,30,ver,negc);pixel(27,31,31,ver,ver);
	pixel(27,32,32,negc,ver);pixel(27,33,34,amac,ver);pixel(27,35,35,negc,ver);pixel(27,36,38,verc,ver);pixel(27,39,39,verc,verc);
	pixel(27,40,40,ver,ver);pixel(27,41,41,negc,ver);pixel(27,42,44,ver,ver);pixel(27,45,47,ver,verc);pixel(27,48,49,ver,ama);
	pixel(27,50,50,verc,verc);pixel(27,51,52,verc,ver);pixel(27,53,53,gri,ver);pixel(27,54,54,neg,ver);pixel(27,55,56,negc,neg);
	pixel(27,57,57,neg,ver);pixel(27,58,58,ver,ver);pixel(27,59,59,ver,negc);pixel(27,60,62,ver,ver);pixel(27,63,63,neg,neg);
	pixel(27,64,65,azu,azu);pixel(27,66,67,neg,azu);pixel(27,68,68,gric,azu);pixel(27,69,70,ver,azu);pixel(27,71,71,gric,azu);
	pixel(27,72,73,neg,azu);pixel(27,74,75,azu,azu);pixel(27,76,81,azu,neg);pixel(27,82,83,azu,azu);pixel(27,84,85,mor,mor);
	pixel(27,86,86,neg,neg);pixel(27,87,118,gric,gric);
	//Línea 29
	pixel(28,0,0,ama,roj);pixel(28,1,1,roj,ama);pixel(28,2,3,roj,roj);pixel(28,4,4,ama,roj);pixel(28,5,5,roj,ama);
	pixel(28,6,6,ama,roj);pixel(28,7,7,roj,roj);pixel(28,8,8,roj,ama);pixel(28,9,9,ama,roj);pixel(28,10,13,roj,roj);
	pixel(28,14,17,roj,ama);pixel(28,18,18,ama,ama);pixel(28,19,24,roj,ama);pixel(28,25,25,ama,ama);pixel(28,26,27,roj,neg);
	pixel(28,28,29,neg,ver);pixel(28,30,37,ver,ver);pixel(28,38,38,verc,verc);pixel(28,39,42,ver,ver);pixel(28,43,43,ver,negc);
	pixel(28,44,53,ver,ver);pixel(28,54,54,ver,neg);pixel(28,55,56,neg,negc);pixel(28,57,57,ver,neg);pixel(28,58,60,ver,ver);
	pixel(28,61,61,ver,negc);pixel(28,62,63,ver,ver);pixel(28,64,64,neg,neg);pixel(28,65,66,azu,azu);pixel(28,67,67,azu,neg);
	pixel(28,68,68,neg,gric);pixel(28,69,70,ver,ver);pixel(28,71,71,neg,gric);pixel(28,72,72,azu,neg);pixel(28,73,74,azu,azu);
	pixel(28,75,75,azu,neg);pixel(28,76,76,neg,neg);pixel(28,77,77,gric,gric);pixel(28,78,79,roj,roj);pixel(28,80,80,gric,gric);
	pixel(28,81,81,neg,neg);pixel(28,82,82,azu,neg);pixel(28,83,83,azu,azu);pixel(28,84,85,mor,mor);pixel(28,86,86,mor,neg);
	pixel(28,87,87,neg,gric);pixel(28,88,118,gric,gric);
	//Línea 30
	pixel(29,0,1,roj,roj);pixel(29,2,2,ama,roj);pixel(29,3,3,roj,ama);pixel(29,4,6,roj,roj);pixel(29,7,7,roj,ama);
	pixel(29,8,8,ama,roj);pixel(29,9,9,roj,roj);pixel(29,10,10,roj,ama);pixel(29,11,11,ama,roj);pixel(29,12,17,roj,roj);
	pixel(29,18,18,ama,ama);pixel(29,19,25,roj,roj);pixel(29,26,26,roj,ama);pixel(29,27,27,ama,roj);pixel(29,28,29,roj,roj);
	pixel(29,30,31,roj,neg);pixel(29,32,33,neg,ver);pixel(29,34,35,ver,ver);pixel(29,36,36,ver,negc);pixel(29,37,37,ver,ver);
	pixel(29,38,38,verc,verc);pixel(29,39,43,ver,ver);pixel(29,44,44,ver,ama);pixel(29,45,45,ver,negc);pixel(29,46,48,ver,ver);
	pixel(29,49,49,ver,negc);pixel(29,50,63,ver,ver);pixel(29,64,64,neg,neg);pixel(29,65,65,azu,azu);pixel(29,66,66,mor,mor);
	pixel(29,67,72,mor,azu);pixel(29,73,74,mor,mor);pixel(29,75,75,mor,azu);pixel(29,76,76,azu,azu);pixel(29,77,77,azu,neg);
	pixel(29,78,79,azu,roj);pixel(29,80,80,azu,neg);pixel(29,81,82,azu,azu);pixel(29,83,83,mor,azu);pixel(29,84,86,mor,mor);
	pixel(29,87,87,neg,neg);pixel(29,88,118,gric,gric);	
}
void p_uno()//PANTALLA TIPO 1
{
	/*----------------------------------------------------------------
	 Mediante esta función imprimimos la pantalla de presentación.
	----------------------------------------------------------------*/
	//Línea superior
	pixel(1,0,0,gric,gric);pixel(1,1,117,ver,roj);pixel(2,0,0,gric,gric);color(gric,gric);pixel(2,1,117,gric,azu);
	//Línea inferior
	pixel(1,0,0,gric,gric);pixel(27,1,117,ver,roj);pixel(28,0,0,gric,gric);color(gric,gric);pixel(28,1,117,gric,azu);
	//Logo
	logo(44,4);
	//Texto
	gotoxy(17,18);
	printf("El Programa de Manejo de Personal  (PMP),  est%c dise%cado conforme a las  indicaciones",160,164);
	gotoxy(17,19);
	printf("propuestas para el proyecto final de la materia de  LENGUAJES DE COMPUTACI%cN I  de la",224);
	gotoxy(17,20);
	printf("la carrera de Ingenier%ca en Computaci%cn Inteligente (ICI) impartida en la Universidad",161,162);
	gotoxy(17,21);
	printf("Aut%cnoma de Aguascalientes (UAA).",162);
}
void p_dos(int col[])//PANTALLA TIPO 2
{
	/*----------------------------------------------------------------
	 Mediante esta función imprimimos la pantalla de configuración.
	----------------------------------------------------------------*/
	int i;
	if(col[1]==gric)system("color F0");
	else system("color 80");
	//Logo pequeño
	pixel(1,1,3,neg,neg);pixel(1,4,4,col[1],col[1]);pixel(1,5,5,neg,neg);pixel(1,6,6,neg,col[1]);
	pixel(1,7,7,col[1],col[1]);pixel(1,8,8,neg,col[1]);pixel(1,9,9,neg,neg);pixel(1,10,10,col[1],col[1]);
	pixel(1,11,13,neg,neg);pixel(2,1,1,neg,neg);pixel(2,2,3,col[1],neg);pixel(2,4,4,col[1],col[1]);
	pixel(2,5,5,neg,neg);pixel(2,6,6,col[1],col[1]);pixel(2,7,7,col[1],neg);pixel(2,8,8,col[1],col[1]);
	pixel(2,9,9,neg,neg);pixel(2,10,10,col[1],col[1]);pixel(2,11,11,neg,neg);pixel(2,12,13,col[1],neg);
	pixel(3,1,1,col[1],neg);pixel(3,2,4,col[1],col[1]);pixel(3,5,5,col[1],neg);pixel(3,6,8,col[1],col[1]);
	pixel(3,9,9,col[1],neg);pixel(3,10,10,col[1],col[1]);pixel(3,11,11,col[1],neg);pixel(3,12,13,col[1],col[1]);
	//Línea superior
	pixel(1,0,0,col[1],col[1]);pixel(1,15,117,ver,roj);pixel(2,0,0,col[1],col[1]);pixel(2,15,117,col[1],azu);
	//Línea lateral
	for(i=4;i<=28;i++)
	{
		pixel(i,1,1,roj,roj);pixel(i,2,2,ver,ver);pixel(i,3,3,azu,azu);
	}
}
void p_ejecucion(int col[])//PANTALLA DE EJECUCIÓN
{
	/*----------------------------------------------------------------
	 Mediante esta función imprimimos la pantalla de ejecución.
	----------------------------------------------------------------*/
	pixel(1,0,0,col[1],col[1]);pixel(1,1,117,ver,roj);pixel(2,0,0,col[1],col[1]);pixel(2,1,117,col[1],azu);
}
void p_final()//PANTALLA FINAL
{
	/*----------------------------------------------------------------
	 Mediante esta función imprimimos la pantalla final.
	----------------------------------------------------------------*/
	system("color F0");
	//Línea inferior
	pixel(1,0,0,gric,gric);pixel(27,1,117,ver,roj);pixel(28,0,0,gric,gric);color(gric,gric);pixel(28,1,117,gric,azu);
	//Logo
	logo(44,2);
	//Texto
	gotoxy(58,19);
	color(gric,ver);printf("Autor:");color(gric,negc);
	gotoxy(47,21);
	printf("Juan Francisco Gallo Ram%crez",161);
}
void logo(int x,int y)//GENERADOR DE LOGO
{
	/*----------------------------------------------------------------
	 Mediante esta función imprimimos el logo de nuestro programa,
	 solo basta con colocar la línea y las coordenadas en x donde
	 queremos imprimirlo.
	----------------------------------------------------------------*/
	//Línea 1
	pixel(y,x,x+1,gric,gric);pixel(y,x+2,x+14,neg,gric);pixel(y,x+15,x+16,neg,neg);pixel(y,x+17,x+31,gric,gric);
	//Línea 2
	pixel(y+1,x,x,gric,gric);pixel(y+1,x+1,x+1,neg,neg);pixel(y+1,x+2,x+2,gric,neg);pixel(y+1,x+3,x+3,gric,gric);
	pixel(y+1,x+4,x+7,neg,gric);pixel(y+1,x+8,x+11,gric,gric);pixel(y+1,x+12,x+14,neg,gric);pixel(y+1,x+15,x+16,gric,gric);
	pixel(y+1,x+17,x+19,neg,gric);pixel(y+1,x+20,x+24,gric,gric);pixel(y+1,x+25,x+28,neg,gric);pixel(y+1,x+29,x+31,gric,gric);
	//Línea 3
	pixel(y+2,x,x,gric,gric);pixel(y+2,x+1,x+1,neg,neg);pixel(y+2,x+2,x+2,gric,gric);pixel(y+2,x+3,x+3,neg,neg);
	pixel(y+2,x+4,x+7,negc,negc);pixel(y+2,x+8,x+8,negc,neg);pixel(y+2,x+9,x+9,neg,gric);pixel(y+2,x+10,x+10,gric,gric);
	pixel(y+2,x+11,x+11,neg,neg);pixel(y+2,x+12,x+14,gri,gri);pixel(y+2,x+15,x+16,gri,neg);pixel(y+2,x+17,x+19,gri,gri);
	pixel(y+2,x+20,x+20,neg,neg);pixel(y+2,x+21,x+23,gric,gric);pixel(y+2,x+24,x+24,neg,neg);pixel(y+2,x+25,x+28,negc,negc);
	pixel(y+2,x+29,x+29,negc,neg);pixel(y+2,x+30,x+30,neg,gric);pixel(y+2,x+31,x+31,gric,gric);
	//Línea 4
	pixel(y+3,x,x,roj,gric);pixel(y+3,x+1,x+1,roj,neg);pixel(y+3,x+2,x+2,gric,gric);pixel(y+3,x+3,x+3,neg,neg);
	pixel(y+3,x+4,x+8,negc,negc);pixel(y+3,x+9,x+9,neg,neg);pixel(y+3,x+10,x+10,gric,gric);pixel(y+3,x+11,x+11,neg,neg);
	pixel(y+3,x+12,x+12,gri,gri);pixel(y+3,x+13,x+13,neg,neg);pixel(y+3,x+14,x+14,neg,gri);pixel(y+3,x+15,x+16,gri,gri);
	pixel(y+3,x+17,x+17,neg,gri);pixel(y+3,x+18,x+18,neg,neg);pixel(y+3,x+19,x+19,gri,gri);pixel(y+3,x+20,x+20,neg,neg);
	pixel(y+3,x+21,x+23,gric,gric);pixel(y+3,x+24,x+24,neg,neg);pixel(y+3,x+25,x+29,negc,negc);pixel(y+3,x+30,x+30,neg,neg);
	pixel(y+3,x+31,x+31,gric,gric);
	//Línea 5
	pixel(y+4,x,x+1,azu,ver);pixel(y+4,x+2,x+2,gric,gric);pixel(y+4,x+3,x+3,neg,neg);pixel(y+4,x+4,x+4,negc,negc);
	pixel(y+4,x+5,x+7,neg,negc);pixel(y+4,x+8,x+8,gric,neg);pixel(y+4,x+9,x+10,gric,gric);pixel(y+4,x+11,x+11,neg,neg);
	pixel(y+4,x+12,x+12,gri,gri);pixel(y+4,x+13,x+13,neg,neg);pixel(y+4,x+14,x+14,gric,gric);pixel(y+4,x+15,x+16,gric,neg);
	pixel(y+4,x+17,x+17,gric,gric);pixel(y+4,x+18,x+18,neg,neg);pixel(y+4,x+19,x+19,gri,gri);pixel(y+4,x+20,x+20,neg,neg);
	pixel(y+4,x+21,x+23,gric,gric);pixel(y+4,x+24,x+24,neg,neg);pixel(y+4,x+25,x+25,negc,negc);pixel(y+4,x+26,x+28,neg,negc);
	pixel(y+4,x+29,x+29,gric,neg);pixel(y+4,x+30,x+31,gric,gric);
	//Línea 6
	pixel(y+5,x,x,gric,gric);pixel(y+5,x+1,x+1,neg,neg);pixel(y+5,x+2,x+2,gric,gric);pixel(y+5,x+3,x+3,neg,neg);
	pixel(y+5,x+4,x+4,negc,negc);pixel(y+5,x+5,x+5,neg,neg);pixel(y+5,x+6,x+10,gric,gric);pixel(y+5,x+11,x+11,neg,neg);
	pixel(y+5,x+12,x+12,gri,gri);pixel(y+5,x+13,x+13,neg,neg);pixel(y+5,x+14,x+17,gric,gric);pixel(y+5,x+18,x+18,neg,neg);
	pixel(y+5,x+19,x+19,gri,gri);pixel(y+5,x+20,x+20,neg,neg);pixel(y+5,x+21,x+23,gric,gric);pixel(y+5,x+24,x+24,neg,neg);
	pixel(y+5,x+25,x+25,negc,negc);pixel(y+5,x+26,x+26,neg,neg);pixel(y+5,x+27,x+29,gric,gric);pixel(y+5,x+30,x+30,roj,gric);
	pixel(y+5,x+31,x+31,gric,gric);
	//Línea 7
	pixel(y+6,x,x,gric,gric);pixel(y+6,x+1,x+1,neg,neg);pixel(y+6,x+2,x+2,gric,gric);pixel(y+6,x+3,x+3,gric,neg);
	pixel(y+6,x+4,x+4,neg,negc);pixel(y+6,x+5,x+5,gric,neg);pixel(y+6,x+6,x+6,gric,gric);pixel(y+6,x+7,x+7,neg,gric);
	pixel(y+6,x+8,x+10,gric,gric);pixel(y+6,x+11,x+11,gric,neg);pixel(y+6,x+12,x+12,neg,gri);pixel(y+6,x+13,x+13,gric,neg);
	pixel(y+6,x+14,x+17,gric,gric);pixel(y+6,x+18,x+18,gric,neg);pixel(y+6,x+19,x+19,neg,gri);pixel(y+6,x+20,x+20,gric,neg);
	pixel(y+6,x+21,x+21,gric,gric);pixel(y+6,x+22,x+22,neg,gric);pixel(y+6,x+23,x+23,gric,gric);pixel(y+6,x+24,x+24,gric,neg);
	pixel(y+6,x+25,x+25,neg,negc);pixel(y+6,x+26,x+26,gric,neg);pixel(y+6,x+27,x+27,gric,gric);pixel(y+6,x+28,x+28,azu,gric);
	pixel(y+6,x+29,x+29,gric,ver);pixel(y+6,x+30,x+31,gric,gric);
	//Línea 8
	pixel(y+7,x,x,gric,gric);pixel(y+7,x+1,x+1,gric,neg);pixel(y+7,x+2,x+2,neg,neg);pixel(y+7,x+3,x+16,neg,gric);
	pixel(y+7,x+17,x+31,gric,gric);
	//Línea 9
	pixel(y+8,x,x+14,gric,gric);pixel(y+8,x+15,x+16,gric,neg);pixel(y+8,x+17,x+31,gric,gric);
	//Texto
	color(gric,neg);
	gotoxy(x+8,y+9);
	printf("Programa de Manejo");
	gotoxy(x+8,y+10);
	printf("   de Personal");
}
void c_aleatoria(int c_trabajador[])//GENERADOR DE CLAVE
{
	/*----------------------------------------------------------------
	 Mediante esta función nos es posible generar las claves 
	 aleatorias y únicas, es decir, no se repiten ya que las validamos
	 mediante un ciclo para ello; en dado caso que se lleguen 
	 a repetir, les asignamos un nuevo valor y volvemos a evaluar,
	 así susevivamente hasta obtener nuestras claves únicas.
	----------------------------------------------------------------*/
	int h,i,rep;
	for(h=0;h<TRB;h++)
	{
		c_trabajador[h]= 1000 + rand() % 9000;
		do
		{
			rep=0;
			for(i=h;i>0;i--)
			{
				if(c_trabajador[h]==c_trabajador[i-1])
				{
					rep++;
					c_trabajador[h]= 1000 + rand() % 9000;
				}
			}	
		}while(rep>0);
	}
}
void n_aleatorio(char n_trabajador[][MAX])//GENERADOR DE NOMBRE
{
	/*----------------------------------------------------------------
	 Mediante esta función nos es posible generar los nombres 
	 aleatorios. Generamos dos números aleatorios, según el número
	 es el género asignado al nombre, y en ello nos basamos para
	 asignar los 2 de los 32 nombres a los hombre sin repetir, 
	 y los 2 de los 19 nombres de mujer sin repetir, además se 
	 generan los dos apellidos con la diferencia que estos tienen la 
	 posibilidad de repetirse.
	----------------------------------------------------------------*/
	char nombre_h[32][15]={"Francisco","Javier",{'N','i','c','o','l',160,'s','\0'},"Pablo",{'I','s','s','a',161,'\0'},"Brandom",{'A','d','r','i',160,'n','\0'},{'C',130,'s','a','r','\0'},"Emmanuel","Boris",{'I','v',160,'n','\0'},{'B','e','n','j','a','m',161,'n','\0'},"Alejandro",{181,'n','g','e','l','\0'},"Haniel","Enrique","Joab",{'N','o',130,'\0'},{'S','h','a','d','d','a',161,'\0'},{'J','o','s',130,'\0'},"Alfredo","Juan","Luis","Manuel","Aldo",{'R','a',163,'l','\0'},{'R','e','n',130,'\0'},"Paul","Josue",{'S','e','b','a','s','t','i',160,'n','\0'},"Alan","David"};
	char nombre_m[19][15]={{'M','a','r',161,'a','\0'},"Fernanda","Daniela","Evelyn","Vanessa","Yaretzi","Nadia","Itzel","Guadalupe","Karina","Jessica","Ximena","Abril","Rosalinda","Eunice","Andrea","Natalia","Claudia",{'S','o','f',161,'a','\0'}};
	char apellido[35][15]={"Altamira","Mata","Alvarado","Moreno","Aparicio",{'G','u','t','i',130,'r','r','e','z','\0'},"Arrioja",{'P','i','z','a',164,'a'},{'A','v','e','n','d','a',164,'o','\0'},{'L',162,'p','e','z','\0'},{'B','a','r','r',162,'n','\0'},{181,'l','v','a','r','e','z','\0'},"Bernal","Orozco","Amezcua","Castillo","Campos","Aguayo","Corona","Morales","Mota","Cruz","Mora","De Luna","Ortega","Gallo",{'R','a','m',161,'r','e','z','\0'},"Reyna","Franco",{'G','a','r','c',161,'a','\0'},"Tafoya","Flores",{'J','i','m',130,'n','e','z','\0'},{'F','e','r','n',160,'n','d','e','z','\0'},"Aguilar"};
	int h,i,j,rep,genero,n[2],a[2];
	
	for(h=0;h<TRB;h++)
	{
		genero=rand()%2;
		if(genero==0)//Hombre
		{
			for(i=0;i<2;i++)
				{
					n[i] = rand() % 32;
					a[i] = rand() % 35;
					do
					{
						rep=0;
						for(j=i;j>0;j--)
						{
							if(n[i]==n[j-1])
							{
								rep++;
								n[i] = rand() % 32;
							}
						}	
					}
					while(rep>0);
				}
				sprintf(n_trabajador[h],"%s %s %s %s",nombre_h[n[0]],nombre_h[n[1]],apellido[a[0]],apellido[a[1]]);
		}else //Mujer
		{
			for(i=0;i<2;i++)
				{
					n[i] = rand() % 19;
					a[i] = rand() % 35;
					do
					{
						rep=0;
						for(j=i;j>0;j--)
						{
							if(n[i]==n[j-1])
							{
								rep++;
								n[i] = rand() % 32;
							}
						}	
					}
					while(rep>0);
				}
				sprintf(n_trabajador[h],"%s %s %s %s",nombre_m[n[0]],nombre_m[n[1]],apellido[a[0]],apellido[a[1]]);
		}
	}
}
void s_aleatorio(float s_trabajador[])//GENERADOR DE SUELDO
{
	/*----------------------------------------------------------------
	 Mediante esta función nos es posible generar los sueldos 
	 aleatorias, estos se pueden repetir aun que es poco probable,
	 los sueldos van desde los 4,500 hasta los 150,000.
	----------------------------------------------------------------*/
	int h;
	for(h=0;h<TRB;h++)
	{
		s_trabajador[h]= 45000 + rand() % 1455010;
		s_trabajador[h]=s_trabajador[h]/10;
	}
}
void menu(int col[1],int son[1],int c_trabajador[],char n_trabajador[][MAX],float s_trabajador[],int c_reg[])//MENÚ DE EJECUCIÓN
{
	/*----------------------------------------------------------------
	 Ésta función es la funión del menú de opciones de ejecución,
	 ésta función toma la opción a ejecutar, para finalmente 
	 mediante llamar las funciones, ejecuta dicho proceso.
	----------------------------------------------------------------*/
	char opc[MAX];
	do
	{
		system("cls");p_ejecucion(col);
		pixel(6,17,17,col[1],neg);pixel(6,18,18,neg,col[1]);pixel(7,19,45,col[1],neg);
		gotoxy(20,6);color(col[1],neg);printf("MEN%c DEL PROGRAMA\n",233);
		gotoxy(0,8);color(col[1],neg);
		printf("\t\t\ta. Mostrar todos los trabajadores\n");
		printf("\t\t\tb. Buscar un registro\n");
		printf("\t\t\tc. Ordenar registros\n");
		printf("\t\t\td. Insertar nuevos registros\n");
		printf("\t\t\te. Eliminar un registro\n");
		printf("\t\t\tf. Modificar registro\n");
		printf("\t\t\tg. Configuraci%cn %c\n",162,15);
		printf("\t\t\th. ");color(col[1],roj);printf("<- Salir\n\n");
		printf("\t\t%c ",175);
		color(col[1],neg);printf("Ingresa una opci%cn: ",162);
		color(col[1],azuc);scanf("%s", &opc);
		if(strcmp(opc, "a")==0)opc_a(col,son,c_trabajador,n_trabajador,s_trabajador);
		else if(strcmp(opc, "b")==0)opc_b(col,son,c_trabajador,n_trabajador,s_trabajador);
		else if(strcmp(opc, "c")==0)opc_c(col,son,c_trabajador,n_trabajador,s_trabajador);
		else if(strcmp(opc, "d")==0)opc_d(col,son,c_trabajador,n_trabajador,s_trabajador,c_reg);
		else if(strcmp(opc, "e")==0)opc_e(col,son,c_trabajador,n_trabajador,s_trabajador,c_reg);
		else if(strcmp(opc, "f")==0)opc_f(col,son,c_trabajador,n_trabajador,s_trabajador);
		else if(strcmp(opc, "g")==0)config(col,son);
		else if(strcmp(opc, "h")==0)system("cls");
		else {color(col[1],roj);printf("\n\t\t### OPCI%cN INV%cLIDA ###",224,181);printf("%c",son[1]);getch();}
	}while(strcmp(opc,"h")!=0);
	
}
void config(int col[],int son[])//MENÚ DE CONFIGURACIÓN
{
	/*----------------------------------------------------------------
	 La función de configuración, donde se realizan las opciones
	 de interfaz, para mejorar un poco la experiencia del usuario,
	 según la opción que sea elejida, ambia el color a uno más 
	 oscuro, o activa o desactiva los sonidos.
	----------------------------------------------------------------*/
	char e_mod[12];
	char e_son[12];
	char opc[MAX];
	
	do
	{
		system("cls");p_dos(col);pixel(6,17,17,col[1],neg);pixel(6,18,18,neg,col[1]);pixel(7,19,45,col[1],neg);
		gotoxy(20,6);color(col[1],neg);printf("OPCIONES DE INICIO\n");
		gotoxy(0,8);color(col[1],neg);printf("\t\t\ta. Modo osuro");
		if(col[1]==gric)
		{
			strcpy(e_mod,"Desactivado");color(col[1],roj);printf("%c",son[1]);
		}else
		{
			printf(" %c%c",6,son[1]);strcpy(e_mod,"Activado");color(col[1],ver);
		}
		printf("\t\t(%s)\n",e_mod);
		color(col[1],neg);printf("\t\t\tb. Sonido");
		if(son[1]==0)
		{
			strcpy(e_son,"Desactivado");color(col[1],roj);
		}else
		{
			printf(" %c%c",son[1],14);strcpy(e_son,"Activado");color(col[1],ver);
		}
		printf("\t\t(%s)\n",e_son);
		color(col[1],neg);printf("\t\t\tc. ");color(col[1],ama);printf("Continuar ->\n");
		color(col[1],neg);printf("\t\t\td. ");color(col[1],roj);printf("<- Salir\n\n");
		printf("\t\t%c ",175);color(col[1],neg);printf("Ingresa una opci%cn: ",162);
		color(col[1],azuc);scanf("%s", &opc);
		if(strcmp(opc, "a")==0)
		{
				if(col[1]==gric)
				{	
					col[1]=negc;
				}else
				{
					col[1]=gric;
				}	
		}
		else if(strcmp(opc, "b")==0)
		{
				if(son[1]==0)
				{	
					son[1]=7;
				}else
				{
					son[1]=0;
				}	
		}
		else if(strcmp(opc, "c")==0)
		{
		}
		else if(strcmp(opc, "d")==0)
		{
			system("cls");p_final();getch();exit (0);	
		}
		else
		{
			color(col[1],roj);printf("\n\t\t### OPCI%cN INV%cLIDA ###",224,181);getch();
		}
	}while(strcmp(opc, "c")!=0);
	
}
void mostrar(int col[],int c_trabajador[],char n_trabajador[][MAX],float s_trabajador[])//FUNCIÓN DE APOYO PARA MOSTRAR CADENAS
{
	/*----------------------------------------------------------------
	 Mediante esta función nos es posible imprimir los datos del
	 trabajador, muy útil ya que su uso es frecuente a lo largo
	 de la ejecución del programa.
	----------------------------------------------------------------*/
	int i,reg=TRB,rep=0;
	gotoxy(0,8);color(roj,col[1]);printf("\n\t\t CLAVE                 NOMBRE                    SUELDO  \n");
	for(i=0;i<TRB;i++)if(c_trabajador[i]==0)reg--;
	color(col[1],rojc);
	if(reg==0)printf("\n\t\t                   (Sin registros)\n");
	else
	{
		color(col[1],neg);
		for(i=0;i<TRB;i++)
		{
			if(c_trabajador[i]==0);
			else
			{
				printf("\t\t #%i\t %s",c_trabajador[i],n_trabajador[i]);
				gotoxy(64,10+rep);printf("$%.2f\n",s_trabajador[i]);
				rep++;
			}
		}
	}
}
void opc_a(int col[],int son[],int c_trabajador[],char n_trabajador[][MAX],float s_trabajador[])//FUNCIÓN PARA MOSTRAR CADENAS
{
	/*----------------------------------------------------------------
	 Función donde sólo nos muestra nuestro listado de datos.
	----------------------------------------------------------------*/
	system("cls");
	p_ejecucion(col);
	pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
	gotoxy(20,6);color(col[1],neg);printf("MOSTRAR TRABAJADORES\n",233);
	mostrar(col,c_trabajador,n_trabajador,s_trabajador);printf("%c",son[1]);
	getch();
}
void opc_b(int col[],int son[],int c_trabajador[],char n_trabajador[][MAX],float s_trabajador[])//FUNCIÓN PARA BUSCAR CADENAS
{
	/*----------------------------------------------------------------
	 Función donde si ingresamos la clave, o el nombre del trabajador
	 nos mostrara un resumen del mismo, si los datos son mal
	 ingresados, mostrará mensaje de error.
	----------------------------------------------------------------*/
	char opc[MAX];
	int i,bus,opcn;
	do
	{
		system("cls");
		p_ejecucion(col);bus=-1;
		pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
		gotoxy(20,6);color(col[1],neg);printf("BUSCAR REGISTRO\n",233);
		gotoxy(0,8);color(col[1],neg);
		printf("\t\t\ta. Por nombre\n");
		printf("\t\t\tb. Por clave\n");
		printf("\t\t\tc. ");color(col[1],ver);printf("<- Regresar\n\n");color(col[1],roj);
		printf("\t\t%c ",175);color(col[1],neg);printf("Ingresa una opci%cn: ",162);
		color(col[1],azuc);scanf("%s", &opc);
		if(strcmp(opc, "a")==0)
		{
			system("cls");
			p_ejecucion(col);
			pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
			gotoxy(20,6);color(col[1],neg);printf("BUSCAR REGISTRO (Nombre)\n",233);
			mostrar(col,c_trabajador,n_trabajador,s_trabajador);
			color(col[1],roj);printf("\n\t\t%c ",175);color(col[1],neg);printf("Ingresa el nombre: ",162);
			color(col[1],azuc);fflush(stdin);gets(opc);
			for(i=0;i<TRB;i++)
			{
				if(strcmp(opc,n_trabajador[i])==0)
				{
					bus=i;
				}
			}
			if(bus==-1)
			{
				system("cls");
				p_ejecucion(col);
				pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
				gotoxy(20,6);color(col[1],neg);printf("BUSCAR REGISTRO (Nombre)\n",233);
				gotoxy(0,8);color(col[1],roj);
				printf("\n\t\t   ### NO ENCONTRADO ###");printf("%c",son[1]);
			}
			else
			{
				system("cls");
				p_ejecucion(col);
				pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
				gotoxy(20,6);color(col[1],neg);printf("BUSCAR REGISTRO (Nombre)\n",233);
				gotoxy(0,8);
				color(col[1],roj);printf("\n\t\t CLAVE:  ");color(col[1],azu);printf("%i",c_trabajador[bus]);
				color(col[1],roj);printf("\n\t\t NOMBRE: ");color(col[1],azu);printf("%s",n_trabajador[bus]);
				color(col[1],roj);printf("\n\t\t SUELDO: ");color(col[1],azu);printf("$%.2f",s_trabajador[bus]);printf("%c",son[1]);
			}
			getch();
		}
		else if(strcmp(opc, "b")==0)
		{
			system("cls");
			p_ejecucion(col);
			pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
			gotoxy(20,6);color(col[1],neg);printf("BUSCAR REGISTRO (Clave)\n",233);
			gotoxy(0,8);color(col[1],neg);
			mostrar(col,c_trabajador,n_trabajador,s_trabajador);
			color(col[1],roj);printf("\n\t\t%c ",175);
			color(col[1],neg);printf("Ingresa el clave: ",162);
			color(col[1],azuc);scanf("%i",&opcn);
			for(i=0;i<TRB;i++)
			{
				if(opcn==c_trabajador[i])
				{
					bus=i;
				}
			}
			if(bus==-1)
			{
				system("cls");
				p_ejecucion(col);
				pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
				gotoxy(20,6);color(col[1],neg);printf("BUSCAR REGISTRO (Nombre)\n",233);
				gotoxy(0,8);color(col[1],roj);
				printf("\n\t\t   ### NO ENCONTRADO ###");printf("%c",son[1]);
			}else
			{
				system("cls");
				p_ejecucion(col);
				pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
				gotoxy(20,6);color(col[1],neg);printf("BUSCAR REGISTRO (Nombre)\n",233);
				gotoxy(0,8);
				color(col[1],roj);printf("\n\t\t CLAVE:  ");color(col[1],azu);printf("%i",c_trabajador[bus]);
				color(col[1],roj);printf("\n\t\t NOMBRE: ");color(col[1],azu);printf("%s",n_trabajador[bus]);
				color(col[1],roj);printf("\n\t\t SUELDO: ");color(col[1],azu);printf("$%.2f",s_trabajador[bus]);printf("%c",son[1]);
			}
			getch();
		}
		else if (strcmp(opc, "c")==0);
		else {color(col[1],roj);printf("\n\t\t  ### OPCI%cN INV%cLIDA ###",224,181);printf("%c",son[1]);getch();}
	}while(strcmp(opc,"c")!=0);
}
void opc_c(int col[],int son[],int c_trabajador[],char n_trabajador[][MAX],float s_trabajador[])//FUNCIÓN PARA ORDENAR CADENAS
{
	/*----------------------------------------------------------------
	 Función donde nos es posible ordenar ya sea por nombre
	 (alfabeticamente), por clave (de menor a mayor), o por sueldo
	 (de mayor a menor) los trabajdores existentes.
	----------------------------------------------------------------*/
	int i,j,aux;
	char opc[MAX];
	int cla[TRB];
	char nom[TRB][MAX];
	float auxf,sld[TRB];
	char caux[MAX];
	
	do
	{
		system("cls");
		p_ejecucion(col);
		pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
		gotoxy(20,6);color(col[1],neg);printf("ORDENAR REGISTRO\n",233);
		gotoxy(0,8);color(col[1],neg);
		printf("\t\t\ta. Por nombre\n");
		printf("\t\t\tb. Por clave\n");
		printf("\t\t\tc. Por salario\n");
		printf("\t\t\td. ");color(col[1],ver);printf("<- Regresar\n\n");color(col[1],roj);
		printf("\t\t%c ",175);color(col[1],neg);printf("Ingresa una opci%cn: ",162);
		color(col[1],azuc);scanf("%s", &opc);
		for(i=0;i<TRB;i++)
		{
			strcpy(nom[i],n_trabajador[i]);
			cla[i]=c_trabajador[i];
			sld[i]=s_trabajador[i];
		}
		if(strcmp(opc, "a")==0)
		{
			system("cls");
			p_ejecucion(col);
			pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
			gotoxy(20,6);color(col[1],neg);printf("ORDENAR REGISTRO (Nombre)\n",233);
			gotoxy(0,8);color(col[1],neg);
			for(i=0;i<TRB-1;i++)
			{
				for(j=0;j<TRB-1;j++)
				{
					if(strcmp(nom[j],nom[j+1])==1)
					{
						strcpy(caux,nom[j+1]);
						strcpy(nom[j+1],nom[j]);
						strcpy(nom[j],caux);
						aux=cla[j+1];
						cla[j+1]=cla[j];
						cla[j]=aux;
						auxf=sld[j+1];
						sld[j+1]=sld[j];
						sld[j]=auxf;
					}
				}
			}
			mostrar(col,cla,nom,sld);printf("%c",son[1]);
			getch();
		}
		else if(strcmp(opc, "b")==0)
		{
			system("cls");
			p_ejecucion(col);
			pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
			gotoxy(20,6);color(col[1],neg);printf("ORDENAR REGISTRO (Clave)\n",233);
			gotoxy(0,8);color(col[1],neg);
			for(i=0;i<TRB-1;i++)
			{
				for(j=0;j<TRB-1;j++)
				{
					if(cla[j]>cla[j+1])
					{
						strcpy(caux,nom[j+1]);
						strcpy(nom[j+1],nom[j]);
						strcpy(nom[j],caux);
						aux=cla[j+1];
						cla[j+1]=cla[j];
						cla[j]=aux;
						auxf=sld[j+1];
						sld[j+1]=sld[j];
						sld[j]=auxf;
					}
				}
			}
			mostrar(col,cla,nom,sld);printf("%c",son[1]);
			getch();
		}else if (strcmp(opc, "c")==0)
		{
			system("cls");
			p_ejecucion(col);
			pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
			gotoxy(20,6);color(col[1],neg);printf("ORDENAR REGISTRO (Salario)\n",233);
			gotoxy(0,8);color(col[1],neg);
			for(i=0;i<TRB-1;i++)
			{
				for(j=0;j<TRB-1;j++)
				{
					if(sld[j]<sld[j+1])
					{
						strcpy(caux,nom[j+1]);
						strcpy(nom[j+1],nom[j]);
						strcpy(nom[j],caux);
						aux=cla[j+1];
						cla[j+1]=cla[j];
						cla[j]=aux;
						auxf=sld[j+1];
						sld[j+1]=sld[j];
						sld[j]=auxf;
					}
				}
			}
			mostrar(col,cla,nom,sld);printf("%c",son[1]);
			getch();
		}else if (strcmp(opc, "d")==0);
		else {color(col[1],roj);printf("\n\t\t### OPCI%cN INV%cLIDA ###",224,181);printf("%c",son[1]);getch();}
	}while(strcmp(opc,"d")!=0);
}
void opc_d(int col[],int son[],int c_trabajador[],char n_trabajador[][MAX],float s_trabajador[],int c_reg[])//FUNCIÓN PARA INSERTAR CADENAS
{
	/*----------------------------------------------------------------
	 Función donde se nos es posible ingresar un nuevo trabajador,
	 para ello es necesario tener libre al menor 1 espacio, de no 
	 ser así, mostrará mensahe de error y pedirá liberar un espacio.
	----------------------------------------------------------------*/
	char opc[MAX];
	int err,i,reg,cla;
	char nom [MAX];
	float sld;
	do
	{
		system("cls");
		reg=TRB-c_reg[1];
		p_ejecucion(col);
		pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
		gotoxy(20,6);color(col[1],neg);printf("INSERTAR REGISTRO\n",233);
		gotoxy(0,8);color(col[1],neg);
		if(c_reg[1]==TRB)
		{	
			color(col[1],roj);
			printf("\n\t\t    ### REGISTROS LLENOS ###");
			printf("\n\t      Borra registros para ingresar nuevos...");printf("%c",son[1]);getch();
			strcpy(opc,"b");
		}else
		{
			printf("\t\t\ta. A%cadir\n",164);
			printf("\t\t\tb. ");color(col[1],ver);printf("<- Regresar\n\n");color(col[1],roj);
			printf("\t\t%c ",175);color(col[1],neg);printf("Ingresa una opci%cn: ",162);
			color(col[1],azuc);scanf("%s", &opc);
			if(strcmp(opc,"a")==0)
			{
				do
				{
					system("cls");
					p_ejecucion(col);err=0;
					pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
					gotoxy(20,6);color(col[1],neg);printf("INSERTAR REGISTRO\n",233);
					color(col[1],ver);printf("\n\t\t   HAY %i REGISTROS DISPONIBLES.",reg);
					color(col[1],roj);printf("\n\n\t\t%c ",175);color(col[1],neg);printf("Ingresa clave: ",162);
					color(col[1],azuc);scanf("%i",&cla);
					if(cla<1000 || cla>9999)
					{
						color(col[1],roj);printf("\n\t\t### DEBE SER MAYOR A 1000 Y MENOR A 9999 ###",224,181);err=1;printf("%c",son[1]);
						getch();
					}
					else
					{
						for(i=0;i<TRB;i++)
						{
							if(cla==c_trabajador[i])
							{
								err=1;
							}
						}
						if(err==1)
						{
							color(col[1],roj);printf("\n\t\t### CLAVE YA EXISTENTE ###",224,181);printf("%c",son[1]);
							getch();
						}
					}
				}while(err==1);
				color(col[1],roj);printf("\n\t\t%c ",175);color(col[1],neg);printf("Ingresa nombre: ",162);
				color(col[1],azuc);fflush(stdin);gets(nom);
				color(col[1],roj);printf("\n\t\t%c ",175);color(col[1],neg);printf("Ingresa sueldo: ",162);
				color(col[1],azuc);scanf("%f",&sld);
				c_trabajador[TRB-reg]=cla;
				s_trabajador[TRB-reg]=sld;
				strcpy(n_trabajador[TRB-reg],nom);
				c_reg[1]++;printf("%c",son[1]);
				color(col[1],ver);printf("\n\t\t + + + A%cADIDO + + +",165);printf("%c",son[1]);
				getch();
			}else if(strcmp(opc,"b")==0);
			else {color(col[1],roj);printf("\n\t\t### OPCI%cN INV%cLIDA ###",224,181);printf("%c",son[1]);getch();}
		}	
	}while(strcmp(opc,"b")!=0);
}
void opc_e(int col[],int son[],int c_trabajador[],char n_trabajador[][MAX],float s_trabajador[],int c_reg[])//FUNCIÓN PARA ELIMINAR CADENAS
{
	/*----------------------------------------------------------------
	 Función donde mediante la búsqueda de un trabajador por su nombre
	 o clave, se nos permite borrar los datos de dicho trabajador.
	----------------------------------------------------------------*/
	char opc[MAX];
	int i,bus,opcn;
	do
	{
		system("cls");
		p_ejecucion(col);bus=-1;
		pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
		gotoxy(20,6);color(col[1],neg);printf("ELIMINAR REGISTRO\n",233);
		gotoxy(0,8);color(col[1],neg);
		printf("\t\t\ta. Por nombre\n");
		printf("\t\t\tb. Por clave\n");
		printf("\t\t\tc. ");color(col[1],ver);printf("<- Regresar\n\n");color(col[1],roj);
		printf("\t\t%c ",175);color(col[1],neg);printf("Ingresa una opci%cn: ",162);
		color(col[1],azuc);scanf("%s", &opc);
		if(strcmp(opc, "a")==0)
		{
			system("cls");
			p_ejecucion(col);
			pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
			gotoxy(20,6);color(col[1],neg);printf("ELIMINAR REGISTRO (Nombre)\n",233);
			gotoxy(0,8);color(col[1],neg);
			mostrar(col,c_trabajador,n_trabajador,s_trabajador);
			color(col[1],roj);printf("\n\t\t%c ",175);
			color(col[1],neg);printf("Ingresa el nombre: ",162);
			color(col[1],azuc);fflush(stdin);gets(opc);
			for(i=0;i<TRB;i++)
			{
				if(strcmp(opc,n_trabajador[i])==0)
				{
					bus=i;
				}
			}
			if(bus==-1)
			{
				system("cls");
				p_ejecucion(col);
				pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
				gotoxy(20,6);color(col[1],neg);printf("ELIMINAR REGISTRO (Nombre)\n",233);
				gotoxy(0,8);color(col[1],roj);
				printf("\n\t\t   ### NO EXISTENTE ###");printf("%c",son[1]);
			}else
			{
				system("cls");
				p_ejecucion(col);
				pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
				gotoxy(20,6);color(col[1],neg);printf("ELIMINAR REGISTRO (Nombre)\n",233);
				gotoxy(0,8);color(col[1],roj);
				for(i=bus;i<TRB-1;i++)
				{
					strcpy(n_trabajador[i],n_trabajador[i+1]);
					c_trabajador[i]=c_trabajador[i+1];
					s_trabajador[i]=s_trabajador[i+1];
				}
				strcpy(n_trabajador[c_reg[1]-1],"");
				c_trabajador[c_reg[1]-1]= 0;
				s_trabajador[c_reg[1]-1]= 0;
				c_reg[1]--;
				color(col[1],roj);printf("\n\t\t   - - - ELIMINADO - - -");printf("%c",son[1]);
			}
			getch();
		}
		else if(strcmp(opc, "b")==0)
		{
			system("cls");
			p_ejecucion(col);
			pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
			gotoxy(20,6);color(col[1],neg);printf("ELIMINAR REGISTRO (Clave)\n",233);
			gotoxy(0,8);color(col[1],neg);
			mostrar(col,c_trabajador,n_trabajador,s_trabajador);
			color(col[1],roj);printf("\n\t\t%c ",175);
			color(col[1],neg);printf("Ingresa el clave: ",162);
			color(col[1],azuc);scanf("%i",&opcn);
			for(i=0;i<TRB;i++)
			{
				if(opcn==c_trabajador[i])
				{
					bus=i;
				}
			}
			if(bus==-1)
			{
				system("cls");
				p_ejecucion(col);
				pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
				gotoxy(20,6);color(col[1],neg);printf("ELIMINAR REGISTRO (Clave)\n",233);
				gotoxy(0,8);color(col[1],roj);
				printf("\n\t\t   ### NO EXISTENTE ###");printf("%c",son[1]);
			}else
			{
				system("cls");
				p_ejecucion(col);
				pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
				gotoxy(20,6);color(col[1],neg);printf("ELIMINAR REGISTRO (Clave)\n",233);
				gotoxy(0,8);color(col[1],roj);
				for(i=bus;i<TRB-1;i++)
				{
					strcpy(n_trabajador[i],n_trabajador[i+1]);
					c_trabajador[i]=c_trabajador[i+1];
					s_trabajador[i]=s_trabajador[i+1];
				}
				strcpy(n_trabajador[c_reg[1]-1],"");
				c_trabajador[c_reg[1]-1]= 0;
				s_trabajador[c_reg[1]-1]= 0;
				c_reg[1]--;
				color(col[1],roj);printf("\n\t\t   - - - ELIMINADO - - -");printf("%c",son[1]);
			}
			getch();
		}else if (strcmp(opc, "c")==0);
		else {color(col[1],roj);printf("\n\t\t### OPCI%cN INV%cLIDA ###",224,181);printf("%c",son[1]);getch();}
	}while(strcmp(opc,"c")!=0);
}
void opc_f(int col[],int son[],int c_trabajador[],char n_trabajador[][MAX],float s_trabajador[])//FUNIÓN PARA MODIFICAR CADENAS
{
	/*----------------------------------------------------------------
	 Función donde es posible la modificación de alguno de los datos
	 de un trabajador, para ello primero lo buscamos mediante su
	 clave o nombre, después se despliagan las opciones para 
	 determinarque tipo de dato es el que se va a modificar.
	----------------------------------------------------------------*/
	char opc[MAX];
	int i,b,cla,err,opcn;
	do
	{
		system("cls");
		p_ejecucion(col);b=-1;
		pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
		gotoxy(20,6);color(col[1],neg);printf("MODIFICAR REGISTRO\n",233);
		gotoxy(0,8);color(col[1],neg);
		printf("\t\t\ta. Buscar por nombre\n");
		printf("\t\t\tb. Buscar por clave\n");
		printf("\t\t\tc. ");color(col[1],ver);printf("<- Regresar\n\n");color(col[1],roj);
		printf("\t\t%c ",175);color(col[1],neg);printf("Ingresa una opci%cn: ",162);
		color(col[1],azuc);scanf("%s", &opc);
		if(strcmp(opc, "a")==0)
		{
			system("cls");
			p_ejecucion(col);
			pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
			gotoxy(20,6);color(col[1],neg);printf("MODIFICAR REGISTRO \n",233);
			gotoxy(0,8);color(col[1],neg);
			mostrar(col,c_trabajador,n_trabajador,s_trabajador);
			color(col[1],roj);printf("\n\t\t%c ",175);
			color(col[1],neg);printf("Ingresa el nombre: ",162);
			color(col[1],azuc);fflush(stdin);gets(opc);
			for(i=0;i<TRB;i++)
			{
				if(strcmp(opc,n_trabajador[i])==0)
				{
					b=i;
				}
			}
			if(b==-1)
			{
				system("cls");
				p_ejecucion(col);
				pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
				gotoxy(20,6);color(col[1],neg);printf("MODIFICAR REGISTRO \n",233);
				gotoxy(0,8);color(col[1],roj);
				printf("\n\t\t   ### NO EXISTENTE ###");printf("%c",son[1]);getch();
			}else
			{
				do
				{
					system("cls");
					p_ejecucion(col);
					pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
					gotoxy(20,6);color(col[1],neg);printf("MODIFICAR REGISTRO \n",233);
					gotoxy(0,8);printf("\t\t\ta. Modificar nombre\n");
					printf("\t\t\tb. Modificar clave\n");
					printf("\t\t\tc. Modificar salario\n");
					printf("\t\t\td. ");color(col[1],ver);printf("<- Regresar\n\n");
					color(col[1],roj);
					printf("\t\t%c ",175);color(col[1],neg);printf("Ingresa una opci%cn: ",162);
					color(col[1],azuc);scanf("%s", &opc);
					if(strcmp(opc,"a")==0)
					{
						system("cls");
						p_ejecucion(col);
						pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
						gotoxy(20,6);color(col[1],neg);printf("MODIFICAR REGISTRO (Nombre) \n",233);
						color(col[1],roj);printf("\n\t\t CLAVE:  ");color(col[1],azu);printf("%i",c_trabajador[b]);
						color(col[1],roj);printf("\n\t\t NOMBRE: ");color(col[1],azu);printf("%s",n_trabajador[b]);
						color(col[1],roj);printf("\n\t\t SUELDO: ");color(col[1],azu);printf("$%.2f",s_trabajador[b]);
						color(col[1],roj);
						printf("\n\n\t\t%c ",175);color(col[1],neg);printf("Ingresa nombre: ",162);
						color(col[1],azuc);fflush(stdin);gets(n_trabajador[b]);
						color(col[1],ver);printf("\n\t\tMODIFICADO.");printf("%c",son[1]);getch();
					}else if(strcmp(opc,"b")==0)
					{
						do
						{
							system("cls");err=0;
							p_ejecucion(col);
							pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
							gotoxy(20,6);color(col[1],neg);printf("MODIFICAR REGISTRO (Clave)\n",233);
							color(col[1],roj);printf("\n\t\t CLAVE:  ");color(col[1],azu);printf("%i",c_trabajador[b]);
							color(col[1],roj);printf("\n\t\t NOMBRE: ");color(col[1],azu);printf("%s",n_trabajador[b]);
							color(col[1],roj);printf("\n\t\t SUELDO: ");color(col[1],azu);printf("$%.2f",s_trabajador[b]);
							color(col[1],roj);
							printf("\n\n\t\t%c ",175);color(col[1],neg);printf("Ingresa clave: ",162);
							color(col[1],azuc);scanf("%i",&cla);
							if(cla<1000 || cla>9999)
							{
								color(col[1],roj);printf("\n\t\t### DEBE SER MAYOR A 1000 Y MENOR A 9999 ###",224,181);err=1;printf("%c",son[1]);
								getch();
							}
							else
							{
								for(i=0;i<TRB;i++)
								{
									if(cla==c_trabajador[i])
									{
										err=1;
									}
								}
								if(err==1)
								{
									color(col[1],roj);printf("\n\t\t### CLAVE YA EXISTENTE ###",224,181);printf("%c",son[1]);
									getch();
								}
							}
						}while(err==1);
						c_trabajador[b]=cla;
						color(col[1],ver);printf("\n\t\tMODIFICADO.");printf("%c",son[1]);getch();
					}else if(strcmp(opc,"c")==0)
					{
						system("cls");
						p_ejecucion(col);
						pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
						gotoxy(20,6);color(col[1],neg);printf("MODIFICAR REGISTRO (Sueldo)\n",233);
						color(col[1],roj);printf("\n\t\t CLAVE:  ");color(col[1],azu);printf("%i",c_trabajador[b]);
						color(col[1],roj);printf("\n\t\t NOMBRE: ");color(col[1],azu);printf("%s",n_trabajador[b]);
						color(col[1],roj);printf("\n\t\t SUELDO: ");color(col[1],azu);printf("$%.2f",s_trabajador[b]);
						color(col[1],roj);
						printf("\n\n\t\t%c ",175);
						color(col[1],neg);printf("Ingresa sueldo: ",162);
						color(col[1],azuc);scanf("%f",&s_trabajador[b]);
						color(col[1],ver);printf("\n\t\tMODIFICADO.");printf("%c",son[1]);getch();
					}else if(strcmp(opc,"d")==0);
					else {color(col[1],roj);printf("\n\t\t### OPCI%cN INV%cLIDA ###",224,181);printf("%c",son[1]);getch();}
				}while(strcmp(opc,"d")!=0);
					
			}
		}
		else if(strcmp(opc, "b")==0)
		{
			system("cls");
			p_ejecucion(col);
			pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
			gotoxy(20,6);color(col[1],neg);printf("MODIFICAR REGISTRO \n",233);
			gotoxy(0,8);color(col[1],neg);
			mostrar(col,c_trabajador,n_trabajador,s_trabajador);
			color(col[1],roj);printf("\n\t\t%c ",175);
			color(col[1],neg);printf("Ingresa la clave: ",162);
			color(col[1],azuc);scanf("%i",&opcn);
			for(i=0;i<TRB;i++)
			{
				if(opcn==c_trabajador[i])
				{
					b=i;
				}
			}
			if(b==-1)
			{
				system("cls");
				p_ejecucion(col);
				pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
				gotoxy(20,6);color(col[1],neg);printf("MODIFICAR REGISTRO \n",233);
				gotoxy(0,8);color(col[1],roj);
				printf("\n\t\t   ### NO EXISTENTE ###");printf("%c",son[1]);getch();
			}else
			{
				do
				{
					system("cls");
					p_ejecucion(col);
					pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
					gotoxy(20,6);color(col[1],neg);printf("MODIFICAR REGISTRO \n",233);
					gotoxy(0,8);printf("\t\t\ta. Modificar nombre\n");
					printf("\t\t\tb. Modificar clave\n");
					printf("\t\t\tc. Modificar salario\n");
					printf("\t\t\td. ");color(col[1],ver);printf("<- Regresar\n\n");
					color(col[1],roj);
					printf("\t\t%c ",175);color(col[1],neg);printf("Ingresa una opci%cn: ",162);
					color(col[1],azuc);scanf("%s", &opc);
					if(strcmp(opc,"a")==0)
					{
						system("cls");
						p_ejecucion(col);
						pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
						gotoxy(20,6);color(col[1],neg);printf("MODIFICAR REGISTRO (Nombre) \n",233);
						color(col[1],roj);printf("\n\t\t CLAVE:  ");color(col[1],azu);printf("%i",c_trabajador[b]);
						color(col[1],roj);printf("\n\t\t NOMBRE: ");color(col[1],azu);printf("%s",n_trabajador[b]);
						color(col[1],roj);printf("\n\t\t SUELDO: ");color(col[1],azu);printf("$%.2f",s_trabajador[b]);
						color(col[1],roj);
						printf("\n\n\t\t%c ",175);color(col[1],neg);printf("Ingresa nombre: ",162);
						color(col[1],azuc);fflush(stdin);gets(n_trabajador[b]);
						color(col[1],ver);printf("\n\t\tMODIFICADO.");printf("%c",son[1]);getch();
					}else if(strcmp(opc,"b")==0)
					{
						do
						{
							system("cls");
							p_ejecucion(col);
							pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
							gotoxy(20,6);color(col[1],neg);printf("MODIFICAR REGISTRO (Clave)\n",233);
							color(col[1],roj);printf("\n\t\t CLAVE:  ");color(col[1],azu);printf("%i",c_trabajador[b]);
							color(col[1],roj);printf("\n\t\t NOMBRE: ");color(col[1],azu);printf("%s",n_trabajador[b]);
							color(col[1],roj);printf("\n\t\t SUELDO: ");color(col[1],azu);printf("$%.2f",s_trabajador[b]);
							color(col[1],roj);
							printf("\n\n\t\t%c ",175);color(col[1],neg);printf("Ingresa clave: ",162);
							color(col[1],azuc);scanf("%i",&cla);
							if(cla<1000 || cla>9999)
							{
								color(col[1],roj);printf("\t\t\n### DEBE SER MAYOR A 1000 Y MENOR A 9999 ###",224,181);err=1;printf("%c",son[1]);
								getch();
							}
							else
							{
								for(i=0;i<TRB;i++)
								{
									if(cla==c_trabajador[i])
									{
										err=1;
									}
								}
								if(err==1)
								{
									color(col[1],roj);printf("\t\t\n### CLAVE YA EXISTENTE ###",224,181);printf("%c",son[1]);
									getch();
								}
							}
						}while(err==1);
						c_trabajador[b]=cla;
						color(col[1],ver);printf("\n\t\tMODIFICADO.");printf("%c",son[1]);getch();
					}else if(strcmp(opc,"c")==0)
					{
						system("cls");
						p_ejecucion(col);
						pixel(6,17,17,col[1],gri);pixel(6,18,18,gri,col[1]);pixel(7,19,45,col[1],gri);
						gotoxy(20,6);color(col[1],neg);printf("MODIFICAR REGISTRO (Sueldo)\n",233);
						color(col[1],roj);printf("\n\t\t CLAVE:  ");color(col[1],azu);printf("%i",c_trabajador[b]);
						color(col[1],roj);printf("\n\t\t NOMBRE: ");color(col[1],azu);printf("%s",n_trabajador[b]);
						color(col[1],roj);printf("\n\t\t SUELDO: ");color(col[1],azu);printf("$%.2f",s_trabajador[b]);
						color(col[1],roj);
						printf("\n\n\t\t%c ",175);
						color(col[1],neg);printf("Ingresa sueldo: ",162);
						color(col[1],azuc);scanf("%f",&s_trabajador[b]);
						color(col[1],ver);printf("\n\t\tMODIFICADO.");printf("%c",son[1]);getch();
					}else if(strcmp(opc,"d")==0);
					else {color(col[1],roj);printf("\n\t\t### OPCI%cN INV%cLIDA ###",224,181);getch();printf("%c",son[1]);}
				}while(strcmp(opc,"d")!=0);
			}
		}else if (strcmp(opc, "c")==0);
		else {color(col[1],roj);printf("\n\t\t### OPCI%cN INV%cLIDA ###",224,181);printf("%c",son[1]);getch();}
	}while(strcmp(opc,"c")!=0);
}
int main()
{
	/*----------------------------------------------------------------
	 Función principal, en la cual se determina el orden para
	 la realización de cada una de las funciones, en nuestro caso
	 es muy corta, ya que usamos bastantes funciones para un mayor 
	 orden.
	----------------------------------------------------------------*/
	int col[1];
	int son[1];
	int c_trabajador[TRB];
	char n_trabajador[TRB][MAX];
	float s_trabajador[TRB];
	int c_reg[1];
	c_reg[1]=TRB;
	col[1]=gric;son[1]=0;
	
	//GENERACIÓN DE NÚMEROS ALEATORIOS
	srand(time(NULL));
	c_aleatoria(c_trabajador);
	n_aleatorio(n_trabajador);
	s_aleatorio(s_trabajador);
	//PANTALLA DE INICIO
	p_inicial();logo(86,8);getch();
	//PANTALLA DE PRESENTACIÓN
	system("cls");p_uno();getch();
	//PANTALLA DE CONFIGURACIÓN
	system("cls");config(col,son);
	//PANTALLA DE MENÚ
	menu(col,son,c_trabajador,n_trabajador,s_trabajador,c_reg);
	//PANTALLA FINAL
	p_final();getch();
}
