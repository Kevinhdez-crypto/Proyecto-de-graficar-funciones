//Kevin Hernandez Umana C33773
/*Este codigo se basa en graficar dos funciones cuadraticas y el subdominio donde
la diferencia entre ellas sea menor al rango ingresado por el usuario (de 0 a 100). Todo esto se graficara
con el programa de gnuplot.*/
#include <stdio.h>
#include "cabecera.h"

int main (){
    double a, b, c, d, e, f, porcentaje_error; //declaro variables que voy a necesitar

    //pido los valores de los coeficientes
    printf("Ingrese los coeficientes de la primera funcion de la forma 'a, b, c': "); 
    scanf("%lf %lf %lf", &a, &b, &c);

    //pido los coeficientes de la segunda funcion
    printf("Ingrese los coeficientes de la segunda funcion de la forma 'd, e, f': "); 
    scanf("%lf %lf %lf", &d, &e, &f);
    
    //pido el porcentaje de error e indico de el rango
    printf("Ingrese el porcentaje de error permitido entre (0 a 100): "); 
    scanf("%lf", &porcentaje_error);

    
    encontrar_subdominio(a, b, c, d, e, f, porcentaje_error);

    printf("Grafica lista.\n");
    return 0;
}