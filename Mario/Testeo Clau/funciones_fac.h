#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#include<stdbool.h>
#include"struc.h"
#include<time.h>


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


struct Productos {
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



struct Productos get_info() {
    struct Productos input;
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

//almacenar producto
int agregarprod(FILE *fileused_a) {

  limpiarbuffer();

  int prod_input_num = 0;
  struct Productos structtemp;
  int guardadobien = 0;

  fileused_a = fopen("Master.txt","r");
  
  if (fileused_a == NULL) {
    printf("nel pastel \n");
    fclose(fileused_a);
  } else {
    printf("dele \n");
    fclose(fileused_a);
    
    printf("cuantos productos desea ingresar? \n");
    scanf("%d", &prod_input_num);

    for (int counter1 = 1; counter1 <= prod_input_num; counter1++) 
    {

      fileused_a = fopen("Master.txt","a");
        
      limpiarbuffer();
      structtemp = get_info();
      guardadobien = fwrite(&structtemp, sizeof(struct Productos),1, fileused_a );

      if (guardadobien >0) {
       printf("todo chingon\n");
      } else 
       {
        printf("nel perro \n");
       }
        
        fclose(fileused_a);
        

    }

  }

  return 0;
}

//ver producto

int ver_producto(FILE *fileVProducto, struct Productos prod)
{
    FILE *temporal;
 struct Productos prod;
 
 fileVProducto = fopen("VER  .txt","r");
 temporal = fopen("temporal.txt","a+");
    int ver=0;
    limpiarbuffer();
    printf("Codigo: \n");
    printf("Nombre: \n");
    printf("Cantidad Disponible: \n");
    printf("Descripcion: \n");
    fread(&prod, sizeof(struct Productos), 1, fileVProducto);
    while(!feof(fileVProducto)){
     ver++;
     printf("%s \n", ver, prod.prodID);
     printf("%s \n", ver, prod.nombre);
     printf("%d \n", ver, prod.price);
     printf("%s \n", ver, prod.descripcion);
     fread(&prod, sizeof(struct Productos), 1, fileVProducto);
    }
  
}


// retirar producto 
int retirar_producto(FILE *fileProducto, struct Productos prod)
{
 FILE *temporal;
 struct Productos prod;
 
 fileProducto = fopen("facturafile.txt","r");
 temporal = fopen("temporal.txt","a+");
    int buscar=0;
    int sucursal=0;
    int ext_cant=0;
    int sucursal;
    
    char ID[10];
    
    printf("**********Retirar producto***********\n");
    printf("Digite el codigo del producto:\n");
    scanf("%s", &ID);
    limpiarbuffer();
    printf("Digite el sucursal:\n");
    scanf("%d", &sucursal);
    limpiarbuffer();
    rewind(fileProducto);
    fread(&prod, sizeof(struct Productos), 1, fileProducto);
    while (!feof(fileProducto)) // wtf does this search in?
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
    manejoexistenciasfact(sucursal,ID,ext_cant);
    float subtotal;
    float iva=1.5;
    float total;
    int opcfact=0;

    subtotal= prod.price*ext_cant;
    printf("Su subtotal a pagar es de= %.2f \n", subtotal);
    
    printf("IVA= %.2f \n", iva);

    total= subtotal*iva;
    printf("Su total a pagar es de= %.2f \n", total);
    
    FILE *fileFactura;
    printf("¿Desea imprimir su factura?\n");
    printf("Digite 1 para guardar, 0 solo para salir: \n");
   scanf("%d", &opcfact);
   if (opcfact==1)
   {
    
    print_factura(fileFactura);

   }


}
  
}


struct fact_detalle {
  char ID_fact[10];
  char U_medid[10];
 char prodID[10];  
 int tipo;
 char Tipo[25];
 char nombre[50];
 float price;
 char descripcion[200];
 float subtotal1;
 
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

    //printf("\n ID de cliente : "); 
    //gets(IDcliente);
    //fread(&temp_b, sizeof(struct Productos),1, fileused_b);

    printf("\n*************Factura Detalle**************\n");
    printf("\nIngrese ID de la factura: ");
    gets(enc.detalle.ID_fact);
    limpiarbuffer();
    printf("\nNumero de Factura: %d",num);
    limpiarbuffer(); 
    printf("\nIngrese Unidad de medida del producto: ");
    gets(enc.detalle.U_medid);
    limpiarbuffer();

}

//realizar factura
int print_factura(FILE *fileFactura)
{
    limpiarbuffer();
    int fact=0;
    struct fact_enc factura;
    int crearfact = 0;

    fileFactura = fopen("factura.txt","r");
  
  if (fileFactura == NULL) {
    printf("Su factura no ha podido crearse... \n");
    fclose(fileFactura);}
    else
    {
   
    fclose(fileFactura);
    for (int counter1 = 1; counter1 <= fact; counter1++) {

      fileFactura= fopen("Factura.txt","a");
      limpiarbuffer();
      factura = info_fact();
      crearfact = fwrite(&factura, sizeof(struct fact_enc),1, fileFactura);


      if (crearfact>0) {
       printf("Su factura se ha creado correctamente...\n");
      } else 
       {
        printf("No se ha creado su factura...\n");
       }
        
        fclose(fileFactura);
        

    }
    }
    
    return 0;

}




//menu facturacion
int menu_fac()
{
    FILE *fichero;
    struct Productos pr;
    int opcion = 0;
    printf("\n ********** Menu de facturación **********\n");
    printf("- Opcion 1: Ver producto \n");
    printf("- Opcion 2: Retirar porducto\n");
    printf("- Opcion 4: Salir \n");
    printf("- Digite su opcion: ");
    scanf("%d", &opcion);
    switch (opcion)
    {
    case 1:
    printf("Usted ha ingresado a Buscar producto \n");
    //ver_producto();
    limpiarbuffer();
    screenclean();
      break;

    case 2:
    printf("Usted ha ingresado a Retirar Producto \n");
    retirar_producto(fichero,pr);
    limpiarbuffer();
    screenclean();

      break;
    default:
      break;
    }





    return opcion;
}