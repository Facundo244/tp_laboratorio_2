#ifndef arrayEmployee
#define arrayEmployee
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define VACIO -1
#define OCUPADO 0
#define BORRADO 1
#define A 1000
#define S 51
#define TAM 3


typedef struct
{
    int estado;
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} sEmployee;


void menu(sEmployee listadoEmployee[]);
void cargarEmployee(sEmployee listadoEmployee[] , int tam);
int buscarLibre(sEmployee listadoEmployee[]);
void cargarLibre(sEmployee listadoEmployee[]);
int IdAuto(void);
void inicializarArrayIlogicamente(sEmployee listadoEmployee[]);
int employeeRemove(sEmployee listadoEmployee[] , int id , int tam);
int addEmployee(sEmployee listadoEmployee[] , int tam , char name[] , char lastName[] , float salary , int sector );


#endif // Biblioteca
