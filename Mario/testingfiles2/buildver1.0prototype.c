#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<stdbool.h>

void limipiarbuffer() {
    fflush(stdin);
    fflush(stdout);
}

void cleanscreen() {
    system("pause");
    system("cls");
}

struct cantdist {
    int cantidad_en_centra;
    int cantidad_en_sucursal_1;
    int cantidad_en_sucursal_2;
    int cantidad_en_sucursal_3;
    int cantidad_en_sucursal_4;

};

struct product_template {
 char prodID[10];  
 char nombre[50];
 float priceunit;
 char descripcion[200];
 float gastos_varios; 

 struct cantdist sub;
 
};

struct product_template get_info() {
    struct product_template input;
      printf("\nIngrese ID del producto (maximo 10 caracteres, no se debe repetir) ");
      gets(input.prodID);
      limipiarbuffer(); 
      
      printf("\nIngrese nombre: ");
      scanf("%s",input.nombre);
      limipiarbuffer();

      printf("\nIngrese precio: ");
      scanf("%f",&input.priceunit);
      limipiarbuffer();

      printf("\nIngrese una breve descripcion del producto: ");
      scanf("%s",input.descripcion);
      limipiarbuffer();
      
     int cant_centralverifier = 0;
     
      
      printf("\nIngrese la cantidad central: ");
      cant_centralverifier = scanf("%d",&input.sub.cantidad_en_centra);
      limipiarbuffer();
      while (cant_centralverifier == 0) {
          printf("\n invalid input, ingrese valor otra vez\n");
          cant_centralverifier = scanf("%d",&input.sub.cantidad_en_centra);
          limipiarbuffer();
      }

      int cantidades_conduerdan = 0;
       
      while (cantidades_conduerdan != 1 ) {
        printf("\nIngrese la cantidad en sucursal 1: ");
        scanf("%d",&input.sub.cantidad_en_sucursal_1);
        limipiarbuffer();

        printf("\nIngrese la cantidad sucursal 2: ");
        scanf("%d",&input.sub.cantidad_en_sucursal_2);
        limipiarbuffer();

        printf("\nIngrese la cantidad sucursal 3: ");
        scanf("%d",&input.sub.cantidad_en_sucursal_3);
        limipiarbuffer();

        printf("\nIngrese la cantidad sucursal 4: ");
        scanf("%d",&input.sub.cantidad_en_sucursal_4);
        limipiarbuffer();
        
        int suma = input.sub.cantidad_en_sucursal_1 + input.sub.cantidad_en_sucursal_2 + input.sub.cantidad_en_sucursal_3 + input.sub.cantidad_en_sucursal_4;
        if (suma != input.sub.cantidad_en_centra) {
          printf("\ncantidades repartidas no concuerdan con la central\n");
        } else {
          cantidades_conduerdan = 1;
        }
      }


    return input;
}

int agregarprod(FILE *fileused_a) {

  limipiarbuffer();

  int prod_input_num = 0;
  struct product_template structtemp;
  int guardadobien = 0;


  fileused_a = fopen("masterfile.txt","a+");
  
  if (fileused_a != NULL) {
    printf("cuantos productos desea ingresar? \n");
    scanf("%d", &prod_input_num);

    for (int counter1 = 1; counter1 <= prod_input_num; counter1++) 
    {

      limipiarbuffer();
      structtemp = get_info();
      guardadobien = fwrite(&structtemp, sizeof(struct product_template),1, fileused_a );

      if (guardadobien >0) {
       printf("todo chingon\n");
      } else 
       {
        printf("nel perro \n");
       }
    }
  }


  fclose(fileused_a);
  return 0;
}


