#pragma once

#include"struct.h"
#include"extrafunctions.h"
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<stdbool.h>

int modificar(FILE *ficheromod) {
  
 FILE *temporal;
 struct product_template temp_c;



 


  char IDseeker[10];

  int cantextract;

  int sucursalorg =0;
  int sucursaldest =0;
  int cantextract2 =0;
  
 
  //  int valuetochange = 0; 
 
 ficheromod = fopen("masterfile.txt","r");
 temporal = fopen("temporal.txt","a+");

printf("Ingrese la ID del producto que desea comprar\n");
  gets(IDseeker);
  limipiarbuffer();

   while (fread(&temp_c, sizeof(struct product_template), 1, ficheromod) == 1) {
     
     if (!strcmp(temp_c.prodID, IDseeker)) {
          printf("%s\n", temp_c.prodID);
          printf("central: %d \n", temp_c.sub.cantidad_en_centra);
          printf("1: %d \n", temp_c.sub.cantidad_en_sucursal_1);
          printf("2: %d \n", temp_c.sub.cantidad_en_sucursal_2);
          printf("3: %d \n", temp_c.sub.cantidad_en_sucursal_3);
          printf("4: %d \n", temp_c.sub.cantidad_en_sucursal_4);

          printf("Digite la sucursal de origen: ");
          scanf("%d",&sucursalorg);
          limipiarbuffer();

          printf("Digite la cantidad retirada: ");
          scanf("%d",&cantextract2);
          limipiarbuffer();


           switch (sucursalorg)
          {
          case 1:
            while (cantextract > temp_c.sub.cantidad_en_sucursal_1) {
                 printf("cantidad excede existencias, digite denuevo");
                 scanf("%d", &cantextract);
                 limipiarbuffer();
            }
            temp_c.sub.cantidad_en_sucursal_1 = temp_c.sub.cantidad_en_sucursal_1 - cantextract2; 
            break;
          
          default:
            break;
          }
          
          printf("Digite la sucursal donde se depositaran los productos");
          scanf("%d",&sucursaldest);

          switch (sucursaldest)
          {
          case 1:
            /* code */
            break;
          case 2:
            temp_c.sub.cantidad_en_sucursal_2 = temp_c.sub.cantidad_en_sucursal_2 + cantextract2;
            break;
          
          default:
            break;
          }


    
     } else {
        fwrite(&temp_c, sizeof(struct product_template), 1, temporal);
     }
   }




  fclose(temporal);
 fclose(ficheromod);
 int borrado;
 borrado = remove("masterfile.txt");
    if(borrado==0)
    {
        rename("temporal.txt", "masterfile.txt");
    }
  return 0;
}


int verportipo(FILE *ficherodeverportipo) {

struct product_template estructura;
int tipo;
int comparador;
    
ficherodeverportipo = fopen("masterfile.txt","r");
rewind(ficherodeverportipo);


printf("Digite tipo\n");
scanf("%d",&tipo);
limipiarbuffer();
 
switch (tipo)
{ 
case 1:
    comparador =1;
    break;
case 2:
    comparador =2;
    break;
case 3:
    comparador =3;
    break;
case 4:
    comparador =4;
    break;
default:
    break;
}

 while (fread(&estructura, sizeof(struct product_template), 1, ficherodeverportipo) == 1) {

   if (estructura.tipo==comparador) {
       printf("\n \n%s \n",estructura.prodID);
       printf("\nNombre: %s \n", estructura.nombre);
       printf("Precio: %.2f \n", estructura.priceunit);
       printf("Descripcion: %s \n", estructura.descripcion);

       printf("central: %d \n", estructura.sub.cantidad_en_centra);
       printf("1: %d \n", estructura.sub.cantidad_en_sucursal_1);
       printf("2: %d \n", estructura.sub.cantidad_en_sucursal_2);
       printf("3: %d \n", estructura.sub.cantidad_en_sucursal_3);
       printf("4: %d \n", estructura.sub.cantidad_en_sucursal_4);
   }
    
 }
    fclose(ficherodeverportipo);
    return 0;
}

