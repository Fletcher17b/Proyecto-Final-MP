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
        -traslado interno de productos entre sucursales
        -Tipo
        -Sucurcal
        - WIP: manejo de existencias en la factura
  
      - Cuando hay una compra (ingreso de productos) mediante la funcion "modificar" se realiza la suma 

 - Detalles de funciones:

    transferencia_interna_prods: usada para transferir entre sucursales cantidades de productos
    ver por tipos: imprime en pantalla los productos que sean iguales al tipo seleccionado
    versucursal: Usuario elije una sucursal y todos los productos que tengan existencias en esa sucursal se imprimen en pantalla


*/


int transferencia_interna_prods() {

  //codigos de error: 1 rename() no funciono 2 remove() no funciono, 0 es que todo bien
  FILE *ficheromod;
  FILE *temporal;
 struct Productos temp_c;
  char IDseeker[10];
  int banderaloop1=0;
  int banderaloop2=0;
  int sucursalorg =0;
  int sucursaldest =0;
  int cantextract2 =0;
 
   ficheromod = fopen("Master.txt","r");
  temporal = fopen("temp.txt","w+");

//Validacion 
 if (ficheromod == NULL || temporal == NULL) {
        printf("Error al abrir fichero \n");
        return 1;
    }

//Proceso principal
  limpiarbuffer();
  printf("Ingrese la ID del producto el cual se va a transferir\n");
  gets(IDseeker);
  limpiarbuffer();
   
   rewind(ficheromod);
   int bumb;
   bumb = fread(&temp_c, sizeof(struct Productos), 1, ficheromod);
   printf("%d\n",bumb);
   
   rewind(ficheromod);
   while (fread(&temp_c, sizeof(struct Productos), 1, ficheromod) == 1) {
     
     if (!strcmp(temp_c.prodID, IDseeker)) {
          printf("%s\n", temp_c.prodID);
          printf("central: %d \n", temp_c.sub.SucursalCentral);
          printf("1: %d \n", temp_c.sub.sucursal_1);
          printf("2: %d \n", temp_c.sub.sucursal_2);
          printf("3: %d \n", temp_c.sub.sucursal_3);
          printf("4: %d \n", temp_c.sub.sucursal_4);

        int sucurvalid =0;
        printf("Digite la sucursal de origen: ");
        while (sucurvalid !=1)
        {
          
          scanf("%d",&sucursalorg);
          if (sucursalorg == 1 || sucursalorg ==2 || sucursalorg == 3||sucursalorg == 4 )
          { sucurvalid =1;} else { printf("Cant invalid\n"); }
        }
        
          
        
          limpiarbuffer();

          printf("Digite la cantidad retirada: ");
          

        while (banderaloop1 !=1) { 
          scanf("%d",&cantextract2);
          limpiarbuffer();
           switch (sucursalorg)
          {
          case 1:
            while (cantextract2 > temp_c.sub.sucursal_1) {
                 printf("cantidad excede existencias, digite denuevo: ");
                 scanf("%d", &cantextract2);
                 limpiarbuffer();
            }
            temp_c.sub.sucursal_1 = temp_c.sub.sucursal_1 - cantextract2; 
            banderaloop1 =1;
            break;

            case 2:
            while (cantextract2 > temp_c.sub.sucursal_2) {
                 printf("cantidad excede existencias, digite denuevo: ");
                 scanf("%d", &cantextract2);
                 limpiarbuffer();
            }
            temp_c.sub.sucursal_2 = temp_c.sub.sucursal_2 - cantextract2; 
            banderaloop1 =1;
            break;

            case 3:
            while (cantextract2 > temp_c.sub.sucursal_3) {
                 printf("cantidad excede existencias, digite denuevo: ");
                 scanf("%d", &cantextract2);
                 limpiarbuffer();
            }
            temp_c.sub.sucursal_3 = temp_c.sub.sucursal_3 - cantextract2; 
            banderaloop1 =1;
            break;

            case 4:
            while (cantextract2 > temp_c.sub.sucursal_4) {
                 printf("cantidad excede existencias, digite denuevo: ");
                 scanf("%d", &cantextract2);
                 limpiarbuffer();
            }
            temp_c.sub.sucursal_4 = temp_c.sub.sucursal_4 - cantextract2; 
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
          limpiarbuffer();

          switch (sucursaldest)
          {
          case 1:
            temp_c.sub.sucursal_1 = temp_c.sub.sucursal_1 + cantextract2;
            banderaloop2=1;
            break;
          case 2:
            temp_c.sub.sucursal_2 = temp_c.sub.sucursal_2 + cantextract2;
            banderaloop2=1;
            break;
          case 3:
            temp_c.sub.sucursal_3 = temp_c.sub.sucursal_3 + cantextract2;
            banderaloop2=1;
            break;
          case 4:
            temp_c.sub.sucursal_4 = temp_c.sub.sucursal_4 + cantextract2;
            banderaloop2=1;
            break;
          default:
           printf("surcursal invalida\n");
            break;
          }

     }
          fwrite(&temp_c, sizeof(struct Productos), 1, temporal);

     } else {
        fwrite(&temp_c, sizeof(struct Productos), 1, temporal);
     }

   }



  int cerro1,cerro2; //Variables para acesiorarse que cerrraron bien los ficheros
  cerro1 = fclose(temporal);
  cerro2 = fclose(ficheromod);

  if (cerro1 == 0 ) {
    printf("cerro bien temporal\n");
  }

  if (cerro2 == 0 ) {
    printf("cerro bien master\n");
  }

  // Codigo no funciona sin esto, por que? no tengo idea -Mario
    ficheromod = fopen("Master.txt", "a"); //cambiar a por w
    fclose(ficheromod);

   int borrado = remove("Master.txt");
   printf("remove: %d\n",borrado);
    if (borrado == 0) {
        int renombrado = rename("temp.txt", "Master.txt");
        printf("rename: %d\n",renombrado);
        if (renombrado != 0) {
            printf("Error en rename()\n");
            return 1; 
        }
    } else {
        printf("Error al borrar Master\n");
        return 2;
    }

  return 0;
}

int verportipo(FILE *ficherodeverportipo) {

struct Productos estructura;
int tipo;
int comparador;
    
ficherodeverportipo = fopen("Master.txt","r");
rewind(ficherodeverportipo);


printf("Digite tipo\n");
scanf("%d",&tipo);
limpiarbuffer();
 
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

 while (fread(&estructura, sizeof(struct Productos), 1, ficherodeverportipo) == 1) {

   if (estructura.tipo==comparador) {
       printf("\n \n%s \n",estructura.prodID);
       printf("\nNombre: %s \n", estructura.nombre);
       printf("Precio: %.2f \n", estructura.price);
       printf("Descripcion: %s \n", estructura.descripcion);

       printf("central: %d \n", estructura.sub.SucursalCentral);
       printf("1: %d \n", estructura.sub.sucursal_1);
       printf("2: %d \n", estructura.sub.sucursal_2);
       printf("3: %d \n", estructura.sub.sucursal_3);
       printf("4: %d \n", estructura.sub.sucursal_4);
   }
    
 }
    fclose(ficherodeverportipo);
    return 0;
}

int versucursal(FILE *ficherosucural) {

    ficherosucural = fopen("Master.txt","r");

    if (ficherosucural == NULL) {
    printf("Error \n"); 
    return 1;
    }
    struct Productos estructura;
    int banderadelloop =0;


  int sucselct;

  printf("Elija la sucursal que quiera ver\n");

  while (banderadelloop!=1) {
  scanf("%d",&sucselct);
  limpiarbuffer();
  switch (sucselct)
  {
  case 1:
    
    printf("Productos disponibles en sucursal 1: \n");  
    rewind(ficherosucural);  
    while (fread(&estructura, sizeof(struct Productos), 1, ficherosucural) == 1) {

   if (estructura.sub.sucursal_1 != 0) {
       printf("%s \n",estructura.prodID);
       printf("Nombre: %s \n", estructura.nombre);
       printf("Precio: %.2f \n", estructura.price);
       printf("Descripcion: %s \n", estructura.descripcion);

       printf("central: %d \n", estructura.sub.SucursalCentral);
       printf("cantidad: %d \n\n", estructura.sub.sucursal_1);
      
   }
     limpiarbuffer();
 }
    banderadelloop =1;
    break;
  case 2:
    printf("Productos disponibles en sucursal 2: \n");    
    while (fread(&estructura, sizeof(struct Productos), 1, ficherosucural) == 1) {

   if (estructura.sub.sucursal_2 > 0) {
       printf("%s \n",estructura.prodID);
       printf("Nombre: %s \n", estructura.nombre);
       printf("Precio: %.2f \n", estructura.price);
       printf("Descripcion: %s \n", estructura.descripcion);

       printf("central: %d \n", estructura.sub.SucursalCentral);
       printf("cantidad: %d \n\n", estructura.sub.sucursal_2);
   }
    
 }
    banderadelloop =1;
    break;
  case 3:
    printf("Productos disponibles en sucursal 3: \n");    
    while (fread(&estructura, sizeof(struct Productos), 1, ficherosucural) == 1) {

   if (estructura.sub.sucursal_3 > 0) {
       printf("%s \n",estructura.prodID);
       printf("Nombre: %s \n", estructura.nombre);
       printf("Precio: %.2f \n", estructura.price);
       printf("Descripcion: %s \n", estructura.descripcion);

       printf("central: %d \n", estructura.sub.SucursalCentral);
       printf("cantidad: %d \n\n", estructura.sub.sucursal_3);

    
   }
    
 }
    banderadelloop =1;
    break;
  case 4:
    printf("Productos disponibles en sucursal 4: \n");    
    while (fread(&estructura, sizeof(struct Productos), 1, ficherosucural) == 1) {

   if (estructura.sub.sucursal_4 > 0) {
       printf("%s \n",estructura.prodID);
       printf("Nombre: %s \n", estructura.nombre);
       printf("Precio: %.2f \n", estructura.price);
       printf("Descripcion: %s \n", estructura.descripcion);

       printf("central: %d \n", estructura.sub.SucursalCentral);
       printf("cantidad: %d \n\n", estructura.sub.sucursal_4);

    
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

// Funcion en WIP



int manejoexistenciasfact(int sucursal ,char IDdelprod[10],int cantidadretirada) {

  //Funcion en WIP pendiente comprobar con Claudia si funciona en conjunto con su parte
  //codigos de error: 1 rename() no funciono 2 remove() no funciono, 0 es que todo bien

  FILE *ficheromod = NULL;
  FILE *temporal = NULL;
  struct Productos temp_c;

  ficheromod = fopen("Master.txt","r");
  temporal = fopen("temp.txt","w+");
  
  rewind(ficheromod);
  while (fread(&temp_c, sizeof(struct Productos), 1, ficheromod) == 1) 
  {
    if (!strcmp(IDdelprod,temp_c.prodID)) 
    {
       switch (sucursal)
       {
       case 1:
          temp_c.sub.sucursal_1 = temp_c.sub.sucursal_1 - cantidadretirada; 
        break;
        case 2:
          temp_c.sub.sucursal_2 = temp_c.sub.sucursal_2 - cantidadretirada; 
        break;
        case 3:
          temp_c.sub.sucursal_3 = temp_c.sub.sucursal_3 - cantidadretirada; 
        break;
        case 4:
          temp_c.sub.sucursal_4 = temp_c.sub.sucursal_4 - cantidadretirada; 
        break;
       }
       fwrite(&temp_c,sizeof(struct Productos),1,ficheromod);

    } else {
      fwrite(&temp_c,sizeof(struct Productos),1,ficheromod);
    }
  }

  fclose(temporal);
  fclose(ficheromod);

  int borrado = remove("Master.txt");
    if (borrado == 0) {
        int renombrado = rename("temp.txt", "Master.txt");
        if (renombrado != 0) {
            printf("Error en el rename()\n");
            return 1;
        }
    } else {
        printf("Error al borrar master\n");
        return 2;
    }  
  return 0;
}

