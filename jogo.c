#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"
#include "validacao.h"

//As funções de validação neste módulo só funcionará quando já possuir armazenamento.
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
    char linha[256];
    int tam;
    char *nome, *resumo;
    int diaLanc;
    int mesLanc;
    int anoLanc;
    unsigned int id;
    char esc;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                     SIG-GAMES | Adicionar jogo                    |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Nome: ");
        scanf(" %255[^\n]", linha);
        tam = strlen(linha);
        nome = (char *) malloc(tam+1);
        strcpy(nome,linha);
        getchar();
        printf("                     Data de lancamento (DD/MM/AA)\n");
        printf("                      Dia: ");
        scanf("%d", &diaLanc);
        getchar();
        printf("                      Mes: ");
        scanf("%d", &mesLanc);
        getchar();
        printf("                      Ano: ");
        scanf("%d", &anoLanc);
        getchar();
        printf("                     Resumo: ");
        scanf(" %255[^\n]", linha);
        tam = strlen(linha);
        resumo = (char *) malloc(tam+1);
        strcpy(resumo,linha);
        getchar();
        printf("                     ID: ");
        scanf("%d", &id);
        getchar();

        if(!checkData(anoLanc, mesLanc, diaLanc) || !checkResumo(resumo)){
            if(!checkData(anoLanc, mesLanc, diaLanc)){
                printf("                       *Data Invalida.\n");
            }
            if(!checkResumo(resumo)){
                printf("                       *Resumo Invalido.\n");
            }
            //checkID só funcionará quando já possuir armazenamento
            printf("  ---------------------------------------------------------------------  \n");
            printf("  |                    1. Tentar novamente                            |  \n");
            printf("  |                    0. Voltar                                      |  \n");
            printf("  ---------------------------------------------------------------------  \n");
            printf("                     Digite a opcao desejada: ");
            scanf("%c", &esc);
            getchar();
        } else{
            printf("                     Jogo adicionado.\n");
            printf("  ---------------------------------------------------------------------  \n");
            printf("  |                     1. Adicionar outro jogo                       |  \n");
            printf("  |                     0. Voltar                                     |  \n");
            printf("  ---------------------------------------------------------------------  \n");
            printf("                     Digite a opcao desejada: ");
            scanf("%c", &esc);
            getchar();
        }
        
    } while(esc != '0');
    telaJogo();
}

void telaPesquisarJogo(void){
    unsigned int id;
    char esc;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                    SIG-GAMES | Pesquisar jogo                     |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Informe o ID/Nome do jogo: ");
        scanf("%d", &id);
        getchar();

        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                     1. Pesquisar outro jogo                       |  \n");
        printf("  |                     0. Voltar                                     |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
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
