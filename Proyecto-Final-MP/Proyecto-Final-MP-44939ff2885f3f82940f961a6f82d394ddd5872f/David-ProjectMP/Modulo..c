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
        limpiarbuffer();
        switch (op)
        {
        case 1:
            limpiarbuffer(); 
            system("cls"); 
            AgregarProd(Prod, sub1); 

            break;
        
        default:
            break;
        }
    }
     

    
    
    

}