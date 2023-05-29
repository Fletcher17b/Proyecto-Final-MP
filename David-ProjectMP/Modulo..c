#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Struct.h"
#include "Funciones.h"

int main(){
    int op= 0; 
    struct Productos sub1;
    int banderaw = 0;
    FILE *Prod=NULL;
    

    while (!banderaw)
    {
        op = menu();
        switch (op)
        {
        case 1:
            limpiarbuffer(); 
            system("cls"); 
            AgregarProd(Prod, sub1); 

            break;
        case 2: 
            limpiarbuffer(); 
            system("cls"); 
            

            break;
        case 3: 
            limpiarbuffer(); 
            system("cls"); 
            

            break;

        case 4: 
            limpiarbuffer(); 
            system("cls"); 
            visualizarAtleta(Prod, sub1); 

            break;
        
        default:
            break;
        }
    }
     

    
    
    

}