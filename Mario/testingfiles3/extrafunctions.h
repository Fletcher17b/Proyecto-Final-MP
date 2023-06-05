#pragma once

#include"struct2.h"
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<stdbool.h>

void limpiarbuffer() {
    fflush(stdin);
    fflush(stdout);
}

void saltoLinea()
{
    printf("\n"); 
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

   fileused_a = fopen("masterfile.txt","a");
        
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


  
  
  //fclose(fileused_a);

  
  
  return 0;
}


int Menutipo(FILE *Franchyeska, struct Productos pr, FILE *Datos, struct Productos prov){

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
        AgregarProd(Franchyeska, pr);
        datoscompra(Datos, prov);  
        
        break;
    case 2:
        strcpy(pr.Tipo, "Brazalete"); 
        pr.tipo = 2;
        AgregarProd(Franchyeska, pr);
        break;
    case 3:
        strcpy(pr.Tipo, "Anillos"); 
        pr.tipo = 3;
        AgregarProd(Franchyeska, pr);
        break;
    case 4:
        strcpy(pr.Tipo, "Arete"); 
        pr.tipo = 4;
        AgregarProd(Franchyeska, pr);
        break;
    case 5:
        strcpy(pr.Tipo, "Cadena"); 
        pr.tipo = 5;
        AgregarProd(Franchyeska, pr);
        break;
    
    case 6:
        break;
    default:
        break;
    }
    return opcM;
}



void AgregarProd(FILE *Franchyeska, struct Productos pr){
    
    int Control = 0; //Variable de control// 
    int Vmenu= 0; 
    Franchyeska = fopen("Master.txt", "a");
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

void datoscompra(FILE *Datos, struct Productos pr){ 
    int dat= 0; 
    int Control = 0;
    Datos = fopen("Master.txt", "a");
    if(Datos==NULL){
        printf("Error, el fichero no ha sido creado! \n");
         
    }
    else
    {
        printf("************* Datos de compra *************\n");
        printf("*** Ingrese - 1 - si desea añadir datos de compra ***\n");
        printf("*** Ingrese - 0 - si NO desea añadir datos de compra ***\n");
        scanf("%d", &dat); 
        if (dat=1)
        {
            limpiarbuffer(); 
            printf("Nombre del proovedor: ");    
            gets(pr.prov.NameProv); 
            saltoLinea(); 
            limpiarbuffer();

            printf("Producto: ");    
            gets(pr.prov.productprovID); 
            saltoLinea(); 
            limpiarbuffer();

            Control=fwrite(&pr, sizeof(struct Productos), 1, Datos);
            if(Control>0){
                printf("\nLos datos del producto han sido guardados con exito! \n");
            }
            else{
                printf("\nERROR: intente nuevamente, si el error persiste contacte con el Administrador del Sistema... \n");
            }
        }
        else
        {
            printf("Regresando al menu principal, espere un momento \n");
            system("cls"); 
            limpiarbuffer(); 
        
            
        }
        
    }

    
    

    
    

}
