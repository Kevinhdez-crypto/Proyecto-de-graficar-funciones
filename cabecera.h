// Declaracion de la funcion para calcular el error relativo entre las dos funciones
double calcular_error_relativo(double f1, double f2);

// Declaracion de la funcion para evaluar una funcion cuadratica 
double evaluar_funcion(double a, double b, double c, double x);

// Declaracion de la funcion que encuentra el subdominio donde el error es menor que el porcentaje
void encontrar_subdominio(double a, double b, double c, double d, double e, double f, double porcentaje_error);

// Declaracion de la funcion que genera la grafica de las funciones y el subdominio
void generar_grafica(double a, double b, double c, double d, double e, double f, double subdominio_a, double subdominio_b);