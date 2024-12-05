#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cabecera.h"  

// Funcion para evaluar una funcion cuadratica 
double evaluar_funcion(double a, double b, double c, double x) {
    return a * x * x + b * x + c;
}

// Funcion para calcular el error relativo entre dos funciones f1 y f2
double calcular_error_relativo(double f1, double f2) {
    return fabs(f1 - f2) / fabs(f1) * 100;
}

// Funcion que encuentra el subdominio donde el error es menor que el porcentaje
void encontrar_subdominio(double a, double b, double c, double d, double e, double f, double porcentaje_error) {
    double x, f1, f2, error_relativo;
    double subdominio_a = -1, subdominio_b = -1;
    int encontrado = 0;

    // Buscar el subdominio [a, b] donde la diferencia relativa entre las funciones no supere el error permitido
    for (x = -100000; x <= 100000; x += 0.1) {  // Iteramos con un paso pequeno para encontrar el subdominio
        f1 = evaluar_funcion(a, b, c, x);
        f2 = evaluar_funcion(d, e, f, x);

        // Calculamos el error relativo
        error_relativo = calcular_error_relativo(f1, f2);

        // Si el error es menor al porcentaje de error
        if (error_relativo < porcentaje_error) {
            if (!encontrado) {
                subdominio_a = x;  // Encontramos el primer punto del subdominio
                encontrado = 1;
            }
        } else {
            if (encontrado) {
                subdominio_b = x;  // Encontramos el segundo punto del subdominio
                break;
            }
        }
    }

    // Si encontramos el subdominio, lo mostramos
    if (encontrado && subdominio_b > subdominio_a) {
        printf("Subdominio encontrado: [%.2f, %.2f]\n", subdominio_a, subdominio_b);
    } else {
        printf("No se encontro un subdominio donde la diferencia entre las funciones sea menor al porcentaje de error.\n");
    }

    // Llamar a la funcion para graficar las funciones y las lineas del subdominio
    generar_grafica(a, b, c, d, e, f, subdominio_a, subdominio_b);
}

// Funcion que genera la grafica de las dos funciones y las lineas verticales representando el subdominio
void generar_grafica(double a, double b, double c, double d, double e, double f, double subdominio_a, double subdominio_b) {
    FILE *gp;

    // Abrir un pipe hacia gnuplot
    gp = popen("gnuplot -persistent", "w");
    if (gp == NULL) {
        fprintf(stderr, "Error al abrir gnuplot.\n");
        exit(1);
    }

    // Configurar Gnuplot
    fprintf(gp, "set title 'Graficas de f1 y f2 con subdominio de error relativo'\n");
    fprintf(gp, "set xlabel 'x'\n");
    fprintf(gp, "set ylabel 'y'\n");
    fprintf(gp, "set yrange [-10:10]\n");  // Rango de 'Y' entre -10 y 10

    // Graficar las dos funciones cuadraticas
    fprintf(gp, "plot %lf*x**2 + %lf*x + %lf title 'f1' with lines, ", a, b, c);
    fprintf(gp, "%lf*x**2 + %lf*x + %lf title 'f2' with lines\n", d, e, f);

    // Si encontramos un subdominio, graficamos las lineas verticales correspondientes
    if (subdominio_a != -1 && subdominio_b != -1) {
        fprintf(gp, "set arrow from %.2f, -10 to %.2f, 10 nohead lc rgb 'red' lw 2\n", subdominio_a, subdominio_a);  // Línea roja en subdominio_a
        fprintf(gp, "set arrow from %.2f, -10 to %.2f, 10 nohead lc rgb 'blue' lw 2\n", subdominio_b, subdominio_b);  // Línea azul en subdominio_b
    }

    // Cerrar gnuplot
    pclose(gp);
}