#include <stdio.h>

int main(void){
    telaSobre();
    telaPrincipal();
    telaEquipe();     
    
    printf("=========================================================================\n");
    telaListar();
    telaAdicionar();
    telaRemover();
    telaAlugar();
    telaConsulta();

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

void telaPrincipal(void){
    //printf("----------------------------------------------------\n");
    printf("SIG-GAMES | Alugue o seu jogo!\n");
    printf("Escolha uma opcao:\n1. Listar Jogos\n2. Adicionar Jogo\n3. Remover Jogo\n4. Alugar Jogo\n5. Consultar Jogos Alugados\n6. Sobre\n7. Equipe\n0. Sair\n");
    //printf("----------------------------------------------------\n");
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

//PROTÓTIPOS DE TELA SEM ESTRUTURAS DE REPETIÇÃO OU DE DECISÃO

void telaListar(void){

    printf("=== TELA LISTAR ===\n");

    printf("| Jogo 1\n");
    printf("| Jogo 2\n");
    printf("| Jogo 3\n");
    printf("| Jogo 4\n");
    printf("| Jogo 5\n");
    printf("| Jogo 6\n\n");
    
}

void telaAdicionar(void){

    printf("=== TELA ADICIONAR ===\n");

    printf("Informe o nome do jogo para ser adicionado: \n");
    printf("Informe o ano em que o jogo foi lancado: \n");
    printf("De uma breve sinopse do jogo: \n\n");

    //mostrar o jogo adicionado com todos os detalhes na linha seguinte
}

void telaRemover(void){

    printf("=== TELA REMOVER ===\n");

    printf("Informe o ID do jogo que deseja remover: \n\n");

    //perguntar se o usuário tem certeza que quer remover o jogo ID - NOME

}

void telaAlugar(void){
    printf("=== TELA ALUGAR ===\n");

    printf("Informe o nome ou ID do jogo que deseja alugar: \n\n");
    
    //perguntar se o usuário tem certeza que quer alugar o jogo ID - NOME de DATA DE ALUGAÇÃO até DATA LIMITE
}

void telaConsulta(void){
    printf("=== TELA CONSULTAR JOGOS ALUGADOS ===\n");

    printf("Jogos alugados ate [DATA DE HOJE]: \n");
    
    printf("| Jogo 1\n");
    printf("| Jogo 2\n");
    printf("| Jogo 3\n");      //mostrar data limite dos jogos
    printf("| Jogo 4\n");
    printf("| Jogo 5\n");
    printf("| Jogo 6\n");
}