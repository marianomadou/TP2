#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define TAM_M 10


void cargaMovie(EMovie *lista)
{
    int index;
    int ingresar_genero;

    cargarDesdeArchivo(lista);

    index = obtenerEspacioLibre(lista);

    printf("Lista\n");

    muestraListaMovie(lista, TAM_M);


    if (index!=-1)
    {
        getString("\nTITULO:",(lista+index)->titulo, 1,30);
        (lista+index)->duracion=IngresarEntero("Duracion en minutos:", 1, 300);
        getString("Ingrese Descripcion:",(lista+index)->descripcion, 10, 500);
        (lista+index)->puntaje=IngresarEntero("Puntaje:", 1, 10);
        getString("URL imagen:",(lista+index)->linkimage, 5, 150);
        (lista+index)->idmovie = index+1;

        ingresar_genero=IngresarEntero("Genero: Terror-1 , Comedia-2, Drama-3, Accion-4, Otros-5", 1, 5);

        traerGenero(ingresar_genero, (lista+index)->genero);

        printf("%s", (lista+index)->genero);

        if (Confirmacion("confirma"))
        {
            guadarListaArchivo(lista);
        }

    }else

    {
        printf("\nNo hay lugar para guardar\n");
    }

}

int borraPelicula(EMovie *lista)
{
    EMovie aux= {0};
    int baja;
    int index;
    int retorno=0;
    int cargadas;

    cargarDesdeArchivo(lista);

    if(lista != NULL)
    {
    cargadas = muestraListaMovie(lista, TAM_M);

    if (cargadas!=0)
    {
        baja = IngresarEntero("\nID Pelicula: ", 1, 100);
        index=BuscarMovie(lista,baja);

         if(index!=-1 && lista[index].idmovie != 0 )
    {
        {
            printf("\n\n----------------------------------------------------\n");
            printf("\tPelicula: %s", lista[index].titulo);
        }

        if(Confirmacion("Desea confirmar la baja?"))
        {
            lista[index].idmovie=aux.idmovie;
            guadarListaArchivo(lista);
        }

    }
     else
    {
        printf("Error, No se encontro la pelicula");
        retorno=-1;
    }
    }

}
 return retorno;
}

int modificaPelicula(EMovie *lista)
{

    EMovie aux= {0};
    int modificar;
    int index;
    int retorno=0;
    int cargadas;

    cargarDesdeArchivo(lista);

    if(lista != NULL)
    {
   cargadas= muestraListaMovie(lista, TAM_M);

   if(cargadas!=0)
   {
        modificar = IngresarEntero("\nID Pelicula: ", 1, 10);

    index=BuscarMovie(lista,modificar);

    if(index!=-1)
    {
        {

        printf("\tPelicula: %s", (lista+index)->titulo);

        printf("\n\n----------------------------------------------------\n");
        getString("\nTITULO:",aux.titulo, 1,40);
        aux.duracion=IngresarEntero("DURACION en minutos:", 1, 300);
        getString("Ingrese Descripcion:",aux.descripcion, 10, 500);
        aux.puntaje=IngresarEntero("Puntaje:", 1, 10);
        getString("URL imagen:",aux.linkimage, 3, 150);
        aux.idmovie = (lista+index)->idmovie;
        }

        if(Confirmacion("Desea confirmar los cambios?"))
        {
            lista[index]=aux;
            guadarListaArchivo(lista);
        }
    }

    else
    {
        printf("Pelicula no encontrada");
        retorno=-1;
    }
    }
   }
     return retorno;
}

