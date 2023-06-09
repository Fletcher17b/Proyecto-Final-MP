#pragma once
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<stdbool.h>
#include"struct2.h"

void limpiarbuffer() {
    fflush(stdin);
    fflush(stdout);
}

void cleanscreen() {
    system("pause");
    system("cls");
}

void saltoLinea() {
   printf("\n");
}


void subAgregarProd(FILE *Franchyeska, struct Productos pr, FILE *Datos){
    
    int Control = 0; //Variable de control// 
    int dat= 0; 

    struct proveedoresFich temp;

     Datos = fopen("masterDC.txt", "a");
      if(Datos==NULL){
        printf("Error, el fichero no ha sido creado! \n");
    }

    Franchyeska = fopen("masterfile.txt", "a");
    if(Franchyeska==NULL){
        printf("Error, el fichero no ha sido creado! \n");
         
    }
    else
    {
        
        limpiarbuffer(); 

        printf("Tipo de producto: %s \n", pr.Tipo);
        limpiarbuffer();  

        printf("ID: ");    
        gets(pr.prodID); 
        saltoLinea(); 
        limpiarbuffer();

        printf("Nombre del producto: ");    
        gets(pr.nombre); 
        saltoLinea(); 

        limpiarbuffer();
        printf("Precio del producto: ");    
        scanf("%f", &pr. price);
        saltoLinea(); 

        limpiarbuffer();
        printf("Descripcion del producto (400 caracteres): ");    
        gets(pr.descripcion); 
        saltoLinea();

        limpiarbuffer();
        printf("Cantidad en sucursal central: ");    
        scanf("%d", &pr.sub.SucursalCentral);
        saltoLinea();

        int cantidades_concuerdan= 0; 
        while (cantidades_concuerdan != 1)
        {
            printf("\nIngrese la cantidad en sucursal 1: ");
            scanf("%d", &pr.sub.sucursal_1); 
            limpiarbuffer();

            printf("\nIngrese la cantidad en sucursal 2: ");
            scanf("%d", &pr.sub.sucursal_2); 
            limpiarbuffer();

            printf("\nIngrese la cantidad en sucursal 3: ");
            scanf("%d", &pr.sub.sucursal_3); 
            limpiarbuffer();
            
            printf("\nIngrese la cantidad en sucursal 4: ");
            scanf("%d", &pr.sub.sucursal_4); 
            limpiarbuffer();

            int suma= pr.sub.sucursal_1+pr.sub.sucursal_2+pr.sub.sucursal_3+pr.sub.sucursal_4; 
            if (suma != pr.sub.SucursalCentral){
                printf("\n cantidades repartidas no concuerdan con la central\n");
            } else

            {
                cantidades_concuerdan=1;
            }
        
        }

        printf("************* Datos de compra *************\n");
        printf("*** Ingrese - 1 - si desea añadir datos de compra ***\n");
        printf("*** Ingrese - 0 - si NO desea añadir datos de compra ***\n");
        scanf("%d", &dat); 
        if (dat==1)
        {
           strcpy(temp.productprovID, pr.prodID);
           printf("Ingrese ID del proveedor (No se puede repetir) \n");
           gets(temp.proveedorID);
           limpiarbuffer();
           temp.aSucursalCentral = pr.sub.SucursalCentral;
           temp.asucursal_1 = pr.sub.sucursal_1;
           temp.asucursal_2 =pr.sub.sucursal_2;
           temp.asucursal_3 =pr.sub.sucursal_3;
           temp.asucursal_4 = pr.sub.sucursal_4;

        int control2 = 0;    
        control2 = fwrite(&pr, sizeof(struct Productos), 1, Datos);
        if(control2>0){
            printf("\nLos datos del proveedor han sido guardados con exito! \n");
        }
        else{
            printf("\nERROR: intente nuevamente, si el error persiste contacte con el Administrador del Sistema... \n");
        }
        
        } 

        Control=fwrite(&pr, sizeof(struct Productos), 1, Franchyeska);
        if(Control>0){
            printf("\nLos datos del producto han sido guardados con exito! \n");
        }
        else{
            printf("\nERROR: intente nuevamente, si el error persiste contacte con el Administrador del Sistema... \n");
        }
    limpiarbuffer();

    
    }

    fclose(Franchyeska); 

}


