#include <unistd.h>
#include <stdio.h>
#include <assert.h>
#include <fcntl.h>
#include <string.h>

/*typedef struct Pessoa{
    char nome[tm];
    char idade[5];
}pessoa;*/

int main(int argc, char const *argv[]) {

  int tm = sizeof(argv[2]);
  int tmi = sizeof(argv[3]);
  //struct Pessoa pessoa1;
  int d = open("pessoas.txt", O_WRONLY, 0666);
  int n;
  typedef struct Pessoa{
      char nome[tm];
      char idade[tmi];
  }pessoa;
  struct Pessoa pessoa1;

//  printf("%s\n",argv[1] );

if(strcmp("-i",argv[1]) == 0){
  strcpy(pessoa1.nome, argv[2]);
  strcpy(pessoa1.idade, argv[3]);
  printf("%s\n", pessoa1.nome);
  printf("%s\n",pessoa1.idade);
  printf("%d\n", tm);
  write (d,pessoa1.nome,tm);
  write(d,pessoa1.idade,tmi);

}

close(d);
  //strcpy(pessoa1.nome, "Tiago");

  //pessoa1.nome = "Tiago";

  //printf("%s\n", pessoa1.nome);
  //printf("%d\n",pessoa1.idade);

  return 0;
}
