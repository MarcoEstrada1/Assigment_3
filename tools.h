/**************** O B S E R V A C I O N E S  ****************/
/*   Usualmente los arhcivos .h son provistos a los usuarios
     para que vean las funcionalidades que estan disponibles
	 en el módulo. Por tanto es bueno comentar brevemente lo
	 que hace cada cada funcion. Vean alguno de los archivos
	 .h de las librerias que usan para que vean como se hace.
*/ 


double **generated_matriz(int columnas, int filas);
double *generated_vector(int dimension);
double *matriz_vector_multiplicated(double **matriz, double *vector, int dimension, int filas);
double funcion_suma(double **matriz, double*vector, int dimension, int desde, int hasta);
double *solution_system_of_aquations(double **matriz,double *vector, int dimension, int iteraciones,double TOL);
