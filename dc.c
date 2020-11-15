#include <stdio.h>
#include "calc_helper.h"

#include "strutil.h"

#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static bool parse_num(const char *tok, calc_num *dest) {
    char *end;
    *dest = strtol(tok, &end, 10);
    return *end == '\0';
}
bool calc_parse(const char *tok, struct calc_token *parsed) {
    if (parse_num(tok, &parsed->value)) {
        parsed->type = TOK_NUM;
        return true;
    }
    else {
        parsed->type = TOK_OPER;
    }

    if (strlen(tok) == 1) {
        char op = tok[0];
        if (op == '+') {
            parsed->oper.op = OP_ADD;
        }
        else if (op == '-') {
            parsed->oper.op = OP_SUB;
        }
        else if (op == '*') {
            parsed->oper.op = OP_MUL;
        }
        else if (op == '/') {
            parsed->oper.op = OP_DIV;
        }
        else if (op == '^') {
            parsed->oper.op = OP_POW;
        }
        else if (op == '?') {
            parsed->oper.op = OP_TERN;
        }
        else if (op == '(') {
            parsed->type = TOK_LPAREN;
        }
        else if (op == ')') {
            parsed->type = TOK_RPAREN;
        }
        else {
            return false;
        }
    }
    else if (strcmp(tok, "log") == 0) {
        parsed->oper.op = OP_LOG;
    }
    else if (strcmp(tok, "sqrt") == 0) {
        parsed->oper.op = OP_RAIZ;
    }
    else {
        return false;
    }

    return true;
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
  int i = 0;
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
  char *tok = "234";
  struct calc_token token_devuelto;
  if (calc_parse(tok, &token_devuelto)){
    printf("se ha parseado con exito!\n");
    switch (token_devuelto.type) {
      case TOK_NUM:
        printf("es un numero %d\n",token_devuelto.value );
        break;
      case TOK_OPER:
        printf("es un operador\n" );
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
      case TOK_LPAREN: printf("es parentesis izquierdo\n" );break;
      case TOK_RPAREN: printf("es parentesis derecho\n" );break;
    }
    // printf("token_devuelto.type=%d\n",token_devuelto.type );
    // printf("token_devuelto.value=%d\n",token_devuelto.value );
    // printf("token_devuelto.oper=%d\n",token_devuelto.oper );
  }
  fclose(fh);
  return 0;
}
