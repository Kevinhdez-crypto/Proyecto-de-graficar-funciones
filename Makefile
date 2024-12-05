# Makefile para compilar el proyecto

# Variables
CC = gcc               
CFLAGS = -Wall -g       #advertencias
SRC = proyecto.c funciones.c   # Archivos fuente de tu proyecto
OBJ = proyecto.o funciones.o   # Archivos objeto generados
EXEC = exe              # Nombre del ejecutable


all: p2

# Regla para compilar el ejecutable
p2: $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)   #Compila los objetos en el ejecutable

# Regla para compilar el archivo fuente proyecto.c a objeto proyecto.o
proyecto.o: proyecto.c cabecera.h
	$(CC) $(CFLAGS) -c proyecto.c

# Regla para compilar el archivo fuente funciones.c a objeto funciones.o
funciones.o: funciones.c cabecera.h
	$(CC) $(CFLAGS) -c funciones.c

# Limpiar archivos generados (como los objetos y el ejecutable)
clean:
	rm -f $(OBJ) $(EXEC)

# Regla para ejecutar el programa
run: p2
	./$(EXEC)