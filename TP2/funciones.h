#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    unsigned int edad;
    long int dni;
    int estado;

}EPersona;

void HardCodeAr(EPersona []);
int obtenLibreEspacio(EPersona lista[], int);
int buscarPorDni(EPersona [], int, long int);
void cargarPersona(EPersona [], int);
void ordenarListadoPersonas (EPersona [], int );
void mostrarListadoPersonas (EPersona [], int );
void graficoListadoPersonas (EPersona [], int );

#endif // FUNCIONES_H_INCLUDED
