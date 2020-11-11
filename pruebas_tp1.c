#include "testing.h"
#include "strutil.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Prueba EJEMPLO. */
static void prueba_ejemplo(void) {
    printf("INICIO DE PRUEBAS EJEMPLO\n");

    print_test("prueba ejmplo", true);
}
static void prueba_substring_vacio(void) {
    printf("INICIO DE PRUEBAS SUBSTRING VACIO\n");
    char * s = "";
    char * sub_s = substr(s, 2);
    bool ok = strcmp(s,sub_s)==0;
    free(sub_s);
    print_test("substring string vacio ", ok);
}
static void prueba_substring(void) {
    printf("INICIO DE PRUEBAS SUBSTRING \n");
    char * s = "Hola mundo";
    char * sub_s = substr(s, 6);
    bool ok = strcmp("Hola m",sub_s)==0;
    free(sub_s);
    print_test("substring string vacio ", ok);
}
static void prueba_substring_n_grande(void) {
    printf("INICIO DE PRUEBAS SUBSTRING n MAS GRANDE \n");
    char * s = "Algoritmos";
    char * sub_s = substr(s, 30);
    bool ok = strcmp("Algoritmos",sub_s)==0;
    free(sub_s);
    print_test("substring con n mas grande que string ", ok);
}
static void prueba_substring_sumando(void) {
    printf("INICIO DE PRUEBAS SUBSTRING SUMANDO AL STRING \n");
    char * s = "Ejemplo";
    char * sub_s = substr(s + 4, 2);
    bool ok = strcmp("pl",sub_s)==0;
    free(sub_s);
    print_test("Moviendo por string sumando entero ", ok);
}
void pruebas_lista_estudiante() {
    prueba_ejemplo();
    prueba_substring_vacio();
    prueba_substring();
    prueba_substring_n_grande();
    prueba_substring_sumando();
}


/*
 * Función main() que llama a la función de pruebas.
 */

#ifndef CORRECTOR  // Para que no dé conflicto con el main() del corrector.

int main(void) {
    pruebas_lista_estudiante();
    return failure_count() > 0;  // Indica si falló alguna prueba.
}

#endif
