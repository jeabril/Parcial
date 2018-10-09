#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define A 3
#define VACIO -1
#define LLENO 1
#include "funciones.h"




int funcionIdJuego(sJuegos arrayJuegos[],int cant)
{
    int i ;
    for( i= 0; i<cant; i++)
    {

        if(arrayJuegos[i].isEmpty==VACIO)
        {
            arrayJuegos[i].codigoDeJuego=i;
            return i;
        }
    }
    return -1;
}
void inicializarArrayJuegos(sJuegos arrayJuegos[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        arrayJuegos[i].isEmpty=VACIO;
    }

}
int buscarEspacioEnElArray(sJuegos arrayJuegos[], int cant)
{
    int aux=VACIO;
    int i;

    for(i=0; i<cant; i++)
    {
        if(arrayJuegos[i].isEmpty==VACIO)
        {
            aux=i;
            break;
        }
    }

    return aux;
}
void altaJuego(sJuegos arrayJuegos[],int cant,int i)
{
    printf("el codigo de juego es:%d",i);

    printf("\n\ningrese descripcion: ");
    fflush(stdin);
    gets(arrayJuegos[i].descripcion);
    while(strlen(arrayJuegos[i].descripcion)>51)
    {
        printf("\n\nreingrese descripcion: ");
        gets(arrayJuegos[i].descripcion);
    }

    printf("\ningrese importe: ");
    scanf("%f", & arrayJuegos[i].importe);
    while(arrayJuegos[i].importe <0)
    {
        printf("\nreingrese importe: ");
        scanf("%f", & arrayJuegos[i].importe);

    }
    arrayJuegos[i].codigoDeJuego=i;
    arrayJuegos[i].isEmpty=LLENO;
}
void modificacionJuegos(sJuegos arrayJuegos[],int cant)
{

    int aceptar2;
    int i;
    int auxId;
    int flag=0;
    char modificacion;


    printf("\ningrese codigo de juego para modificar : ");
    scanf("%d",&auxId);

    for(i=0; i<cant; i++)
    {
        if(arrayJuegos[i].isEmpty!=VACIO && auxId==arrayJuegos[i].codigoDeJuego)
        {
            do
            {
                system("cls");
                printf("-----------------\n");
                printf("-5) DESCRIPCION -\n");
                printf("-6) IMPORTE     -\n");
                printf("-----------------\n");

                printf("ingrese el campo a modificar: ");
                scanf("%d",&aceptar2);
                system("cls");
                switch(aceptar2)
                {
                case 5:
                    printf("ingrese una nueva descripcion: ");
                    fflush(stdin);
                    gets(arrayJuegos[i].descripcion);
                    while(strlen(arrayJuegos[i].descripcion)>51)
                    {
                        printf("\nreingrese nueva descripcion: ");
                        gets(arrayJuegos[i].descripcion);
                    }

                    break;


                case 6:
                    printf("\ningrese nuevo importe: ");
                    scanf("%f", & arrayJuegos[i].importe);
                    while(arrayJuegos[i].importe <0)
                    {
                        printf("reingrese nuevo importe: ");
                        scanf("%f", & arrayJuegos[i].importe);

                    }
                    break;



                }
                printf("\nquiere modificar otro campo?\ns/para continuar n/para salir\n");
                modificacion=getch();
                system("cls");
            }
            while(modificacion=='s');


            flag=LLENO;
            break;
        }
    }
    if(flag==0)
    {
        printf("\nNo existe el codigo de juego vuelva a ingresarlo\n");
    }
}
void bajaJuego(sJuegos arrayJuegos[],int cant)
{

    int i;
    int flag=0;
    int aceptar1;
    int auxId2;
    printf("\nIngrese codigo de juego para dar de baja: ");
    scanf("%d", & auxId2);

    for( i=0; i<cant; i++)
    {
        if(arrayJuegos[i].isEmpty!=VACIO && auxId2==arrayJuegos[i].codigoDeJuego)
        {
            flag=1;
            printf("\ndesea dar de baja a este juego?\n s/para continuar n/para salir\n");
            aceptar1=getch();
            if(aceptar1 =='s')
            {
                printf("\nse ha dado de baja a este juego.\n");
                arrayJuegos[i].isEmpty=VACIO;
                break;
            }
            else if (aceptar1!='s')
            {
                printf("\nprecione s para volver al menu\n");
            }

        }

    }

    if(flag==0)
    {
        printf("\nNo existe el codigo de juego, vuelva a ingresarlo\n");
    }
}
void funcionListar( sJuegos arrayJuegos[], int cant)
{
    int i;
    int j;
    int a;
    sJuegos aux;
    sJuegos aux2;
    printf("  ordenado alfabeticamente por importe:\n");
    for(i=0; i< cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(arrayJuegos[i].importe>arrayJuegos[j].importe)
            {
                aux2=arrayJuegos[i];
                arrayJuegos[i]=arrayJuegos[j];
                arrayJuegos[j]=aux2;

            }
          }
    }
    for (i=0; i<cant; i++)
    {
        if(arrayJuegos[i].isEmpty==LLENO)
        {
            printf("  importe:%.2f \n",arrayJuegos[i].importe);
        }

    }
    printf("  ordenado alfabeticamente por descripcion:\n");
    for(i=0; i< cant-1; i++)
    {
        for(a=i+1; a<cant; a++)
        {
            if(stricmp(arrayJuegos[i].descripcion,arrayJuegos[a].descripcion)>0)
            {
                aux=arrayJuegos[i];
                arrayJuegos[i]=arrayJuegos[a];
                arrayJuegos[a]=aux;

            }
        }
    }
    for (i=0; i<cant; i++)
    {
        if(arrayJuegos[i].isEmpty==LLENO)
        {
            printf("  descripcion:%s \n",arrayJuegos[i].descripcion);
        }

    }
}
int funcionIdclientes(sClientes arrayClientes[],int cant)
{
    int i ;
    for( i=0; i<cant; i++)
    {
        if(arrayClientes[i].isEmpty==VACIO)
        {
            arrayClientes[i].codigoDeCliente=i;
            return i;

        }

    }
    return -1;
}