void generaPagina(EMovie *lista, char nombrearchivo[])
{

  FILE* archivoHTML;

  char cpuntaje[2];
  char cduracion[4];

  cargarDesdeArchivo(lista);

  char buffer[7000]= {};
  strcat(buffer,"<!DOCTYPE html>"

            "<html lang='es'>"
            "<head>"
                "<meta http-equiv='Content-Type' content='text/html; charset=ISO-8859-1'>"
                "<meta name='viewport' content='width=device-width, initial-scale=1'>"
                "<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->"
                "<title>Lista peliculas</title>"
                "<!-- Bootstrap Core CSS -->"
                "<link href='css/bootstrap.min.css' rel='stylesheet'>"
                "<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->"
                "<link href='css/custom.css' rel='stylesheet'>"
                "<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->"
                "<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->"
                "<!--[if lt IE 9]>"
                    "<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>"
                    "<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>"
                "<![endif]-->"
            "</head>"
           " <body>"
                "<div class='container'><div class='row' style='padding-bottom:40px;'><div class='col-md-3' style='background-color:#20459b;'></div><div col-md-4' style='background-color:#20459b;'><img class='img-responsive left' src='imagenes/header.png'></div></div>"
                    "<div class='row'>");

                        for (int i=0; i<TAM_M; i++)
                        {
                            if ((lista+i)->idmovie!=0)
                            {

                        itoa((lista+i)->duracion, cduracion, 10);
                        itoa((lista+i)->puntaje, cpuntaje, 10);

                        strcat(buffer,"<!-- Repetir esto para cada pelicula -->"
                        "<article class='col-md-6 article-intro'>"
                        "<div class='col-md-4 article-intro'>"
                            "<a href='#'>"
                                "<img class='img-responsive img-rounded' src='");

                        strcat(buffer, (lista+i)->linkimage);

                        strcat(buffer,"'/></a>"

                                "<a href='#'></div><div class='col-md-8 article-intro'><h3>");

                            strcat(buffer,(lista+i)->titulo);

                            strcat(buffer,"</a>"
                            "</h3><br/>"
                            "<ul>"
                                "<li>Genero:");

                            strcat(buffer, (lista+i)->genero);

                            strcat(buffer,"</li><li>Puntaje:");
                            strcat(buffer, cpuntaje);

                              strcat(buffer, "</li><li>Duracion:");
                              strcat(buffer,cduracion);
                              strcat(buffer, "</li></ul><p></div><article class='col-md-12 article-intro'>");
                             strcat(buffer, (lista+i)->descripcion);

                            strcat(buffer,"</p>"
                        "</article></article>"
                        "<!-- Repeat -->");

                            }
                        }

                        strcat(buffer,"</div>"
                "<!-- /.row -->"
                "</div>"
               " <!-- /.container -->"
                "<!-- jQuery -->"
                "<script src='js/jquery-1.11.3.min.js'></script>"
                "<!-- Bootstrap Core JavaScript -->"
                "<script src='js/bootstrap.min.js'></script>"
               "<!-- IE10 viewport bug workaround -->"
               " <script src='js/ie10-viewport-bug-workaround.js'></script>"
                "<!-- Placeholder Images -->"
                "<script src='js/holder.min.js'></script>"
            "</body>"
            "</html>");

    archivoHTML = fopen(nombrearchivo,"w");
    fprintf(archivoHTML,buffer);
    fclose(archivoHTML);
 }

int cargarDesdeArchivo(EMovie *x)
{
	FILE *f;
	int retorno=0;
	int bandera=0;

	 for(int i=0; i<TAM_M; i++)
    {
        (x+i)->idmovie=0;
    }

	f=fopen("lista_de_pelis.dat", "rb");
	if(f==NULL)
	{
		f= fopen("lista_de_pelis.dat", "wb");
		bandera=1;

		if(f==NULL)
		{
			retorno=1;
		}
	}

	if(bandera==0)
	{
     while(!feof(f))
        {
          fread(x,sizeof(EMovie),TAM_M,f);
        }
	}

	fclose(f);
	return retorno;
}

int guadarListaArchivo(EMovie *x)
{
	FILE *f;
	int retorno=0;

	f=fopen("lista_de_pelis.dat", "wb");
	if(f==NULL)
	{
			retorno=1;
    }

	if(retorno ==0)
	{
      fwrite(x,sizeof(EMovie),TAM_M,f);
    }

	fclose(f);

	return retorno;
}

