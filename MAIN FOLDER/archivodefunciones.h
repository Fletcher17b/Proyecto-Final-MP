#pragma once

void limpiarbuffer() {
    fflush(stdin);
    fflush(stdout);
}

void cleanscreen() {
    system("pause");
    system("cls");
}

void saltoLinea() {
   printf("\n");
}