void inicializarArrayClientes(sClientes arrayClientes[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        arrayClientes[i].isEmpty=VACIO;
    }

}
int buscarEspacioEnElArrayCliente(sClientes arrayClientes[], int cant)
{
    int aux=VACIO;
    int i;

    for(i=0; i<cant; i++)
    {
        if(arrayClientes[i].isEmpty==VACIO)
        {
            aux=i;
            break;
        }
    }

    return aux;
}
void altaCliente(sClientes arrayClientes[],int cant,int i)
{
     printf("el codigo de cliente es:%d",i);

    printf("\n\nIngrese nombre: ");

    fflush(stdin);
    gets(arrayClientes[i].nombre);
    while(strlen(arrayClientes[i].nombre)>51)
    {
        printf("\nReingrese nombre: ");
        gets(arrayClientes[i].nombre);
    }


    printf("\nIngrese sexo: ");

    fflush(stdin);
    gets(arrayClientes[i].sexo);
    while(strlen(arrayClientes[i].sexo)>51)
    {
        printf("\nReingrese sexo: ");
        gets(arrayClientes[i].sexo);
    }


    printf("\ningrese telefono: ");
    gets(arrayClientes[i].telefono);


    while(strlen(arrayClientes[i].telefono)>21)
    {
        printf("\nreingrese telefono: ");
        gets(arrayClientes[i].telefono);
    }
    arrayClientes[i].codigoDeCliente=i;
    arrayClientes[i].isEmpty=LLENO;
}
void modificacionClientes(sClientes arrayClientes[],int cant)
{

    int aceptar2;
    int i ;
    int auxId;
    int flag =0;
    char modificacion;


    printf("\ningrese codigo de cliente para modificar : ");
    scanf("%d",&auxId);

    for(i=0; i<cant; i++)
    {
        if(arrayClientes[i].isEmpty!=VACIO && auxId==arrayClientes[i].codigoDeCliente)
        {
            do
            {
                system("cls");
                printf("-----------------\n");
                printf(" -9) SEXO       -\n");
                printf("-10) NOMBRE     -\n");
                printf("-11) TELEFONO   -\n");
                printf("                -\n");
                printf("-----------------\n");

                printf("ingrese el campo a modificar: ");
                scanf("%d",&aceptar2);
                system("cls");
                switch(aceptar2)
                {
                case 9:

                    printf("\ningrese nuevo sexo: ");
                    fflush(stdin);
                    gets(arrayClientes[i].sexo);
                    while(strlen(arrayClientes[i].sexo)>51)
                    {
                        printf("\nreingrese nuevo sexo: ");
                        fflush(stdin);
                        gets(arrayClientes[i].sexo);
                    }


                    break;


                case 10:
                    printf("\ningrese nuevo nombre: ");
                    fflush(stdin);
                    gets(arrayClientes[i].nombre);
                    while(strlen(arrayClientes[i].nombre)>51)
                    {
                        printf("\nreingrese nuevo nombre: ");
                        fflush(stdin);
                        gets(arrayClientes[i].nombre);
                    }
                    break;

                case 11:
                    printf("\ningrese nuevo telefono: ");
                    fflush(stdin);
                    gets(arrayClientes[i].telefono);
                    while(strlen(arrayClientes[i].telefono)>21)
                    {
                        printf("reingrese nuevo telefono: ");
                        fflush(stdin);
                        gets(arrayClientes[i].telefono);

                    }


                    break;


                }
                printf("\nquiere modificar otro campo?\ns/para continuar n/para salir\n");
                modificacion=getch();
                system("cls");
            }
            while(modificacion=='s');


            flag=LLENO;
            break;
        }
    }
    if(flag==0)
    {
        printf("\nNo existe el codigo de juego vuelva a ingresarlo\n");
    }
}
void bajaCliente(sClientes arrayClientes[],int cant)
{

    int i;
    int flag=0;
    int aceptar1;
    int auxId2;
    printf("\nIngrese codigo de cliente para dar de baja: ");
    scanf("%d", & auxId2);

    for( i=0; i<cant; i++)
    {
        if(arrayClientes[i].isEmpty!=VACIO && auxId2==arrayClientes[i].codigoDeCliente)
        {
            flag=1;
            printf("\ndesea dar de baja a este cliente?\n s/para continuar n/para salir\n");
            aceptar1=getch();
            if(aceptar1 =='s')
            {
                printf("\nse ha dado de baja a este cliente.\n");
                arrayClientes[i].isEmpty=VACIO;
                break;
            }
            else if (aceptar1!='s')
            {
                printf("\nprecione s para volver al menu\n");
            }

        }

    }

    if(flag==0)
    {
        printf("\nNo existe el codigo de cliente, vuelva a ingresarlo\n");
    }
}
void funcionListar2( sClientes arrayClientes[], int cant)
{
    int i;
    int j;
    int a;
    sClientes aux;
    sClientes aux2;
    printf("  ordenado alfabeticamente por nombre:\n");
    for(i=0; i< cant-1; i++)
    {
        for(a=i+1; a<cant; a++)
        {
            if(stricmp(arrayClientes[i].nombre,arrayClientes[a].nombre)>0)
            {
                aux2=arrayClientes[i];
                arrayClientes[i]=arrayClientes[a];
                arrayClientes[a]=aux2;

            }
        }
    }
    for (i=0; i<cant; i++)
    {
        if(arrayClientes[i].isEmpty==LLENO)
        {
            printf("  nombre:%s \n",arrayClientes[i].nombre);
        }

    }
    printf("  ordenado alfabeticamente por apellido:\n");
    for(i=0; i< cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(stricmp(arrayClientes[i].sexo,arrayClientes[j].sexo)>0)
            {
                aux=arrayClientes[i];
                arrayClientes[i]=arrayClientes[j];
                arrayClientes[j]=aux;

            }
        }
    }
    for (i=0; i<cant; i++)
    {
        if(arrayClientes[i].isEmpty==LLENO)
        {
            printf("  Sexo: %s \n",arrayClientes[i].sexo);
        }

    }
}
void mostrarId(sJuegos arrayJuegos[],int cant,int i)
{

    for(i=0; i<cant; i++)
    {
        if(arrayJuegos[i].isEmpty==LLENO)
        {

            printf("codigos de juegos:%d\n",i);
        }
    }

}
void mostrarId2(sClientes arrayClientes[],int cant,int i)
{

    for(i=0; i<cant; i++)
    {
        if(arrayClientes[i].isEmpty==LLENO)
        {
            printf("codigos de clientes:%d\n",i);
        }
    }

}
void altaAlquileres(sAlquileres arrayAlquileres[],sJuegos arrayJuegos[],sClientes arrayClientes[],int cant)
{
    int i ;


    int codjue;
    int codcli;
    int exito=0;
    sFecha fecha;



    do
    {
        printf("Ingrese codigo de juego: ");
        fflush(stdin);
        scanf("%d",&codjue);

        for (i=0; i<cant; i++)
        {
            if(arrayJuegos[i].isEmpty == LLENO && arrayJuegos[i].codigoDeJuego==codjue)
            {
                exito = 1;
                break;
            }
        }
        if (!exito)
        {
            printf("\nERROR! Id invalido!\n");
        }
    }
    while (exito == 0);

    exito = 0;

    do
    {
        printf("\ningrese codigo de cliente: ");
        fflush(stdin);
        scanf("%d",&codcli);
        for (int i=0; i<cant; i++)
        {
            if(arrayClientes[i].isEmpty == LLENO && arrayClientes[i].codigoDeCliente==codcli)
            {
                exito = 1;
            }
        }
        if (!exito)
        {
            printf("\nERROR! Id invalido!\n");
        }
    }
    while (!exito);

    printf("ingrese el dia: ");
    fflush(stdin);
    scanf("%d",& fecha.dia);
     printf("ingrese el mes: ");
    fflush(stdin);
    scanf("%d",& fecha.mes);
     printf("ingrese el anio: ");
    fflush(stdin);
    scanf("%d",& fecha.anio);
    printf("codigo de juego es:%d\n",codjue);
    printf("codigo de cliente es:%d\n",codcli);
    printf("tu codigo de alquiler es:%d\n" ,funcionIdAlquiler(arrayAlquileres,A));
    printf("gracias por comprar, le recuerdo que tiene una semana sus datos son:%d %d\n %d\n %d\n %d\n" ,codjue,codcli,fecha.dia,fecha.mes,fecha.anio);

}
int funcionIdAlquiler(sAlquileres arrayAlquieres[],int cant)
{
    int i ;
    for( i= 0; i<cant; i++)
    {

        if(arrayAlquieres[i].isEmpty==VACIO)
        {
            arrayAlquieres[i].codigoDeAlquiler=i;
            return i;
        }
    }
     return-1;
}



