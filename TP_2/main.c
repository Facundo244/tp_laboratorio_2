#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"

int main()
{
    sEmployee listadoEmployee[TAM];
    initEmployees(listadoEmployee , TAM);
    menuEmployees(listadoEmployee , TAM);

}
