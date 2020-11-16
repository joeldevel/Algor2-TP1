#include "strutil.h"
#include "calc_helper.h"
#include <stdio.h>
#include <math.h>

void procesar_linea(char*tokens[]) {
  int i = 0;
  pilanum_t *pila = pilanum_crear();
  while (tokens[i]!=NULL) {
     struct calc_token token_devuelto;
     char *tok = tokens[i];
     if (calc_parse(tok, &token_devuelto)){
       switch (token_devuelto.type) {
           case TOK_NUM:
               apilar_num(pila, token_devuelto.value);
           break;
           case TOK_OPER:

               switch (token_devuelto.value) {
                   case OP_ADD:;
                      calc_num b = 0;
                      if(desapilar_num(pila, &b)){
                        printf("");
                      } else {
                        printf("ERROR al desapilar suma\n");
                        break;
                      }

                      calc_num a = 0;
                      if(desapilar_num(pila, &a)) {
                        printf("");
                      } else {
                        printf("ERROR al desapilar suma\n");
                        break;
                      }
                      apilar_num(pila, (long int)a+(long int)b);
                      break;
                   case OP_SUB:
                       b = 0;
                       if(desapilar_num(pila, &b)){
                       } else {printf("no se desapila!!!\n");}

                       a = 0;
                       if(desapilar_num(pila, &a))
                       apilar_num(pila, (long int)a-(long int)b);
                       break;
                   case OP_MUL:
                       b = 0;
                       if(desapilar_num(pila, &b)){
                       } else {printf("no se desapila!!!\n");}

                       a = 0;
                       if(desapilar_num(pila, &a))
                       apilar_num(pila, (long int)a*(long int)b);
                       break;
                   case OP_DIV:
                       b = 0;
                       if(desapilar_num(pila, &b)){
                       } else {printf("no se desapila!!!\n");}

                       a = 0;
                       if (desapilar_num(pila, &a))
                       if (b==0) {
                          printf("ERROR división por cero!!!\n");
                          break;
                        }
                       apilar_num(pila, (long int)a/(long int)b);
                       break;
                   case OP_POW:
                       b = 0;
                       if(desapilar_num(pila, &b)){
                       } else {printf("no se desapila!!!\n");}

                       a = 0;
                       if (desapilar_num(pila, &a))
                       if (b<0) {
                          printf("ERROR potencia negativa!!!\n");
                          break;
                        }
                       apilar_num(pila, (long int)pow(a,b));
                       break;
                   case OP_LOG:
                       printf("Longarismo\n");
                       b = 0;
                       if(desapilar_num(pila, &b)){
                       } else {printf("no se desapila!!!\n");}
                       a = 0;
                       if (desapilar_num(pila, &a))
                       if (b<2) {
                          printf("ERROR base menor a 2 !!!\n");
                          break;
                        }
                       apilar_num(pila, (long int)(log(a)/log(b)));
                       break;
                   case OP_RAIZ:
                       a = 0;
                       if (desapilar_num(pila, &a))
                       if (a<0) {
                          printf("ERROR raiz negativa!!!\n");
                          break;
                        }
                       apilar_num(pila, (long int)sqrt(a));
                       break;
                   case OP_TERN:
                      a = 0;
                      if(desapilar_num(pila, &a)){
                      } else {printf("no se desapila!!!\n");}
                      b = 0;
                      if (desapilar_num(pila, &b)) {
                        }
                      calc_num c = 0;
                      if (!desapilar_num(pila, &c)) {
                         printf("ERROR falta un operando !!!\n");
                         break;
                       }
                      apilar_num(pila, (long int)(c?b:a));
                      break;
               } break;
           case TOK_LPAREN: printf("es parentesis izquierdo (\n" );break;
           case TOK_RPAREN: printf("es parentesis derecho )\n" );break;
           default: printf("ERROR, no es un token valido\n");
       }
     }
     i++;
  }
  if (!pila_esta_vacia(pila)) {
    printf("%ld\n", *(size_t*)pila_ver_tope(pila));
  }

  pilanum_destruir(pila);
}
int main(int argc, char *argv[]) {
    char line[256];
    char **palabras = NULL;
    while (fgets(line, sizeof(line), stdin)) {
        palabras = dc_split(line);
        procesar_linea(palabras);
        free_strv(palabras);
    }
  return 0;
}
