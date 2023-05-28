#pragma once

struct cantproductos
{
    int SucursalCentral; 
    int sucursal_1; 
    int sucursal_2; 
    int sucursal_3; 
    int sucursal_4; 

};

struct Productos
{
    char prodID[10];  
    char nombre[50];
    float price;
    char descripcion[200];
    struct cantproductos sub; 
   
};

