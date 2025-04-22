/*
    --------------------------------------------------------------------------------------
    LENGUAJES DE COMPUTACI√ìN II                                               07|02|2023
    --------------------------------------------------------------------------------------
    Programa: RepasoPOO.cpp                            Alumnos: 
                                                            Luis Pablo Esparza Terrones
                                                            Juan Francisco Gallo Ramirez
                                                            Pablo Alvarado Moreno
                                                            Luis Manuel Flores JimÈnez
    Objetivo:
        Por parejas, construya un programa con POO en C++ que obtenga el 
        √°rea y el per√≠metro de un Rect√°ngulo, un Cuadrado, un Circulo y un Tri√°ngulo. 
        (Realice un men√∫ para que el usuario indique cu√°l figura desea y la ultima opci√≥n que sea Salir del men√∫).
        No olvide que debe incluir todos o la mayor√≠a de los conceptos vistos en clases: 
        clase, atributos, m√©todos, m√©todo constructor, objeto (s), get, set, herencia, polimorfismo.
*/

#include <iostream>
#include <math.h>
#include <conio.h>
#include <windows.h>

#define PI 3.14159265359
const char S=175, P=16, C=2;

using namespace std;

//--------------------------< CLASE #1    RECT¡NGULO  >---
class Rectangl
{
protected:
    double height;
    double base;
public:
    virtual void set(double, double);
    virtual double getArea();
    virtual double getPerimeter();

};

void Rectangl::set(double _height, double _base)
{
    height = _height;
    base = _base;
}

double Rectangl::getArea()
{
    double area;
    area = height * base;
    return area;
}

double Rectangl::getPerimeter()
{
    double perimeter;
    perimeter = (height * 2) + (base * 2);
    return perimeter;
}
//--------------------------< CLASE #1    RECT¡NGULO  >---
//--------------------------< SUBCLASE #1  CUADRADO   >---
class Square :public Rectangl
{
public:
    double getArea();
    double getPerimeter();
    void set(double);
};

void Square::set(double _base)
{
    base = _base;
}

double Square::getArea()
{
    double area;
    area = pow(base,2);
    return area;
}

double Square::getPerimeter()
{
    double perimeter;
    perimeter = base * 4;
    return perimeter;
}
//--------------------------< CLASE #1    RECT¡NGULO  >---
//--------------------------< SUBCLASE #1  TRI¡NGULO  >---
class Triangle :public Rectangl
{
public:
    double getArea();
    double getPerimeter();
    void set(double,double);
};

void Triangle::set(double _height, double _base)
{
    height = _height;
    base = _base;
}

double Triangle::getArea()
{
    double area;
    area = (height * base) / 2;
    return area;
}

double Triangle::getPerimeter()
{
    double perimeter;
    perimeter = base * 3;
    return perimeter;
}
//--------------------------< CLASE #2     CÕRCULO    >---
class Circle
{
private:
    double diameter;
public:
    double getArea();
    double getPerimeter();
    void set(double);
};

void Circle::set(double _diameter)
{
    diameter = _diameter;
}

double Circle::getArea()
{
    double area;
    double radius = diameter / 2;
    area = PI * pow(radius, 2);
    return area;
}

