#include "strutil.h"
#include "calc_helper.h"
#include "pila.h"
#include "cola.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void analizar_tokens(cola_t* cola, pila_t *pila, char*tokens[]) {
  // necesito una pila de operadores y una cola de numeros
  printf("entrando a analizar\n" );
  int i = 0;
  struct calc_token token_devuelto;
  while (tokens[i]!=NULL) {
     // printf("tokens[%d] = %s\n", i,tokens[i]);
     char *tok = tokens[i];
     if (calc_parse(tok, &token_devuelto)){
       // printf("se ha parseado con exito!\n");
       switch (token_devuelto.type) {
         case TOK_NUM:
         // printf("es un numero %d\n",token_devuelto.value );
         cola_encolar(cola, (void*)token_devuelto.value);
         break;
         case TOK_OPER:;
            // if (pila_esta_vacia(pila)) {
            printf("token devuelto.type =%d\n", token_devuelto.type);
            printf("token devuelto.oper.op =%d\n", token_devuelto.oper.op);
            printf("token devuelto.oper.precedencia =%d\n", token_devuelto.oper.precedencia);
            struct calc_token * t = malloc(sizeof(struct calc_token));
            t->type = token_devuelto.type;
            t->oper.op = token_devuelto.oper.op;
            t->oper.precedencia = token_devuelto.oper.precedencia;
            printf("t->type =%d\n", t->type);
            printf("t->oper.op =%d\n", t->oper.op);
            printf("t->oper.precedencia =%d\n----\n", t->oper.precedencia);
            pila_apilar(pila,t);
            //     // pila_apilar(pila,"+");
            // }
            // else {
            // if( !pila_esta_vacia(pila) ) {
              // while( (token_devuelto.oper.precedencia<= (*(struct calc_token *)pila_ver_tope(pila)).oper.precedencia))  {
                 // cola_encolar(cola, pila_desapilar(pila));
              // }
            // }
              // pila_apilar(pila, &(token_devuelto.value));
            // }
            // printf("precedencia %d \n",token_devuelto.oper.precedencia);
            // printf("es un operador " );
            break;
         case TOK_LPAREN:
         printf("precedencia %d \n",token_devuelto.oper.precedencia);

            // pila[tope_pila] = '(';
            // pila_apilar(pila, &(token_devuelto.type));
            // printf("es parentesis izquierdo (\n" );
            break;
         case TOK_RPAREN:
         // if (pila_esta_vacia(pila)) printf("ERROR BALANCEO rparen\n");
         //    while(((*(struct calc_token *)pila_ver_tope(pila)).type!=TOK_LPAREN) &&!pila_esta_vacia(pila)) {
         //      cola_encolar(cola, pila_desapilar(pila));
         //    }
         //    if (!pila_esta_vacia(pila))
         //      pila_desapilar(pila); // y desechar el token;
         //    printf("es parentesis derecho )\n" );
         break;
       }
     }
     i++;
  }
  // while (!pila_esta_vacia(pila)) {
  //   if ((*(struct calc_token *)pila_ver_tope(pila)).type==TOK_RPAREN) printf("ERROR BALANCEO fin tokens\n");
  //   cola_encolar(cola, pila_desapilar(pila));
  // }
  // printf("**************SALIDA**********\n");

}
void shunting() {

}
int main(int argc, char*argv[]) {
  printf("compila!!!!\n");
  // char * tokens[]= {"3","6","4","112","+","(","-","*","^","/",NULL};
  char * tokens[]= {"3","6","4","112","+","-","*","/","^",NULL};
   cola_t *cola = cola_crear();
   pila_t *pila = pila_crear();

  analizar_tokens(cola,pila,tokens);

  // free_strv(tokens);
  // cola_t * c = cola_crear();
  // int datos[] = { 1, 2, 3};
  // cola_encolar(c,&datos[0]);
  // cola_encolar(c,&datos[1]);
  // cola_encolar(c,&datos[2]);
  // while ( !cola_esta_vacia(c)) {
  //   printf("%d \n",*(int*)cola_desencolar(c) );
  // }
  // printf("\n");
  // int i = 0;
  // while ( tokens[i]) {
  //   printf("%s ",tokens[i] );
  //   i++;
  // }
  // printf("\n");
  if (!cola_esta_vacia(cola))
    printf("NO esta vacia\n");
  while(!cola_esta_vacia(cola)) {
    // printf("%d ", *(int*)cola_ver_primero(cola));
    printf("%d ", (int*)cola_desencolar(cola)  );
    // (struct calc_token*)
  }
  // printf("\n");
  // char * operador = " ";
  // if ( pila_desapilar(pila) == OP_ADD) {
  //   operador = "+";
  // }
  // struct calc_token * p = (struct calc_token *) pila_desapilar(pila);
  struct calc_token * p = NULL;
  // printf("el calc_token esta es =%p\n", p);
  // printf("el calc_token->type  es =%d\n", p->type);
  while(!pila_esta_vacia(pila)) {
    // printf("hay algo\n ");
    // free(pila_desapilar(pila));
    p = pila_desapilar(pila);
    switch (p->oper.op) {
      case OP_ADD: printf("+ ");break;
      case OP_SUB: printf("- ");break;
      case OP_MUL: printf("* ");break;
      case OP_DIV: printf("/ ");break;
      case OP_POW: printf("^ ");break;
    }
    free(p);
  }
  // free(p);
  // printf("%s ", operador  );

  printf("\n");
  cola_destruir(cola, NULL);
  pila_destruir(pila);
  return 0;
}