int verespecifico() {
    limipiarbuffer();
  cleanscreen();
  
  FILE *fileused_0;
  struct product_template temp_0;

  printf("\n comprob \n");

  fileused_0 = fopen("masterfile.txt","r");
  fread(&temp_0, sizeof(struct product_template),1, fileused_0);
  char IDseeker[10];
  int exit;
  gets(IDseeker);

  while(!feof(fileused_0) && exit != 1) {

  if(!strcmp(IDseeker, temp_0.prodID)) { 
    limipiarbuffer();
    printf("\nNombre: %s \n", temp_0.nombre);
    printf("Precio: %.2f \n", temp_0.priceunit);
    printf("Descripcion: %s \n", temp_0.descripcion);

    printf("central: %d \n", temp_0.sub.cantidad_en_centra);
    printf("1: %d \n", temp_0.sub.cantidad_en_sucursal_1);
    printf("2: %d \n", temp_0.sub.cantidad_en_sucursal_2);
    printf("3: %d \n", temp_0.sub.cantidad_en_sucursal_3);
    printf("4: %d \n", temp_0.sub.cantidad_en_sucursal_4);
    exit =1 ;
  } 
  fread(&temp_0, sizeof(struct product_template),1, fileused_0);
      
  } 

    return 0;
}



int versucursal(FILE *ficherosucural) {

    ficherosucural = fopen("masterfile.txt","r");
    struct product_template estructura;


  int sucselct;

  printf("Elija la sucursal que quiera ver\n");
  scanf("%d",&sucselct);
   limipiarbuffer();
  switch (sucselct)
  {
  case 1:
    
    printf("Productos disponibles en sucursal 1: \n");  
    rewind(ficherosucural);  
    while (fread(&estructura, sizeof(struct product_template), 1, ficherosucural) == 1) {

   if (estructura.sub.cantidad_en_sucursal_1 != 0) {
       printf("%s \n",estructura.prodID);
       printf("Nombre: %s \n", estructura.nombre);
       printf("Precio: %.2f \n", estructura.priceunit);
       printf("Descripcion: %s \n", estructura.descripcion);

       printf("central: %d \n", estructura.sub.cantidad_en_centra);
       printf("cantidad: %d \n\n", estructura.sub.cantidad_en_sucursal_1);
      
   }
     limipiarbuffer();
 }
    
    break;
  case 2:
    printf("Productos disponibles en sucursal 2: \n");    
    while (fread(&estructura, sizeof(struct product_template), 1, ficherosucural) == 1) {

   if (estructura.sub.cantidad_en_sucursal_2 > 0) {
       printf("%s \n",estructura.prodID);
       printf("Nombre: %s \n", estructura.nombre);
       printf("Precio: %.2f \n", estructura.priceunit);
       printf("Descripcion: %s \n", estructura.descripcion);

       printf("central: %d \n", estructura.sub.cantidad_en_centra);
       printf("cantidad: %d \n\n", estructura.sub.cantidad_en_sucursal_2);

    
   }
    
 }
    break;
  case 3:
    printf("Productos disponibles en sucursal 3: \n");    
    while (fread(&estructura, sizeof(struct product_template), 1, ficherosucural) == 1) {

   if (estructura.sub.cantidad_en_sucursal_3 > 0) {
       printf("%s \n",estructura.prodID);
       printf("Nombre: %s \n", estructura.nombre);
       printf("Precio: %.2f \n", estructura.priceunit);
       printf("Descripcion: %s \n", estructura.descripcion);

       printf("central: %d \n", estructura.sub.cantidad_en_centra);
       printf("cantidad: %d \n\n", estructura.sub.cantidad_en_sucursal_3);

    
   }
    
 }
    break;
  case 4:
    printf("Productos disponibles en sucursal 1: \n");    
    while (fread(&estructura, sizeof(struct product_template), 1, ficherosucural) == 1) {

   if (estructura.sub.cantidad_en_sucursal_4 > 0) {
       printf("%s \n",estructura.prodID);
       printf("Nombre: %s \n", estructura.nombre);
       printf("Precio: %.2f \n", estructura.priceunit);
       printf("Descripcion: %s \n", estructura.descripcion);

       printf("central: %d \n", estructura.sub.cantidad_en_centra);
       printf("cantidad: %d \n\n", estructura.sub.cantidad_en_sucursal_4);

    
   }
    
 }
    break;  

  default:
    break;
  }





    fclose(ficherosucural);
    return 0;
}