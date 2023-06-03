#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#include"struc.h"


// limpia buffer
void cleanbuff(){
    fflush(stdin);
    fflush(stdout);
}

// limpia y pausa pantalla de terminal 
void screenclean() {
    system("pause");
    system("cls");
}

struct cantdist {
    int cantidad_en_centra;
    int cantidad_en_sucursal_1;
    int cantidad_en_sucursal_2;
    int cantidad_en_sucursal_3;
    int cantidad_en_sucursal_4;

};


struct product_template {
 char prodID[10];  
 char nombre[50];
 float priceunit;
 char descripcion[200];
 float gastos_varios; 

 struct cantdist sub;
 
};

struct factura {
    int cantidad_en_centra;
    int cantidad_en_sucursal_1;
    int cantidad_en_sucursal_2;
    int cantidad_en_sucursal_3;
    int cantidad_en_sucursal_4;

};

struct factura get_fact() {
    struct product_template input;
      printf("\nIngrese ID del producto (maximo 10 caracteres, no se debe repetir) ");
      gets(input.prodID);
      limparbuffer(); 
      
      printf("\nIngrese nombre: ");
      scanf("%s",input.nombre);
      limpiarbuffer();

      printf("\nIngrese precio: ");
      scanf("%f",&input.priceunit);
      limpiarbuffer();

      printf("\nIngrese una breve descripcion del producto: ");
      scanf("%s",input.descripcion);
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
          printf("\ncantidades repartidas no concuerdan con la central\n");
        } else {
          cantidades_conduerdan = 1;
        }
      }


    return input;
}

//almacenar producto
void new_product(FILE *fileProducto, struct product_template prod)
{
  int agregado = 0;
    if(fileProducto!=NULL){
        cleanbuff();
        screenclean();
        printf(" - Datos del producto -");
        printf("\n");
        printf("Codigo: ");
        gets(prod.prodID);
        printf("\n");
        cleanbuff();
        printf("Nombre del producto: ");
        gets(prod.nombre);
        printf("\n");
        cleanbuff();
        printf("Precio: ");
        scanf("%f", &prod.priceunit);
        printf("\n");
        cleanbuff();
        printf("Descripcion: ");
        gets(prod.descripcion);
        printf("\n");
        cleanbuff();
        agregado=fwrite(&prod, sizeof(struct product_template), 1, fileProducto);
        if (agregado>0)
        {
           printf("\n Los datos han sido agregados...\n");
        }
        else{
            printf("\n No se han podido agregar nuevos productos \n");
        }
        
    }
    else
    {
       printf("\n No existe un fichero... \n");
    }
}


//ver producto
void ver_producto(FILE *fileProducto, struct product_template prod)
{
    int ver=0;
    cleanbuff();
    printf("Codigo: \n");
    printf("Nombre: \n");
    printf("Cantidad Disponible: \n");
    printf("Descripcion: \n");
    fread(&prod, sizeof(struct product_template), 1, fileProducto);
    while(!feof(fileProducto)){
     ver++;
     printf("%s \n", ver, prod.prodID);
     printf("%s \n", ver, prod.nombre);
     printf("%d \n", ver, prod.priceunit);
     printf("%s \n", ver, prod.descripcion);
     fread(&prod, sizeof(struct product_template), 1, fileProducto);
    }
  
}


// menu retirar producto 
void retirar_producto(FILE *fileProducto, struct product_template prod)
{
    FILE *temporal;
 struct product_template temp_c;
 
 fileProducto = fopen("facturafile.txt","r");
 temporal = fopen("temporal.txt","a+");
    int buscar=0;
    int sucursal=0;
    int ext_cant=0;
    char ID[10];
    
    printf("**********Retirar producto***********\n");
    printf("Digite el codigo del producto:\n");
    scanf("%s", &ID);
    rewind(fileProducto);
    fread(&prod, sizeof(struct product_template), 1, fileProducto);
    while (!feof(fileProducto))
    {
        if(!strcmp(ID, prod.prodID)){
        buscar=true;
        cleanbuff();
        printf("Nombre: %s \n", prod.nombre);
        printf("Precio del producto: %.2f \n", prod.priceunit);
        printf("Descripcion: %s \n", prod.descripcion);
        }
    }
   
   printf("Digite el numero de productos que desea extraer:\n");
   scanf("%d", &ext_cant);
   if (ext_cant!=0);
   {
     printf("\n");
      printf("Digite el numero de productos que desea extraer:\n");
   }
   else
   {
    printf("Digite el numero de productos que desea extraer:\n");
    return menu_fac();
   }

}

//realizar factura
void print_factra(FILE *fileProducto, struct product_template prod)
{
    printf("----------------------------\n");
    printf("----- Datos del Producto-----\n");
    printf("----------------------------\n");
}

//menu facturacion
int menu_fac()
{
    int opcion = 0;
    printf("\n ********** Menu de facturación **********\n");
    printf("- Opcion 1: Buscar producto \n");
    printf("- Opcion 2: Retirar porducto\n");
    printf("- Opcion 3: Realizar factura \n"); // o luego de retirar producto
    printf("- Opcion 4: Salir \n");
    printf("- Digite su opcion: ");
    scanf("%d", &opcion);
    return opcion;
}