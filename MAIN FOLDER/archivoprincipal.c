#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<stdbool.h>
#include"FuncionesMario.h"
#include"FuncionesDavid.h"
#include"FuncionesClaudia.h"
#include"archivodeestructuras.h"
#include"archivodefunciones.h"

void gestion_inv() 
{
cleanscreen();

FILE *Franchyeska = NULL;
FILE *Dat=NULL; 


int bandera =0;
int eleccion = 0;
while (bandera != 1) 
 {
printf("\n Menu de inventario \n 1. Agregar Productos \n 2. Trasladar productos entre sucursales\n 3. Menu de visulisacion de Productos \n 4. Volver\n");
scanf("%d",&eleccion);
switch (eleccion)
     {
case 1:
    PrincipFunc_Agregar(Franchyeska,Dat);
    cleanscreen();
    break;

case 2:
    transferencia_interna_prods();
    cleanscreen();
    break;

case 3:
    visualizarProductos(Franchyeska);
    cleanscreen();
    break;

case 4:
    bandera =1;
    cleanscreen();
    
    break;

default:
    printf("opcion invalida\n");
    system("pause");
    break;
    }
  }
}

int main(){
  int loopexit=0;
  int opcion;

  while (loopexit!=1)
  {
    system("cls");
    printf("Bienvenido a \n Usted dispone de las siguientes opciones: \n");
    printf(" 1. Gestion de inventario \n 2. Facturar productos\n 4. Salir del programa\n");
    scanf("%d",&opcion);
    limpiarbuffer();

    switch (opcion)
    {
    case 1:
        gestion_inv();
        break;
    case 2:
        menu_fac();
        break;

    case 4:
        loopexit =1;
        break;
    
    default:
      printf("Opcion invalida\n");
        break;
    }
  }
  
   

    return 0;
}