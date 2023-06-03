#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<stdbool.h>
#include"FuncionesMario.h"
#include"FuncionesDavid.h"
#include"archivodeestructuras.h"
#include"archivodefunciones.h"

void gestion_inv() 
{
cleanscreen();

FILE *Franchyeska = NULL;
FILE *Dat=NULL; 
struct Productos pr1;

int bandera =0;
int eleccion = 0;
while (bandera != 1) 
 {
printf("\n Menu de inventario \n 1. Agregar Productos \n 2. Trasladar productos entre sucursales\n 3. Menu de visulisacion de Productos \n 4. Volver\n");
scanf("%d",&eleccion);
switch (eleccion)
     {
case 1:
    PrincipFunc_Agregar(Franchyeska,pr1,Dat);
    cleanscreen();
    break;

case 2:
    transferencia_interna_prods(Franchyeska);
    cleanscreen();
    break;

case 3:
    visualizarProductos(Franchyeska,pr1);
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

    gestion_inv();

    return 0;
}