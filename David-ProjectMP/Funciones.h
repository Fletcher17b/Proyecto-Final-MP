#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Struct.h"

void limpiarbuffer()
{
    fflush(stdin); 
    fflush(stdout); 
}

void saltoLinea()
{
    printf("\n"); 
}
int menu()
{
    int opc = 0; 
    printf("*************MENU PRINCIPAL*************\n");
    printf(" - Opcion 1: Agregar productos *\n");
    printf(" - Opcion 2: Actualizar productos *\n");
    printf(" - Opcion 3: Eliminar productos *\n");
    printf(" - Opcion 4: Visualizar productos *\n");
    printf(" - Opcion 4: Salir *\n");
    printf("****************************************\n");
    scanf("%d", &opc); 
    return opc; 
    
}

FILE * abrirFicheroA(){
    FILE *Franchyeska; 
    Franchyeska = fopen("Master.txt", "w");
    if(Franchyeska==NULL){
        printf("Error, el fichero no ha sido creado! \n");
        return 1; // Mario 5/30: esta es una funcion de tipo FILE no de tipo int por lo que no puede retornar un entero 
    }
    else{
        printf("El fichero ha sido abierto en modo agregar. \n");
        //system("cls");
        printf("\nRegresando al menu principal... \n");
    }
    return Franchyeska;
}


void AgregarProd(FILE *Franchyeska, struct Productos pr){
    
    int Control = 0; //Variable de control// 
    Franchyeska = fopen("Master.txt", "a+");
    if(Franchyeska==NULL){
        printf("Error, el fichero no ha sido creado! \n");
        return 1; //Mario 5/30: mismo que el error de mas arriba, tipo FILE no int
    }
    else
    {
        printf("ID: ");    
        gets(pr.prodID); 
        saltoLinea(); 

        printf("Nombre del producto: ");    
        gets(pr.nombre); 
        saltoLinea(); 

        printf("Precio del producto: ");    
        scanf("%f", &pr. price);
        saltoLinea(); 

        printf("Descripcion del producto (200 caracteres): ");    
        gets(pr.descripcion); 
        saltoLinea();

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
    }

    fclose(Franchyeska); 

}

void Leerfichero(FILE *Franchyeska){
    Franchyeska = fopen("archivoAtleta.txt", "r");
    if(Franchyeska==NULL){
       Franchyeska = fopen("archivoAtleta.txt", "w");
        printf("Creamos el fichero \n");
    }
    else{
        Franchyeska = fopen("archivoAtleta.txt", "a");
        printf(" lectura \n");
    }

}

void visualizarAtletas(FILE *Franchyeska, struct Productos pr)
{
    char prodID[10];
    int opc= 0; 
    limpiarbuffer(); 
    printf("Digite - 1 - para ver todos los productos\n"); 
    printf("Digite - 0- para ver todos los productos\n"); 
    limpiarbuffer(); 
    scanf("%d", &opc);
    if (opc==1)
    {
        int contador= 0; 
        limpiarbuffer(); 
        saltoLinea(); 
        printf("N \t ID \t\t Nombre del producto \t Precio \t Descripcion \t\t Sucursal Central \t Sucursal 1 \t Sucursal 2 \t Sucursal 3 \t Sucursal 4 \n");
        fread(&pr, sizeof(struct Productos), 1, Franchyeska);
        while (!feof(Franchyeska))
        {
            contador++; 
            printf("%d \t %s \t\t %s \t %f \t %s \t\t %d \t %d \t %d \t %d \t %d", pr.prodID, pr. price, pr.descripcion, pr.sub.SucursalCentral, pr.sub.sucursal_1, pr.sub.sucursal_2, pr.sub.sucursal_3, pr.sub.sucursal_4); 
            // Mario 5/30: verifica que los formatos (los %letra) concuerden con el tipo de variable de del struct usado, also hay un espacio en pr. price
            fread(&pr, sizeof(struct Productos), 1, Franchyeska); 

        }


        

    }





    else
    {
        if (opc==0)
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

                printf("cantidad en sucursal 1: %d \n", &pr.sub.sucursal_1);  // Mario 5/30: el & no va por que llamas a la variable no a la direccion de ella
                limpiarbuffer();

                printf("cantidad en sucursal 2: %d \n", &pr.sub.sucursal_2);
                limpiarbuffer();

                printf("cantidad en sucursal 3: %d \n", &pr.sub.sucursal_3);
                limpiarbuffer();
                
                printf("cantidad en sucursal 4: %d \n", &pr.sub.sucursal_4);
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
    else{
        printf("Estimado Usuario, por favor ingrese una opcion valida! \n");
    }   

        
    }
    fclose(Franchyeska); 
    

}