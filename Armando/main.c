#include<stdio.h>
#include"funciones.h"
#include"estructura.h"
#include<string.h>
#include<stdlib.h>
int main() {
    FILE* fileProduct;
    struct product_template product;
    
    fileProduct = fopen("productos.dat", "a");
    if (fileProduct == NULL) {
        printf("Error al abrir el archivo de productos.\n");
        return 1;
    }
    
    newProduct(fileProduct, product);
    
    return 0;
}
