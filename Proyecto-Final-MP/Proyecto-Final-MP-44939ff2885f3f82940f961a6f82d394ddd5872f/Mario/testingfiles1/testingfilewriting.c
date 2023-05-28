#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>

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

void limipiarbuffer() {
    fflush(stdin);
    fflush(stdout);
}

 struct product_template get_info() {
    struct product_template input;
      printf("\nIngrese nombre: ");
      scanf("%s",input.nombre);
      limipiarbuffer();

      printf("\nIngrese precio: ");
      scanf("%f",&input.price);
      limipiarbuffer();

      printf("\nIngrese una breve descripcion del producto: ");
      scanf("%s",input.descripcion);
      limipiarbuffer();

    return input;
}

FILE * creaciondeficheros() {
    FILE *fileopen = NULL;
    char nombre[100];
    char txtextention[] = ".txt";
    char datextention[] = ".dat";
    printf("Ingrese nombre del archivo\n");
    gets(nombre);
    strcat(nombre,txtextention);
    printf("\n %s \n",nombre);
    fileopen = fopen(nombre, "w");
     
    if(fileopen==NULL){
        printf("Error, el fichero no ha sido creado! \n");
    }
    else{
        printf("El fichero %s ha sido abierto en modo lectura. \n", nombre);
        printf("\nRegresando al menu principal... \n");
    }
    limipiarbuffer();
    fclose(fileopen);

    return fileopen;
}

FILE * abrirFichero(){
    FILE *fileAtleta = NULL;
    fileAtleta = fopen("filename.txt", "w");
    if(fileAtleta==NULL){
        printf("Error, el fichero no ha sido creado! \n");
    }
    else{
        printf("El fichero ha sido abierto en modo lectura. \n");
        //system("cls");
        printf("\nRegresando al menu principal... \n");
    }
     limipiarbuffer();
    fclose(fileAtleta);

    return fileAtleta;
}

int nuevosproductos(FILE *a) {
    int cant=0;
    int n =0;
    //int *sizeofarray;
    // struct product_template temp;
    char nombre1[100];
    char nombre2[100];
    char txtextention[] = ".txt";
    char datextention[] = ".dat";
    printf("Ingrese nombre del archivo\n");
    gets(nombre1);
    strcpy(nombre2,nombre1);
    strcat(nombre2,txtextention);
    a = fopen(nombre2, "w");
    struct product_template *templist;
    printf("Ingrese # prods \n");
    scanf("%d",&cant);
     limipiarbuffer();

   templist = (struct product_template*) malloc(cant*sizeof(struct product_template) );

   while (n < cant) { 
      templist[n] = get_info();
      n++;
    }
    
    for (int i = 0; i < n; i++) {
        fprintf(a, "Nombre: %s\n", templist[i].nombre);
        fprintf(a, "Precio: %.2f\n", templist[i].price);
        fprintf(a, "Descripcion: %s\n", templist[i].descripcion);
        fprintf(a, "\n");
    }

    if (n > 0) {
        printf("\nLos datos de los productos han sido guardados con éxito!\n");
    } else {
        perror("Error: ");
        return(-1);
    }
    
    
    char txtextention2[] = "_2.txt";
    strcat(nombre1,txtextention2);
    FILE *fileopen2 = NULL;
    fileopen2 = fopen(nombre1,"w");
    int guardado=fwrite(templist, sizeof(struct product_template), n, fileopen2);
    
    if(guardado>0){
            printf("\nLos datos del atleta han sido guardados con exito! \n");
        }
        else{
            printf("\nERROR: intente nuevamente, si el error persiste contacte con el Administrador del Sistema... \n");
        } 

       limipiarbuffer();
       free(templist);
       fclose(a);
    return 0;
}

int main() {

FILE *filepointer = NULL;
filepointer = creaciondeficheros();
nuevosproductos(filepointer);

}