#include <stdio.h>
#include <stdlib.h>
#include "lib/petest.h"

// funcao para mensagem de erro padrao
void fatal(char *msg){
  fprintf(stderr, "Erro: %s\n", msg);
  exit(1);
}

int main(int argc, char *argv[]){

  FILE * fh;

  unsigned char buffer[32];

  if(argc < 2){
    fatal("Informe o nome do arquivo");
  }

  fh = fopen(argv[1], "rb"); //read + bin

  if(fh == NULL ){
    fatal("Nao foi possivel abrir o arquivo");
  }

  if (fread(buffer, 32, 1, fh) != 1){
    fatal("Nao consegui ler os 32 bytes!!"); 
  }
  
  if (!petest_ispe(buffer)){
    fatal("arquivo nao parece ser um PE");
  }

  fclose(fh);

  return 0;
}
