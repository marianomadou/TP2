#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{

char titulo[20];
char genero[20];
int duracion;
char descripcion[500];
int puntaje;
char linkimage[50];
int idmovie;

}EMovie;

int IngresarEntero(char [], int, int);

/** \brief valida un numero entero ingresado se encuatre dentro de un rango
 * \param minimo valor entero
 * \param maximo valor entero
 * \return un entero validado
 *
 */

int validarEntero (int, int, int);

/**
 * \brief Solicita un número entero usuario que el mismo ingresa como un strnig
 * \param mensaje Es el mensaje a ser mostrado
 * \param el valor minimo para ese entero
  * \param el valor maximo para ese entero
 * \return El número ingresado por el usuario tipo entero
 *
 */


int validarRangoEntero (int , int , int );

/** \brief Valida el rango de un entero
 *
 * \param
 * \param
 * \return
 *
 */


void getString(char [],char [], int , int );

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void getStringletras(char [],char [], int , int );

 /**
 * Obtiene el primer indice sin datos del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */

int obtenerEspacioLibre(EMovie *);

int esTexto(char []);

int esNumero(char []);

int Confirmacion(char []);


void getStringEntero(char [],char [], int , int );

void cargaMovie(EMovie *);

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */

int agregarPelicula(EMovie);


/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borraPelicula(EMovie *movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */

void generaPagina(EMovie *, char []);

int modificaPelicula(EMovie *);

int muestraListaMovie(EMovie [], int );

int BuscarMovie(EMovie *, int );

int cargarDesdeArchivo(EMovie *x);

int guadarListaArchivo(EMovie *x);

char* traerGenero(int, char [] );



#endif // FUNCIONES_H_INCLUDED
