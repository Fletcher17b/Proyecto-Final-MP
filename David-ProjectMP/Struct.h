#pragma once


struct cantproductos
{
    int SucursalCentral; 
    int sucursal_1; 
    int sucursal_2; 
    int sucursal_3; 
    int sucursal_4; 

};

struct proveedores
{
    char NameProv[60];
    char productop[30];
    
    
};


struct Productos
{
    char prodID[10];  
    char nombre[50];
    float price;
    char descripcion[400];
    char Tipo[25];
    int tipo;

    struct proveedores prov; 
    struct cantproductos sub; 
   
};

