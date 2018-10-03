#ifndef arrayEmployees
#define arrayEmployees
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
    char name[24];
    char lastName[24];
    float salary;
    char sector;
    int isEmpty;

} sEmployee;

int mostrarListadoEmployees(sEmployee listadoEmployee[] , int tam);
void menuEmployees(sEmployee listadoEmployee[] , int);
int printEmployees(sEmployee* listadoEmployee , int );
int sortEmployees(sEmployee* listadoEmployee , int , int );
int findEmployeeById(sEmployee listadoEmployee[] , int );
int initEmployees(sEmployee listadoEmployee[] , int );
int employeeRemove(sEmployee listadoEmployee[] , int tam);
int addEmployee(sEmployee listadoEmployee[] , int );
void mostrarUnEmploye(sEmployee listadoEmployee);
void employeeRemoveById(sEmployee listadoEmployee[], int tam);
int cargarLibre(sEmployee listadoEmployee[] , int);
int IdAuto(void);
int buscarLibre(sEmployee listadoEmployee[]);
void employeeModify(sEmployee listadoEmployee[] , int tam);


#endif // Biblioteca
