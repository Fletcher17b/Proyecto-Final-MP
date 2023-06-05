#pragma once

#include"struct.h"
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<stdbool.h>

void limpiarbuffer() {
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
      limpiarbuffer(); 


      printf("\nIngrese nombre: ");
      scanf("%s",input.nombre);
      limpiarbuffer();

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

      limpiarbuffer();

     int cant_centralverifier = 0;


      printf("\nIngrese la cantidad central: ");
      cant_centralverifier = scanf("%d",&input.sub.SucursalCentral);
      limpiarbuffer();
      while (cant_centralverifier == 0) {
          printf("\n invalid input, ingrese valor otra vez\n");
          cant_centralverifier = scanf("%d",&input.sub.SucursalCentral);
          limpiarbuffer();
      }

      int cantidades_conduerdan = 0;

      while (cantidades_conduerdan != 1 ) {
        printf("\nIngrese la cantidad en sucursal 1: ");
        scanf("%d",&input.sub.sucursal_1);
        limpiarbuffer();

        printf("\nIngrese la cantidad sucursal 2: ");
        scanf("%d",&input.sub.sucursal_2);
        limpiarbuffer();

        printf("\nIngrese la cantidad sucursal 3: ");
        scanf("%d",&input.sub.sucursal_3);
        limpiarbuffer();

        printf("\nIngrese la cantidad sucursal 4: ");
        scanf("%d",&input.sub.sucursal_4);
        limpiarbuffer();

        int suma = input.sub.sucursal_1 + input.sub.sucursal_2 + input.sub.sucursal_3 + input.sub.sucursal_4;
        if (suma != input.sub.SucursalCentral) {
          printf("\ncantidades repartidas no concuerdan con la central, cantidad central: %d\n", input.sub.SucursalCentral);
        } else {
          cantidades_conduerdan = 1;
        }
      }


    return input;
}

int agregarprod(FILE *fileused_a) {

  limpiarbuffer();

  struct product_template structtemp;
  int guardadobien = 0;

   fileused_a = fopen("master.txt","a");

      limpiarbuffer();
      structtemp = get_info();
      guardadobien = fwrite(&structtemp, sizeof(struct product_template),1, fileused_a );

      if (guardadobien >0) {
       printf("todo chingon\n");
      } else 
       {
        printf("nel perro \n");
       }

    fclose(fileused_a);
  return 0;
}


/// @brief 
/// @param sucursal 
/// @param IDdelprod 
/// @param cantidadretirada 
/// @return 
// He aqui la funcion de manejo de existencias
int manejoexistenciasfact(int sucursal ,char IDdelprod[10],int cantidadretirada) {

  //Funcion en WIP pendiente comprobar con Claudia si funciona en conjunto con su parte
  //codigos de error: 1 rename() no funciono 2 remove() no funciono, 0 es que todo bien

  FILE *ficheromod = NULL;
  FILE *temporal = NULL;
  struct product_template temp_c;

  ficheromod = fopen("Master.txt","r");
  temporal = fopen("temp.txt","w+");
  
  rewind(ficheromod);
  while (fread(&temp_c, sizeof(struct product_template), 1, ficheromod) == 1) 
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
       fwrite(&temp_c,sizeof(struct product_template),1,ficheromod);

    } else {
      fwrite(&temp_c,sizeof(struct product_template),1,ficheromod);
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

int transferencia_interna_prods() {
  FILE *ficheromod = NULL;
  FILE *temporal = NULL;
 struct product_template temp_c;
  char IDseeker[10];
  int banderaloop1=0;
  int banderaloop2=0;
  int sucursalorg =0;
  int sucursaldest =0;
  int cantextract2 =0;
 
 ficheromod = fopen("master.txt","r");
 temporal = fopen("temp.txt","w+");

printf("Ingrese la ID del producto el cual se va a transferir\n");
  gets(IDseeker);
  limpiarbuffer();
   
   rewind(ficheromod);
   while (fread(&temp_c, sizeof(struct product_template), 1, ficheromod) == 1) {
     
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
          fwrite(&temp_c, sizeof(struct product_template), 1, temporal);

     } else {
        fwrite(&temp_c, sizeof(struct product_template), 1, temporal);
     }
   }




  fclose(temporal);
  fclose(ficheromod);

 int borrado = remove("master.txt");
    if (borrado == 0) {
        int renombrado = rename("temp.txt", "master.txt");
        if (renombrado != 0) {
            printf("Error renaming temp.txt to master.txt\n");
            return -1; // Error renaming file
        }
    } else {
        printf("Error removing master.txt\n");
        return -1; // Error removing file
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

 while (fread(&estructura, sizeof(struct product_template), 1, ficherodeverportipo) == 1) {

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

int verespecifico() {
    limpiarbuffer();
  cleanscreen();
  
  FILE *fileused_0;
  struct product_template temp_0;

  printf("\n comprob \n");

  fileused_0 = fopen("master.txt","r");
if (fileused_0 == NULL) { return 1;}

  fread(&temp_0, sizeof(struct product_template),1, fileused_0);
  char IDseeker[10];
  int exit;
  gets(IDseeker);

  while(!feof(fileused_0) && exit != 1) {

  if(!strcmp(IDseeker, temp_0.prodID)) { 
    limpiarbuffer();
    printf("\nNombre: %s \n", temp_0.nombre);
    printf("Precio: %.2f \n", temp_0.price);
    printf("Descripcion: %s \n", temp_0.descripcion);

    printf("central: %d \n", temp_0.sub.SucursalCentral);
    printf("1: %d \n", temp_0.sub.sucursal_1);
    printf("2: %d \n", temp_0.sub.sucursal_2);
    printf("3: %d \n", temp_0.sub.sucursal_3);
    printf("4: %d \n", temp_0.sub.sucursal_4);
    exit =1 ;
  } 
  fread(&temp_0, sizeof(struct product_template),1, fileused_0);
      
  } 

    return 0;
}



int versucursal(FILE *ficherosucural) {

    ficherosucural = fopen("master.txt","r");

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
  limpiarbuffer();
  switch (sucselct)
  {
  case 1:
    
    printf("Productos disponibles en sucursal 1: \n");  
    rewind(ficherosucural);  
    while (fread(&estructura, sizeof(struct product_template), 1, ficherosucural) == 1) {

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
    while (fread(&estructura, sizeof(struct product_template), 1, ficherosucural) == 1) {

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
    while (fread(&estructura, sizeof(struct product_template), 1, ficherosucural) == 1) {

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
    while (fread(&estructura, sizeof(struct product_template), 1, ficherosucural) == 1) {

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

