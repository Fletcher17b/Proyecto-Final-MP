#pragma once

struct product_template {
 char nombre[50];
 float price;
 char descripcion[200];
 float gastos_varios;
 int cantidad; 

 int checklist[4]; // en base a las posiciones que se encuentren en este array se realizara una checklist 

};

 struct cantidaes {
    int cantidad_en_centra;
    int cantidad_en_sucursales[];

 };

