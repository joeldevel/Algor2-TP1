#include <stdio.h>
#include "strutil.h"
#include "calc_helper.h"


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
int main(int argc, char *argv[]) {
  printf("dc compila!\n");
  // for( int i = 0; i < argc; i++) {
  //   printf("argv[%i]= %s\n",i,argv[i] );
  // }
  // leer de un archivo
  int ch = 0;
  char *file_name = "ej.txt";
  FILE* fh=fopen("ej.txt", "r");
  int operandos[2] = {0,0};
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

  char **palabras = dc_split("123 9 + sqrt     log * ^ ( )");
  analizar_tokens(palabras);
  free_strv(palabras);
  fclose(fh);
  return 0;
}
