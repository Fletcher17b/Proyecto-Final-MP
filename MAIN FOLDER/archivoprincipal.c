#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<stdbool.h>
#include"FuncionesMario.h"
#include"FuncionesDavid.h"
//#include"FuncionesClaudia.h"
#include"FuncionesArmando.h"
#include"archivodeestructuras.h"
#include"archivodefunciones.h"

void gestion_inv() 
{
cleanscreen();

FILE *Franchyeska = NULL;
FILE *Dat=NULL; 
struct Productos pr; 


int segurodeeliminacion=0;
int bandera =0;
int eleccion = 0;
while (bandera != 1) 
 {
cleanscreen();
printf("\n Menu de inventario \n 1. Agregar Productos\n 2. Eliminar producto \n 3. Trasladar productos entre sucursales\n 4. Menu de visualizacion de Productos \n 5. Ver proveedores\n 6. Salir\n");
scanf("%d",&eleccion);
switch (eleccion)
     {
case 1:
    PrincipFunc_Agregar(Franchyeska,Dat);
    cleanscreen();
    break;

case 2:
    printf("Atencion: Al elimnar un producto este sera retirado de todas las sucursales\n Presione 1 si esta seguro de continuar: ");
    scanf("%d",&segurodeeliminacion);
    if (segurodeeliminacion ==1) {
        removeprod(Franchyeska);
    } 
    cleanscreen();
    break;

case 3:
    transferencia_interna_prods();
    cleanscreen();
    break;

case 4:
    visualizarProductos(Franchyeska);
    cleanscreen();
    break;
case 5:
   Proveedores(Dat,pr);
   break;

case 6:
    bandera =1;
    cleanscreen();
    
    break;



default:
    printf("opcion invalida\n");
    system("pause");
    break;
    }
  }
}

void clientes() {

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
            Buscarusuario();
            break;
            }
        case 3:
        {
            limpiarbuffer();
            borrarArchivo();
            break;

        }
        default:
            printf("Por favor, ingresa una opcion valida para que podamos continuar\n");
            break;
            cleanscreen();
            }

}

int main(){
  int loopexit=0;
  int opcion;

  franchyeska_inicio();

  clientes();


  while (loopexit!=1)
  {
    system("cls");
    printf(" Usted dispone de las siguientes opciones: \n");
    printf(" 1. Gestion de inventario \n 2. Facturar productos\n 4. Salir del programa\n");
    scanf("%d",&opcion);
    limpiarbuffer();

    switch (opcion)
    {
    case 1:
        gestion_inv();
        break;
    case 2:
        
        break;

    case 4:
        loopexit =1;
        break;
    
    default:
      printf("Opcion invalida\n");
        break;
    }
  }
  
   

    return 0;
}