int obtenerEspacioLibre(EMovie *lista)
{
    int index = -1;

    for(int i=0; i<TAM_M; i++)
    {
        if((lista+i)->idmovie==0)
        {
            index=i;
            break;
        }
    }

    return index;
}

int muestraListaMovie(EMovie lista[], int tam)
{
    int flag=0;

    if(lista != NULL)
    {

    for(int i=0; i<tam; i++)
    {
        if (flag==0 && lista[i].idmovie!=0)
        {
        printf("\nID\tTitulo\t\tGenero\t\tDescripcion");
        printf("\n----------------------------------------------------------------------------------");
        flag=1;

        }

        if(lista[i].idmovie!=0)

        {
            printf("\n%d\t%.30s\t%0.10s\t\t%.55s...\t\n",lista[i].idmovie,lista[i].titulo,lista[i].genero,lista[i].descripcion);
        }

    }
        if (flag==0)
        {
        printf("\nNo hay Peliculas cargadas");
        }
        printf("\n----------------------------------------------------------------------------------");
    }

    return flag;
}

int BuscarMovie(EMovie *lista, int id)
{
    int index = -1;

    for(int i=0; i<TAM_M; i++)
    {
        if((lista+i)->idmovie==id && lista != NULL)
        {
            index=i;
            break;
        }
    }

    return index;
}

char* traerGenero(int numero, char genero[])
{
        switch (numero)
                {
                case 1:
                    strcpy(genero, "Terror");
                    break;
                case 2:
                    strcpy(genero, "Comedia");
                    break;
                case 3:
                    strcpy(genero, "Drama");
                    break;
                case 4:
                    strcpy(genero, "Accion");
                    break;
                case 5:
                    strcpy(genero, "Otros");
                    break;
                }
    return genero;
}

int IngresarEntero(char mensaje[], int min, int max)
{
    int entero;
    puts(mensaje);
    fflush(stdin);
    scanf("%d",&entero);
    entero = validarEntero(entero, min, max);

    return entero;
}

int validarEntero (int dato, int min, int max)
{
    while(dato < min || dato > max)
    {

        fflush(stdin);
        printf("Dato no v%clido reingresar: ", 160);
        scanf("%d", &dato);

    }

    return dato;

}

void getString(char mensaje[],char input[], int min, int max)
{
    int len;
    int valido=0;

    do
    {
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);

    len = strlen(input);
    if(len < min || len > max)
    {
        printf("Error,");
    }
    else
    {
       valido =1 ;

    }
    }
    while(valido ==0);

}

void getStringletras(char mensaje[],char input[], int min, int max)
{
        int estex=0;
        do
        {
        getString(mensaje, input, min,max);

        estex = esTexto(input);

        if (estex == 0)
        {
            printf("Error, ingresar %cnicamente letras", 163);
        }

        }
        while (estex == 0);
}

void getStringEntero(char mensaje[],char input[], int min, int max)
{
        int esnum=0;
        do
        {
        getString(mensaje, input, min,max);

        esnum = esNumero(input);

        if (esnum == 0)
        {
            printf("Error, ingresar %cnicamente n%cmeros", 163, 163);
        }

        }
        while (esnum == 0);
}

int esTexto(char texto[])
{
    int estexto = 0;

    int len = strlen(texto);

    for (int i=0; i<len; i++)
    {
        if (isalpha(texto[i]) || isspace(texto[i]))
        {
            estexto = 1;
        }
        else
        {

            estexto = 0;
            break;

        }

    }

    return estexto;

}

int esNumero(char numero[])
{

    int esnum = 0;

    int len = strlen(numero);

    for (int i=0; i<len; i++)
    {
        if (isdigit(numero[i]))
        {
            esnum = 1;
        }
        else
        {

            esnum = 0;
            break;

        }

    }

    return esnum;

}

int Confirmacion(char mensaje[])
{
     char confirma;
     int retorno=0;

      printf("\n.....................................................");

     printf("\n%s s/n: ", mensaje);

     confirma= getche();
     confirma= tolower(confirma);

     if(confirma == 's')
     {
         retorno=1;

     }

     return retorno;

}
