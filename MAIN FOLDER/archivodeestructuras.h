#pragma once

struct cantdist {
    int SucursalCentral;
    int sucursal_1;
    int sucursal_2;
    int sucursal_3;
    int sucursal_4;

};

struct proveedoresFich {
  
    char NameProv[60];
    char proveedorID[30];
    char productprovID[30];
    int aSucursalCentral;
    int asucursal_1;
    int asucursal_2;
    int asucursal_3;
    int asucursal_4;

};

struct proveedores //David
{

    char NameProv[60];
    char productprovID[30];

    
    
};


struct Productos {
 char prodID[10];  
 int tipo;
 char Tipo[25];
 char nombre[50];
 float price;
 char descripcion[400];
 
 struct proveedores prov; 
 struct cantdist sub;
 
};