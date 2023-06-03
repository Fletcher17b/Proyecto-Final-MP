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
    printf("\n *************MENU PRINCIPAL*************\n");
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
    
    }
    else{
        printf("El fichero ha sido abierto en modo agregar. \n");
        //system("cls");
        printf("\nRegresando al menu principal... \n");
    }
    return Franchyeska;
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
    printf("Digite - 0- para ver todos los productos\n"); 
    limpiarbuffer(); 
    scanf("%d", &opc);
    if (opc==1)
    {
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
    else{
        printf("Estimado Usuario, por favor ingrese una opcion valida! \n");
    }   

        
    }
    fclose(Franchyeska); 
    

}



