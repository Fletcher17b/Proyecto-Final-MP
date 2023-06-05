#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

void limpiarbuffer() {
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

struct Productos {
 char prodID[10];  
 char nombre[50];
 float priceunit;
 char descripcion[200];
 float gastos_varios; 

 struct cantdist sub;
 
};

struct Productos get_info() {
    struct Productos input;
      printf("\nIngrese ID del producto (maximo 10 caracteres, no se debe repetir) ");
      gets(input.prodID);
      limpiarbuffer(); 
      
      printf("\nIngrese nombre: ");
      scanf("%s",input.nombre);
      limpiarbuffer();

      printf("\nIngrese precio: ");
      scanf("%f",&input.priceunit);
      limpiarbuffer();

      printf("\nIngrese una breve descripcion del producto: ");
      scanf("%s",input.descripcion);
      limpiarbuffer();
      
     int cant_centralverifier = 0;
     
      
      printf("\nIngrese la cantidad central: ");
      cant_centralverifier = scanf("%d",&input.sub.cantidad_en_centra);
      limpiarbuffer();
      while (cant_centralverifier == 0) {
          printf("\n invalid input, ingrese valor otra vez\n");
          cant_centralverifier = scanf("%d",&input.sub.cantidad_en_centra);
          limpiarbuffer();
      }

      int cantidades_conduerdan = 0;
       
      while (cantidades_conduerdan != 1 ) {
        printf("\nIngrese la cantidad en sucursal 1: ");
        scanf("%d",&input.sub.cantidad_en_sucursal_1);
        limpiarbuffer();

        printf("\nIngrese la cantidad sucursal 2: ");
        scanf("%d",&input.sub.cantidad_en_sucursal_2);
        limpiarbuffer();

        printf("\nIngrese la cantidad sucursal 3: ");
        scanf("%d",&input.sub.cantidad_en_sucursal_3);
        limpiarbuffer();

        printf("\nIngrese la cantidad sucursal 4: ");
        scanf("%d",&input.sub.cantidad_en_sucursal_4);
        limpiarbuffer();
        
        int suma = input.sub.cantidad_en_sucursal_1 + input.sub.cantidad_en_sucursal_2 + input.sub.cantidad_en_sucursal_3 + input.sub.cantidad_en_sucursal_4;
        if (suma != input.sub.cantidad_en_centra) {
          printf("\ncantidades repartidas no concuerdan con la central, cantidad central: %d\n", input.sub.cantidad_en_centra);
        } else {
          cantidades_conduerdan = 1;
        }
      }


    return input;
}

int agregarprod(FILE *fileused_a) {

  limpiarbuffer();

  struct Productos structtemp;
  int guardadobien = 0;

   fileused_a = fopen("Master.txt","a");

      limpiarbuffer();
      structtemp = get_info();
      guardadobien = fwrite(&structtemp, sizeof(struct Productos),1, fileused_a );

      if (guardadobien >0) {
       printf("todo chingon\n");
      } else 
       {
        printf("nel perro \n");
       }

    fclose(fileused_a);
  return 0;
}

char banana[20];



int modifyprods(FILE *fileused_b) { 

 limpiarbuffer(); 
 
 char IDseeker[10];
 bool found = false;
 FILE *temporal;
 struct Productos temp_b;
 
 fileused_b = fopen("Master.txt","r");
 temporal = fopen("temporal.txt","a+");
 
 printf("Ingrese el ID del producto que desea modificar: ");
 gets(IDseeker);

 fread(&temp_b, sizeof(struct Productos),1, fileused_b);
 while(!feof(fileused_b)) {
  if(!strcmp(IDseeker, temp_b.prodID)) {
    found = true;
    limpiarbuffer();
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
       limpiarbuffer();

       switch (valuetochange)
       {
       case 1:
        printf("Usted ha elejido modificar el precio \n");
        scanf("%f", &temp_b.priceunit);
        limpiarbuffer();
        break;

       case 7:
         loopexit1 =1;
         break;
       
       default:
        break;
       }
    limpiarbuffer();
      
    }
    fwrite(&temp_b, sizeof(struct Productos), 1, temporal);
    printf("la neta que todo chingon");

    

  } else {
    fwrite(&temp_b, sizeof(struct Productos), 1, temporal);
  }
  fread(&temp_b, sizeof(struct Productos ), 1, fileused_b);
 }
 
 if (found == false) {
  printf("\n se mamo usted \n");
 }

 fclose(temporal);
 fclose(fileused_b);

 fileused_b = fopen("Master.txt","r");
 temporal = fopen("temporal.txt","a+");

 fclose(temporal);
 fclose(fileused_b);
 int borrado;
 borrado = remove("Master.txt");
    if(borrado==0)
    {
        rename("temporal.txt", "Master.txt");
    }

  return 0;
}


