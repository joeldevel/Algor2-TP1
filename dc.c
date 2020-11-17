#include "strutil.h"
#include "calc_helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// recibe un array de string con cada operando de la operacion
void procesar_linea(char*tokens[]) {
  // printf("entrando a procesar_linea\n" );
  int i = 0;
  pilanum_t *pila = pilanum_crear();
  while (tokens[i]!=NULL) {
     struct calc_token token_devuelto;
     char *tok = tokens[i];
     if (calc_parse(tok, &token_devuelto)){
       // printf("se ha parseado con exito!\n");
       switch (token_devuelto.type) {
           case TOK_NUM:
               // printf("Poner en la pila %d\n",token_devuelto.value );
               // printf("sumandole 1 %d\n",token_devuelto.value+1 );
               // if(pila_esta_vacia(pila))
                // printf("La pila esta vacia\n");
               // if (token_devuelto.value <0)
                  // printf("el numero es negativo\n");
               apilar_num(pila, token_devuelto.value);
               // printf("ver tope pila =%lu\n", *(size_t*)pila_ver_tope(pila));
           break;
           case TOK_OPER:
               // printf("es un operador " );
               // printf("token_devuelto.oper=%d\n",token_devuelto.oper );
               switch (token_devuelto.value) {
                   case OP_ADD:;
                      // printf("Sumando +\n");
                      calc_num b = 0;
                      if(desapilar_num(pila, &b)){
                        // printf("");
                      } else {
                        // printf("no se desapila!!!\n");
                        printf("ERROR al desapilar suma\n");
                        break;
                      }

                      calc_num a = 0;
                      if(desapilar_num(pila, &a)) {
                        // printf("");
                      } else {
                        printf("ERROR al desapilar suma\n");
                        break;
                      }
                      // printf("b=%p\n",b );
                      // printf("b=%lu\n", b);
                      apilar_num(pila, a+b);
                      // printf("Se apila =%d\n", (long int)a+(long int)b);
                      // printf("ver tope pila =%lu\n", *(size_t*)pila_ver_tope(pila));

                      break;
                   case OP_SUB:
                       // printf("restando -\n");
                       b = 0;
                       if(desapilar_num(pila, &b)){
                         // printf("Desapilando\n");
                       } else {printf("no se desapila!!!\n");}

                       a = 0;
                       if(desapilar_num(pila, &a))
                       // printf("Desapilando\n");
                       apilar_num(pila, a-b);
                       // printf("ver tope pila =%lu\n", *(size_t*)pila_ver_tope(pila));
                       break;
                   case OP_MUL:
                       // printf("Multiplicando\n");
                       b = 0;
                       if(desapilar_num(pila, &b)){
                         // printf("Desapilando\n");
                       } else {printf("no se desapila!!!\n");}

                       a = 0;
                       if(desapilar_num(pila, &a))
                       // printf("Desapilando\n");
                       apilar_num(pila, a*b);
                       // printf("ver tope pila =%lu\n", *(size_t*)pila_ver_tope(pila));
                       break;
                   case OP_DIV:
                       // printf("dividiendo\n");
                       b = 0;
                       if(desapilar_num(pila, &b)){
                         // printf("Desapilando\n");
                       } else {printf("no se desapila!!!\n");}

                       a = 0;
                       if (desapilar_num(pila, &a))
                       // printf("Desapilando\n");
                       if (b==0) {
                          printf("ERROR división por cero!!!\n");
                          break;
                        }
                       apilar_num(pila, a/b);
                       // printf("ver tope pila =%lu\n", *(size_t*)pila_ver_tope(pila));
                       break;
                      // printf("Division por cero /\n");
                      // break;
                   case OP_POW:
                       // printf("potencia\n");
                       b = 0;
                       if(desapilar_num(pila, &b)){
                         // printf("Desapilando\n");
                       } else {printf("no se desapila!!!\n");}

                       a = 0;
                       if (desapilar_num(pila, &a))
                        // printf("Desapilando\n");
                       if (b<0) {
                          printf("ERROR potencia negativa!!!\n");
                          break;
                        }
                       apilar_num(pila, (long long)pow((double)a,(double)b));
                       // printf("ver tope pila =%lu\n", *(size_t*)pila_ver_tope(pila));
                       break;
                   case OP_LOG:
                       printf("Longarismo\n");
                       // base
                       b = 0;
                       if(desapilar_num(pila, &b)){
                         // printf("Desapilando\n");
                       } else {printf("no se desapila!!!\n");}
                       // numero a aplicar
                       a = 0;
                       if (desapilar_num(pila, &a))
                        // printf("Desapilando\n");
                       if (b<2) {
                          printf("ERROR base menor a 2 !!!\n");
                          break;
                        }
                       apilar_num(pila, (long long)floor((log((double)a)/log((double)b))) );
                       // printf("ver tope pila =%lu\n", *(size_t*)pila_ver_tope(pila));
                       break;

                   case OP_RAIZ:
                       // printf("raiz cuadrada\n");
                       // necesito 1 solo operando
                       a = 0;
                       if (desapilar_num(pila, &a))
                        // printf("Desapilando\n");
                       if (a<0) {
                          printf("ERROR raiz negativa!!!\n");
                          break;
                        }
                       apilar_num(pila, (long long)floor(sqrt((double)a)));
                       // printf("ver tope pila =%lu\n", *(size_t*)pila_ver_tope(pila));
                       break;
                   case OP_TERN:
                   // printf("op ternario\n");
                      // op3
                      a = 0;
                      if(desapilar_num(pila, &a)){
                        // printf("Desapilando\n");
                      } else {printf("no se desapila!!!\n");}
                      // op2
                      b = 0;
                      if (desapilar_num(pila, &b)) {
                        // printf("Desapilando\n");
                        }
                      calc_num c = 0;
                      if (!desapilar_num(pila, &c)) {
                         printf("ERROR falta un operando !!!\n");
                         break;
                       }
                      // printf("a=%lu, b=%ld, c=%lu\n",a,b,c );
                      apilar_num(pila, (c?b:a));
                      // printf("ver tope pila =%ld\n", *(size_t*)pila_ver_tope(pila));
                      break;

                    // printf("recibe tres operandos?\n"); break;
               } break;
           case TOK_LPAREN: printf("es parentesis izquierdo (\n" );break;
           case TOK_RPAREN: printf("es parentesis derecho )\n" );break;
           default: printf("ERROR, no es un token valido\n");
       }
     }
     i++;
  }
  if (!pila_esta_vacia(pila)) {
    void * t = pila_desapilar(pila);
    printf("%ld\n", *(size_t*)t);
    free(t);
  }
  else {
    printf("ERROR pila vacia\n");
  }

  pilanum_destruir(pila);
}

int main(int argc, char *argv[]) {
  char line[BUFSIZ];
	char **operandos;

	while(fgets(line,BUFSIZ,stdin) != NULL){
    operandos = dc_split(line);
    procesar_linea(operandos);
    free_strv(operandos);
	}
  return 0;
}
