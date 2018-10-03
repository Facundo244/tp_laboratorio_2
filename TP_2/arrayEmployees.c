#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "arrayEmployees.h"



void menuEmployees(sEmployee listadoEmployee[] , int tam)
{
    int opcion=0;
    do
    {
            printf("\n      *********************************************");
            printf("\n      ||                                         ||");
            printf("\n      ||          .:EMPLOYEE REGISTER:.          ||");
            printf("\n      ||                                         ||");
            printf("\n      *********************************************");
            printf("\n      ||                                         ||");
            printf("\n      ||      1. ALTA                            ||");
            printf("\n      ||                                         ||");
            printf("\n      ||      2. MODIFICACION                    ||");
            printf("\n      ||                                         ||");
            printf("\n      ||      3. BAJA                            ||");
            printf("\n      ||                                         ||");
            printf("\n      ||      4. INFORMAR                        ||");
            printf("\n      ||                                         ||");
            printf("\n      ||                                         ||");
            printf("\n      ||                                         ||");
            printf("\n      ||                                         ||");
            printf("\n      ||   5.Salir                               ||");
            printf("\n      *********************************************");
            printf("\n                                                    ");
            printf("\n");
            printf("\n          Ingrese una opcion (1/5) : ");
            scanf("%d" , & opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                cargarLibre(listadoEmployee , tam);
                break;

            case 2:
                system("cls");
                employeeModify(listadoEmployee , tam);
                break;

            case 3:
                system("cls");
                IdAuto();
                employeeRemoveById(listadoEmployee, tam );
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

void employeeRemoveById(sEmployee listadoEmployee[], int tam)
{
    int bandera =0;
    int acceder;
    int idaux;

    printf("\n Ingrese el ID del empleado a remover ");
    scanf("%d" , & idaux);

    for(int i=0; i<tam ; i++)
    {
        if(listadoEmployee[i].isEmpty!=VACIO && idaux == listadoEmployee[i].id)
        {
            bandera=1;
            printf("\n ¿ Desea dar de baja permanentemente a este empleado ? \n (s/n)");
            acceder=getch();
            if(acceder == 's')
            {
                printf("   ----------------------------------------------    \n");
                printf("            Removiendo datos del Empleado...         \n");
                printf("   ----------------------------------------------    \n");
                system("pause");
                system("cls");
                printf("   ----------------------------------------------   \n");
                printf("            Se removio Exitosamente!!                \n");
                printf("   ----------------------------------------------    \n");
                listadoEmployee[i].estado=VACIO;
                break;
            }
            else if (acceder != 's')
            {
                printf("\n Precione la tecla s para salir al menu \n");
            }
        }
    }
    if(bandera==0)
    {
        printf("\n No se encuentra este ID en la base de datos \n");
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
        printf("\n Ingrese nombre del empleando: ");
        scanf("%s" , &listadoEmployee[i].name);
        printf("\n Ingrese apellido del empleado: ");
        scanf("%s" , &listadoEmployee[i].lastName);
        fflush(stdin);
        printf("\n Ingrese salario del empleado: ");
        scanf("%f", &listadoEmployee[i].salary);
        fflush(stdin);
        printf("\n Ingrese al sector que pertenece: ");
        scanf("%s" , &listadoEmployee[i].lastName);
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

    return -1;

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

    printf("%8d %14s %15s %19f %8d \n\n", listadoEmployee.id , listadoEmployee.name,
                                 listadoEmployee.lastName, listadoEmployee.salary, listadoEmployee.sector);
}


int mostrarListadoEmployees(sEmployee listadoEmployee[] , int tam)
{
    int retorno = -1;
    int i;

    system("cls");
    printf("%10s %10s %10s %15s %12s \n\n", "ID Employee --" , " -- Nombre --" ,  " -- Apellido --" ,  " -- Salario --" , " -- Sector --");

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


int findEmployeeById(sEmployee listadoEmployee[] , int tam , int id)
{
    int resultado = -1;
    int i;

    for(i = 0 ; i < tam; i++)
    {
        if(listadoEmployee[i].id == id && listadoEmployee[i].estado == 1)
        {
            resultado = i;
            break;
        }
    }
    return resultado;
}

int IdAuto(void)
{
    static int IDEmpleado=0;

    IDEmpleado++;
    return IDEmpleado;
}


void employeeModify(sEmployee listadoEmployee[] , int tam)
{
    int idaux;
    int i;
    int opcion;
    char validar;

    mostrarListadoEmployees(listadoEmployee , tam);
    printf("Ingrese el ID del empleado: ");
    scanf("%d" , &idaux);

    for(i=0 ; i<tam ; i++)
    {
        if(idaux == listadoEmployee[i].id)
        {
            mostrarListadoEmployees(listadoEmployee , tam);
            printf("Desea modificar algun dato ?  s / n");
            validar=getch();
            if(validar == 's')
            {
                printf("\n      *********************************************");
                printf("\n      ||                                         ||");
                printf("\n      ||          QUE DESEA MODIFICAR ?          ||");
                printf("\n      ||                                         ||");
                printf("\n      *********************************************");
                printf("\n      ||                                         ||");
                printf("\n      ||      1. Nombre                          ||");
                printf("\n      ||                                         ||");
                printf("\n      ||      2. Apellido                        ||");
                printf("\n      ||                                         ||");
                printf("\n      ||      3. Salario                         ||");
                printf("\n      ||                                         ||");
                printf("\n      ||      4. Sector                          ||");
                printf("\n      ||                                         ||");
                printf("\n      ||                                         ||");
                printf("\n      ||   5.Salir                               ||");
                printf("\n      *********************************************");
                printf("\n");
                printf("\n          Ingrese una opcion (1/5) :      ");
                scanf("%d" , & opcion);

                switch(opcion)
                {
                    case 1:
                        system("cls");
                        fflush(stdin);
                        printf("Ingrese nuevo nombre: ");
                        gets(listadoEmployee[i].name);
                        printf("\n\n");
                        mostrarListadoEmployees(listadoEmployee , tam);
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        fflush(stdin);
                        printf("Ingrese nuevo apellido: ");
                        gets(listadoEmployee[i].lastName);
                        printf("\n\n");
                        mostrarListadoEmployees(listadoEmployee , tam);
                        system("pause");
                        break;
                    case 3:
                        system("cls");
                        fflush(stdin);
                        printf("Ingrese nuevo salario: ");
                        scanf("%f" , &listadoEmployee[i].salary);
                        printf("\n\n");
                        mostrarListadoEmployees(listadoEmployee , tam);
                        system("pause");
                        break;
                    case 4:
                        system("cls");
                        fflush(stdin);
                        printf("Ingrese nuevo sector: ");
                        scanf("%s" , &listadoEmployee[i].sector);
                        printf("\n\n");
                        mostrarListadoEmployees(listadoEmployee , tam);
                        system("pause");
                        break;
                    case 5:
                        opcion = 5;
                        break;
                    default:
                        printf("Ingrese una opcion valida");

                }
            }
        }
    }
}

void alphabeticallyOrderedByLastName(sEmployee listadoEmployee[] , int tam)
{
    int i;
    int j;
    sEmployee aux;


    system("cls");
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
                if (strcmp(listadoEmployee[i].lastName , listadoEmployee[j].lastName) > 0)
                {
                    aux=listadoEmployee[i];
                    listadoEmployee[i]=listadoEmployee[j];
                    listadoEmployee[j]=aux;
                }
        }
    }

    printf(" ----------------------------------------------\n");
    printf("            Ordenando Alfabeticamente...       \n");
    printf(" ----------------------------------------------\n");

    for(i=0 ; i<tam ; i++)
    {
        if(listadoEmployee[i].isEmpty == OCUPADO)
        {
            printf(" nombre:%s  apellido:%s  salario:%.2f  sector:%d\n" , listadoEmployee[i].name , listadoEmployee[i].lastName ,
                   listadoEmployee[i].salary , listadoEmployee[i].sector);
        }
    }

}

void alphabeticallyOrderedByName(sEmployee listadoEmployee[] , int tam)
{
    int i;
    int j;
    sEmployee aux;

    system("cls");
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
                if (strcmp(listadoEmployee[i].name , listadoEmployee[j].name) > 0)
                {
                    aux=listadoEmployee[i];
                    listadoEmployee[i]=listadoEmployee[j];
                    listadoEmployee[j]=aux;
                }
        }
    }

    printf(" ----------------------------------------------\n");
    printf("            Ordenando Alfabeticamente...       \n");
    printf(" ----------------------------------------------\n");

    for(i=0 ; i<tam ; i++)
    {
        if(listadoEmployee[i].isEmpty == OCUPADO)
        {
            printf(" nombre:%s  apellido:%s  salario:%.2f  sector:%d\n" , listadoEmployee[i].name , listadoEmployee[i].lastName ,
                   listadoEmployee[i].salary , listadoEmployee[i].sector);
        }
    }

}

void alphabeticallyOrderedBySector(sEmployee listadoEmployee[] , int tam)
{
    int i;
    int j;
    sEmployee aux;

    system("cls");
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
                if (strcmp(listadoEmployee[i].sector , listadoEmployee[j].sector) > 0)
                {
                    aux=listadoEmployee[i];
                    listadoEmployee[i]=listadoEmployee[j];
                    listadoEmployee[j]=aux;
                }
        }
    }

    printf(" ----------------------------------------------\n");
    printf("            Ordenando Alfabeticamente...       \n");
    printf(" ----------------------------------------------\n");
    for(i=0 ; i<tam ; i++)
    {
        if(listadoEmployee[i].isEmpty == OCUPADO)
        {
            printf(" nombre:%s  apellido:%s  salario:%.2f  sector:%d\n" , listadoEmployee[i].name , listadoEmployee[i].lastName ,
                   listadoEmployee[i].salary , listadoEmployee[i].sector);
        }
    }

}



