#include "testing.h"
#include "strutil.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "calc_helper.h"

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
// split
static void prueba_split(void) {
    printf("INICIO DE PRUEBAS SPLIT \n");
    // split("abc,,def", ',')
    char *linea = "abc,,def";
    char *str1 = "abc";
    char *str2 = "def";
    char sep = ',';
    bool ok = true;
    char ** array_strings = split(linea, sep);

    ok &= strcmp(array_strings[0],str1)==0;
    print_test("Crea string 0 ", ok);
    ok &= strlen(array_strings[1])==0;
    print_test("Crea string 1", ok);
    ok &= strcmp(array_strings[2],str2)==0;
    print_test("Crea string 2 ", ok);
    free_strv(array_strings);
}
static void prueba_split_strings_vacios(void) {
    printf("INICIO DE PRUEBAS SPLIT STRINGs VACIOs\n");
    char *linea1 = "";
    char *linea2 = ",";
    char sep = ',';
    int cant_elem1 = 1;
    int cant_elem2 = 2;
    bool ok = true;
    char ** array_strings = split(linea1, sep);

    ok &= strlen(array_strings[0])==0;
    print_test("Crea string vacio", ok);
    int i = 0;
    while (array_strings[i]!=NULL) {
      i++;
    }
    ok &= i == cant_elem1;
    print_test("El array1 tien3 la cantidad correcta",ok );

    free_strv(array_strings);
    array_strings = split(linea2, sep);
    ok &= strlen(array_strings[0])==0;
    ok &= strlen(array_strings[1])==0;
    print_test("Crea strings vacios", ok);
    i = 0;
    while (array_strings[i]!=NULL) {
      i++;
    }
    ok &= i == cant_elem2;
    print_test("El array2 tiene la cantidad correcta",ok );
    free_strv(array_strings);
}
static void prueba_split_casos_borde(void) {
    printf("INICIO DE PRUEBAS SPLIT CASOS BORDE\n");
    char *linea1 = "abc,def,";
    char *linea2 = ",abc,def";
    char *str1 = "abc";
    char *str2 = "def";
    char sep = ',';
    int cant_elem1 = 3;
    int cant_elem2 = 3;
    bool ok = true;
    char ** array_strings = split(linea1, sep);


    ok &= strcmp(array_strings[0],str1) ==0;
    print_test("Crea string", ok);
    ok &= strcmp(array_strings[1],str2) ==0;
    print_test("Crea string", ok);
    ok &= strlen(array_strings[2])==0;
    print_test("Crea string vacio", ok);

    int i = 0;
    while (array_strings[i]!=NULL) {
      i++;
    }
    ok &= i == cant_elem1;
    print_test("El array1 tiene la cantidad correcta",ok );
    free_strv(array_strings);

    array_strings = split(linea2, sep);
    ok &= strlen(array_strings[0])==0;
    print_test("Crea string vacio", ok);
    ok &= strcmp(array_strings[1],str1) ==0;
    print_test("Crea string", ok);
    ok &= strcmp(array_strings[2],str2) ==0;
    print_test("Crea string", ok);

    i = 0;
    while (array_strings[i]!=NULL) {
      i++;
    }
    ok &= i == cant_elem2;
    print_test("El array3 tiene la cantidad correcta",ok );
    free_strv(array_strings);
}
static void prueba_split_sep_fin_linea(void) {
    printf("INICIO DE PRUEBAS SPLIT SEPARADOR FIN LINEA\n");
    char *linea = "abc";
    char *str1 = "abc";
    char sep = '\0';
    int cant_elem = 1;
    bool ok = true;
    char ** array_strings = split(linea, sep);

    ok &= strcmp(array_strings[0],str1) ==0;
    print_test("Crea string", ok);
    int i = 0;
    while (array_strings[i]!=NULL) {
      i++;
    }
    ok &= i == cant_elem;
    print_test("El array tiene la cantidad correcta",ok );

    free_strv(array_strings);
}
// join
static void
void pruebas_lista_estudiante() {
    prueba_ejemplo();
    prueba_substring_vacio();
    prueba_substring();
    prueba_substring_n_grande();
    prueba_substring_sumando();
    // split
    prueba_split();
    prueba_split_strings_vacios();
    prueba_split_sep_fin_linea();
    prueba_split_casos_borde();
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
