#pragma once
#include"datablueprintfile.h"

#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>

char txtextention[] = ".txt";

void limipiarbuffer() {
    fflush(stdin);
    fflush(stdout);
}

void cleanscreen() {
    system("pause");
    system("cls");
}


// funcion para crear el fichero con nuestra estructura
void newProduct(FILE* fileProduct, struct product_template product) {
    int guardado = 0;
    
    if (fileProduct != NULL) {
        fflush(stdin);
        system("cls");
        printf(" - DATOS DEL PRODUCTO -\n\n");
        
        printf("ID del producto: ");
        scanf("%s", product.prodID);
        fflush(stdin);
        
        printf("Nombre: ");
        fgets(product.nombre, sizeof(product.nombre), stdin);
        fflush(stdin);
        
        printf("Precio: ");
        scanf("%f", &product.price);
        fflush(stdin);
        
        printf("Descripción: ");
        fgets(product.descripcion, sizeof(product.descripcion), stdin);
        fflush(stdin);
        
        printf("Cantidad en central: ");
        scanf("%d", &product.sub.cantidad_en_centra);
        fflush(stdin);
        
        printf("Cantidad en sucursal 1: ");
        scanf("%d", &product.sub.cantidad_en_sucursal_1);
        fflush(stdin);
        
        printf("Cantidad en sucursal 2: ");
        scanf("%d", &product.sub.cantidad_en_sucursal_2);
        fflush(stdin);
        
        printf("Cantidad en sucursal 3: ");
        scanf("%d", &product.sub.cantidad_en_sucursal_3);
        fflush(stdin);
        
        printf("Cantidad en sucursal 4: ");
        scanf("%d", &product.sub.cantidad_en_sucursal_4);
        fflush(stdin);
        
        guardado = fwrite(&product, sizeof(struct product_template), 1, fileProduct);
        
        if (guardado > 0) {
            printf("\n¡Los datos del producto han sido guardados con éxito!\n");
        } else {
            printf("\nERROR: Inténtalo nuevamente. Si el error persiste, contacta al Administrador del Sistema.\n");
        }
    } else {
        printf("\nERROR: Verifica que el archivo de productos exista, esté abierto en modo agregar y no esté siendo utilizado por otro programa.\n");
    }
    
    fclose(fileProduct);
}


// menu de nuevos productos 


int removerfichero() {
  char masterfile[15] = "masterfile.txt";
  char removedfile[100];
  int ismaster;
  int whileexit = 0;
  
  while (whileexit != 1) {
  int whileexit2 = 0;
  limipiarbuffer();

  printf("Ingrese nombre del archivo que quiera borrar: ");
  gets(removedfile);
  limipiarbuffer();
  
  strcat(removedfile,txtextention);

  ismaster = strcmp(masterfile,removedfile);
  
  if (ismaster == 0) {
    printf("usted no puede borrar el master\n");
    cleanscreen();
  } else {
     int succesfulremove = remove(removedfile);
     if (succesfulremove == 0) {
      printf("Archivo borrado con exito\n");
      whileexit =1;
     } else {printf("Archivo no se ha podido borrar \n"); }
     
     cleanscreen();
  }

   printf("Para volver al menu principal digite 1: ");
  scanf("%d",&whileexit2);
  if (whileexit2 == 1) {
    whileexit =1;
    printf("saliendo al menu \n");
    cleanscreen();
    } 
}



  return 0;
}

int actualizar(FILE *a)
{
  char lineweneed[26] = "Cantidad en sucursal 3: ";
  rewind(a);
  while (!feof(a)) {
    fgets(lineweneed,20,a);
    puts(lineweneed);
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
      
      printf("\nIngrese la cantidad central: ");
      scanf("%d",&input.sub.cantidad_en_centra);
      limipiarbuffer();

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
          printf("\ncantidades repartidas no concuerdan con la central\n");
        } else {
          cantidades_conduerdan = 1;
        }
      }


    return input;
}

int nuevosproductos(FILE *a) {
    int cant=0;
    int n =0;
    //int *sizeofarray;
    // struct product_template temp;
    char nombre1[100];
    char nombre2[100];
    //char datextention[] = ".dat";

    printf("Ingrese nombre del archivo\n");
    gets(nombre1);
    strcpy(nombre2,nombre1);
    strcat(nombre2,txtextention);
    a = fopen(nombre2, "w");
    struct product_template *templist;
    printf("Ingrese # prods \n");
    scanf("%d",&cant);
     limipiarbuffer();

   templist = (struct product_template*) malloc(cant*sizeof(struct product_template) );

   while (n < cant) { 
      templist[n] = get_info();
      n++;
    }
    
    for (int i = 0; i < n; i++) {
        fprintf(a, "Nombre: %s\n", templist[i].prodID);
        fprintf(a, "Nombre: %s\n", templist[i].nombre);
        fprintf(a, "Precio: %.2f\n", templist[i].price);
        fprintf(a, "Descripcion: %s\n", templist[i].descripcion);
        fprintf(a, "Cantidad en central: %d\n", templist[i].sub.cantidad_en_centra);
        fprintf(a, "Cantidad en sucursal 1: %d\n", templist[i].sub.cantidad_en_sucursal_1);
        fprintf(a, "Cantidad en sucursal 2: %d\n", templist[i].sub.cantidad_en_sucursal_2);
        fprintf(a, "Cantidad en sucursal 3: %d\n", templist[i].sub.cantidad_en_sucursal_3);
        fprintf(a, "\n");
    }

    if (n > 0) {
        printf("\nLos datos de los productos han sido guardados con éxito!\n");
    } else {
        perror("Error: ");
        return(-1);
    }
    
    
/*    char txtextention2[] = "_2.txt";
    strcat(nombre1,txtextention2);
    FILE *fileopen2 = NULL;
    fileopen2 = fopen(nombre1,"w");
    int guardado=fwrite(templist, sizeof(struct product_template), n, fileopen2);
    
    if(guardado>0){
            printf("\nLos datos del atleta han sido guardados con exito! \n");
        }
        else{
            printf("\nERROR: intente nuevamente, si el error persiste contacte con el Administrador del Sistema... \n");
        }  */

       limipiarbuffer();
       free(templist);
       fclose(a);
     
    return 0;
}

int menu1() {
    limipiarbuffer();
    int opc1;
    int exitmenu1;
    FILE *filepointer = NULL;
    
  
  while (exitmenu1 != 1) {
    printf("\n Sus opciones son: \n 1. Ingresar nuevos productos\n 2. Actualizar cantidades de productos\n 3. Remover Productos \n 4. Salir al menu principal \n");
    scanf("%d",&opc1);
    switch (opc1) {
        case 1: 
          limipiarbuffer();
          cleanscreen();
          nuevosproductos(filepointer);
          exitmenu1 =1;
          break;

        case 2:
          actualizar(filepointer);
          break;

        case 3:
          removerfichero();
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
