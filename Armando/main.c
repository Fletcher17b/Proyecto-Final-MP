#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
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

    int opregistro;
    cleanscreen();
    limpiarbuffer();
    printf("Eres nuevo usuario o ya has ingresado alguna vez?\n");
    printf("Si eres nuevo pulsa 1, si ya te habias registrado pulsa 2, si quieres eliminar tu registro pulsa 3.\n");
    scanf("%d", &opregistro);

    switch (opregistro) {
        case 1:
        limpiarbuffer();
            printf("Estamos encantados de tener un nuevo usuario, por favor registrate para que estes siempre con nosotros\n");
            registroCliente();
            printf("Registro de cliente completado.\n");
            cleanscreen();
            break;
        case 2:
            {
                limpiarbuffer();
                char nombreArchivo[100];
                printf("Ingrese su nombre de usuario (agrega .txt): ");
                scanf("%s", nombreArchivo);

                int resultado = buscarArchivo(nombreArchivo);

                if (resultado == 0) {
                    printf("No estas registrado, por favor registrate a continuacion\n");
                    registroCliente();
                    printf("Registro de cliente completado.\n");
                } else {
                    printf("Usted ya esta registrado, Bienvenido\n");
                }
                break;
                limpiarbuffer();
            }
        case 3:
        {
            char nombreArchivo[100];
            printf("Usted ha elegido eliminar su registro\n");
            borrarArchivo();
            break;

        }
        default:
            printf("Por favor, ingresa una opcion valida para que podamos continuar\n");
            break;
            cleanscreen();
            }
    
    return 0;
}
