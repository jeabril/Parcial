#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define A 3
#define VACIO -1
#define LLENO 1
#include "funciones.h"

void menu(sJuegos arrayJuegos[],sClientes arrayClientes[],sAlquileres arrayAlquileres[]);

int main()
{
    sJuegos arrayJuegos[A];
    sClientes arrayClientes[A];
    sAlquileres arrayAlquileres[A];

    inicializarArrayJuegos(arrayJuegos,A);
    inicializarArrayClientes(arrayClientes,A);
    menu(arrayJuegos,arrayClientes,arrayAlquileres);

    return 0;
}

void menu(sJuegos arrayJuegos[],sClientes arrayClientes[],sAlquileres arrayAlquileres[])
{

    int opcion;
    char seguir;
    int indice;
    int indice1;
    int flag=0;
    int flag1=0;

    do
    {
        system("color F5");
        printf("                    _______________________________________\n");
        printf("                   |                                       |\n");
        printf("                   |               MENU JUEGOS             |\n");
        printf("                   |        1) ALTAS    2)MODIFICAR        |\n");
        printf("                   |        3) BAJA     4)INFORMAR         |\n");
        printf("                   |                                       |\n");
        printf("                   |                                       |\n");
        printf("                   |                                       |\n");
        printf("                   |             MENU CLIENTES             |\n");
        printf("                   |        5) ALTAS    6)MODIFICAR        |\n");
        printf("                   |        7) BAJA     8)INFORMAR         |\n");
        printf("                   |                                       |\n");
        printf("                   |            MENU ALQUILERES            |\n");
        printf("                   |               9) ALTAS                |\n");
        printf("                   |_______________________________________|\n");

        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        system("cls");
        fflush(stdin);
        switch(opcion)
        {
        case 1:
            flag=1;
            indice=buscarEspacioEnElArray(arrayJuegos,A);
            if( indice!=VACIO)
            {
                altaJuego(arrayJuegos,A,indice);
            }
            else
            {
                printf("No hay espacio en el array\n");
            }
            break;

        case 2:
            if(flag==0)
            {
                printf("Usted debe cargar al juego primero");
            }
            else
            {
                mostrarId(arrayJuegos,A,indice);
                modificacionJuegos(arrayJuegos,A);
            }
            break;

        case 3 :
            if(flag==0)
            {
                printf("Usted debe cargar el juego primero");
            }
            else
            {
                mostrarId(arrayJuegos,A,indice);
                bajaJuego(arrayJuegos,A);
            }
            break;

        case 4:
            if(flag==0)
            {
                printf("Usted debe cargar al juego primero");
            }
            else
            {
                funcionListar(arrayJuegos,A);
            }
            break;

        case 5:
            flag1=1;
            indice1=buscarEspacioEnElArrayCliente(arrayClientes,A);
            if( indice1!=VACIO)
            {
                altaCliente(arrayClientes,A,indice1);
            }
            else
            {
                printf("No hay espacio en el array\n");
            }
            break;

        case 6:
            if(flag1==0)
            {
                printf("Debe cargar al cliente primero");
            }
            else
            {
                mostrarId2(arrayClientes,A,indice1);
                modificacionClientes(arrayClientes,A);
            }
            break;

        case 7 :
            if(flag1==0)
            {

                printf("Usted debe cargar el cliente primero");

            }
            else
            {
                mostrarId2(arrayClientes,A,indice1);
                bajaCliente(arrayClientes,A);

            }
            break;

        case 8:
            if(flag1==0)
            {

                printf("Usted debe cargar al cliente primero");

            }
            else
            {
                funcionListar2(arrayClientes,A);
            }
            break;

        case 9:
            if(flag1==0)
            {

                printf("Usted debe cargar el alquiler primero");

            }
            else
            {
                altaAlquileres(arrayAlquileres,arrayJuegos,arrayClientes,A);
            }
            break;
        }
        printf("\nQuiere volver al menu?\ns/Para continuar n/Para salir\n");
        seguir=getch();
        system("cls");
    }
    while(seguir =='s');
}
