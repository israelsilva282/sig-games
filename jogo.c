#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"
#include "validacao.h"

typedef struct jogo Jogo;

struct jogo{
    char nome[255];
    char sinopse[255];
    char estiloJogo[255];
    int diaLanc;
    int mesLanc;
    int anoLanc;
    int id;
    char situacao;
};
void telaJogo(void){
    char esc;

    system("clear||cls");
    printf("  ---------------------------------------------------------------------  \n");
    printf("  |                      SIG-GAMES | Menu Jogo                        |  \n");
    printf("  ---------------------------------------------------------------------  \n");
    printf("  |                        1. Adicionar Jogo                          |  \n");
    printf("  |                        2. Pesquisar jogo                          |  \n");
    printf("  |                        3. Listar jogo                             |  \n");
    printf("  |                        4. Editar jogo                             |  \n");
    printf("  |                        5. Remover jogo                            |  \n");
    printf("  |                        0. Voltar                                  |  \n");
    printf("  ---------------------------------------------------------------------  \n");
    printf("                     Digite a opcao desejada: ");
    scanf("%c", &esc);
    getchar();
    
    switch(esc){
        case '1':
            telaAdicionarJogo();
            break;
        case '2':
            telaPesquisarJogo();
            break;
        case '3':
            telaListarJogos();
            break;
        case '4':
            telaEditarJogo();
            break;
        case '5':
            telaRemoverJogo();
            break;
        case '0':
            
            break;
    }
}

