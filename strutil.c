#include "strutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
// char **split(const char *str, char sep) {
char ** split_(const char *str, char sep) {
    int string_ini = 0;
    int cantidad_strings = 0;
    int pos = 0;
    int contador_palabras = 0;
    // while (str[pos]!='\0') {
    //     if (str[pos]==sep) {
    //         cantidad_strings++;
    //         // printf("%c en pos %d\n", str[pos], pos);
    //     } else {
    //
    //     }
    //     pos++;
    // }
    // para saber cuantos elementos tiene el array de strings
    while(str[pos]!='\0') {
      if (str[pos]==sep) {
        cantidad_strings++;
      }
      // printf("en el while\n");
      pos++;
    }     //O(n)

    // creo el array de strings
    cantidad_strings++;
    char ** palabras = malloc(sizeof(char*)*(cantidad_strings+1));
    pos = 0;
    while(str[pos]!='\0') {
      if (str[pos]==sep) {
        printf("inicio=%d, fin=%d\n",string_ini, pos);
        char *palabra = malloc(sizeof(char)*(pos-string_ini+1));
        memcpy(palabra, str+string_ini, pos-string_ini);
        palabra[pos-string_ini] = '\0';
        palabras[contador_palabras] = palabra;
        contador_palabras++;
        string_ini=pos+1;
      }
      pos++;
    }    //O(n)
    //copiar la ultima palabra
    // printf("inicio=%d, fin=%d\n",string_ini, pos);

    char *palabra = malloc(sizeof(char)*(pos-string_ini+1));
    memcpy(palabra, str+string_ini, pos-string_ini);
    palabra[pos-string_ini] = '\0';
    palabras[contador_palabras] = palabra;
    contador_palabras++;
    palabras[contador_palabras] = NULL;



    // char *palabra = malloc(sizeof(char)*(pos+1));
    // memcpy(palabra, str, pos);
    // palabra[pos] = '\0';
    // printf("nueva palabra=%s\n",palabra);
    // free(palabra);
    printf("cantidad de nuevos strings = %d\n", cantidad_strings);
    printf("tam palabras=%d\n", sizeof(palabras));
    printf("tam char*=%d\n", sizeof(char*));
    printf("strlen(str)=%d\n", strlen(str));
    // printf("tam char=%d\n", sizeof(char));
    return palabras;
}
int main(int argc, char* argv[]) {
    printf("compila\n");
    // char ** palabras = split_("pirulo, pirulas, chingolo, monchito", ',');
    // Casos borde propuestos
    // char ** palabras = split_("abc,,def", ',');
    // char ** palabras = split_("abc,def,", ',');
    // char ** palabras = split_(",abc,def", ',');
    // char ** palabras = split_("abc", '\0');
    // char ** palabras = split_("", ',');
    char ** palabras = split_(",", ',');


    // split_("", ',');
    // char * palabra_original = "potirolis";
    // char * palabra_copiada = strdup(palabra_original);
    // printf("palabra original= %p, palabra_copiada=%p\n", palabra_original, palabra_copiada);
    // printf("palabra_original=%s, palabra_copiada=%s\n", palabra_original, palabra_copiada);
    // free(palabra_copiada);
    int i = 0;
    while (palabras[i]!=NULL) {
       printf("palabras[%d] = %s\n", i,palabras[i]);
       i++;
    }
    i = 0;
    while (palabras[i]!=NULL) {
       // printf("palabras[i] = %s\n", palabras[i]);
        free(palabras[i]);
       i++;
    }
    // borrar la ultima?
    // free(palabras[i]);
    free(palabras);
    return 0;
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
