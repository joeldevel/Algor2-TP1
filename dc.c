#include "strutil.h"
#include "calc_helper.h"
#include <stdio.h>
#include <math.h>


void analizar_tokens(char*tokens[]) {
  printf("entrando a analizar\n" );
  int i = 0;
  while (tokens[i]!=NULL) {
     // printf("tokens[%d] = %s\n", i,tokens[i]);
     struct calc_token token_devuelto;
     char *tok = tokens[i];
     if (calc_parse(tok, &token_devuelto)){
       // printf("se ha parseado con exito!\n");
       switch (token_devuelto.type) {
         case TOK_NUM:
         printf("es un numero %d\n",token_devuelto.value );
         break;
         case TOK_OPER:
         printf("es un operador " );
         // printf("token_devuelto.oper=%d\n",token_devuelto.oper );
         switch (token_devuelto.value) {
           case OP_ADD: printf("+\n"); break;
           case OP_SUB: printf("+\n"); break;
           case OP_MUL: printf("*\n"); break;
           case OP_DIV: printf("/\n"); break;
           case OP_POW: printf("^\n"); break;
           case OP_LOG: printf("log\n"); break;
           case OP_RAIZ: printf("sqrt\n"); break;
           case OP_TERN: printf("?\n"); break;
         }
         break;
         case TOK_LPAREN: printf("es parentesis izquierdo (\n" );break;
         case TOK_RPAREN: printf("es parentesis derecho )\n" );break;
       }
     }
     i++;
  }
}
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
                        printf("");
                      } else {
                        // printf("no se desapila!!!\n");
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
                      // printf("b=%p\n",b );
                      // printf("b=%lu\n", b);
                      apilar_num(pila, (long int)a+(long int)b);
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
                       apilar_num(pila, (long int)a-(long int)b);
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
                       apilar_num(pila, (long int)a*(long int)b);
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
                       apilar_num(pila, (long int)a/(long int)b);
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
                       apilar_num(pila, (long int)pow(a,b));
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
                       apilar_num(pila, (long int)(log(a)/log(b)));
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
                       apilar_num(pila, (long int)sqrt(a));
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
                      apilar_num(pila, (long int)(c?b:a));
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
    printf("%ld\n", *(size_t*)pila_ver_tope(pila));
    // printf("ERROR pila vacia\n");
  }
  // else {
  // }

  pilanum_destruir(pila);
}
int main(int argc, char *argv[]) {
  // printf("dc compila!\n");
  // pilanum_t *pila = pilanum_crear();
  // apilar_num(pila,3456);
  // pilanum_destruir(pila);
  // for( int i = 0; i < argc; i++) {
  //   printf("argv[%i]= %s\n",i,argv[i] );
  // }
  // leer de un archivo
  int ch = 0;
  char *file_name = "ej.txt";
  FILE* fh=fopen("ej.txt", "r");
  if (!fh) {
    printf("ERROR al abrir el archivo\n"); return 1;
  }
  else {
    char line[256];
    char **palabras = NULL;
    while (fgets(line, sizeof(line), stdin)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        // printf("%s", line);
        palabras = dc_split(line);
        // analizar_tokens(palabras);
        procesar_linea(palabras);
        free_strv(palabras);
    }
  }
  // int operandos[2] = {0,0};
  // int i = 0;
  // mientras no fin de archivo
  // while ((ch = fgetc(fh)) != EOF) {
  //   // mientras no fin de linea
  //   while(ch != '\n') {
  //     // si char no es operando ni operacion, seguir
  //     if (ch == ' ') {
  //       ch = fgetc(fh); printf(" espacio\n");
  //       continue;
  //     }
  //     if (ch == '*' || ch == '+' || ch == '-' || ch == '/') {
  //       putchar(ch);
  //       printf(" es operador\n");
  //     }
  //     else {
  //       putchar(ch);
  //       operandos[i] = (int)ch - 48;
  //       i++;
  //       printf(" Es operando\n");
  //     }
  //     ch = fgetc(fh);
  //   }
  //   if (ch == '\n') printf("\n");
  //   // else
  //     // printf("%c",(char)ch);
  //   // }
  // }
  // printf("operandos[0]=%d\n", operandos[0]);
  // printf("operandos[1]=%d\n", operandos[1]);

  // char **palabras = dc_split("123 9 + sqrt     log * ^ ( )");
  // analizar_tokens(palabras);
  // free_strv(palabras);
  fclose(fh);
  return 0;
}