int modifyprods(FILE *fileused_b) { 

 limipiarbuffer(); 
 
 char IDseeker[10];
 bool found = false;
 FILE *temporal;
 struct product_template temp_b;
 
 fileused_b = fopen("masterfile.txt","r");
 temporal = fopen("temporal.txt","a+");
 
 printf("Ingrese el ID del producto que desea modificar: ");
 gets(IDseeker);

 fread(&temp_b, sizeof(struct product_template),1, fileused_b);
 while(!feof(fileused_b)) {
  if(!strcmp(IDseeker, temp_b.prodID)) {
    found = true;
    limipiarbuffer();
    int loopexit1 = 0;
    int valuetochange = 0; 

    printf("\nNombre: %s \n", temp_b.nombre);
    printf("Precio: %.2f \n", temp_b.priceunit);
    printf("Descripcion: %s \n", temp_b.descripcion); 
    

    while (loopexit1 != 1) 
    {
       printf("Ingrese valor que quiere actualizar: \n 1. precio \n 7. Salir \n ");
       scanf("%d", &valuetochange);
       printf("\n");
       limipiarbuffer();

       switch (valuetochange)
       {
       case 1:
        printf("Usted ha elejido modificar el precio \n");
        scanf("%f", &temp_b.priceunit);
        limipiarbuffer();
        break;

       case 7:
         loopexit1 =1;
         break;
       
       default:
        break;
       }
    limipiarbuffer();
      
    }
    fwrite(&temp_b, sizeof(struct product_template), 1, temporal);
    printf("la neta que todo chingon");

    

  } else {
    fwrite(&temp_b, sizeof(struct product_template), 1, temporal);
  }
  fread(&temp_b, sizeof(struct product_template ), 1, fileused_b);
 }
 
 if (found == false) {
  printf("\n se mamo usted \n");
 }

 fclose(temporal);
 fclose(fileused_b);
 int borrado;
 borrado = remove("masterfile.txt");
    if(borrado==0)
    {
        rename("temporal.txt", "masterfile.txt");
    }

  return 0;
}


int removeprod(FILE *fileused_c) {

  limipiarbuffer();

 char IDseeker[10];
 bool found = false;
 FILE *temporal;
 struct product_template temp_c;

 fileused_c = fopen("masterfile.txt","r");
 temporal = fopen("temporal.txt","a+");
 printf("\n\n");
 gets(IDseeker);
  
  fread(&temp_c, sizeof(struct product_template),1, fileused_c);
  while(!feof(fileused_c)) {

     if(!strcmp(IDseeker, temp_c.prodID)) {
    found = true;
    limipiarbuffer(); 
    int choice;
      
      printf("\nNombre: %s \n", temp_c.nombre);
      printf("Precio: %.2f \n", temp_c.priceunit);
      printf("Descripcion: %s \n", temp_c.descripcion); 
      
      printf("Eliminar? \n");
      scanf("%d",&choice);

      if (choice == 1) {
        printf("bye file \n");

      } else {
        fwrite(&temp_c,sizeof(struct product_template),1,temporal);
        printf("back to main\n");
      }


     } else { 
       fwrite(&temp_c, sizeof(struct product_template), 1, temporal);
     }
     fread(&temp_c, sizeof(struct product_template),1, fileused_c);
  }

 
if (found == false) {
  printf("\n se mamo usted \n");
 }

 fclose(temporal);
 fclose(fileused_c);
 int borrado;
 borrado = remove("masterfile.txt");
    if(borrado==0)
    {
        rename("temporal.txt", "masterfile.txt");
    }


  return 0;
}

