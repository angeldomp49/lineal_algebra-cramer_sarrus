#include <iostream>
#include <stdlib.h>
#include "algebraLineal.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	
	/*La variable capacidad que va a asignar el tamaño del arreglo bidimensional
	, luego el valor que se va a pedir para cada coeficiente
	, luego los apuntadores*/
	  
	int        capacidad;
	float      determinante;
	float      coeficiente;
	float*     constantes;
	float*     valorDeLasVariables;
	float**    indiceColumnas;
	
	/*Pedimos el valor al usuario.*/
	cout<<"ingrese el numero de incognitas: ";
	cin>>capacidad;
	
    /*Inicializamos el doble apuntador y sus apuntadores a float correspondientes*/
    /*Luego el apuntador de las constantes*/
    
	indiceColumnas = (float**)malloc(sizeof(float*)*capacidad);
	constantes     = (float*)malloc(sizeof(float)*capacidad); 
	
	for(int i=0; i<=(capacidad-1);i++){
		indiceColumnas[i] = (float*)malloc(sizeof(float)*capacidad);
	}

    /*se permiten los subindices para recorrer un apuntador y doble apuntador de la 
	forma apuntador[k] y dobleApuntador[k][i]*/
    
	for(int k=0;k<=(capacidad-1);k++){
	   for(int i=0;i<=(capacidad-1);i++){
            cout<<"ingrese valor del elemento "<<"["<<k+1<<"]"<<"["<<i+1<<"]"<<": "<<endl;
    	    cin>>coeficiente;
    	    indiceColumnas[k][i] = coeficiente; 
	    }
	}
	
	/*Pedimos las constantes*/
	for(int i=0;i<=(capacidad-1);i++){
		cout<<"ingrese la constante "<<i+1<<" :";
		cin>>coeficiente;
		constantes[i] = coeficiente;
	}
	
	/*El primer paso para obtener el determinante es multiplicar en forma diagonal
	desde el termino con subindices [0][0] hasta el termino subindices [n-1][n-1]
	donde n es el tamaño del arreglo y ambos subindices se incrementan, luego el 
	resultado de esta multiplicacion se guarda. 
	
	El siguiente paso es parecido solo
	que ahora se incrementa el primer subindice antes de comenzar, de modo que la 
	multiplicacion comienza en [1][0] y como un subindice va a llegar al valor de
	n-1, pero el otro no, entonces la multiplicacion se va a detener cuando el 
	segundo subindice llegue al valor n-1 despues de que el primero lo haya hecho
	aun si no es al mismo tiempo y el resultado de este segundo paso se guarda. 
	
	Los pasos subsecuentes suceden igual hasta que se terminen los elementos de la
	columna que es igual a mientras i<= n-1.
	
	El ultimo paso es sumar el resultado de las multiplicaciones de los pasos
	anteriores.*/
    
    determinante = algebraLineal::buscarDeterminante(indiceColumnas,capacidad);
    
    valorDeLasVariables = (float*)malloc(sizeof(float)*capacidad);
    
    for(int i = 0;i <= capacidad-1;i++){
    	
    	float delta            = algebraLineal::buscarDelta(indiceColumnas,constantes,capacidad,i);
		valorDeLasVariables[i] = delta/determinante;
	}
	for(int i=0;i<=capacidad-1;i++){		
		cout<<"variable "<<i+1<<": "<<valorDeLasVariables[i]<<endl;
	}
	
	system("pause");
	return 0;
}
