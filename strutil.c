#include "strutil.h"
#include <stdio.h>
#include <stdlib.h>

char *substr(const char *str, size_t n) {
    char *nueva_cadena = malloc(sizeof(char)*(n+1));  // O(1)
    if (!nueva_cadena) return NULL;                   // O(1)
    size_t i = 0;                                     // O(1)
    while (i < n) {
      // printf("Dentro del while\n" );
      nueva_cadena[i] = str[i];
      i++;
    }                                                  // O(n)
    nueva_cadena[i] = '\0';                            // O(1)
    return nueva_cadena;                               // O(1)
}
// int main(int argc, char *argv[]) {
//
//   printf("compila!!!\n");
//   char * palabra = "Hola mundo";
//   printf("palabra es = %s\n", palabra);
//   char * sub_palabra = substr(palabra, 6);
//   printf("la sub palabra es %s\n", sub_palabra);
//   free(sub_palabra);
//
//   const char* ejemplo= "Ejemplo";
//   sub_palabra = substr(ejemplo+4, 2);
//   printf("la sub palabra es %s\n", sub_palabra);
//   free(sub_palabra);
//
//   char * palabra2 = "Algoritmos";
//   sub_palabra = substr(palabra2, 30);
//   printf("la sub palabra es %s\n", sub_palabra);
//   free(sub_palabra);
//   return 0;
// }
