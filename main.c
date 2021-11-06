#include <stdio.h>


void telaSobre(void);
void telaPrincipal(void);
void telaEquipe(void);

void telaAdicionarCliente(void);
void telaPesquisarCliente(void);
void telaEditarCliente(void);
void telaRemoverCliente(void);

void telaAdicionarFuncionario(void);
void telaPesquisarFuncionario(void);
void telaEditarFuncionario(void);
void telaRemoverFuncionario(void);

void telaAdicionarJogo(void);
void telaPesquisarJogo(void);
void telaListarJogos(void);
void telaEditarJogo(void);
void telaRemoverJogo(void);


int main(void){
    telaSobre();
    telaPrincipal();
    telaEquipe();     
    
    printf("=========================================================================\n");

    telaAdicionarCliente();
    telaPesquisarCliente();
    telaEditarCliente();
    telaRemoverCliente();

    printf("=========================================================================\n");

    telaAdicionarFuncionario();
    telaPesquisarFuncionario();
    telaEditarFuncionario();
    telaRemoverFuncionario();

    printf("=========================================================================\n");

    telaAdicionarJogo();
    telaPesquisarJogo();
    telaListarJogos();
    telaEditarJogo();
    telaRemoverJogo();

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
    char esc;

    //printf("----------------------------------------------------\n");
    printf("SIG-GAMES | Alugue o seu jogo!\n");
    //printf("Escolha uma opcao:\n1. Listar Jogos\n2. Adicionar Jogo\n3. Remover Jogo\n4. Alugar Jogo\n5. Consultar Jogos Alugados\n6. Sobre\n7. Equipe\n0. Sair\n");
    //printf("----------------------------------------------------\n");

    printf("Escolha uma opcao:\n1. Modulo Cliente\n2. Modulo Funcionario\n3. Modulo Jogo\n");
    scanf("%c", &esc);
    getchar();


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


void telaCliente(void){
    char esc;
    printf("SIG-GAMES | Menu Cliente");
    printf("1. Adicionar Cliente\n2. Pesquisar cliente\n3. Editar Cliente\n4. Remover Cliente\n");
    scanf("%c", &esc);
    getchar();
}

void telaAdicionarCliente(void){
    char nome[52];
    char dataNasc[11];
    char email[52];
    char cpf[12];
    char endereco[52];


    printf("SIG-GAMES | Adicionar Cliente\n");
    printf("Nome completo: ");
    scanf("%[A-ZÇÁÉÍÓÚÂÊÔÃÕÀ a-zçáéíóúâêôãõà]", nome);
    getchar();
    printf("Data de nascimento: ");
    scanf("%[0-9/]", dataNasc);
    getchar();
    printf("Endereco: ");
    scanf("%[A-ZÇÁÉÍÓÚÂÊÔÃÕ a-zçáéíóúâêôãõ0-9./-]", endereco);
    getchar();
    printf("Email: ");
    scanf("%[A-Za-z@._]", email);
    getchar();
    printf("CPF: ");
    scanf("%[0-9.-]", cpf);
    getchar();
    printf("Cliente cadastrado.\n");
}

void telaPesquisarCliente(void){
    char cpf[12];


    printf("SIG-GAMES | Pesquisar cliente\n");
    printf("Informe o CPF do cliente: ");
    scanf("%[0-9.-]", cpf);
    getchar();
    
}

void telaEditarCliente(void){
    char cpf[12];
    
    printf("SIG-GAMES | Editar cliente\n");
    printf("Informe o CPF do cliente: ");
    scanf("%[0-9.-]", cpf);
    getchar();
}

void telaRemoverCliente(void){
    char cpf[12];


    printf("SIG-GAMES | Remover cliente\n");
    printf("Informe o CPF do cliente: ");
    scanf("%[0-9.-]", cpf);
    getchar();
}

void telaFuncionario(void){
    char esc;


    printf("SIG-GAMES | Menu Funcionario");
    printf("1. Adicionar Funcionario\n2. Pesquisar Funcionario\n3. Editar Funcionario\n4. Remover Funcionario\n");
    scanf("%c", esc);
    getchar();

}

void telaAdicionarFuncionario(void){
    char nome[52];
    char cargo[34];
    char dataNasc[11];
    char email[52];
    char cpf[12];
    char endereco[52];

    printf("SIG-GAMES | Adicionar funcionario\n");
    printf("Nome completo: ");
    scanf("%[A-ZÇÁÉÍÓÚÂÊÔÃÕÀ a-zçáéíóúâêôãõà]", nome);
    getchar();
    printf("Cargo: ");
    scanf("%[A-Z a-z]", cargo);
    getchar();
    printf("Data de nascimento ");
    scanf("%[0-9/]", dataNasc);
    getchar();
    printf("Endereco: ");
    scanf("%[A-ZÇÁÉÍÓÚÂÊÔÃÕ a-zçáéíóúâêôãõ0-9./-]", endereco);
    getchar();
    printf("Email: ");
    scanf("%[A-Za-z@._]", email);
    getchar();
    printf("CPF: ");
    scanf("%[0-9.-]", cpf);
    getchar();
    printf("Funcionario adicionado.\n");
}

void telaPesquisarFuncionario(void){
    printf("SIG-GAMES | Pesquisar funcionario\n");
    printf("Informe o CPF do funcionario: \n");
}

void telaEditarFuncionario(void){
    printf("SIG-GAMES | Editar funcionario\n");
    printf("Informe o CPF do funcionario: \n");
}

void telaRemoverFuncionario(void){
    printf("SIG-GAMES | Remover funcionario\n");
    printf("Informe o CPF do funcionario: \n");
}

void telaJogo(void){
    printf("SIG-GAMES | Menu Jogo\n");
    printf("1. Adicionar Jogo\n2. Pesquisar jogo\n3. Listar jogo\n4. Editar jogo\n5. Remover jogo\n");
}

void telaAdicionarJogo(void){
    printf("SIG-GAMES | Adicionar jogo\n");
    printf("Nome: \n");
    printf("Data de lancamento: \n");
    printf("Resumo: \n");
    printf("ID: \n");
    printf("Jogo adicionado.\n");
}

void telaPesquisarJogo(void){
    printf("SIG-GAMES | Pesquisar jogo\n");
    printf("Informe o ID/Nome do jogo: \n");
}

void telaListarJogos(void){
    printf("SIG-GAMES | Listar jogos\n");
    //1. jogo1
    //2. jogo2
    //3. jogo3
}

void telaEditarJogo(void){
    printf("SIG-GAMES | Editar jogo\n");
    printf("Informe o ID/Nome do jogo: \n");
}

void telaRemoverJogo(void){
    printf("SIG-GAMES | Remover jogo\n");
    printf("Informe o ID/Nome do jogo: \n");
}
