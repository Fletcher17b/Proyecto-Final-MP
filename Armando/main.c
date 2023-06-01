#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
    int op;
    printf("-----Bienvenido a Franchyeska Accesorios-----\n");
    printf("-----Somos una tienda de joyeria para mujeres.-----\n");
    printf("si quieres obtener mas informacion sobre la tienda pulsa 1 de lo contrario pulsa 2.");
    switch (op)
    {
    case 1:
        if (op=1)
        {
            printf("Pulsaste 1, aqui tendras mas informacion de la tienda");
            printf("Nuestra sucursal principal esta ubicada en bello horizonte, para ser exacto de la rotonda de bello horizonte 2 cuadras al sur, 1 cuadra al oeste y media cuadra al sur. Para contactarte con nosotros puedes usar nuestras redes sociales o nuestro whatsapp +505 8112 1134\n ");
        }
        
        break;
    case 2:
    if (op=2)
    {
        printf("Nada mas que decir");
    }
    

    default:
        break;
    }
    

    const char* nombreArchivo = "clientes.dat";
    eliminarArchivo(nombreArchivo);
    registroCliente();
    return 0;
}
