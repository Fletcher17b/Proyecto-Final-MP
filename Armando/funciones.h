#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void limpiarbuffer() {
    fflush(stdin);
    fflush(stdout);
}

void cleanscreen() {
    system("pause");
    system("cls");
}

struct Cliente {
    char nombre[50];
    char direccion[100];
    int telefono;
};

void registroCliente() {
    struct Cliente nuevoCliente;
    printf("Ingrese el nombre del cliente: ");
    scanf("%s", nuevoCliente.nombre);

    printf("Ingrese la direccion del cliente: ");
    scanf("%s", nuevoCliente.direccion); 

    printf("Ingrese el telefono del cliente: ");
    scanf("%d", &nuevoCliente.telefono);

    FILE *file;
    file = fopen("clientes.dat", "a");
    if (file == NULL) {
        printf("Error al crear el archivo.\n");
        exit(1);
    }
    fwrite(&nuevoCliente, sizeof(struct Cliente), 1, file);
    fclose(file);
}

int eliminarArchivo(const char* nombreArchivo) {
    int resultado = remove(nombreArchivo);
    if (resultado == 0) {
        printf("El archivo \"%s\" ha sido eliminado correctamente.\n", nombreArchivo);
        return 0;
    } else {
        printf("Error al eliminar el archivo \"%s\".\n", nombreArchivo);
        return -1;
    }
}
