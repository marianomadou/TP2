#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAM 20

/*
TP2
Mariano Madou / Division: 1 "C"
2.1 Descripción:
Definir una estructura que represente una persona, con los campos nombre, edad, dni y un flag de estado.
Hacer un programa que defina un array de 20 ítems de esta estructura y con un menú como el siguiente:
1. Agregar una persona
2. Borrar una persona
3. Imprimir lista ordenada por nombre
4. Imprimir gráfico de edades

Se utilizará el campo de estado para indicar si el ítem del array esta ocupado o no.
El gráfico deberá ser un gráfico de barras en donde se agruparán 3 barras:
• Menores de 18
• De 19 a 35
• Mayores de 35.
En el eje Y se marcarán la cantidad de personas en el grupo, y en el eje X el grupo
Ejemplo:
*
* *
* * *
* * *
* * *
* * *
 <18 19-35 >35
Gráfico para una estadística de 6 personas con edad menor a 18, 4 personas con edades entre
19 y 35, y 5 personas con edades mayores a 35.
*/


int main()
{
    EPersona listadoPersonas[TAM] = {0};
    HardCodeAr(listadoPersonas);

    int index;
    long int dni;

    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("TP 2:\n");
        printf("1- Agregar una persona\n");
        printf("2- Borrar una persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        printf("\n");
        printf("\nIngrese una opcion del menu: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                index= obtenLibreEspacio(listadoPersonas, TAM);
                if (index != -1)
                {
                    cargarPersona(listadoPersonas, index);
                }
               else{
                    printf("No hay mas espacio para cargar otra persona");
                }
                break;

            case 2:

                printf("Ingresar el DNI de la Persona: \n");
                fflush(stdin);
                scanf("%ld", &dni);

                index = buscarPorDni(listadoPersonas, TAM, dni);

                if (index != -1)
                {
                   printf("Se borro el registro con DNI Nro: %ld", dni);
                   listadoPersonas[index].dni = 0;//
                   listadoPersonas[index].estado = 0;//
                }
               else{
                    printf("Persona no encontrada");
                }
                break;

            case 3:
                ordenarListadoPersonas(listadoPersonas, TAM);
                mostrarListadoPersonas(listadoPersonas, TAM);

                break;
            case 4:
                 graficoListadoPersonas(listadoPersonas, TAM);
                break;

            case 5:
                seguir = 'n';
                break;
        }
        printf("\n\n");
        system("pause");
        system("cls");
    }
    return 0;
}
