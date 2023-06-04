#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#include"struc.h"


// limpia buffer
void limpiarbuffer(){
    fflush(stdin);
    fflush(stdout);
}

// limpia y pausa pantalla de terminal 
void screenclean() {
    system("pause");
    system("cls");
}

struct cantdist {
    int SucursalCentral;
    int sucursal_1;
    int sucursal_2;
    int sucursal_3;
    int sucursal_4;

};


struct product_template {
    char prodID[10];  
 int tipo;
 char Tipo[25];
 char nombre[50];
 float price;
 char descripcion[200];

 struct cantdist sub;
 
};

struct fact_detalle {
 char prodID[10];  
 int tipo;
 char Tipo[25];
 char nombre[50];
 float price;
 char descripcion[200];
 
};

struct fact_enc {
   char IDfact[10];
   char IDorg[10];
   char numser[10];
   char cajero[20];
   char IDcliente;
   float subtotal;
   float iva;
   float total;

   struct fact_detalle detalle;
};

struct Cliente {
    char nombre[50];
    char direccion[100];
    int telefono;
    int telefono[20];
};

struct fact_enc info_fact() {
    struct fact_enc enc;
    time_t fecha;
    int num=0;
    bool found;
    time(&fecha);

    printf("\n*************Factura Encabezado**************\n");
    printf("\nIngrese ID de la factura ");
    gets(enc.IDfact );
    limpiarbuffer(); 
       
    printf("\nIngrese ID de la organización: ");
    gets(enc.IDorg );
    limpiarbuffer(); 
      
    printf("\n Fecha : ");
    printf("%s\n", ctime(&fecha));
    limpiarbuffer(); 

    num++;
    printf("\n Numero de factura %d",num);
    printf( ": \n");
    limpiarbuffer(); 

    printf("\n Estimado usuario, digite numero de serie (Ingrese letra ) : ");
    gets(enc.numser);
    limpiarbuffer();

    printf("\n Atendido por : ");
    gets(enc.cajero);
    limpiarbuffer();

    printf("\n ID de cliente : "); 
    gets(IDcliente);
    fread(&temp_b, sizeof(struct product_template),1, fileused_b);
    while(!feof(fileused_b)) {
  if(!strcmp(IDcliente, temp_b.prodID)) {
    found = true;
    limpiarbuffer();
    int loopexit1 = 0;
    int valuetochange = 0; 

    printf("\nNombre: %s \n", temp_b.nombre);
    printf("Precio: %.2f \n", temp_b.priceunit);
    printf("Descripcion: %s \n", temp_b.descripcion);}
    }

}


int other_info(){

    printf("Usted ha decido realizar su factura:");



}


struct factura get_fact() {
    struct product_template input;
      printf("\nIngrese ID del producto (maximo 10 caracteres, no se debe repetir) ");
      gets(input.prodID);
      limpiarbuffer(); 
      
      printf("\nIngrese nombre: ");
      scanf("%s",input.nombre);
      limpiarbuffer();

      printf("\nIngrese precio: ");
      scanf("%f",&input.price);
      limpiarbuffer();

      printf("\nIngrese una breve descripcion del producto: ");
      scanf("%s",input.descripcion);
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
          printf("\ncantidades repartidas no concuerdan con la central\n");
        } else {
          cantidades_conduerdan = 1;
        }
      }


    return input;
}

//almacenar producto
int new_product(FILE *fileProducto, struct product_template prod)
{
  int agregado = 0;
    if(fileProducto!=NULL){
        limpiarbuffer();
        screenclean();
        printf(" - Datos del producto -");
        printf("\n");
        printf("Codigo: ");
        gets(prod.prodID);
        printf("\n");
        limpiarbuffer();
        printf("Nombre del producto: ");
        gets(prod.nombre);
        printf("\n");
        limpiarbuffer();
        printf("Precio: ");
        scanf("%f", &prod.price);
        printf("\n");
        limpiarbuffer();
        printf("Descripcion: ");
        gets(prod.descripcion);
        printf("\n");
        limpiarbuffer();
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
int ver_producto(FILE *fileProducto, struct product_template prod)
{
    int ver=0;
    limpiarbuffer();
    printf("Codigo: \n");
    printf("Nombre: \n");
    printf("Cantidad Disponible: \n");
    printf("Descripcion: \n");
    fread(&prod, sizeof(struct product_template), 1, fileProducto);
    while(!feof(fileProducto)){
     ver++;
     printf("%s \n", ver, prod.prodID);
     printf("%s \n", ver, prod.nombre);
     printf("%d \n", ver, prod.price);
     printf("%s \n", ver, prod.descripcion);
     fread(&prod, sizeof(struct product_template), 1, fileProducto);
    }
  
}


// menu retirar producto 
void retirar_producto(FILE *fileProducto, struct product_template prod)
{
    FILE *temporal;
 struct product_template prod;
 
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
        limpiarbuffer();
        printf("Nombre: %s \n", prod.nombre);
        printf("Precio del producto: %.2f \n", prod.price);
        printf("Descripcion: %s \n", prod.descripcion);
        }
    }
   
   printf("Digite el numero de productos que desea extraer:\n");
   scanf("%d", &ext_cant);
   if (ext_cant==0)
   {
    printf("Regresando al menu principal...\n");

   }
   else
   {
    float subtotal;
    float iva=1.5;
    float total;

    subtotal= prod.price*ext_cant;
    printf("Su subtotal a pagar es de= %.2f \n", subtotal);
    
    printf("IVA= %.2f \n", iva);

    total= subtotal*iva;
    printf("Su total a pagar es de= %.2f \n", total);


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