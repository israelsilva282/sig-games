#include <stdio.h>

int main(void){
    telaSobre();
    telaPrincipal();
    telaEquipe();     
}

/*Funcionalidades: 
Listar jogos
    Detalhar jogo
Adicionar jogo
Remover jogo
Alugar jogo
Consultar jogos alugados

*/

void telaPrincipal(void){
    printf("----------------------------------------------------\n");
    printf("SIG-GAMES | Alugue o seu jogo!\n");
    printf("Escolha uma opcao:\n1. Listar Jogos\n2. Adicionar Jogo\n3. Remover Jogo\n4. Alugar Jogo\n5. Consultar Jogos Alugados\n6. Sobre\n7. Equipe\n0. Sair\n");
    printf("----------------------------------------------------\n");
}

void telaSobre(void){
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
}

void telaEquipe(void){
    printf("  ---------------------------------------------------------------------  \n");
    printf("  |                     Projeto desenvolvido por:                     |  \n");
    printf("  |                 Manoel Anizio Azevedo de Oliveira                 |  \n");
    printf("  |              E-mail: manoel.oliveira.066@ufrn.edu.br              |  \n");
    printf("  |                       Israel Costa e Silva                        |  \n");
    printf("  |                E-mail: israel.silva.117@ufrn.edu.br               |  \n");
    printf("  |          Repositorio: https://github.com/manizio/sig-games        |  \n");
    printf("  ---------------------------------------------------------------------  \n");
}