void telaAdicionarJogo(void){
    FILE* file;
    Jogo* jogo;
    char esc;
    jogo = (Jogo*) malloc(sizeof(Jogo));
    int novoid = 0;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                     SIG-GAMES | Adicionar jogo                    |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Nome: ");
        scanf(" %255[^\n]", jogo->nome);
        getchar();
        printf("                     Sinopse: ");
        scanf("%255[^\n]", jogo->sinopse);
        getchar();
        printf("                     Data de lancamento (DD/MM/AA)\n");
        printf("                     Dia: ");
        scanf("%d", &jogo->diaLanc);
        getchar();
        printf("                     Mes: ");
        scanf("%d", &jogo->mesLanc);
        getchar();
        printf("                     Ano: ");
        scanf("%d", &jogo->anoLanc);
        getchar();
        printf("                     Estilo de jogo: ");
        scanf(" %255[^\n]", jogo->estiloJogo);
        getchar();
        file = fopen("jogos.dat", "rb");
        if(file == NULL){
            printf("Ocorreu um problema ao adicionar o ID.");
            exit(1);
        }else{  
            fread(jogo, sizeof(Jogo), 1, file);
            fseek(file, (-1)*sizeof(Jogo), SEEK_END); 
            novoid = jogo->id + 1;
            fclose(file);
        }
        jogo->id = novoid;
        jogo->situacao = 'd';

        if(!checkData(jogo->anoLanc, jogo->mesLanc, jogo->diaLanc) || !checkResumo(jogo->sinopse)){
            if(!checkData(jogo->anoLanc, jogo->mesLanc, jogo->diaLanc)){
                printf("                       *Data Invalida.\n");
            }
            if(!checkResumo(jogo->sinopse)){
                printf("                       *Resumo Invalido.\n");
            }
            do{
                printf("  ---------------------------------------------------------------------  \n");
                printf("  |                    1. Tentar novamente                            |  \n");
                printf("  |                    0. Voltar                                      |  \n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("                     Digite a opcao desejada: ");
                scanf("%c", &esc);
                getchar();
            } while (!checkDigit(esc));
        } else{
            file = fopen("jogos.dat", "ab");
            if(file){
                fwrite(jogo, sizeof(Jogo), 1, file);
                fclose(file);
            } else{
                printf("Ocorreu um erro com a criação do arquivo!");
                exit(1);
            }
            free(jogo);
            do{
                printf("                     Jogo adicionado.\n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("  |                     1. Adicionar outro jogo                       |  \n");
                printf("  |                     0. Voltar                                     |  \n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("                     Digite a opcao desejada: ");
                scanf("%c", &esc);
                getchar();
            } while (!checkDigit(esc));
        }
    } while(esc != '0');
    telaJogo();
}

void telaPesquisarJogo(void){
    FILE* file;
    Jogo* jogo;
    int id;
    char esc;
    char situacao[20];
    jogo = (Jogo*) malloc(sizeof(Jogo));
    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                    SIG-GAMES | Pesquisar jogo                     |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Informe o ID do jogo: ");
        scanf("%d", &id);
        getchar();
        if(!checkID(id)){    
            do
            {
                printf("                       *ID Invalido.\n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("  |                    1. Tentar novamente                            |  \n");
                printf("  |                    0. Voltar                                      |  \n");
                printf("  ---------------------------------------------------------------------  \n");
                printf("                     Digite a opcao desejada: ");
                scanf("%c", &esc);
                getchar();
            } while (!checkDigit(esc));
        } else{    
            file = fopen("jogos.dat", "rb");
            if(file == NULL){
                printf("Ocorreu um erro ao ler o arquivo!");
                exit(1);
            }
            while(!feof(file)){
                fread(jogo, sizeof(Jogo), 1, file);
                if(jogo->id == id && (jogo->situacao != 'x')){
                    printf("ID: %u\n", jogo->id);
                    printf("Nome: %s\n", jogo->nome);
                    printf("Sinopse: %s\n", jogo->sinopse);
                    printf("Data de lancamento: %d/%d/%d\n", jogo->diaLanc, jogo->mesLanc, jogo->anoLanc);
                    printf("Estilo de jogo: %s\n", jogo->estiloJogo);
                    if(jogo->situacao == 'd'){
                        strcpy(situacao, "Disponivel");
                    } else if (jogo->situacao == 'a'){
                        strcpy(situacao, "Alugado");
                    }else if (jogo->situacao == 'x'){
                        strcpy(situacao, "Excluido");
                    } else {
                        strcpy(situacao, "Nao informado");
                    }
                    printf("Situacao: %s\n", situacao);
                    fclose(file);
                    break;
                }
            }
            fclose(file);
            do{
            printf("  ---------------------------------------------------------------------  \n");
            printf("  |                     1. Pesquisar outro jogo                       |  \n");
            printf("  |                     0. Voltar                                     |  \n");
            printf("  ---------------------------------------------------------------------  \n");
            printf("                     Digite a opcao desejada: ");
            scanf("%c", &esc);
            getchar();
            }while(!checkDigit(esc));
        }
    }while (esc != '0');
    telaJogo();
}

void telaListarJogos(void){
    system("clear||cls");
    printf("  ---------------------------------------------------------------------  \n");
    printf("  |                      SIG-GAMES | Listar jogos                     |  \n");
    printf("  ---------------------------------------------------------------------  \n");
    printf("                         1. jogo1\n");
    printf("                         2. jogo2\n");
    printf("                         3. jogo3\n");
    printf("  ---------------------------------------------------------------------  \n");
    printf("  |                     Pressione enter para sair...                  |  \n");
    printf("  ---------------------------------------------------------------------  \n");
    getchar();
}

void telaEditarJogo(void){
    unsigned int id;
    char esc;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                      SIG-GAMES | Editar jogo                      |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Informe o ID/Nome do jogo: ");
        scanf("%d", &id);
        getchar();

        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                        1. Editar outro jogo                       |  \n");
        printf("  |                        0. Voltar                                  |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
    }while (esc != '0');
    telaJogo();
}

void telaRemoverJogo(void){
    unsigned int id;
    char esc;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                      SIG-GAMES | Remover jogo                     |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Informe o ID/Nome do jogo: ");
        scanf("%d", &id);
        getchar();
        printf("                     Jogo removido.");

        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                       1. Remover outro jogo                       |  \n");
        printf("  |                       0 Voltar                                    |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
    } while(esc != '0');
    telaJogo();
}
