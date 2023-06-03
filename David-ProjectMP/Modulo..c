#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Struct.h"
#include "Funciones.h"
#include "Prueba.h"

int main(){
    int op= 0; 
    struct Productos sub1;
    struct Productos prov1;
    int banderaw = 0;
    FILE *Prod=NULL;
    FILE *Dat=NULL; 
    

    while (!banderaw)
    {
        op = menu();
        switch (op)
        {
        case 1:
            limpiarbuffer(); 
            system("cls"); 
            int opmenu= 0; 
            opmenu= Menutipo(Prod, sub1, Dat, prov1);  
            

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
            visualizarProductos(Prod, sub1); 

            break;
        
        default:
            break;
        }
    }
     

    
    
    

}