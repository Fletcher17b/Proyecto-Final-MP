#pragma once

#include"struct.h"
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<stdbool.h>

void limipiarbuffer() {
    fflush(stdin);
    fflush(stdout);
}

void cleanscreen() {
    system("pause");
    system("cls");
}

struct product_template get_info() {
    struct product_template input;
    int prodtype;
      printf("\nIngrese ID del producto (maximo 10 caracteres, no se debe repetir) ");
      gets(input.prodID);
      limipiarbuffer(); 

      
      printf("\nIngrese nombre: ");
      scanf("%s",input.nombre);
      limipiarbuffer();

      printf("\nSeleccione tipo del producto ( \n ");
      printf("1. Brazalete \n 2. Pulsera \n 3. Chapa \n 4. Collar \n 5. Anillos \n 6. Cadenas \n ");
      scanf("%d", &prodtype);
      switch (prodtype)
      {
      case 1:
        input.tipo = 1;
        break;

      case 2:
        input.tipo =2;
        break;
      default:
        break;
      }

      limipiarbuffer();

     int cant_centralverifier = 0;
     
      
      printf("\nIngrese la cantidad central: ");
      cant_centralverifier = scanf("%d",&input.sub.cantidad_en_centra);
      limipiarbuffer();
      while (cant_centralverifier == 0) {
          printf("\n invalid input, ingrese valor otra vez\n");
          cant_centralverifier = scanf("%d",&input.sub.cantidad_en_centra);
          limipiarbuffer();
      }

      int cantidades_conduerdan = 0;
       
      while (cantidades_conduerdan != 1 ) {
        printf("\nIngrese la cantidad en sucursal 1: ");
        scanf("%d",&input.sub.cantidad_en_sucursal_1);
        limipiarbuffer();

        printf("\nIngrese la cantidad sucursal 2: ");
        scanf("%d",&input.sub.cantidad_en_sucursal_2);
        limipiarbuffer();

        printf("\nIngrese la cantidad sucursal 3: ");
        scanf("%d",&input.sub.cantidad_en_sucursal_3);
        limipiarbuffer();

        printf("\nIngrese la cantidad sucursal 4: ");
        scanf("%d",&input.sub.cantidad_en_sucursal_4);
        limipiarbuffer();
        
        int suma = input.sub.cantidad_en_sucursal_1 + input.sub.cantidad_en_sucursal_2 + input.sub.cantidad_en_sucursal_3 + input.sub.cantidad_en_sucursal_4;
        if (suma != input.sub.cantidad_en_centra) {
          printf("\ncantidades repartidas no concuerdan con la central, cantidad central: %d\n", input.sub.cantidad_en_centra);
        } else {
          cantidades_conduerdan = 1;
        }
      }


    return input;
}

int agregarprod(FILE *fileused_a) {

  limipiarbuffer();

  struct product_template structtemp;
  int guardadobien = 0;

   fileused_a = fopen("masterfile.txt","a");
        
      limipiarbuffer();
      structtemp = get_info();
      guardadobien = fwrite(&structtemp, sizeof(struct product_template),1, fileused_a );

      if (guardadobien >0) {
       printf("todo chingon\n");
      } else 
       {
        printf("nel perro \n");
       }
        
       
        
    

    fclose(fileused_a);


  
  
  //fclose(fileused_a);

  
  
  return 0;
}