#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>
#include"archivodeestructuras.h"
#include"archivodefunciones.h"
#include"FuncionesMario.h"


struct fact_enc info_fact() {
    struct fact_enc enc;
    time_t fecha;
    int num=0;
    time(&fecha);

    printf("\n*************Factura Encabezado**************\n");
    printf("\nIngrese ID de la factura ");
    gets(enc.IDfact);
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
   return enc;
}


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

void retirar_producto(FILE *fileProducto, struct Productos prod)
{
 FILE *temporal =NULL;
 
 fileProducto = fopen("facturafile.txt","r");
 if (fileProducto == NULL) {
    fclose(fileProducto);
    return 1;
 }
 temporal = fopen("temporal.txt","a+");
    bool buscar = false;
    int sucursal=0;
    int ext_cant=0;
    
    char ID[10];
    
    printf("**********Retirar producto***********\n");
    printf("Digite el codigo del producto:\n");
    gets(ID);
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
        fread(&prod, sizeof(struct Productos), 1, fileProducto);
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
    
    FILE *fileFactura = NULL;
    printf("¿Desea imprimir su factura?\n");
    printf("Digite 1 para guardar, 0 solo para salir: \n");
   scanf("%d", &opcfact);
   if (opcfact==1)
   {
    
    
    print_factura(fileFactura);

      }


   }

}


int menu_fac()
{
    FILE *fichero = NULL;
    struct Productos pr;
    int opcion = 0;
    printf("\n ********** Menu de facturación **********\n");
    printf("- Opcion 1: Ver producto ()\n");
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
    cleanscreen();
      break;

    case 2:
    printf("Usted ha ingresado a Retirar Producto \n");
    retirar_producto(fichero,pr);
    limpiarbuffer();
    cleanscreen();

      break;

    case 4: 
      break;
    default:
      break;
    }





    return 0;
}