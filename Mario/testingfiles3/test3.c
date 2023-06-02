#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<stdbool.h>
#include"struct.h"
#include"extrafunctions.h"
#include"funciones_de_verprods.h"


int vercantidades() {

    FILE *elfichero = NULL;
    
    
  limipiarbuffer();
  int loopexit = 0;
  int choice2;

while (loopexit != 1) {
    limipiarbuffer();
    printf("Ver productos: \n 1. Por tipo \n 2. Producto especifico\n 3. Por sucursal \n 4. Salir \n");
    scanf("%d", &choice2);
    switch (choice2)
    {
    case 1:
        cleanscreen();
        verportipo(elfichero);
        break;

    case 2:
        cleanscreen();
        verespecifico();
        break;

    case 3:
        cleanscreen();
        versucursal(elfichero);
        break;

    case 4:
        loopexit =1;
        cleanscreen();
        break;
    
    default:
      printf("opcion invalida");
      cleanscreen();
        break;
    }

}

    return 0;
}

int movercantidades(){

    
    
 


    limipiarbuffer();
  int loopexit = 0;
  int choice2;

  printf("di");

    return 0;
}

int menubodegas() {

   int loopexit = 0;
   int choice;
   limipiarbuffer();
  
   while (loopexit != 1)
   {
     limipiarbuffer();
     printf("Digite opcion\n");
     printf(" 1. ver cant \n 2. mover productos entre sucursales \n");
     scanf("%d",&choice);
     
     limipiarbuffer();
     switch (choice)
     {
     case 1:
        printf("Ver cantidades\n");
        vercantidades();
        break;

    case 2:
        printf("Mover productos\n");
        movercantidades();

        break;
     
     default:
        break;
     }
   }
   

    return 0;
}



int main() {
    
    FILE *elfichero = NULL;
    int loopexit =0;
    int choice;
    int exit;

while (loopexit != 1) {
cleanscreen();
    
    printf("Menu\n");
    printf(" 1. Ingreso de productos () \n 2. Informacion de clientes \n 3. Facturacion \n 4. Control de bodegas \n 10. Salir\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        agregarprod(elfichero);
        break;

    case 2:
        /* code */
        break;

    case 3:
        /* code */
        break;

    case 4:
        printf("Entrando a menu de bodegas\n");
        cleanscreen();
        menubodegas();
        break;

    case 5:
        /* code */
        break;

    case 10:
        printf("exit (1)?\n");
        scanf("%d",&exit);
        if (exit == 1) {
            printf("you exited");
            loopexit =1;
        } else { printf("non valid"); cleanscreen();}
        break;
    
    default:
      printf("opcion invalida\n");
        break;
    }
}

    return 0;
}