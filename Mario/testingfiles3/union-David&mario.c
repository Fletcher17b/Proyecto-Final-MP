#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<stdbool.h>
#include"struct2.h"
#include"funcionesmario&david.h"


int protomain() {

    FILE *Franchyeska = NULL;
    FILE *Dat=NULL; 
    struct Productos pr1;

    

    int choice=0;

    printf("1. Agregar Productos \n 2. ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        PrincipFunc_Agregar(Franchyeska,pr1,Dat);
        break;
    
    default:
        break;
    }

    return 0;
}

int main() {

    protomain();
    return 0;
}