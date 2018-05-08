#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void HardCodeAr(EPersona lista[])
{
    long int dni[15]={27387009,26434796,25449878,39455339,28468743,38796334,45879631,24638748,25879357,14793631,34896758,89653478,15679358,25398746,48357963};
    char nombre[15][50]={"Mariano","Sebas","Flor", "Javier", "Eduardo", "Silvia", "Nina", "Roberto", "Ricardo", "Susana", "Alberto", "Norma", "Ezequie", "Vicky", "German"};
    unsigned int edad[15]={38,36,41,15,17,30,16,15,63,28,59,75,50,34,27};
    int estado[15]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

    for(int i=0; i<15; i++)
    {
        strcpy(lista[i].nombre, nombre[i]);
        lista[i].dni=dni[i];
        lista[i].edad=edad[i];
        lista[i].estado=estado[i];
    }
}

int obtenLibreEspacio(EPersona lista[], int tam)
{
    int index = -1;
    for(int i=0;i<tam;i++){
        if(lista[i].dni==0){
            index=i;
            break;
        }
    }
    return index;
}

void cargarPersona(EPersona lista[], int index)
{
    printf("Ingrese el DNI: ");
    scanf("%ld",&lista[index].dni);

    fflush(stdin);
    printf("\nIngrese el Nombre: ");
    gets(lista[index].nombre);

    fflush(stdin);
    printf("\nIngrese Edad: ");
    scanf("%d",&lista[index].edad);

    lista[index].estado = 1;
}

void mostrarListadoPersonas (EPersona lista[], int tam)
{
    int i;
    int flag= 0;

    printf("_______________________________________________________\n");

    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==1)
        {
            printf("\n%s\t\t\%ld\t%d \n", lista[i].nombre, lista[i].dni, lista[i].edad);
            flag = 1;
        }
    }
        if(flag == 0)
        {
            printf("\nNo existen datos cargados\n");
        }
        printf("_______________________________________________________\n");

}

int buscarPorDni(EPersona lista[], int tam, long int dni)
{
int index = -1;


    for(int i=0;i<tam;i++){
        if(lista[i].dni==dni){
            index = i;
        }
    }
return index;
}

void ordenarListadoPersonas(EPersona lista[], int tam )
{
    EPersona aux[tam];

    for(int i=0; i<tam-1; i++)
    {

        for(int j=i+1; j<tam; j++)
        {
             if(lista[i].estado == 1)
             {

                 if((strcmp(lista[i].nombre,lista[j].nombre))> 0)
                    {
                         aux[i]= lista[i];
                         lista[i]=lista[j];
                         lista[j]=aux[i];

                    }
             }
        }
    }
}

void graficoListadoPersonas (EPersona lista[], int tam )
{
    char grafico1[tam][2];
    char grafico2[tam][2];
    char grafico3[tam][2];
    int w=0;
    int j=0;
    int k=0;

    for(int i=0;i<=tam ; i++){

    strcpy(grafico1[i]," ");
    strcpy(grafico2[i]," ");
    strcpy(grafico3[i]," ");

     }

    for(int i=0;i<tam ; i++)
     {
            if(lista[i].edad <= 18 && lista[i].edad >0)
        {
            fflush(stdin);
            strcpy(grafico1[w], "*");
            w++;
        }

        if(lista[i].edad > 18 && lista[i].edad <=35)
        {
            fflush(stdin);
            strcpy(grafico2[k], "*");
            k++;
        }

        if(lista[i].edad > 35)
                {
                  fflush(stdin);
                  strcpy(grafico3[j], "*");
                  j++;
                }
     }
    printf("\n");

    for(int i=tam;i>=0 ; i--)
        {
           if( (strcmp(grafico1[i],"*")==0) || (strcmp(grafico2[i],"*")==0) || (strcmp(grafico3[i],"*")==0)  )
           {
            printf("  %d-| %s      ", i+1, grafico1[i]);
            printf("%s       ", grafico2[i]);
            printf("%s\n", grafico3[i]);
           }
         }
        printf("  __|_________________________\n");
        printf("     <18   19-35    >35\n\n");
        printf("Gráfico para una estadística de %d personas con edad menor a 18, %d personas con edades entre 19 y 35, y %d personas con edades mayores a 35.\n", w,k,j);
}


