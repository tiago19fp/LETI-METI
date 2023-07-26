/* MP2 - G23 */
/* Eduardo Paiva A85312 */
/* Tiago Ferreira A85392 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 50

FILE *dados;

   typedef struct Biblioteca{

                    int codigo;
                    int ISBN;
                    char nome[MAX];
                    int quantidade;
                    char pessoa[MAX];
                    int pessoaEnc;
                    struct livro *prox;

    }livro;

    livro *ListaInicio=0;
    livro *atual=0;
    livro *fim=0;

        livro *crialista(int IS,int cod, char nom[], int quan, char pess[], int pes){

                livro *lista = (livro*) malloc(sizeof(livro));

                lista->codigo=cod;
                lista->ISBN=IS;
                strcpy(lista->nome, nom);
                lista->quantidade=quan;
                strcpy(lista->pessoa, pess);
                lista->pessoaEnc=pes;
                lista->prox = 0;

                ListaInicio=atual=lista;

                return(lista);

        }

        livro *adiLivro(int IS, char nom[], int quan, char pess[], int pes){

                livro *lista = (livro*) malloc(sizeof(livro));
                lista->ISBN=IS;
                strcpy(lista->nome, nom);
                lista->quantidade=quan;
                strcpy(lista->pessoa, pess);
                lista->pessoaEnc=pes;
                lista->prox = 0;

                atual->prox=lista;
                atual=lista;

                return lista;

        }

        livro *procura(int IS){

                livro *procu=ListaInicio;
                int encon=0;

                while(procu!=0){

                            if(procu->ISBN==IS){
                                encon=1;
                                break;
                            }else{
                                    fim=procu;
                                    procu=procu->prox;
                            }
            }

            if(encon==1){

                return procu;
            }else{
                    return 0;
            }

        }

        livro *editarLivro(livro**esco){

                livro*editar= *esco;
                int escol=0;
                char nom[MAX];
                int IS=0;
                int quan;

                printf("\nNome->1\nISBN->2\nQuantidade->3\n");
                scanf("%d", &escol);
                system("cls");

                if(escol==1){

                    printf("Nome:");
                    fflush(stdin);
                    fgets(nom,MAX,stdin);
                    strcpy(editar->nome,nom);



                }if(escol==2){

                    printf("ISBN:");
                    scanf("%d", &IS);
                    editar->ISBN=IS;


                }if(escol==3){

                    printf("Quantidade:");
                    scanf("%d", &quan);
                    editar->quantidade=quan;

            }

        }

        livro *apaga(livro**esco){

        livro *atual=*esco;
        if (fim!=0){
        fim->prox=atual->prox;
    }
    if (atual==ListaInicio){
        ListaInicio=atual->prox;
    }
    free(atual);
    atual=0;
}

        livro *requisitar(char pess[],int quan, livro**esco){

                livro *requis= *esco;

                if(requis->quantidade<quan){

                    printf("Nao existe unidades suficientes na biblioteca\n");

                }else{

                        strcpy(requis->pessoa, pess);
                        requis->pessoaEnc=quan;
                        requis->quantidade=(requis->quantidade)-quan;
                }

    }

        void imprimir(){

                livro *aux=ListaInicio;

                while(aux!=0){

                            printf("Nome:%sISBN:%d\nQuantidade:%d\n\n", aux->nome, aux->ISBN, aux->quantidade);
                            if(aux->pessoaEnc!=0){

                                printf("\Requisicao de %d livros por parte de %s\n\n", aux->pessoaEnc, aux->pessoa);


                            }

                            aux= aux->prox;
                }
        }

        void ficheiro(FILE *dados) {

                dados=fopen("biblioteca.txt","w");
                livro *gravar=ListaInicio;

                while (gravar!=0){
                            fprintf(dados,"%d\n%s%d\n%d\n%s%d", gravar->codigo, gravar->nome, gravar->ISBN, gravar->quantidade, gravar->pessoa, gravar->pessoaEnc);
                            gravar=gravar->prox;
                }
}

        void carregarbibli(FILE *dados){

            int IS;
            int cod;
            int quan;
            char nom[MAX];
            char pess[MAX];
            int cont=0;
            int pes;
            int i=0;

            dados=fopen("biblioteca.txt","r");

            if (dados==0){
                return 0;
            }

            while (!feof(dados)){

                        fscanf(dados,"%d\n",&cod);
                        fgets(nom,MAX,dados);
                        fscanf(dados,"%d\n",&IS);
                        fscanf(dados,"%d\n",&quan);
                        fgets(pess,MAX,dados);
                        fscanf(dados,"%d\n",&pes);


            if (cont==0){

                crialista(IS,cod,nom,quan,pess, pes);
                cont++;
            }else{

                    adiLivro(IS, nom,quan, pess, pes);
            }
            cod++;
            }
        }

        int main()
{
            int IS;
            int cod=0;
            int quan;
            char nom[MAX];
            char pess[MAX];
            int cont=0;
            int pes=0;

            carregarbibli(dados);
            livro *lista=ListaInicio;
            livro *esco=0;

            int esc;
            while(esc != 0){

                    system("cls");
                    printf("\n -----------------------------\n");
                    printf("|    Adicionar Livro:       1 |\n");
                    printf("|    Editar Livro:          2 |\n");
                    printf("|    Apagar Livro:          3 |\n");
                    printf("|    Requisitar livro:      4 |\n");
                    printf("|    Consultar Biblioteca:  5 |\n");
                    printf("|    Sair e guardar dados:  0 |\n");
                    printf(" -----------------------------\n");
                    scanf("%d", &esc);

            switch(esc){

                        case 1:
                                    system("cls");

                                    if(cont==0 && lista==0){

                                        printf("Nome:");
                                        fflush(stdin);
                                        fgets(nom,MAX,stdin);
                                        printf("ISBN:");
                                        scanf("%d", &IS);
                                        printf("Quantidade:");
                                        scanf("%d", &quan);
                                        crialista(IS,cod, nom, quan, pess, pes);
                                        cod++;
                                        cont++;
                                        system ("cls");

                                        }else{

                                                    while(lista!=0){

                                                                IS=lista->ISBN+1;
                                                                lista=lista->prox;
                                                    }

                                        printf("Nome:");
                                        fflush(stdin);
                                        fgets(nom,MAX,stdin);
                                        printf("ISBN:");
                                        scanf("%d", &IS);
                                        printf("Quandtidade:");
                                        scanf("%d", &quan);
                                        adiLivro( IS,  nom,  quan, pess, pes);
                                        cod++;
                                        system ("cls");
                                        }

                                        break;
                        case 2:

                                        system("cls");
                                        system("cls");
                                        printf("Escreva o ISBN do livro que quer editar:");
                                        scanf("%d",&IS);
                                        esco=procura(IS);
                                        if(esco==0){

                                            printf("\n Nao encontrado \n");

                                        }else{

                                                    editarLivro(&esco);

                                    }
                                    int b=0;
                                    printf("\n\nVoltar(1)");
                                    scanf("%d", &b);
                                    if(b==1){

                                        break;

                                    }
                                    break;
                        case 3:

                                    system("cls");
                                    printf("Escreva o ISBN do livro que quer apagar:");
                                    scanf("%d",&IS);
                                    esco=procura(IS);

                                    if(esco==0){

                                        printf("\n Nao encontrado \n");

                                    }else{

                                                apaga(&esco);
                                                printf("Livro apagado");

                                    }

                                    printf("\n\nVoltar(1)");
                                    int c=0;
                                    scanf("%d", &c);
                                    if(c==1){

                                    break;

                                    }

                                    break;
                        case 4:

                                    system("cls");
                                    printf("Nome Pessoa:");
                                    fflush(stdin);
                                    fgets(pess,MAX,stdin);
                                    printf("ISBN:");
                                    scanf("%d", &IS);
                                    printf("Quantidade:");
                                    scanf("%d", &quan);

                                    esco=procura(IS);

                                    requisitar(pess,quan,&esco);
                                    int f=0;
                                    imprimir();
                                    printf("\n\nVoltar(1)");
                                    scanf("%d", &c);
                                    if(f==1){

                                        break;

                                    }

                                    break;
                        case 5:

                                    system("cls");
                                    int e=0;
                                    imprimir();
                                    printf("\n\nVoltar(1)");
                                    scanf("%d", &c);
                                    if(e==1){

                                        break;

                                    }
                                    break;
                        case 0:

                                    ficheiro(dados);

                        break;
        }

    }

}
