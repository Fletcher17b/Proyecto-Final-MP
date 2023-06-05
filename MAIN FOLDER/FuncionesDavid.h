#pragma once
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<stdbool.h>
#include"FuncionesMario.h"
#include"archivodefunciones.h"
#include"archivodeestructuras.h"


void datoscompra(FILE *Datos, struct Productos pr ) 
{
   int Control=0;
   int datas= 0;  

   Datos = fopen("masterDC.txt", "a");
      if(Datos==NULL){
        printf("Error, el fichero no ha sido creado! \n");
    } else {
        printf("***** Datos de compra *****\n");
        printf("* Ingrese - 1 - si desea añadir datos de compra *\n");
        printf("* Ingrese - 0 - si NO desea añadir datos de compra *\n");
        scanf("%d", &datas); 
        if (datas==1)
        {
            limpiarbuffer(); 

            printf("Ingrese ID: "); 
            gets(pr.prov.provID);
            limpiarbuffer();
            saltoLinea();

            printf("Nombre del proovedor: ");    
            gets(pr.prov.NameProv); 
            saltoLinea(); 
            limpiarbuffer();

            printf("Producto: ");    
            gets(pr.prov.productop); 
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

void Proveedores(FILE *Datos, struct Productos pr)
{
    int contador; 
    char provID[30];   
    Datos = fopen("MasterDC.txt", "r");
    if(Datos==NULL){
        printf("Error, el fichero no existe \n");
         
    } 
    struct Productos proveedores; 
    int opc=0;
    limpiarbuffer(); 
    printf("Digite - 1 - para ver todos los proveedores \n"); 
    printf("Digite - 2 - para ver un proveedor especifico\n");
    scanf("%d", &opc); 
    limpiarbuffer(); 


    switch (opc)
    {
    case 1:
        limpiarbuffer(); 
        saltoLinea(); 
        system("cls"); 
        contador= 0; 

        fread(&pr, sizeof(struct Productos), 1, Datos);
        while (!feof(Datos))
        {
            contador++; 
            limpiarbuffer(); 

            printf("ID: %s", pr.prov.provID); 
                saltoLinea();
<<<<<<< Updated upstream
                
=======

>>>>>>> Stashed changes
            printf("Nombre del proovedor: %s", pr.prov.NameProv);    
            saltoLinea(); 
            limpiarbuffer();

             

            printf("Producto: %s",pr.prov.productop );   
            saltoLinea(); 
            limpiarbuffer();
            fread(&pr, sizeof(struct Productos), 1, Datos);


        }
        break;

    case 2:
        limpiarbuffer(); 
        saltoLinea(); 
        int find = 0; 
        printf ("Digite el numero de codigo ID que desea buscar: ");
        scanf("%s", provID);
        rewind(Datos); 
        fread(&pr, sizeof(struct Productos), 1, Datos);
        while(!feof(Datos))
        {
            if(!strcmp(provID, pr.prov.provID))
            {
                find=1; 
                limpiarbuffer(); 
                printf("----------------------------\n");
                printf("--------- Proveedores --------\n");
                printf("----------------------------\n");

                printf("ID: %s", pr.prov.provID); 
                saltoLinea(); 

                limpiarbuffer();
                printf("Nombre del proveedor: %s", pr.prov.NameProv); 
                saltoLinea(); 

                

                printf("Nombre del proveedor: %s", pr.prov.productop);
                saltoLinea(); 
                /*
                printf("Cantidad del producto: %s", pr.prov.cantprov); 
                saltoLinea(); 
                break;*/

            }
            fread(&pr, sizeof(struct Productos), 1, Datos);
        if (find!=1)
        {
             printf("Ingrese un nombre de proveedor valido e intente nuevamente! \n");
        }
        

        }


        break;
    
    default:
        break;
    }

     


}

void subAgregarProd(FILE *Franchyeska, struct Productos pr, FILE *Datos){
    
    int Control = 0; //Variable de control//      

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

        datoscompra(Datos,pr);       
        

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

void ModificarProd(FILE *Franchyeska, struct Productos pr)
{
    limpiarbuffer(); 
    char IDseeker[20];
    bool found = false;
    FILE *temporal;
    Franchyeska = fopen("Master.txt","r");
    temporal = fopen("temporal.txt","a+");

    printf("Ingrese el ID del producto que desea modificar: ");
    scanf("%s", IDseeker); 
    while(!feof(Franchyeska))
    {
        if(!strcmp(IDseeker, pr.prodID)) 
        {
        found = true;
        limpiarbuffer();
        int opmod = 0;
        limpiarbuffer(); 
    
        printf("ID: %s \n ", pr.prodID); 
        printf("Tipo del producto: %s \n", pr.Tipo); 
        printf("Precio: %f \n", pr.price); 
        printf("Descripcion: %s \n", pr.descripcion); 
        printf("Cantidad en sucursal central: %d \n", pr.sub.SucursalCentral); 
        printf("Cantidad en sucursal 1: %d \n", pr.sub.sucursal_1); 
        printf("Cantidad en sucursal 2: %d \n", pr.sub.sucursal_2);
        printf("Cantidad en sucursal 3: %d \n", pr.sub.sucursal_3);
        printf("Cantidad en sucursal 4: %d \n", pr.sub.sucursal_4);
        fread(&pr, sizeof(struct Productos), 1, Franchyeska);

        printf("Datos que puede editar\n");
        printf("Digite - 1 - para modificar el nombre\n");
        printf("Digite - 2 - para modificar el precio\n");
        printf("Digite - 3 - para modificar la descripcion\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opmod);

        switch (opmod)
        {
            case 1:
                printf("\n Ingrese el nuevo nombre: ");
                gets(pr.nombre); 
                limpiarbuffer(); 
                saltoLinea(); 
                break;
            case 2:
                printf("\n Ingrese el nuevo precio: ");
                scanf("%f", &pr.price);
                limpiarbuffer();
                saltoLinea(); 
                break;

            case 3:
                printf("\n Ingrese la nueva descripcion: ");
                gets(pr.descripcion); 
                limpiarbuffer();
                saltoLinea(); 
                break;
            
            default:
                printf("Estimado Usuario, por favor ingrese una opcion valida! \n");  
                limpiarbuffer(); 
                saltoLinea();
                break;
        }
        fwrite(&pr, sizeof(struct Productos), 1, temporal);
        printf("Producto actualizado con exito! \n");
        }
        else
        {
            fwrite(&pr, sizeof(struct Productos), 1, temporal);
        }
        fread(&pr, sizeof(struct Productos), 1, temporal);

        if(found==false)
        {
        printf("Producto inexistente\n");
        }


        
    }

}

int PrincipFunc_Agregar(FILE *Franchyeska,FILE *dat){

    struct Productos pr;
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

int visualizarProductos(FILE *Franchyeska)
{   
    int contador;
    Franchyeska = fopen("Master.txt", "r");
    if(Franchyeska==NULL){
        printf("Error, el fichero no existe \n");
        return 1;
         
    }
    
    struct Productos pr;
    char prodID[10];
    int opc= 0; 
    limpiarbuffer(); 
    printf("Digite - 1 - para ver todos los productos\n"); 
    printf("Digite - 2 - para ver un producto especifico\n"); 
    printf("Digite - 3 - para ver productos por tipo\n");
    printf("Digite - 4 - para ver por sucursal\n");
    printf("Digite - 5 - para volver\n");
    scanf("%d", &opc);
    limpiarbuffer(); 

    switch (opc)
    {
    case 1:

        limpiarbuffer(); 
        saltoLinea(); 
        contador= 0; 
        
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
                
                limpiarbuffer();
                printf("ID: %s ", pr.prodID);    
                saltoLinea(); 

                printf("Nombre del producto: %s \n", pr.nombre);    
                saltoLinea(); 
                limpiarbuffer();

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
       verportipo(Franchyeska);
       break;

    case 4: 
       versucursal(Franchyeska);
       break;   
    
    case 5:
       
         
       break;
    default:
      printf("Invalid data");
        break;
    }

    fclose(Franchyeska); 
    
    return 0;
}