int removeprod(FILE *fileused_c) {

  limpiarbuffer();

 char IDseeker[10];
 bool found = false;
 FILE *temporal;
 struct Productos temp_c;

 fileused_c = fopen("Master.txt","r");
 temporal = fopen("tempRE.txt","a+");
 printf("\nIngrese ID del producto que desea borrar: \n");
 gets(IDseeker);
 limpiarbuffer();
  
  fread(&temp_c, sizeof(struct Productos),1, fileused_c);
  while(!feof(fileused_c)) {

     if(!strcmp(IDseeker, temp_c.prodID)) {
    found = true;
    limpiarbuffer(); 
    int choice;

      printf("\nNombre: %s \n", temp_c.prodID);  
      printf("\nNombre: %s \n", temp_c.nombre);
      printf("Descripcion: %s \n", temp_c.descripcion); 
      
      printf("Eliminar (1)? \n");
      scanf("%d",&choice);

      if (choice != 1) {
        fwrite(&temp_c,sizeof(struct Productos),1,temporal);
        printf("Volviendo al menu principal\n");

      } else {
        printf("Eliminado \n");
      }


     } else { 
       fwrite(&temp_c, sizeof(struct Productos), 1, temporal);
     }
     fread(&temp_c, sizeof(struct Productos),1, fileused_c);
  }

 
if (found == false) {
  printf("\n Error 404 no encontrado :( \n");
 }

 fclose(temporal);
 fclose(fileused_c);

 fileused_c = fopen("Master.txt","r");
 temporal = fopen("tempRE.txt","a+");

 fclose(temporal);
 fclose(fileused_c);
 int borrado;
 borrado = remove("Master.txt");
    if(borrado==0)
    {
        rename("tempRE.txt", "Master.txt");
    }

  return 0;
}

