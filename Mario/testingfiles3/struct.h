#pragma once

struct cantdist {
    int SucursalCentral;
    int sucursal_1;
    int sucursal_2;
    int sucursal_3;
    int sucursal_4;

};



struct product_template {
 char prodID[10];  
 int tipo;
 char Tipo[25];
 char nombre[50];
 float price;
 char descripcion[400];
 
 struct cantdist sub;
 
};