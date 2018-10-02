#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"



void menuEmployees(sEmployee listadoEmployee[] , int tam)
{
    int opcion=0;
    do
    {
        printf("\n");
        printf("\n          Employee register                   ");
        printf("\n");
        printf("\n           1.Altas                            ");
        printf("\n");
        printf("\n           2.Mostrar Alta                     ");
        printf("\n");
        printf("\n           3.Remover                          ");
        printf("\n");
        printf("\n           4.Baja                             ");
        printf("\n ");
        printf("\n           5.Informe                          ");
        printf("\n");
        printf("\n           6.Salir                            ");
        printf("\n");
        printf("\n          Ingrese una opcion (1/5) : ");
        scanf("%d" , & opcion);
        printf("\n ********************************************** ");



        switch(opcion)
        {
            case 1:
                system("cls");
                cargarLibre(listadoEmployee , tam);
                break;

            case 2:
                system("cls");
                mostrarListadoEmployees(listadoEmployee , tam);
                break;

            case 3:
                system("cls");
                employeeRemoveById(listadoEmployee , tam );
                break;
            case 4:
                system("cls");

                break;
            case 5:
                opcion = 5;
                break;
            case 6:
                opcion = 6;
                break;

        }
        system("pause");
    }
    while(opcion!=6);
    {
    }

}

int initEmployees(sEmployee listadoEmployee[] , int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        listadoEmployee[i].estado = VACIO;
    }

    return 0;
}

int addEmployee(sEmployee listadoEmployee[] , int i)
{

        system("cls");
        printf("Ingrese nombre del empleando: ");
        scanf("%s" , & listadoEmployee[i].name);
        fflush(stdin);
        printf("Ingrese apellido del empleado:" );
        scanf("%s" , & listadoEmployee[i].lastName);
        fflush(stdin);
        printf("Ingrese salario del empleado: ");
        scanf("%f", &listadoEmployee[i].salary);
        fflush(stdin);
        printf("Ingrese al sector que pertenece: ");
        scanf("%d", &listadoEmployee[i].sector);
        fflush(stdin);

        listadoEmployee[i].estado = OCUPADO;
        listadoEmployee[i].id = IdAuto();

        return VACIO;
}

int cargarLibre(sEmployee listadoEmployee[] , int tam )
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
        addEmployee(listadoEmployee, i);
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

void mostrarUnEmploye(sEmployee listadoEmployee)
{

    printf("%8d %10s %10s %17f %11d \n\n", listadoEmployee.id , listadoEmployee.name,
                                 listadoEmployee.lastName, listadoEmployee.salary, listadoEmployee.sector);
}


int mostrarListadoEmployees(sEmployee listadoEmployee[] , int tam)
{
    int retorno = -1;
    int i;

    system("cls");
    printf("%10s %10s %10s %15s %12s \n\n", "ID Employee" , "Nombre" ,  "Apellido" ,  "Salario" , "Sector");

    if(tam > 0 && listadoEmployee != NULL)
    {
        retorno = 0;
        for(i=0; i<tam; i++)
        {
            if(listadoEmployee[i].estado ==OCUPADO)
            {

                mostrarUnEmploye(listadoEmployee[i]);
            }
        }
    }
    return retorno;
}


int findEmployeeById(sEmployee listadoEmployee[] , int tam ,int id)
{
    int i;
    int resultado = -1;

    for(i = 0 ; i < tam; i++)
    {
        if(listadoEmployee[i].isEmpty == OCUPADO && listadoEmployee[i].id == id)
        {
            resultado = i;
            break;
        }
    }
    return resultado;
}

void employeeRemoveById(sEmployee listadoEmployee[], int tam)
{
    mostrarListadoEmployees(listadoEmployee , tam);
    int i;
    int auxId;
    char validar;
    int bandera = 0;

    printf("Ingrese el ID del usuario a remover ");
    scanf("%d" , &auxId);

    for(i = 0 ; i < tam ; i++)
    {
      if(listadoEmployee[i].isEmpty == 0 && auxId == listadoEmployee[i].id)
      {
          printf("%10s %10s %10s %15s %12s \n\n", "ID Employee" , "Nombre" ,  "Apellido" ,  "Salario" , "Sector");
          mostrarUnEmploye(listadoEmployee[i]);
          printf("¿Esta seguro que quiere remover este empleado? \n s o n");
          validar = getch();
          validar = tolower(validar);
          if(validar == 's')
          {
            bandera =1;
            listadoEmployee[i].isEmpty = 1;


          }

      }

    }
    if(bandera == 0)
    {
      printf("El ID no corresponde a ningun empleado");
    }

}

int IdAuto(void)
{
    static int IDEmpleado=0;

    IDEmpleado++;
    return IDEmpleado;
}



/*int removeEmployee(sEmployee listadoEmployee, int id, int tam)
{
    int result = -1;
    int i;

    for(i = 0; i < tam; i++)
    {
        if(listadoEmployee[i].isEmpty == OCUPADO && listadoEmployee[i].id == id)
        {
            listadoEmployee[i].isEmpty = VACIO;
            result = 0;
            break;
        }
    }
    return result;
}
*/
