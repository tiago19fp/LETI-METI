#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <assert.h>
#include <string.h>

typedef struct Pessoa{
  char nome[128];
  int idade;

}pessoa;

int procura(int f, char* nome){
  struct Pessoa p;
  int n;
  lseek(0, &f, SEEK_SET);
  while((n == read(f, &p, sizeof(p))) == sizeof(p) && strcmp(p.nome, nome)) != 0){
    return n <= 0  ? -1 : p.idade; // retorna idade caso contrario -1
  }
}

int main(int argc, char* argv[]){

  struct Pessoa pessoa1;
  //struct Pessoa pessoa2;

  int d = open("pessoas.db", O_CREAT | O_RDWR, 0666);
  int n;
  if (d == -1){
    perror("pessoas.db");
    return 1;
  }

  if(argc == 1){
    while(read(d, &pessoa1, sizeof(pessoa1)) == sizeof(pessoa1){
      char buffer[128*2];
      snprintf(buffer, sizeof(buffer), "%s, %d\n", pessoa1.nome, pessoa1.idade);
      write(1, buffer, strlen(buffer));
    }
   else
  if(argc == 4 && strcmp(argv[1], "-i") == 0){
    if(procura(f, argv[2]) != -1){
      fprintf(stderr,"registo ja existente\n");
      close(f);
      return 1;

    }
    strcpy(pessoa1.nome, argv[2]);
    pessoa1.idade = atoi(argv[3]);
    //lseek(d, 0, SEEK_END);    ja nao é necessario devido à procura
    write(d, pessoa1, sizeof(pessoa1);
  }
  else
  if(argc == 4 && strcmp(argv[1], "-u") == 0){
    if(procura(f, argv[2]) != -1){
      fprintf(stderr, "registo inexistente\n");
      close(f);
      return 1;
    }
    strcpy(pessoa1.nome, argv[2]);
    pessoa1.idade = atoi(argv[3]);
    lseek(f, -sizeof(pessoa1), SEEK_CUR);   // Recuar um registo
    write(f, &pessoa1, sizeof(pessoa1));
    //lseek(d, 0, SEEK_END);    ja nao é necessario devido à procura
    write(d, pessoa1, sizeof(pessoa1));
  }

  close(d);
  return 0;
}