int factura(FILE *fileused_d) {

  limipiarbuffer();
  cleanscreen();

FILE *temporal;
 struct product_template temp_c;
 
 fileused_d = fopen("masterfile.txt","r");
 temporal = fopen("temporal.txt","a+");



  bool found = false;
  char IDseeker[10];
  int sucursal;
  int cantextract;
  float result;
  
    int loopexit1 = 0;
    int loopexit2 = 0;
  //  int valuetochange = 0; 
    int scanfvalidation;
 
  fread(&temp_c, sizeof(struct product_template),1, fileused_d);

  printf("Bienvenido al menu de facturacion \n");

  printf("Ingrese la ID del producto que desea comprar\n");
  gets(IDseeker);

  


while(!feof(fileused_d)) {
  if(!strcmp(IDseeker, temp_c.prodID)) {
    found = true;
    limipiarbuffer();
    
    printf("Nombre: %s \n", temp_c.nombre);
    printf("Precio individual: %.2f \n", temp_c.priceunit);
    printf("Descripcion: %s \n", temp_c.descripcion); 

    printf("Digite la cantidad que desea extraer \n");
    while (loopexit2 != 1) {
       limipiarbuffer();
      scanfvalidation = scanf("%d",&cantextract);

      if (scanfvalidation == 0) { 
        printf("valor invalido\n");
      } else {
        loopexit2 =1;
      }

    }
    
     limipiarbuffer();
    printf("Seleccione la sucursal donde se realizara el tramite \n ");
   
   while (loopexit1 != 1) {
    limipiarbuffer();
    scanf("%d",&sucursal);
    limipiarbuffer();
    switch (sucursal)
    {
    case 0:
      // printf("central no disponible\n");
      loopexit1 =1;
      break;

    case 1:
      limipiarbuffer();
      if (cantextract == 0) {printf("Cantidad no puede ser igual a 0 \n");}
      if (cantextract < 0) {printf("cantidad invalida\n");}
      if (cantextract > temp_c.sub.cantidad_en_sucursal_1) {
        printf("La cantidad deseada excede las existencias, productos disponibles: %d \n", temp_c.sub.cantidad_en_sucursal_1);
        printf("Digite denuevo: ");
        limipiarbuffer();
      } else {
        result = cantextract*temp_c.priceunit;
        printf("El costo por %d unidades del item %s es de %.2f \n", cantextract, temp_c.prodID, result);
        temp_c.sub.cantidad_en_sucursal_1 = temp_c.sub.cantidad_en_sucursal_1 - cantextract;
        loopexit1 =1;
      }  
      break;

    case 2:
      break;
    
    default:
      break;
    }
  }
  
   printf("\nNombre: %s \n", temp_c.nombre);
    printf("Precio: %.2f \n", temp_c.priceunit);
    printf("Descripcion: %s \n", temp_c.descripcion);

    printf("central: %d \n", temp_c.sub.cantidad_en_centra);
    printf("1: %d \n", temp_c.sub.cantidad_en_sucursal_1);
    printf("2: %d \n", temp_c.sub.cantidad_en_sucursal_2);
    printf("3: %d \n", temp_c.sub.cantidad_en_sucursal_3);
    printf("4: %d \n", temp_c.sub.cantidad_en_sucursal_4);

  fwrite(&temp_c, sizeof(struct product_template), 1, temporal);  

   
  
  } else {
    fwrite(&temp_c, sizeof(struct product_template), 1, temporal);
  }
  fread(&temp_c, sizeof(struct product_template ), 1, fileused_d);
 }
  
 fclose(temporal);
 fclose(fileused_d);
 int borrado;
 borrado = remove("masterfile.txt");
    if(borrado==0)
    {
        rename("temporal.txt", "masterfile.txt");
    }
  return 0;
}

int comprob(FILE *fileused_0) {
  limipiarbuffer();
  cleanscreen();

  struct product_template temp_0;

  printf("\n comprob \n");

  fileused_0 = fopen("masterfile.txt","r");
  fread(&temp_0, sizeof(struct product_template),1, fileused_0);
  char IDseeker[10];
  int exit;
  gets(IDseeker);

  while(!feof(fileused_0) && exit != 1) {

  if(!strcmp(IDseeker, temp_0.prodID)) { 
    limipiarbuffer();
    printf("\nNombre: %s \n", temp_0.nombre);
    printf("Precio: %.2f \n", temp_0.priceunit);
    printf("Descripcion: %s \n", temp_0.descripcion);

    printf("central: %d \n", temp_0.sub.cantidad_en_centra);
    printf("1: %d \n", temp_0.sub.cantidad_en_sucursal_1);
    printf("2: %d \n", temp_0.sub.cantidad_en_sucursal_2);
    printf("3: %d \n", temp_0.sub.cantidad_en_sucursal_3);
    printf("4: %d \n", temp_0.sub.cantidad_en_sucursal_4);
    exit =1 ;
  } 
  fread(&temp_0, sizeof(struct product_template),1, fileused_0);
      
  } 


  return 0;
}

void menudef() { 

   FILE *fileused = NULL;
   int loopexit = 0;

   while (loopexit != 1) {
      cleanscreen();
      limipiarbuffer();
      int opcdef = 0;

      printf("Sus opciones son las siguiente: \n 1. Agregar producto \n 2. Modificar producto \n 3. remover producto \n 4. Actualizar cantidad de un producto\n 5. factura \n 7. Actualizar cantidad de producto \n 6. Salir\n");
      scanf("%d",&opcdef);
      limipiarbuffer();
      switch(opcdef) {
        case 1:
          agregarprod(fileused); 

          break;


        case 2: 
          modifyprods(fileused);
          break;

        case 3: 
          removeprod(fileused);
          break;

        case 4: 
          factura(fileused);

          break;  
        
        case 5: 


          break;

        case 6: 
          comprob(fileused);

          break;


        case 7:
          printf("bye \n");
          cleanscreen();
          loopexit = 1;
          break;  

      }

   }
   
}



int main() {

 menudef();

printf("bye bye \n");
    return 0;
}