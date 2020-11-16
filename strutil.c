#include "strutil.h"
#include <stdlib.h>
#include <string.h>

char *substr(const char *str, size_t n) {
    char *nueva_cadena = malloc(sizeof(char)*(n+1));  // O(1)
    if (!nueva_cadena) return NULL;                   // O(1)
    size_t i = 0;                                     // O(1)
    while (i < n) {
      nueva_cadena[i] = str[i];
      i++;
    }                                                  // O(n)
    nueva_cadena[i] = '\0';                            // O(1)
    return nueva_cadena;                               // O(1)
}
// char **split(const char *str, char sep) {
char ** split(const char *str, char sep) {
    int string_ini = 0;
    int cantidad_strings = 0;
    int pos = 0;
    int contador_palabras = 0;
    while(str[pos]!='\0') {
      if (str[pos]==sep) {
        cantidad_strings++;
      }
      pos++;
    }     //O(n)

    // creo el array de strings
    cantidad_strings++;
    char ** palabras = malloc(sizeof(char*)*(cantidad_strings+1));
    pos = 0;
    while(str[pos]!='\0') {
      if (str[pos]==sep) {
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
    char *palabra = malloc(sizeof(char)*(pos-string_ini+1));
    memcpy(palabra, str+string_ini, pos-string_ini);
    palabra[pos-string_ini] = '\0';
    palabras[contador_palabras] = palabra;
    contador_palabras++;
    palabras[contador_palabras] = NULL;
    return palabras;
}
char *join(char **strv, char sep) {
  int i = 0;
  int cantidad_letras = 0;
  while (strv[i]!=NULL) {
     cantidad_letras+=strlen(strv[i])+1;
     i++;
  }
  char *palabra = malloc(sizeof(char)*(cantidad_letras));
  i=0;
  int desplazamiento = 0;
  while (strv[i]!=NULL) {
     if ( strlen(strv[i]) == 0) {
       i++;
       continue;
     }

     if ( desplazamiento == 0 ){
       memcpy(palabra+desplazamiento, strv[i], strlen(strv[i]));
       desplazamiento += strlen(strv[i]);
     }else {
       desplazamiento++;
       memcpy(palabra+desplazamiento, strv[i], strlen(strv[i]));
       desplazamiento += strlen(strv[i]);
     }
     palabra[desplazamiento] = sep;

     i++;
  }
  palabra[desplazamiento] = '\0';
  return palabra;

}
void free_strv(char *strv[]) {
    int i = 0;
    while (strv[i]!=NULL) {
        free(strv[i]);
        i++;
    }
    free(strv);
}