int factura(FILE *fileused_d) {

  limpiarbuffer();
  cleanscreen();

 FILE *temporal;
 struct Productos temp_c;

 FILE *factura;

printf("A nombre de quien wey?");
char queguey[40];
gets(queguey);

char factsting[20] = "factura.txt";

strcat(queguey,factsting);

 factura = fopen(queguey,"w");
 
 fileused_d = fopen("Master.txt","r");
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
 
  fread(&temp_c, sizeof(struct Productos),1, fileused_d);

  printf("Bienvenido al menu de facturacion \n");

  printf("Ingrese la ID del producto que desea comprar\n");
  gets(IDseeker);

  


while(!feof(fileused_d)) {
  if(!strcmp(IDseeker, temp_c.prodID)) {
    found = true;
    limpiarbuffer();
    
    printf("Nombre: %s \n", temp_c.nombre);
    printf("Precio individual: %.2f \n", temp_c.priceunit);
    printf("Descripcion: %s \n", temp_c.descripcion); 

    printf("Digite la cantidad que desea extraer \n");
    while (loopexit2 != 1) {
       limpiarbuffer();
      scanfvalidation = scanf("%d",&cantextract);

      if (scanfvalidation == 0) { 
        printf("valor invalido\n");
      } else {
        loopexit2 =1;
      }

    }
    
     limpiarbuffer();
    printf("Seleccione la sucursal donde se realizara el tramite \n ");
   
   while (loopexit1 != 1) {
    limpiarbuffer();
    scanf("%d",&sucursal);
    limpiarbuffer();
    switch (sucursal)
    {
    case 0:
      // printf("central no disponible\n");
      loopexit1 =1;
      break;

    case 1:
      limpiarbuffer();
      if (cantextract == 0) {printf("Cantidad no puede ser igual a 0 \n");}
      if (cantextract < 0) {printf("cantidad invalida\n");}
      if (cantextract > temp_c.sub.cantidad_en_sucursal_1) {
        printf("La cantidad deseada excede las existencias, productos disponibles: %d \n", temp_c.sub.cantidad_en_sucursal_1);
        printf("Digite denuevo: ");
        limpiarbuffer();
      } else {
        result = cantextract*temp_c.priceunit;
        printf("El costo por %d unidades del item %s es de %.2f \n", cantextract, temp_c.prodID, result);
        temp_c.sub.cantidad_en_sucursal_1 = temp_c.sub.cantidad_en_sucursal_1 - cantextract;
        loopexit1 =1;
      }  
      break;

    case 2:
      limpiarbuffer();
      if (cantextract == 0) {printf("Cantidad no puede ser igual a 0 \n");}
      if (cantextract < 0) {printf("cantidad invalida\n");}
      if (cantextract > temp_c.sub.cantidad_en_sucursal_2) {
        printf("La cantidad deseada excede las existencias, productos disponibles: %d \n", temp_c.sub.cantidad_en_sucursal_2);
        printf("Digite denuevo: ");
        limpiarbuffer();
      } else {
        result = cantextract*temp_c.priceunit;
        printf("El costo por %d unidades del item %s es de %.2f \n", cantextract, temp_c.prodID, result);
        temp_c.sub.cantidad_en_sucursal_2 = temp_c.sub.cantidad_en_sucursal_2- cantextract;
        loopexit1 =1;
      }  
      break;

    case 3:
      limpiarbuffer();
      if (cantextract == 0) {printf("Cantidad no puede ser igual a 0 \n");}
      if (cantextract < 0) {printf("cantidad invalida\n");}
      if (cantextract > temp_c.sub.cantidad_en_sucursal_3) {
        printf("La cantidad deseada excede las existencias, productos disponibles: %d \n", temp_c.sub.cantidad_en_sucursal_3);
        printf("Digite denuevo: ");
        limpiarbuffer();
      } else {
        result = cantextract*temp_c.priceunit;
        printf("El costo por %d unidades del item %s es de %.2f \n", cantextract, temp_c.prodID, result);
        temp_c.sub.cantidad_en_sucursal_3 = temp_c.sub.cantidad_en_sucursal_3 - cantextract;
        loopexit1 =1;
      }  
      break;

    case 4:
      limpiarbuffer();
      if (cantextract == 0) {printf("Cantidad no puede ser igual a 0 \n");}
      if (cantextract < 0) {printf("cantidad invalida\n");}
      if (cantextract > temp_c.sub.cantidad_en_sucursal_4) {
        printf("La cantidad deseada excede las existencias, productos disponibles: %d \n", temp_c.sub.cantidad_en_sucursal_4);
        printf("Digite denuevo: ");
        limpiarbuffer();
      } else {
        result = cantextract*temp_c.priceunit;
        printf("El costo por %d unidades del item %s es de %.2f \n", cantextract, temp_c.prodID, result);
        temp_c.sub.cantidad_en_sucursal_4 = temp_c.sub.cantidad_en_sucursal_4 - cantextract;
        loopexit1 =1;
      }  
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

    fwrite(&temp_c, sizeof(struct Productos), 1, temporal);  

   
  
  } else {
    fwrite(&temp_c, sizeof(struct Productos), 1, temporal);
  }
  fread(&temp_c, sizeof(struct Productos ), 1, fileused_d);
 }
  
 fclose(temporal);
 fclose(fileused_d);
 int borrado;
 borrado = remove("Master.txt");
    if(borrado==0)
    {
        rename("temporal.txt", "Master.txt");
    }
  return 0;
}

int comprob(FILE *fileused_0) {
  limpiarbuffer();
  cleanscreen();

  struct Productos temp_0;

  printf("\n comprob \n");

  fileused_0 = fopen("Master.txt","r");
  fread(&temp_0, sizeof(struct Productos),1, fileused_0);
  char IDseeker[10];
  int exit;
  gets(IDseeker);

  while(!feof(fileused_0) && exit != 1) {

  if(!strcmp(IDseeker, temp_0.prodID)) { 
    limpiarbuffer();
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
  fread(&temp_0, sizeof(struct Productos),1, fileused_0);
      
  } 

  fclose(fileused_0);
  return 0;
}

void menudef() { 

   FILE *fileused = NULL;
   int loopexit = 0;

   while (loopexit != 1) {
      cleanscreen();
      limpiarbuffer();
      int opcdef = 0;

      printf("Sus opciones son las siguiente: \n 1. Agregar producto \n 2. Modificar producto \n 3. remover producto \n 4. Facturar/retirar producto \n 5. NULL \n 6. ver prod \n 7. Salir\n");
      scanf("%d",&opcdef);
      limpiarbuffer();
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