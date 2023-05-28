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
    FILE *Franchyeska = NULL;
    Franchyeska = fopen("Master.txt", "w");
    if(Franchyeska==NULL){
        printf("Error, el fichero no ha sido creado! \n");
    }
    else{
        printf("El fichero ha sido abierto en modo agregar. \n");
        //system("cls");
        printf("\nRegresando al menu principal... \n");
    }
    return Franchyeska;
}


void AgregarProd(FILE *Franchyeska, struct Productos pr){
    //Variable de control// 
    abrirFicheroA();


    int Control = 0; 
    if (Franchyeska!=NULL){
        printf("ID: ");    
        gets(pr.prodID); 
        saltoLinea(); 

        printf("Nombre del producto: ");    
        gets(pr.nombre); 
        saltoLinea(); 

        printf("Precio del producto: ");    
        scanf("%d", &pr. price);
        saltoLinea(); 

        printf("Descripcion del producto (200 caracteres): ");    
        gets(pr.nombre); 
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
    else{
        printf("\nERROR: verifique que el fichero de Atleta exista, que este abierto en modo agregar, y/o finalmente que no esta siendo ocupado por otro programa... \n");
    }

    fclose(Franchyeska); 

}
