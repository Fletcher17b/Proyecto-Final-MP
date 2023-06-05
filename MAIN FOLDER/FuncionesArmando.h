#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"archivodeestructuras.h"
#include"archivodefunciones.h"

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

    fwrite(&nuevoCliente, sizeof(struct Cliente), 1, file);
    fclose(file);
}

int buscarArchivo(const char* nombreArchivo) {
    FILE* file = fopen(nombreArchivo, "r");

    if (file == NULL) {
        printf("Su registro no existe\n");
        return 0; 
    } else {
        printf("El archivo existe.\n");
        fclose(file);
        return 1; 
    }
}

void borrarArchivo() {
    char nombreArchivo[100];
    printf("Usted ha elegido eliminar su registro\n");
    printf("Ingrese su nombre de usuario (agregue .txt): ");
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

void Buscarusuario(){
    char nombreArchivo[100];
    printf("Ingrese su nombre de usuario (agrega .txt): ");
     scanf("%s", nombreArchivo);

    int resultado = buscarArchivo(nombreArchivo);

    if (resultado == 0) {
    printf("Por favor registrate a continuacion\n");
    registroCliente();
    printf("Registro de cliente completado.\n");
    } 
    else {
    printf("Usted ya esta registrado, Bienvenido\n");
    }
}

void franchyeska_inicio(){
    int op;
    printf("-----Bienvenido a Franchyeska Accesorios-----\n");
    printf("-----Somos una tienda de joyeria para mujeres.-----\n");
    printf("si quieres obtener mas informacion sobre la tienda pulsa 1 de lo contrario pulsa cualquier otra tecla.\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
    limpiarbuffer();
        if (op==1)
        {
            printf("Pulsaste 1, aqui tendras mas informacion de la tienda\n");
            printf("Nuestra sucursal principal esta ubicada en bello horizonte, para ser exacto de la rotonda de bello horizonte 2 cuadras al sur, 1 cuadra al oeste y media cuadra al sur. Para contactarte con nosotros puedes usar nuestras redes sociales aparecemos como Franchyeska Accesorios en todas o contactate por nuestro whatsapp +505 8112 1134 estaremos encantados de atenderte\n \n");
            limpiarbuffer();
        }
        
        break;
    case 2:
    if (op!=1)
    {
        printf("Gracias por visitarnos, continua navegando.\n");
    }
    
    default:
        break;
    }

}


