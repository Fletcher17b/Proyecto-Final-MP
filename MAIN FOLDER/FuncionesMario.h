#pragma once
#include"archivodeestructuras.h"
#include"archivodefunciones.h"
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<stdbool.h>

/*
 - Que cosas van aqui?
      - Ver productos por:
        -Tipo
        -Sucurcal
        -Producto particular
  
      - Cuando hay una compra (ingreso de productos) mediante la funcion "modificar" se realiza la suma 

 - Notas:
    Estas funciones tienen que estar dentro de un menu con un puntero, las funciones reciven ese puntero (no lo crean individualmente)
    ejemplo:

    int menu() {
       FILE *cualquiernombre = NULL;
       
       switch(var) {
        case x:
          funcion_a_llamar(cualquiernombre);
        break;
       }
        return 69;
    }

 - Detalles de funciones:

    transferencia_interna_prods: usada para transferir entre sucursales cantidades de productos
    ver por tipos: imprime en pantalla los productos que sean iguales al tipo seleccionado
    versucursal: Usuario elije una sucursal y todos los productos que tengan existencias en esa sucursal se imprimen en pantalla


*/


int transferencia_interna_prods(FILE *ficheromod) {
  
 FILE *temporal;
 struct product_template temp_c;


  char IDseeker[10];

  int cantextract;

  int banderaloop1=0;
  int banderaloop2=0;

  int sucursalorg =0;
  int sucursaldest =0;
  int cantextract2 =0;
  
 
  //  int valuetochange = 0; 
 
 ficheromod = fopen("masterfile.txt","r");
 temporal = fopen("temporal.txt","a+");

printf("Ingrese la ID del producto del cual se le aumentara la cantidad\n");
  fgets(IDseeker,sizeof(IDseeker),stdin);
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
          

        while (banderaloop1 !=1) {
          scanf("%d",&cantextract2);
          limipiarbuffer();
           switch (sucursalorg)
          {
          case 1:
            while (cantextract2 > temp_c.sub.cantidad_en_sucursal_1) {
                 printf("cantidad excede existencias, digite denuevo: ");
                 scanf("%d", &cantextract2);
                 limipiarbuffer();
            }
            temp_c.sub.cantidad_en_sucursal_1 = temp_c.sub.cantidad_en_sucursal_1 - cantextract2; 
            banderaloop1 =1;
            break;

            case 2:
            while (cantextract2 > temp_c.sub.cantidad_en_sucursal_2) {
                 printf("cantidad excede existencias, digite denuevo: ");
                 scanf("%d", &cantextract2);
                 limipiarbuffer();
            }
            temp_c.sub.cantidad_en_sucursal_2 = temp_c.sub.cantidad_en_sucursal_2 - cantextract2; 
            banderaloop1 =1;
            break;

            case 3:
            while (cantextract2 > temp_c.sub.cantidad_en_sucursal_3) {
                 printf("cantidad excede existencias, digite denuevo: ");
                 scanf("%d", &cantextract2);
                 limipiarbuffer();
            }
            temp_c.sub.cantidad_en_sucursal_3 = temp_c.sub.cantidad_en_sucursal_3 - cantextract2; 
            banderaloop1 =1;
            break;

            case 4:
            while (cantextract2 > temp_c.sub.cantidad_en_sucursal_4) {
                 printf("cantidad excede existencias, digite denuevo: ");
                 scanf("%d", &cantextract2);
                 limipiarbuffer();
            }
            temp_c.sub.cantidad_en_sucursal_4 = temp_c.sub.cantidad_en_sucursal_4 - cantextract2; 
            banderaloop1 =1;
            break;
          
          default:
            printf("cantidad invalida\n");

            break;
          }
          
     }
          
          
          
          printf("Digite la sucursal donde se depositaran los productos");

      while(banderaloop2!=1) {
          scanf("%d",&sucursaldest);
          limipiarbuffer();

          switch (sucursaldest)
          {
          case 1:
            temp_c.sub.cantidad_en_sucursal_1 = temp_c.sub.cantidad_en_sucursal_1 + cantextract2;
            banderaloop2=1;
            break;
          case 2:
            temp_c.sub.cantidad_en_sucursal_2 = temp_c.sub.cantidad_en_sucursal_2 + cantextract2;
            banderaloop2=1;
            break;
          case 3:
            temp_c.sub.cantidad_en_sucursal_3 = temp_c.sub.cantidad_en_sucursal_3 + cantextract2;
            banderaloop2=1;
            break;
          case 4:
            temp_c.sub.cantidad_en_sucursal_4 = temp_c.sub.cantidad_en_sucursal_4 + cantextract2;
            banderaloop2=1;
            break;
          default:
           printf("surcursal invalida\n");
            break;
          }

     }
          fwrite(&temp_c, sizeof(struct product_template), 1, temporal);

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

int versucursal(FILE *ficherosucural) {

    ficherosucural = fopen("masterfile.txt","r");

    if (ficherosucural == NULL) {
    printf("Error \n"); 
    return 1;
    }
    struct product_template estructura;
    int banderadelloop =0;


  int sucselct;

  printf("Elija la sucursal que quiera ver\n");

  while (banderadelloop!=1) {
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
    banderadelloop =1;
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
    banderadelloop =1;
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
    banderadelloop =1;
    break;
  case 4:
    printf("Productos disponibles en sucursal 4: \n");    
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
    banderadelloop =1;
    break;  

  default:
    printf("Sucursal inexistente, digite denuevo: ");
    break;
  }

  }



    fclose(ficherosucural);
    return 0;
}