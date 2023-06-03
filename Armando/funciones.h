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
    int telefono[20];
    char cedula[30];
};

void registroCliente() {
    struct Cliente nuevoCliente;
    printf("Ingrese su nombre de usuario: ");
    scanf("%s", nuevoCliente.nombre);

    printf("Ingrese su direccion: ");
    scanf("%s", nuevoCliente.direccion);

    getchar();

    printf("Ingrese su numero: ");
    scanf("%d", &nuevoCliente.telefono);

    printf("Ingrese su numero de cedula: ");
    scanf("%d", &nuevoCliente.cedula);
    getchar();
    
    char nombreArchivo[100];
    snprintf(nombreArchivo, sizeof(nombreArchivo), "%s.txt", nuevoCliente.nombre);

    FILE *file;
    file = fopen(nombreArchivo, "a");
    if (file == NULL) {
        printf("Error al crear el archivo.\n");
        exit(1);
    }

    fprintf(file, "Nombre: %s\n", nuevoCliente.nombre);
    fprintf(file, "Direccion: %s\n", nuevoCliente.direccion);
    fprintf(file, "Telefono: %d\n", nuevoCliente.telefono);
    fprintf(file, "Cedula: %d\n", nuevoCliente.cedula);

    fclose(file);
}

int buscarArchivo(const char* nombreArchivo) {
    FILE* file = fopen(nombreArchivo, "r");

    if (file == NULL) {
        printf("El archivo no existe. Debes registrarte.\n");
        return 0; 
    } else {
        printf("El archivo existe.\n");
        fclose(file);
        return 1; 
    }
}

void borrarArchivo() {
    char nombreArchivo[100];
    printf("Ingrese el nombre del archivo a borrar: ");
    scanf("%s", nombreArchivo);
    
    FILE* archivo = fopen(nombreArchivo, "r");
    
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }
    
    fclose(archivo);
    
    int resultado = remove(nombreArchivo);
    
    if (resultado == 0) {
        printf("Archivo eliminado con exito.\n");
    } else {
        printf("No se pudo eliminar el archivo.\n");
    }
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
