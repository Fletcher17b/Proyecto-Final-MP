#include<stdio.h>
#include"estructura.h"
#include<string.h>
#include<dos.h>
#include<stdlib.h>

void limipiarbuffer() {
    fflush(stdin);
    fflush(stdout);
}

void cleanscreen() {
    system("pause");
    system("cls");
}

void newProduct(FILE* fileProduct, struct product_template product) {
    int guardado = 0;
    
    if (fileProduct != NULL) {
        fflush(stdin);
        system("cls");
        printf(" - DATOS DEL PRODUCTO -\n\n");
        
        printf("ID del producto: ");
        scanf("%s", product.prodID);
        fflush(stdin);
        
        printf("Nombre: ");
        fgets(product.nombre, sizeof(product.nombre), stdin);
        fflush(stdin);
        
        printf("Precio: ");
        scanf("%f", &product.price);
        fflush(stdin);
        
        printf("Descripcion: ");
        fgets(product.descripcion, sizeof(product.descripcion), stdin);
        fflush(stdin);
        
        printf("Cantidad en central: ");
        scanf("%d", &product.sub.cantidad_en_centra);
        fflush(stdin);
        
        printf("Cantidad en sucursal 1: ");
        scanf("%d", &product.sub.cantidad_en_sucursal_1);
        fflush(stdin);
        
        printf("Cantidad en sucursal 2: ");
        scanf("%d", &product.sub.cantidad_en_sucursal_2);
        fflush(stdin);
        
        printf("Cantidad en sucursal 3: ");
        scanf("%d", &product.sub.cantidad_en_sucursal_3);
        fflush(stdin);
        
        printf("Cantidad en sucursal 4: ");
        scanf("%d", &product.sub.cantidad_en_sucursal_4);
        fflush(stdin);
        
        guardado = fwrite(&product, sizeof(struct product_template), 1, fileProduct);
        
        if (guardado > 0) {
            printf("\n¡Los datos del producto han sido guardados con exito!\n");
        } else {
            printf("\nERROR: Intentalo nuevamente. Si el error persiste, contacta al Administrador del Sistema.\n");
        }
    } else {
        printf("\nERROR: Verifica que el archivo de productos exista, esté abierto en modo agregar y no este siendo utilizado por otro programa.\n");
    }
    
    fclose(fileProduct);
}