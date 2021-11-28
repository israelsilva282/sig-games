#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "funcionario.h"
#include "jogo.h"
void telaSobre(void);
char telaPrincipal(void);
void telaEquipe(void);

int main(void){
    char esc;
    
    do{
        esc = telaPrincipal();

        switch(esc){
            case '1':
                telaCliente();
                break;
            case '2':
                telaFuncionario();
                break;
            case '3':
                telaJogo();
                break;
            case '4':
                telaSobre();
                telaEquipe();
                break;
        }
    } while(esc != '0');
    
    return 0;
}

/*Funcionalidades: 
Listar jogos
    Detalhar jogo
Adicionar jogo
Remover jogo
Alugar jogo
Consultar jogos alugados

*/

char telaPrincipal(void){
    char esc;

    system("clear||cls");
    printf("  ---------------------------------------------------------------------  \n");
    printf("  |                    SIG-GAMES | Alugue o seu jogo!                 |  \n");
    printf("  ---------------------------------------------------------------------  \n");

    printf("  ---------------------------------------------------------------------  \n");
    printf("  |                        1. Modulo Cliente                          |  \n");
    printf("  |                        2. Modulo Funcionario                      |  \n");
    printf("  |                        3. Modulo Jogo                             |  \n");
    printf("  |                        4. Sobre                                   |  \n");
    printf("  |                        0. Sair                                    |  \n");
    printf("  ---------------------------------------------------------------------  \n");
    printf("                           Digite a opcao desejada: ");
    scanf("%c", &esc);
    getchar();

    return esc;
}

void telaSobre(void){
    system("clear||cls");
    printf("  ---------------------------------------------------------------------  \n");
    printf("  |            Universidade Federal do Rio Grande do Norte            |  \n");
    printf("  |                Centro de Ensino Superior do Serido                |  \n");
    printf("  |              Departamento de Computacao e Tecnologia              |  \n");
    printf("  |                 Disciplina DCT1106 -- Programacao                 |  \n");
    printf("  |                Projeto Locadora de Jogos SIG-GAMES                |  \n");
    printf("  |              Desenvolvido por: @manizio - Out, 2021               |  \n");
    printf("  |                                @israelsilva282                    |  \n");
    printf("  ---------------------------------------------------------------------  \n");
    printf("\n");
    printf("  ---------------------------------------------------------------------  \n");
    printf("  |                Projeto Locadora de Jogos SIG-GAMES                |  \n");
    printf("  |      Projeto utilizado na disciplina DCT1106 - Programacao.       |  \n");
    printf("  |   programa contem as funcoes basicas para essa etapa do projeto:  |  \n");
    printf("  |      uma tela Sobre, uma tela Principal e uma tela de equipe.     |  \n");
    printf("  |       Todas as funcoes demonstradas na tela principal sao as      |  \n");
    printf("  |       necessarias para o funcionamento da Locadora de Jogos.      |  \n");
    printf("  ---------------------------------------------------------------------  \n");
    printf("                   Pressione enter para continuar...                  |  \n");
    getchar();
}

void telaEquipe(void){
    system("clear||cls");
    printf("  ---------------------------------------------------------------------  \n");
    printf("  |                     Projeto desenvolvido por:                     |  \n");
    printf("  |                 Manoel Anizio Azevedo de Oliveira                 |  \n");
    printf("  |              E-mail: manoel.oliveira.066@ufrn.edu.br              |  \n");
    printf("  |                       Israel Costa e Silva                        |  \n");
    printf("  |                E-mail: israel.silva.117@ufrn.edu.br               |  \n");
    printf("  |          Repositorio: https://github.com/manizio/sig-games        |  \n");
    printf("  ---------------------------------------------------------------------  \n");
    printf("                   Pressione enter para continuar...                  |  \n");
    getchar();
}
