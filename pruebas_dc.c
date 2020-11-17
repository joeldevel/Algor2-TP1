include "testing.h"
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
static void prueba_dc_suma(void) {
    
}
void pruebas_lista_estudiante() {
    prueba_ejemplo();
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
