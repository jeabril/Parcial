#ifndef BIBLIO_H
#define BIBLIO_H
typedef struct
{
    int dia;
    int mes;
    int anio;
} sFecha;

typedef struct
{
    int codigoDeJuego;
    char descripcion[52];
    float importe;
    int isEmpty;
} sJuegos;

typedef struct
{
    int codigoDeCliente;
    char sexo[52];
    char nombre[52];
    char telefono[22];
    int isEmpty;
} sClientes;

typedef struct
{
    int codigoDeAlquiler;
    int codigoDeJuego;
    int codigoDeCliente;
    sFecha miFecha;
    int isEmpty;
} sAlquileres;


void Menu(sJuegos[],sClientes[],sAlquileres[]);
int funcionIdJuego(sJuegos[],int);
void inicializarArrayJuegos(sJuegos[],int);
int buscarEspacioEnElArray(sJuegos[],int);
void altaJuego(sJuegos[],int,int);
void modificacionJuegos(sJuegos[],int);
void bajaJuego(sJuegos[],int);
void funcionListar(sJuegos[],int);
int funcionIdclientes(sClientes[],int);
void inicializarArrayClientes(sClientes[],int);
int buscarEspacioEnElArrayCliente(sClientes[],int);
void altaCliente(sClientes[],int,int);
void modificacionClientes(sClientes[],int);
void bajaCliente(sClientes[],int);
void funcionListar2( sClientes[],int);
void mostrarId(sJuegos[],int,int);
void mostrarId2(sClientes[],int,int);
void altaAlquileres(sAlquileres[],sJuegos[],sClientes[],int);
int funcionIdAlquiler(sAlquileres[],int);



#endif
