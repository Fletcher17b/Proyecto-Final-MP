#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>

int menu1() {
    limipiarbuffer();
    int opc1;
    int exitmenu1;
    FILE *filepointer = NULL;
    
  
  while (exitmenu1 != 1) {
    printf("\n Sus opciones son: \n 1. Ingresar nuevos productos\n 2. Actualizar cantidades de productos\n 3. Remover Productos \n 4. Salir al menu principal \n");
    scanf("%d",&opc1);
    switch (opc1) {
        case 1: 
          limipiarbuffer();
          cleanscreen();
          nuevosproductos(filepointer);
          exitmenu1 =1;
          break;

        case 2:
          // actualizar cantidades
          break;

        case 3:
          // remover productos
          break;
        case 4:
          exitmenu1 = 1;
          break;  

        default:
         printf("opcion invalida");
         cleanscreen();
         break;
    }

  }
    return 0;
}

int menu2() {
  limipiarbuffer();
  int opc2;
  int exitmenu2 =0; 

  while (exitmenu2 != 1)
  {
    printf("\n Sus opciones son: \n 1.  \n 4.  \n");
    scanf("%d",&opc2);

    switch (opc2)
    {
    case 1:
      /* code */
      break;
    
    default:
      break;
    }
  }
  


  return 0;
}


int menu0(){
  
   int opc0;
   int centinela0;

while(centinela0 !=1 ) {

   printf("Sus opciones consisten en: \n 1. Modificar Inventario actual \n 2. Continuar con inventario actual \n 3. Salir \n");
   scanf("%d", &opc0 );

   switch (opc0)
   {
   case 1:
      printf(" \n usted ha seleccionado opcion 1 \n");
      limipiarbuffer();
      menu1();
      cleanscreen();    
    break;

    case 2:
      printf(" \n usted ha seleccionado opcion 2 \n");
      limipiarbuffer();
      menu2();
      cleanscreen();  
     break;

    case 3: 
     centinela0 = 1;  
     break;
   
   default:
    printf("\n usted ha ingresado un valor invalido por favor, ingrese denuevo \n");
    cleanscreen();
    break;
   }

}

    return 0;
} 


int main() {




    return 0;
}