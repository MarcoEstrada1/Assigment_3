#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include "tools.h"

/*Genera una matriz como una reserva de memoria dinamica*/
double **generated_matriz(int columnas, int filas){
	 int i;
	 double **array = (double **)malloc(filas*sizeof(double *));
	 if(array == NULL){
	   perror("ERROR. There is not enough memory");
	   exit(EXIT_FAILURE);
	 }
	 for(i=0;i<filas;i++){
		 array[i]=(double *)malloc(columnas*sizeof(double));
		 if(array[i] == NULL){
		   perror("ERROR. There is not enough memory");
		   exit(EXIT_FAILURE);
		 }
	 }
   
	 return array;
}

/*Genera un vector como una reserva de memoria dinamica*/

double *generated_vector(int dimension){
	double *vector=NULL;
	vector=(double *) malloc((size_t) dimension * sizeof(double) );
	if(vector==NULL){
		perror("ERROR. There is not enough memory");
		exit(EXIT_FAILURE);
	}
	return vector;
	
	
}

/*Multiplicación matriz-vecttor*/

double *matriz_vector_multiplicated(double **matriz, double *vector, int dimension, int filas){
	
	int p,i,j;
	double *result=NULL;
	result=(double *) malloc((size_t) filas* sizeof(double) );
	if(result==NULL){
		perror("ERROR. There is not enough memory");
		exit(EXIT_FAILURE);
	}
	for(i=0; i<filas; i++){
		double contador=0.0d;
		for(j=0; j<dimension;j++){
			contador+=matriz[i][j]*vector[j];
		}
		result[i]=contador;
		
	}
	return result;
	
	
}


/*Resolución de un sistema por el método de gauss*/

/**************** O B S E R V A C I O N E S  ****************/
/*   Este tipo de especificacioens es muy genérica
*/ 
/*funcion auxiliar*/ 
double funcion_suma(double **matriz, double*vector, int dimension, int desde, int hasta){
	 int i;
	 double acumulador=0.0d;
	 for(i=desde; i<hasta; i++){
		 acumulador+=matriz[dimension][i]*vector[i];
	 }
	return acumulador;	
}

double *solution_system_of_aquations(double **matriz,double *vector, int dimension, int iteraciones,double TOL){
	int p,i,j;
	p=0;
	double *result=NULL;
	result=(double *) malloc((size_t) dimension * sizeof(double) );
	if(result==NULL){
		perror("ERROR. There is not enough memory");
		exit(EXIT_FAILURE);
	}
	for(i=0; i<dimension;i++){
	result[i]=0.0000;
		
	}
	while (p<iteraciones){
		
		double *numero;
		numero=generated_vector(dimension);
		for(j=0; j<dimension;j++){
			numero[j]=result[j];
		}
		
		for(i=0; i<dimension; i++){
			double divisor= 1/matriz[i][i];
			result[i]=divisor*(vector[i]-funcion_suma(matriz,result,i, 0, i)-funcion_suma(matriz,numero,i,i+1,dimension));
		}
		
		double *diferencia;
		diferencia=generated_vector(dimension);
		for(j=0;j<dimension;j++){
			diferencia[j]=numero[j]-result[j];
		}
		double contador=0;
		for(j=0;j<dimension;j++){
			contador+=diferencia[j]*diferencia[j];
		}
		double norma=sqrt(contador);
		if (norma<TOL){
			return result;
		} else if(p<iteraciones){
			p++;
		}else{
			perror("EL sistema diverge");
			exit(EXIT_FAILURE);
		}
		
	}
	
	return result;
	
}




