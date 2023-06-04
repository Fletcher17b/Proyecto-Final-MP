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

struct Cliente //Armando
{
    char nombre[50];
    char direccion[100];
    int telefono[20];
    char cedula[30];
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

struct fact_detalle {
 char prodID[10];  
 int tipo;
 char Tipo[25];
 char nombre[50];
 float price;
 char descripcion[200];
 
};

struct fact_enc {
   char IDfact[10];
   char IDorg[10];
   char numser[10];
   char cajero[20];
   char IDcliente;
   float subtotal;
   float iva;
   float total;

   struct fact_detalle detalle;
};