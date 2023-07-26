/* MP2 - G23 */
/* Eduardo Paiva A85312 */
/* Tiago Ferreira A85392 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500

FILE *ficheiro;

typedef  struct estrutura
{

    char nome[MAX];
    int NNS;
    int colestrol;
    int colestrolAnt;
    char DataColestrol[MAX];
    char DataColestrolAnterior[MAX];
    int glicose;
    int glicoseAnt;
    char DataGlicose[MAX];
    char DataGlicoseAnterior[MAX];
    int triglicerideos;
    int triglicerideosAnt;
    char DataTriglicerideos[MAX];
    char DataTriglicerideosAnterior[MAX];
    int acido;
    int acidoAnt;
    char DataAcido[MAX];
    char DataAcidoAnterior[MAX];

} boletim;

boletim utente[MAX];

int Nutente=0;

void AdicionarUtente()
{

    int esc = 1;
    int d=0;

    while(esc != 0)
    {
        printf("Insira o NSN:");
        scanf(" %d", &utente[Nutente].NNS);
        printf("Insira o Nome:");
        fflush(stdin);
        fgets(utente[Nutente].nome,MAX,stdin);

        while(esc!=0)
        {
            printf("Que tipo de analise quer adicionar:\n1 - Colestrol\n2 - Glicose\n3 - Triglecerideos\n4 - Acido Urico\n0 - Nenhuma\n");
            scanf("%d", &d);

            switch(d)
            {

            case 1:
                system("cls");
                printf("Valor analise colestrol:");
                scanf(" %d", &utente[Nutente].colestrol);
                printf("Data da colheita(dd/mm/aa):");
                scanf("%s", utente[Nutente].DataColestrol);
                break;

            case 2:
                system("cls");
                printf("Valor analise Glicose:");
                scanf(" %d", &utente[Nutente].glicose);
                printf("Data da colheita(dd/mm/aa):");
                scanf("%s", utente[Nutente].DataGlicose);
                break;

            case 3:
                system("cls");
                printf("Valor analise Triglecerideos:");
                scanf(" %d", &utente[Nutente].triglicerideos);
                printf("Data da colheita(dd/mm/aa):");
                scanf("%s", utente[Nutente].DataTriglicerideos);
                break;

             case 4:
                system("cls");
                printf("Valor analise Acido Urico:");
                scanf(" %d", &utente[Nutente].acido);
                printf("Data da colheita(dd/mm/aa):");
                scanf("%s", utente[Nutente].DataAcido);
                break;

            case 0:
                utente[Nutente].colestrol = -1;
                utente[Nutente].glicose = -1;
                utente[Nutente].triglicerideos = -1;
                utente[Nutente].acido = -1;
                break;

            }

            system("cls");
            printf("Quer adicionar outra analise?\n1 - sim\n0 - nao\n");
            scanf(" %d", &esc);

        }

        if(utente[Nutente].glicose == 0)
        {
            utente[Nutente].glicose = -1;
        }
        if(utente[Nutente].colestrol == 0)
        {
            utente[Nutente].colestrol = -1;
        }
        if(utente[Nutente].triglicerideos == 0)
        {
            utente[Nutente].triglicerideos = -1;
        }
        if(utente[Nutente].acido == 0)
        {
            utente[Nutente].acido = -1;
        }

        system("cls");
        printf("Quer adicionar outro utente?\n1 - sim\n0 - nao\n");
        scanf(" %d", &esc);
        Nutente++;
    }

}
void editarUtente()
{
    int Bole;
    int c;
    int esc = 1;
    int i;
    int f;
    int g;

    system("cls");
    printf("Insira o NNS que quer alterar:\n");
    scanf("%d", &Bole);

    for(i=0; i<Nutente; i++)
    {
        if(Bole==utente[i].NNS)
        {
            printf("O que quer editar?\n1 - NSS\n2 - Nome\n3 - Analise Colestrol\n4 - Analise Glicose\n5 - Analise Triglicerideos\n6 - Acido Urico\n ");
            scanf("%d", &c);
            switch(c)
            {
            case 1:
                system("cls");
                printf("NSS atual:%d\nInsira o novo NSS:", utente[i].NNS);
                scanf(" %d", &utente[i].NNS);
                break;

            case 2:
                system("cls");
                printf("Nome atual:%sInsira o novo nome:", utente[i].nome);
                fflush(stdin);
                fgets(utente[i].nome,MAX,stdin);
                break;

            case 3:
                system("cls");
                printf("Ultimo Valor Colestrol:%d\nInsira o novo valor:", utente[i].colestrol);
                utente[i].colestrolAnt= utente[i].colestrol;
                scanf(" %d", &utente[i].colestrol);
                printf("Data da ultima collheita Colestrol:%s\nInsira a nova data(dd/mm/aa):", utente[i].DataColestrol);
                strcpy(utente[i].DataColestrolAnterior, utente[i].DataColestrol);
                scanf("%s", utente[i].DataColestrol);

                if(utente[i].colestrolAnt != -1)
                {
                    f =  (utente[i].colestrolAnt*0.20)+utente[i].colestrolAnt;
                    g=  utente[i].colestrolAnt-(utente[i].colestrolAnt*0.20);
                    if(utente[i].colestrol>f|| utente[i].colestrol<g)
                    {
                        printf("\nATENCAOO NOVO VALOR ESTA ACIMA OU ABAIXO 20 PORCENTO COMPARADO COM O VALOR ANTERIOR\n\n");
                    }
                }

                break;

            case 4:
                system("cls");
                printf("Ultimo valor Glicose:%d\nInsira o novo valor:", utente[i].glicose);
                utente[i].glicoseAnt= utente[i].glicose;
                scanf(" %d", &utente[i].glicose);
                printf("Data da ultima colheita Glicose:%s\nInsira a nova data(dd/mm/aa):", utente[i].DataGlicose);
                strcpy(utente[i].DataGlicoseAnterior, utente[i].DataGlicose);
                scanf("%s", utente[i].DataGlicose);

                if(utente[i].glicoseAnt != -1)
                {
                    f =  (utente[i].glicoseAnt*0,20)+utente[i].glicoseAnt;
                    g=  utente[i].glicoseAnt-(utente[i].glicoseAnt*0,20);
                    if(utente[i].glicose>f || utente[i].glicose<g)
                    {
                        printf("\nATENCAO! O NOVO VALOR ESTA ACIMA OU ABAIXO 20 PORCENTO COMPARADO COM O VALOR ANTERIOR\n\n");
                    }

                }
                break;

                case 5:
                system("cls");
                printf("Ultimo valor Triglicerideos:%d\nInsira o novo valor:", utente[i].triglicerideos);
                utente[i].triglicerideosAnt= utente[i].triglicerideos;
                scanf(" %d", &utente[i].triglicerideos);
                printf("Data da ultima colheita triglicerideos:%s\nInsira a nova data(dd/mm/aa):", utente[i].DataTriglicerideos);
                strcpy(utente[i].DataTriglicerideosAnterior, utente[i].DataTriglicerideos);
                scanf("%s", utente[i].DataTriglicerideos);

                if(utente[i].triglicerideosAnt != -1)
                {
                    f =  (utente[i].triglicerideosAnt*0,20)+utente[i].triglicerideosAnt;
                    g=  utente[i].triglicerideosAnt-(utente[i].triglicerideosAnt*0,20);
                    if(utente[i].triglicerideos>f || utente[i].triglicerideos<g)
                    {
                        printf("\nATENCAO! O NOVO VALOR ESTA ACIMA OU ABAIXO 20 PORCENTO COMPARADO COM O VALOR ANTERIOR\n\n");
                    }

                }
                break;

                case 6:
                system("cls");
                printf("Ultimo valor Acido Urico:%d\nInsira o novo valor:", utente[i].acido);
                utente[i].acidoAnt= utente[i].acido;
                scanf(" %d", &utente[i].acido);
                printf("Data da ultima colheita Acido Urico:%s\nInsira a nova data(dd/mm/aa):", utente[i].DataAcido);
                strcpy(utente[i].DataAcidoAnterior, utente[i].DataAcido);
               scanf("%s", utente[i].DataAcido);

                if(utente[i].acidoAnt != -1)
                {
                    f =  (utente[i].acidoAnt*0,20)+utente[i].acidoAnt;
                    g=  utente[i].acidoAnt-(utente[i].acidoAnt*0,20);
                    if(utente[i].acido>f || utente[i].acido<g)
                    {
                        printf("\nATENCAO! O NOVO VALOR ESTA ACIMA OU ABAIXO 20 PORCENTO COMPARADO COM O VALOR ANTERIOR\n\n");
                    }

                }
                break;
            }
        }
    }

        printf("Quer editar mais algum utente?\n1 - sim\n0 - nao\n");
        scanf("%d", &esc);
        switch(esc)
        {
        case 1:
            system("cls");
            editarUtente();
            break;

        case 0:
            break;
        }


}
void apagarUtente()
{
    int bole;
    int esc = 1;
    int i;
    while(esc!= 0)
    {
        printf("Insira o NNS do utente que quer apagar:");
        scanf("%d", &bole);
        for(i=0; i<Nutente; i++)
        {
            if(bole==utente[i].NNS)
            {
                utente[i] = utente[MAX];
            }
        }

        printf("Quer apagar mais algum utente?\n1 - Sim\n0 - Nao\n");
        scanf("%d", &esc);

    }
}
void ConsultarBoletim()
{
    int Bole;
    int esc= 1;
    int i=0;
    while(esc != 0)
    {
        printf("Digite o NNS do utente que quer consultar:");
        scanf("%d", &Bole);
        for(i=0; i<Nutente; i++)
        {
            if(Bole == utente[i].NNS)
            {
                printf("\nNome: %s", utente[i].nome);
                printf("NNS: %d\n", utente[i].NNS);
                if(utente[i].colestrol == -1){

                    printf("Colestrol: Sem dados\n");

                }else{

                            printf("Colestrol:%d|%s|%s \n", utente[i].colestrol, utente[i].DataColestrol,utente[i].DataColestrolAnterior);

                }
                if(utente[i].glicose== -1){

                      printf("Glicose: Sem dados\n");

                 }else{

                            printf("Gliscose: %d|%s|%s \n", utente[i].glicose,utente[i].DataGlicose, utente[i].DataGlicoseAnterior);

                 }if(utente[i].triglicerideos== -1){

                      printf("Triglicerideos: Sem dados\n");

                 }else{

                            printf("Triglicerideos: %d|%s|%s\n", utente[i].triglicerideos,utente[i].DataTriglicerideos, utente[i].DataTriglicerideosAnterior);

                 }if(utente[i].acido== -1){

                      printf("Acido Urico: Sem dados\n");

                 }else{

                            printf("Acido Urico: %d|%s|%s\n", utente[i].acido,utente[i].DataAcido, utente[i].DataAcidoAnterior);

                 }
            }
        }

        printf("\nQuer conultar outro boletim?\n1 - sim \n0 - nao\n");
        scanf(" %d", &esc);
        system("cls");

    }
}

int main()
{

    int esc;

    FILE *ficheiro;
    ficheiro = fopen("pauta.bin","rb");
    if(ficheiro != NULL)
    {
        fread (&NA, sizeof(int), 1, ficheiro);
        fread(PautaNotas,sizeof(pauta),MAX, ficheiro);
    }
    fclose(ficheiro);

    while(esc != 0)
    {
        system("cls");
        printf("\n -----------------------------\n");
        printf("|    Adicionar Utente:      1 |\n");
        printf("|    Editar utente:         2 |\n");
        printf("|    Apagar utente:         3 |\n");
        printf("|    Consultar Boletim:     4 |\n");
        printf("|    Sair e guardar dados:  0 |\n");
        printf(" -----------------------------\n");
        scanf("%d", &esc);

        switch(esc)
        {
        case 1:
            system("cls");
            AdicionarUtente();
            break;
        case 2:
            system("cls");
            editarUtente();
            break;
        case 3:
            system("cls");
            apagarUtente();
            break;
        case 4:
            system("cls");
            ConsultarBoletim();
            break;
        case 0:
            ficheiro = fopen("dados.bin","wb");
            fwrite(&Nutente, sizeof(int), 1, ficheiro);
            fwrite(utente,sizeof(boletim),MAX, ficheiro);
            fclose(ficheiro);
            break;
        }
    }

}
