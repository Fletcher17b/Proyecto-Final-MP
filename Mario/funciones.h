#pragma once
#include"datablueprintfile.h"

#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>

struct product_template globalinventory[100];
int globalinvetoryposition = 100;

void limipiarbuffer() {
    fflush(stdin);
    fflush(stdout);
}

void cleanscreen() {
    system("pause");
    system("cls");
}


// menu de nuevos productos 
int menu1() {
    limipiarbuffer();
    int opc1;
    int exitmenu1;

    
  
  while (exitmenu1 != 1) {
    printf("\n Sus opciones son: \n 1. Ingresar nuevos productos\n 2. Actualizar cantidades de productos\n 3. Remover Productos \n 4. Salir al menu principal \n");
    scanf("%d",&opc1);
    switch (opc1) {
        case 1: 
          limipiarbuffer();
          cleanscreen();
          nuevosproductos();
          exitmenu1 =1;
          break;

        case 2:
          // actualizar cantidades
          break;

        case 3:
          // remover productos
          break;
        case 4:
          exitmenu1 = 1;
          break;  

        default:
         printf("opcion invalida");
         cleanscreen();
         break;
    }

  }
    return 0;
}

int menu2() {
  limipiarbuffer();
  int opc2;
  int exitmenu2 =0; 

  while (exitmenu2 != 1)
  {
    printf("\n Sus opciones son: \n 1.  \n 4.  \n");
    scanf("%d",&opc2);

    switch (opc2)
    {
    case 1:
      /* code */
      break;
    
    default:
      break;
    }
  }
  


  return 0;
}

struct product_template get_info() {
    struct product_template input;
      printf("\nIngrese ID del producto (maximo 10 caracteres, no se debe repetir) ");
      gets(input.prodID);
      limipiarbuffer(); 
      
      printf("\nIngrese nombre: ");
      scanf("%s",input.nombre);
      limipiarbuffer();

      printf("\nIngrese precio: ");
      scanf("%f",&input.price);
      limipiarbuffer();

      printf("\nIngrese una breve descripcion del producto: ");
      scanf("%s",input.descripcion);
      limipiarbuffer();
      
      printf("\nIngrese precio: ");
      scanf("%d",&input.sub.cantidad_en_centra);
      limipiarbuffer();

      


    return input;
}

int nuevosproductos() {
    int cant=0;
    int n =0;
    //int *sizeofarray;
    // struct product_template temp;
    struct product_template *templist;
    printf("Ingrese # prods \n");
    scanf("%d",&cant);


   templist = (struct product_template*) malloc(cant*sizeof(struct product_template) );

   while (n < cant) { 
      templist[n] = get_info();
      n++;
    }
     



       


    return 0;
}



int menu0(){
  
   int opc0;
   int centinela0;

while(centinela0 !=1 ) {

   printf("Sus opciones consisten en: \n 1. Modificar Inventario actual \n 2. Continuar con inventario actual \n 3. Salir \n");
   scanf("%d", &opc0 );

   switch (opc0)
   {
   case 1:
      printf(" \n usted ha seleccionado opcion 1 \n");
      limipiarbuffer();
      menu1();
      cleanscreen();    
    break;

    case 2:
      printf(" \n usted ha seleccionado opcion 2 \n");
      limipiarbuffer();
      menu2();
      cleanscreen();  
     break;

    case 3: 
     centinela0 = 1;  
     break;
   
   default:
    printf("\n usted ha ingresado un valor invalido por favor, ingrese denuevo \n");
    cleanscreen();
    break;
   }

}

    return 0;
}