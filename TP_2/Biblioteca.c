#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Biblioteca.h"



void menu(sEmployee listadoEmployee[])
{
    int opcion=0;
    do
    {
        printf("\n");
        printf("\n          Employee register               ");
        printf("\n");
        printf("\n           1.Altas                            ");
        printf("\n");
        printf("\n           2.Modificar                        ");
        printf("\n");
        printf("\n           3.Baja                             ");
        printf("\n ");
        printf("\n           4.Informe                          ");
        printf("\n");
        printf("\n           5.Salir                            ");
        printf("\n");
        printf("\n          Ingrese una opcion (1/5) : ");
        scanf("%d" , & opcion);
        printf("\n ********************************************** ");



        switch(opcion)
        {
            case 1:
                system("cls");
                cargarLibre(listadoEmployee);
                break;

            case 2:
                system("cls");

                break;

            case 3:
                system("cls");

                break;
            case 4:
                system("cls");

                break;
            case 5:
                opcion = 5;
                break;


        }
        system("pause");
    }
    while(opcion!=5);
    {
    }

}

void inicializarArrayIlogicamente(sEmployee listadoEmployee[])
{
    int i;

    for(i=0; i<TAM; i++)
    {
        listadoEmployee[i].estado = VACIO;
    }
}

void cargarEmployee(sEmployee listadoEmployee[] , int i)
{

        system("cls");
        printf("Ingrese nombre del empleando: ");
        gets(listadoEmployee[i].name);
        fflush(stdin);
        printf("Ingrese apellido del empleado:" );
        gets(listadoEmployee[i].lastName);
        fflush(stdin);
        printf("Ingrese salario del empleado: ");
        scanf("%f", &listadoEmployee[i].salary);
        fflush(stdin);
        printf("Ingrese al sector que pertenece: ");
        scanf("%d", &listadoEmployee[i].sector);
        fflush(stdin);

        listadoEmployee[i].estado = OCUPADO;



}

void cargarLibre(sEmployee listadoEmployee[])
{
    int i;
    i=buscarLibre(listadoEmployee);

    if(i == -1)
    {
        system("cls");
        printf("No se encontro un lugar libre!\n");
        printf("\n");
        system("pause");
    }
    else{
        cargarEmployee(listadoEmployee, i);
    }
}

int buscarLibre(sEmployee listadoEmployee[])
{
     int retorno = -1; //FLAG
     int i;

        for (i=0; i<TAM; i++)
        {
            if (listadoEmployee[i].estado == VACIO)
            {
                retorno = i;
                break;

            }
        }
    return retorno;
}

int addEmployee(sEmployee listadoEmployee[] , int tam , char name[] , char lastName[] , float salary , int sector )
{
   int resultado = -1;
   int indiceVacio;
   emptyIndex(listadoEmployee,tam, emptyIndex);

   if(listadoEmployee != NULL && tam > 0)
   {
       if(indiceVacio >= 0)
       {
            strncpy(listadoEmployee[emptyIndex].name,name,51);
            listadoEmployee[emptyIndex].sector=sector;
            strncpy(listadoEmployee[emptyIndex].lastName,lastName,51);
            listadoEmployee[emptyIndex].salary=salary;
            listadoEmployee[emptyindex].id=generateId();
            listadoEmployee[emptyIndex].isEmpty=0;
            result =0;
       }
   }

}

int employeeRemove(sEmployee listadoEmployee[] , int id , int tam)
{
    int i;
    int resultado = -1;

    for(i = 0 ; i < tam ; i++)
    {
      if(listadoEmployee[i].isEmpty == OCUPADO && listadoEmployee[i].id == id)
      {
          listadoEmployee[i].isEmpty = VACIO;
          resultado = 0;
          break;
      }

    }
}

int IdAuto(void)
{
    static int IDEmpleado=0;

    IDEmpleado++;
    return IDEmpleado;
}

int emptyIndex(sEmployee listadoEmployee,int limit,int emptyIndex[])
{
    int i=0;
    int resultado = -1;
    while(i<limit)
    {
        if(employees[i].isEmpty==-1)
        {
            emptyIndex[]=i;
            resultado = 0;
            break;
        }
        i++;
    }
    return result;