int PrincipFunc_Agregar(FILE *Franchyeska, struct Productos pr, FILE *dat){

    int opcM = 0; 
    printf("\n ****** Ingrese el tipo de producto *****\n");
    printf(" - Opcion 1: Collares \n");
    printf(" - Opcion 2: Brazalete \n");
    printf(" - Opcion 3: Anillos \n");
    printf(" - Opcion 4: Arete    \n");
    printf(" - Opcion 5: Cadena   \n");
    printf(" - Opcion 6: Salir    \n");
    printf("*******************************************\n");
    scanf("%d", &opcM); 
    switch (opcM)
    {
    case 1:
        strcpy(pr.Tipo, "Collares"); 
        pr.tipo = 1;
        subAgregarProd(Franchyeska, pr,dat); 
        
        break;
    case 2:
        strcpy(pr.Tipo, "Brazalete"); 
        pr.tipo = 2;
        subAgregarProd(Franchyeska, pr,dat);
        break;
    case 3:
        strcpy(pr.Tipo, "Anillos"); 
        pr.tipo = 3;
        subAgregarProd(Franchyeska, pr,dat);
        break;
    case 4:
        strcpy(pr.Tipo, "Arete"); 
        pr.tipo = 4;
        subAgregarProd(Franchyeska, pr,dat);
        break;
    case 5:
        strcpy(pr.Tipo, "Cadena"); 
        pr.tipo = 5;
        subAgregarProd(Franchyeska, pr,dat);
        break;
    
    case 6:
        break;
    default:
        break;
    }
    return opcM;
}

void visualizarProductos(FILE *Franchyeska, struct Productos pr)
{   
    Franchyeska = fopen("Master.txt", "r");
    if(Franchyeska==NULL){
        printf("Error, el fichero no ha sido creado! \n");
         
    }
    else
    {
        printf(" El fichero ha sido creado con exito! \n");
    }
    

    char prodID[10];
    int opc= 0; 
    limpiarbuffer(); 
    printf("Digite - 1 - para ver todos los productos\n"); 
    printf("Digite - 2- para ver un producto especifico\n"); 
    printf("Digite 3 para ver productos por tipo\n");
    printf("Digite 4 para ver por sucursal");
    limpiarbuffer(); 
    scanf("%d", &opc);

    switch (opc)
    {
    case 1:
        int contador= 0; 
        limpiarbuffer(); 
        saltoLinea(); 
    
        
        fread(&pr, sizeof(struct Productos), 1, Franchyeska);
        while (!feof(Franchyeska))
        {
            contador++; 
            limpiarbuffer(); 
            printf("N: %d \n", contador); 
            printf("ID: %s \n ", pr.prodID); 
            printf("Tipo del producto: %s \n", pr.Tipo); 
            printf("Precio: %f \n", pr.price); 
            printf("Descripcion: %s \n", pr.descripcion); 
            printf("Cantidad en sucursal central: %d \n", pr.sub.SucursalCentral); 
            printf("Cantidad en sucursal 1: %d \n", pr.sub.sucursal_1); 
            printf("Cantidad en sucursal 2: %d \n", pr.sub.sucursal_2);
            printf("Cantidad en sucursal 3: %d \n", pr.sub.sucursal_3);
            printf("Cantidad en sucursal 4: %d \n", pr.sub.sucursal_4);

            // Mario 5/30: verifica que los formatos (los %letra) concuerden con el tipo de variable de del struct usado, also hay un espacio en pr. price
            fread(&pr, sizeof(struct Productos), 1, Franchyeska); 

        }
        break;

    case 2:
        {
            limpiarbuffer(); 
            saltoLinea(); 
            int find = 0; 
            printf ("Digite el numero de codigo ID que desea buscar: "); 
            scanf("%s", prodID);
            rewind(Franchyeska); 
            fread(&pr, sizeof(struct Productos), 1, Franchyeska); 
            while (!feof(Franchyeska))
            {
            if(!strcmp(prodID, pr. prodID))
            {
                find=1; 
                limpiarbuffer(); 
                printf("----------------------------\n");
                printf("--------- Productos --------\n");
                printf("----------------------------\n");

                printf("ID: %s ", pr.prodID);    
                saltoLinea(); 

                printf("Nombre del producto: %s \n", pr.nombre);    
                gets(pr.nombre); 
                saltoLinea(); 

                printf("Precio del producto: %f \n", pr.price);    
                saltoLinea(); 

                printf("Descripcion del producto (200 caracteres):  %s \n", pr.descripcion);    
                saltoLinea();

                printf("Cantidad en sucursal central: %d \n", pr.sub.SucursalCentral);
                saltoLinea();

                printf("cantidad en sucursal 1: %d \n", pr.sub.sucursal_1);  // Mario 5/30: el & no va por que llamas a la variable no a la direccion de ella
                limpiarbuffer();

                printf("cantidad en sucursal 2: %d \n", pr.sub.sucursal_2);
                limpiarbuffer();

                printf("cantidad en sucursal 3: %d \n", pr.sub.sucursal_3);
                limpiarbuffer();
                
                printf("cantidad en sucursal 4: %d \n", pr.sub.sucursal_4);
                limpiarbuffer();
                break;
        
            }
            fread(&pr, sizeof(struct Productos), 1, Franchyeska); 
            }
        if (find!=1)
        {
            printf("Ingrese un numero ID valido e intente nuevamente! \n");
        }

        }
       break;


    case 3:
       break;
    
    default:
        break;
    }

    fclose(Franchyeska); 
    

}

