#pragma once

struct cantdist {
    int cantidad_en_centra;
    int cantidad_en_sucursales;

};

struct product_template {
 char prodID[10];  
 char nombre[50];
 float price;
 char descripcion[200];
 float gastos_varios; 
 struct cantdist sub;
 
};





