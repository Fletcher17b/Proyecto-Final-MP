#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
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
    fread(&temp_b, sizeof(struct Productos),1, fileused_b);
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
