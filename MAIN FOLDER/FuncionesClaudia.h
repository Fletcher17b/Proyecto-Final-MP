#include"archivodefunciones.h"
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<stdbool.h>


void info_fact (FILE *factura) {
    factura = fopen("Factura.txt","r");

    if(factura==NULL){
        printf("Error, la factura no ha sido creada! \n");
         
    }
    else
    {
    
     struct fact_enc enc;
    time_t fecha;
    int num=0;
    time(&fecha);

    printf("\n****************Factura Encabezado**************\n");
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


   fclose(factura);
    return 0;
}


int consultaensucursal() {
  FILE *ficheromod;
  FILE *temporal;
 struct Productos temp_c;
  char IDseeker[10];
  int banderaloop1=0;
  int sucursalorg =0;
  int cantextract2 =0;
 
ficheromod = fopen("Master.txt","r");
  temporal = fopen("temp.txt","w+");


 if (ficheromod == NULL || temporal == NULL) {
        printf("Error al abrir fichero \n");
        return 1;
    }


  limpiarbuffer();
  printf("Ingrese la ID del producto a comprar\n");
  gets(IDseeker);
  limpiarbuffer();

   

  
   rewind(ficheromod);
   while (fread(&temp_c, sizeof(struct Productos), 1, ficheromod) == 1) {
     
     if (!strcmp(temp_c.prodID, IDseeker)) {
          limpiarbuffer(); 
                printf("----------------------------\n");
                printf("-----------------\n");
                printf("----------------------------\n");
                
                limpiarbuffer();
                printf("ID: %s ", temp_c.prodID);    
                saltoLinea(); 
                printf("Nombre: %s ", temp_c.nombre);    
                saltoLinea(); 
                printf("Tipo: %s ", temp_c.Tipo);    
                saltoLinea(); 
                printf("Precio: %2.f ", temp_c.price);    
                saltoLinea(); 
                printf("Descripcion: %s ", temp_c.descripcion);    
                saltoLinea(); 

        printf("Cantidades disponibles por sucursal: \n");
          printf("1: %d \n", temp_c.sub.sucursal_1);
          printf("2: %d \n", temp_c.sub.sucursal_2);
          printf("3: %d \n", temp_c.sub.sucursal_3);
          printf("4: %d \n", temp_c.sub.sucursal_4);

 
        printf("Seleccione la sucursal de compra: ");

          scanf("%d",&sucursalorg);  
        
          limpiarbuffer();

          printf("Ingrese la cantidad a comprar: ");
          

        while (banderaloop1 !=1) { 
          scanf("%d",&cantextract2);
         switch (sucursalorg)
          {
          case 1:
            while (cantextract2 > temp_c.sub.sucursal_1) {
                 printf("cantidad excede existencias, digite denuevo: ");
                 scanf("%d", &cantextract2);
            }
            
            break;

            case 2:
            while (cantextract2 > temp_c.sub.sucursal_2) {
                 printf("cantidad excede existencias, digite denuevo: ");
                 scanf("%d", &cantextract2);
            }
             
            break;

            case 3:
            while (cantextract2 > temp_c.sub.sucursal_3) {
                 printf("cantidad excede existencias, digite denuevo: ");
                 scanf("%d", &cantextract2);
            }
            
            break;

            case 4:
            while (cantextract2 > temp_c.sub.sucursal_4) {
                 printf("cantidad excede existencias, digite denuevo: ");
                 scanf("%d", &cantextract2);
            }
           
            break;
          
          default:
            printf("cantidad invalida\n");

            break;

          }
    limpiarbuffer();
     float subtotal=0;
     float total=0;
     float IVA=1.15;
     int confirma;
     subtotal=cantextract2*temp_c.price;
     printf("Subtotal: %2.f ", subtotal);    
     saltoLinea(); 
     total=subtotal*IVA;
     printf("Total: %2.f ", total);    
     saltoLinea(); 

     printf("Desea realizar la compra?: \n");
          printf("1:Si \n");
          printf("2:No \n");
          scanf("%d", &confirma);

      switch (confirma)
          {
          case 1:

     printf("Imprimir ");
     

                 
  break;

  case 2:
  printf("Lo esperamos pronto ");
  }
          
     }


          fwrite(&temp_c, sizeof(struct Productos), 1, temporal);

     } else {
        fwrite(&temp_c, sizeof(struct Productos), 1, temporal);
     }

   }
}





