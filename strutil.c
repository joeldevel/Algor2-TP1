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
char ** split(const char *str, char sep) {
    size_t string_ini = 0;
    size_t cantidad_strings = 0;
    size_t pos = 0;
    size_t contador_palabras = 0;
    // while (str[pos]!='\0') {
    //     if (str[pos]==sep) {
    //         cantidad_strings++;
            // printf("%c en pos %d\n", str[pos], pos);
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
        // printf("inicio=%d, fin=%d\n",string_ini, pos);
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
    // printf("cantidad de nuevos strings = %d\n", cantidad_strings);
    // printf("tam palabras=%d\n", sizeof(palabras));
    // printf("tam char*=%d\n", sizeof(char*));
    // printf("strlen(str)=%d\n", strlen(str));
    // printf("tam char=%d\n", sizeof(char));
    return palabras;
}
// char *join(char **strv, char sep);
char *join(char **strv, char sep) {
  size_t i = 0;
  if (strv[i]==NULL) {
    char *palabra = malloc(sizeof(char)*2);
    palabra = "";
    return palabra;
    // return NULL;
  }
  size_t cantidad_letras = 0;
  while (strv[i]!=NULL) {
     printf("palabras[%ld] = %s\n", i, strv[i]);
     cantidad_letras+=strlen(strv[i])+1;
     i++;
  }
  // printf("cantidad de letras = %d\n", cantidad_letras );
  char *palabra = malloc(sizeof(char)*(cantidad_letras));
  i=0;
  size_t desplazamiento = 0;
  while (strv[i]!=NULL) {
     // printf("palabras[%d] = %s\n", i,strv[i]);
     if ( strlen(strv[i]) == 0) {
       // printf("antes del continue\n");
       i++;
       continue;
     }

     if ( desplazamiento == 0 ){
       // printf("strlen(strv[%d])=%d, \n",i, strlen(strv[i]));
       memcpy(palabra+desplazamiento, strv[i], strlen(strv[i]));
       desplazamiento += strlen(strv[i]);
     }else {
       desplazamiento++;
       // printf("strlen(strv[%d])=%d, \n",i, strlen(strv[i]));
       memcpy(palabra+desplazamiento, strv[i], strlen(strv[i]));
       desplazamiento += strlen(strv[i]);
     }
     // desplazamiento++;
     // memcpy(palabra+desplazamiento+1, &sep, 1);
     // printf("desplazamiento=%d\n", desplazamiento);
     printf("sep=%c\n", sep);
     // palabra = sep;
     // strcpy(palabra[desplazamiento],'#');
     if (sep!=0) {
       printf("sep no es 0\n");
       palabra[desplazamiento] = sep;
     } else {
       // palabra[desplazamiento]=' ';
       // desplazamiento++;
       // i++;
       // continue;
       // printf("sep es 0\n");
     }
     // printf("strlen(strv[i])=%d, \n", strlen(strv[i]));
     // printf("palabra[1]=%p, \n", palabra[1]);
     // printf("palabra=%p, palabra[desplazamiento]=%p\n", palabra,&palabra[desplazamiento]);
     // printf("palabra[desplazamiento]=%c\n", palabra[desplazamiento-1]);
     // printf("palabra[desplazamiento]=%c\n", palabra[desplazamiento]);
     // cantidad_letras+=strlen(strv[i])+1;
     i++;
  }
  palabra[desplazamiento] = '\0';
  return palabra;

  // pedir memoria
}
void free_strv(char *strv[]) {
    size_t i = 0;
    while (strv[i]!=NULL) {
        free(strv[i]);
        i++;
    }
    free(strv);
}
// int main(int argc, char* argv[]) {
    // printf("compila\n");
//     char ** palabras = split_("pirulo, pirulas, chingolo, monchito", ',');
//     // char ** palabras = split_("abc,def,ghi,jk", ',');
//     // Casos borde propuestos
//     // char ** palabras = split_("abc,,def", ',');
//     // char ** palabras = split_("abc,def,", ',');
//     // char ** palabras = split_(",abc,def", ',');
//     // char ** palabras = split_("abc", '\0');
//     // char ** palabras = split_("", ',');
//     // char ** palabras = split_(",", ',');
//
//
//     // split_("", ',');
//     // char * palabra_original = "potirolis";
//     // char * palabra_copiada = strdup(palabra_original);
    // printf("palabra original= %p, palabra_copiada=%p\n", palabra_original, palabra_copiada);
    // printf("palabra_original=%s, palabra_copiada=%s\n", palabra_original, palabra_copiada);
//     // free(palabra_copiada);
//     int i = 0;
//     // while (palabras[i]!=NULL) {
    //    printf("palabras[%d] = %s\n", i,palabras[i]);
//     //    i++;
//     // }
//     // i = 0;
//     char *p = join_(palabras, ',');
//     // p[0]='X';
    // printf("la palabra es =%s\n",p );
//     // while (palabras[i]!=NULL) {
    //    // printf("palabras[i] = %s\n", palabras[i]);
//     //     free(palabras[i]);
//     //    i++;
//     // }
//     // borrar la ultima?
//     // free(palabras[i]);
//     free(p);
//     // free(palabras);
//     free_strv(palabras);
//     return 0;
// }
// int main(int argc, char *argv[]) {
//
  // printf("compila!!!\n");
//   char * palabra = "Hola mundo";
  // printf("palabra es = %s\n", palabra);
//   char * sub_palabra = substr(palabra, 6);
  // printf("la sub palabra es %s\n", sub_palabra);
//   free(sub_palabra);
//
//   const char* ejemplo= "Ejemplo";
//   sub_palabra = substr(ejemplo+4, 2);
  // printf("la sub palabra es %s\n", sub_palabra);
//   free(sub_palabra);
//
//   char * palabra2 = "Algoritmos";
//   sub_palabra = substr(palabra2, 30);
  // printf("la sub palabra es %s\n", sub_palabra);
//   free(sub_palabra);
//   return 0;
// }
