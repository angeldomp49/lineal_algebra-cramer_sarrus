#include <iostream>
using namespace std;

class algebraLineal{

	public:
	static float buscarDeterminante(float** matriz,int tallaMatriz);
	static float buscarDelta(float** matriz,float* vectorResultados,int tallaMatriz,int numDelta);
};

float algebraLineal::buscarDeterminante(float** matriz, int tallaMatriz){
	
    /*Variables */
    
	float sumaParcial    = 0;
	float sumaParcial2   = 0;
	
	/*Para el primer termino del metodo de Sarrus, se multiplica diagonalmente
	de arriba a la izquierda hacia abajo a la derecha; luego se suman los terminos.*/
	
	for(int i=0;i<=tallaMatriz-1;i++){
		
		/*inicia con matriz[0][0]*/
		
		bool bandera1                = false;
		bool acabarMultiplicacion    = false;
		float multiplicacionDiagonal = 1;
	    int primerSubindice          = i;
	    int segundoSubindice         = 0;
		
		while(!acabarMultiplicacion){
			
		    multiplicacionDiagonal = 
			multiplicacionDiagonal * matriz[primerSubindice][segundoSubindice];
			
			if(primerSubindice >= tallaMatriz-1){
				
				/*Cuando se encuentra con el ultimo elemento de la columna
				matriz[capacidad-1][] el primer subindice se pone a -1 para que 
				cuando se incremente al inicio del bucle valga 0*/
				
				bandera1        = true;
				primerSubindice = -1;
			}
			if(bandera1){
				if(segundoSubindice >= tallaMatriz-1){
					acabarMultiplicacion = true;
				}
			}
			primerSubindice++;
			segundoSubindice++;
		}
		sumaParcial = sumaParcial + multiplicacionDiagonal;
	}
	
	/*Segundo termino del metodo de Sarrus. Se multiplican de abajo a la izquierda
	hasta arriba a la derecha; luego se suman los terminos.*/
	
	for(int i=tallaMatriz-1;i>=0;i--){
		/*La multiplicacion se inicia en los subindices [capacidad-1][0] y termina en 
	[0][0]*/
	
		bool bandera1                = false;
		bool acabarMultiplicacion    = false;
		float multiplicacionDiagonal = 1;
	    int primerSubindice          = i;
	    int segundoSubindice         = 0;
	    
	    while(!acabarMultiplicacion){
	    	multiplicacionDiagonal   
			= multiplicacionDiagonal * matriz[primerSubindice][segundoSubindice];
			
			if(primerSubindice <=0){
				bandera1 = true;
				primerSubindice = tallaMatriz;
			}
			if(bandera1){
				if(segundoSubindice>=tallaMatriz-1){
					acabarMultiplicacion = true;
				}
			}
			primerSubindice--;
			segundoSubindice++;
		}
		sumaParcial2 = sumaParcial2 + multiplicacionDiagonal;
	}
	return sumaParcial - sumaParcial2;
}

float algebraLineal::buscarDelta(float** buffer,float* vectorResultados, int tallaMatriz,int numDelta){
	
    /*se crea un nuevo arreglo para no cambiar el original*/
    float** matriz = (float**)malloc(sizeof(float*)*tallaMatriz);
    for(int i=0;i<=tallaMatriz-1;i++){
    	matriz[i]=(float*)malloc(sizeof(float)*tallaMatriz);
	}
	
	for(int k=0;k<=tallaMatriz-1;k++){
		for(int i=0;i<=tallaMatriz-1;i++){
			matriz[k][i] = buffer[k][i];
		}
	}
	
	/*se cambia la columna de coeficientes de la fila numDelta por el vector de resultados*/
	
	for(int k=0;k<=tallaMatriz-1;k++){
	    matriz[k][numDelta] = vectorResultados[k];
	}
	
	float sumaParcial    = 0;
	float sumaParcial2   = 0;
	
	/*Para el primer termino del metodo de Sarrus*/
	
	for(int i=0;i<=tallaMatriz-1;i++){
		
		bool bandera1                = false;
		bool acabarMultiplicacion    = false;
		float multiplicacionDiagonal = 1;
		int primerSubindice          = 0;
		int segundoSubindice         = i;
		
		while(!acabarMultiplicacion){
			
		    multiplicacionDiagonal = 
			multiplicacionDiagonal * matriz[primerSubindice][segundoSubindice];
			
			if(segundoSubindice >= tallaMatriz-1){
				bandera1        = true;
				segundoSubindice = -1;
			}
			if(bandera1){
				if(primerSubindice >= tallaMatriz-1){
					acabarMultiplicacion = true;
				}
			}
			primerSubindice++;
			segundoSubindice++;
		}
		sumaParcial = sumaParcial + multiplicacionDiagonal;
	}

	/*Para el segundo termino del metodo de Sarrus (el que se va a restar).*/
	
	for(int i=tallaMatriz-1;i>=0;i--){
		
		/*La multiplicacion se inicia en los subindices [0][capacidad-1] y termina en 
	[0][0]*/
	
		bool bandera1                = false;
		bool acabarMultiplicacion    = false;
		float multiplicacionDiagonal = 1;
	    int primerSubindice          = 0;
	    int segundoSubindice         = i;
	    
	    while(!acabarMultiplicacion){
	    	multiplicacionDiagonal   
			= multiplicacionDiagonal * matriz[primerSubindice][segundoSubindice];
			
			if(segundoSubindice <=0){
				bandera1 = true;
				segundoSubindice = tallaMatriz;
			}
			if(bandera1){
				if(primerSubindice>=tallaMatriz-1){
					acabarMultiplicacion = true;
				}
			}
			primerSubindice++;
			segundoSubindice--;
		}
		sumaParcial2 = sumaParcial2 + multiplicacionDiagonal;
	}
	return sumaParcial - sumaParcial2;
}

