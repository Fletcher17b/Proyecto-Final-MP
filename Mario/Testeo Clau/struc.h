#pragma once

struct cantdist {
    int cantidad_en_centra;
    int cantidad_en_sucursal_1;
    int cantidad_en_sucursal_2;
    int cantidad_en_sucursal_3;
    int cantidad_en_sucursal_4;

};

struct Productos {

 char prodID[10];  
 char nombre[50];
 float priceunit;
 char descripcion[200];
 float gastos_varios; 

 struct cantdist sub;
 
};