double Circle::getPerimeter()
{
    double perimeter;
    perimeter = PI * diameter;
    return perimeter;
}
//==========================(   FUNCI”N PARA COLOR    )===
void color(int c_fondo,int c_texto)
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}
//==========================(    FUNCI”N PRINCIPAL    )===
int main()
{
    int option;
    double height, base;
    double diameter;
    
    Rectangl _rectangle;
	Square _square;
    Triangle _triangle;
    Circle _circle;
    
    system("color F0");
    do
    {
    	system("cls");
    	color(0,15);cout<<"               AREAS AND PERIMETERS               \n";
    	color(7,0); cout<<"                  - Calculator -                  \n"<<endl;
    	color(15,0);cout<<"\tShapes:\n\n";
    	color(15,4);cout<<"\t  1. ";color(15,0);cout<<"Square\n";
    	color(15,1);cout<<"\t  2. ";color(15,0);cout<<"Rectangle\n";
    	color(15,2);cout<<"\t  3. ";color(15,0);cout<<"Equilateral Triangle\n";
    	color(15,6);cout<<"\t  4. ";color(15,0);cout<<"Circle\n";
    	color(15,12);cout<<"\t  5. ";cout<<"<- Exit\n\n";
    	color(15,5);cout<<"\t"<<S;color(15,0);cout<<" What's your selection?: ";
    	color(15,5);cin>>option;
    	switch(option)
    	{
    		case 1:
    			system("cls");
    			color(0,15);cout<<"               AREAS AND PERIMETERS               \n";
    			color(4,15);cout<<"                     (Square)                     \n"<<endl;
    			color(15,5);cout<<"\t"<<S;color(15,0);cout << " Square's Side = ";
	            color(15,5);cin >> height;
	            _square.set(height);
	            cout<<"\n\t";color(14,4);cout << P <<" Area      ";color(15,0);cout<<" "<< _square.getArea()<<endl;
	            cout<<"\t";color(14,4);cout << P <<" Perimeter ";color(15,0);cout<<" "<< _square.getPerimeter() << endl;
    			color(15,0);getch();
				break;
    		case 2:
    			system("cls");
    			color(0,15);cout<<"               AREAS AND PERIMETERS               \n";
    			color(1,15);cout<<"                   (Rectangle)                    \n"<<endl;
                color(15,5);cout<<"\t"<<S;color(15,0);cout << " Rectangle Height = ";
                color(15,5);cin >> height;
                color(15,5);cout<<"\t"<<S;color(15,0);cout << " Rectangle Base = ";
                color(15,5);cin >> base;
                _rectangle.set(height, base);
                cout<<"\n\t";color(14,4);cout << P <<" Area      ";color(15,0);cout<<" "<< _rectangle.getArea()<<endl;
	            cout<<"\t";color(14,4);cout << P <<" Perimeter ";color(15,0);cout<<" "<< _rectangle.getPerimeter() << endl;
    			color(15,0);getch();
				break;
    		case 3:
    			system("cls");
    			color(0,15);cout<<"               AREAS AND PERIMETERS               \n";
    			color(2,15);cout<<"              (Equilateral Triangle)              \n"<<endl;
                color(15,5);cout<<"\t"<<S;color(15,0);cout << " Triangle Base = ";
                color(15,5);cin >> base;
                _triangle.set(base, base);
                cout<<"\n\t";color(14,4);cout << P <<" Area      ";color(15,0);cout<<" "<< _triangle.getArea()<<endl;
	            cout<<"\t";color(14,4);cout << P <<" Perimeter ";color(15,0);cout<<" "<< _triangle.getPerimeter() << endl;
    			color(15,0);getch();
                break;
    		case 4:
    			system("cls");
    			color(0,15);cout<<"               AREAS AND PERIMETERS               \n";
    			color(6,15);cout<<"                     (Circle)                     \n"<<endl;
                color(15,5);cout<<"\t"<<S;color(15,0);cout << " Circle Diameter = ";
                color(15,5);cin >> diameter;
                _circle.set(diameter);
                cout<<"\n\t";color(14,4);cout << P <<" Area      ";color(15,0);cout<<" "<< _circle.getArea()<<endl;
	            cout<<"\t";color(14,4);cout << P <<" Perimeter ";color(15,0);cout<<" "<< _circle.getPerimeter() << endl;
    			color(15,0);getch();
				break;
    		case 5:
    			color(6,15);cout<<"\n             "<<C<<" "<<C<<" "<<C<<" "<<"THANK YOU!!! "<<C<<" "<<C<<" "<<C<<"            \n";
				color(15,0);getch();
    			break;
    		default:
				color(4,15);cout<<"\n            # # # INVALID OPTION # # #            \n";
				color(15,0);getch();
		}
	}while(option!=5);
}

