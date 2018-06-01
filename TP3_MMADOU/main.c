#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <wchar.h>
#include <locale.h>
#define TAM_M 10
//TP3. UTN 2018. Mariano Madou
int main()
{
     EMovie listamovie[TAM_M];

     char seguir='s';
     int opcion;

    setlocale(LC_ALL, "");

    while(seguir=='s')
    {
        printf("-------------------------\n");
        printf("------ BLOCKBUSTER ------\n");
        printf("-------------------------\n");
        printf("1- Agregar película\n");
        printf("2- Borrar película\n");
        printf("3- Modificar película\n");
        printf("4- Generar página web\n");
        printf("\n5- Salir\n");

        opcion = IngresarEntero("\nIngrese una opción: ", 1, 5);

        switch(opcion)
        {
            case 1:
                cargaMovie(listamovie);
                break;
            case 2:
                borraPelicula(listamovie);
                break;
            case 3:
               modificaPelicula(listamovie);
               break;
            case 4:
               generaPagina(listamovie, "listado_de_Peliculas.html");
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
