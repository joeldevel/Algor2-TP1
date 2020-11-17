#include "strutil.h"
#include "calc_helper.h"
#include <stdio.h>
#include <stdlib.h>
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
