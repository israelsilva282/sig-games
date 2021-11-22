#include <stdio.h>


void telaSobre(void);
char telaPrincipal(void);
void telaEquipe(void);

void telaCliente(void);
void telaAdicionarCliente(void);
void telaPesquisarCliente(void);
void telaEditarCliente(void);
void telaRemoverCliente(void);

void telaFuncionario(void);
void telaAdicionarFuncionario(void);
void telaPesquisarFuncionario(void);
void telaEditarFuncionario(void);
void telaRemoverFuncionario(void);

void telaJogo(void);
void telaAdicionarJogo(void);
void telaPesquisarJogo(void);
void telaListarJogos(void);
void telaEditarJogo(void);
void telaRemoverJogo(void);


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
    


    /*
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
    */
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
    //printf("Escolha uma opcao:\n1. Listar Jogos\n2. Adicionar Jogo\n3. Remover Jogo\n4. Alugar Jogo\n5. Consultar Jogos Alugados\n6. Sobre\n7. Equipe\n0. Sair\n");
    //printf("----------------------------------------------------\n");

    printf("  ---------------------------------------------------------------------  \n");
    printf("  |                        1. Modulo Cliente                          |  \n");
    printf("  |                        2. Modulo Funcionario                      |  \n");
    printf("  |                        3. Modulo Jogo                             |  \n");
    printf("  |                        4. Sobre                                   |  \n");
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

//TELAS CLIENTE
void telaCliente(void){
    char esc;

    system("clear||cls");
    printf("  ---------------------------------------------------------------------  \n");
    printf("  |                      SIG-GAMES | Menu Cliente                     |  \n");
    printf("  ---------------------------------------------------------------------  \n");
    printf("  |                        1. Adicionar Cliente                       |  \n");
    printf("  |                        2. Pesquisar cliente                       |  \n");
    printf("  |                        3. Editar Cliente                          |  \n");
    printf("  |                        4. Remover Cliente                         |  \n");
    printf("  |                        0. Voltar                                  |  \n");
    printf("  ---------------------------------------------------------------------  \n");
    printf("                           Digite a opcao desejada: ");
    scanf("%c", &esc);
    getchar();
    switch (esc){
        case '1':
            telaAdicionarCliente();
            break;
        case '2':
            telaPesquisarCliente();
            break;
        case '3':
            telaEditarCliente();
            break;
        case '4':
            telaRemoverCliente();
            break;
        case '0':
            break;
    }
}

void telaAdicionarCliente(void){
    char nome[100];
    char dataNasc[11];
    char email[100];
    char cpf[12];
    char endereco[100];
    char esc;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                    SIG-GAMES | Adicionar Cliente                  |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Nome completo: ");
        scanf("%[A-ZÇÁÉÍÓÚÂÊÔÃÕÀ a-zçáéíóúâêôãõà]", nome);
        getchar();
        printf("                     Data de nascimento (DD/MM/AA): ");
        scanf("%[0-9/]", dataNasc);
        getchar();
        printf("                     Endereco: ");
        scanf("%[A-ZÇÁÉÍÓÚÂÊÔÃÕ a-zçáéíóúâêôãõ0-9./-]", endereco);
        getchar();
        printf("                     Email: ");
        scanf("%[A-Za-z@._]", email);
        getchar();
        printf("                     CPF (Apenas Numeros): ");
        scanf("%[0-9.-]", cpf);
        getchar();
        printf("                     Cliente cadastrado.");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                    1. Cadastrar outro cliente                     |  \n");
        printf("  |                    0. Voltar                                      |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
    } while(esc != '0');
    telaCliente();
}

void telaPesquisarCliente(void){
    char cpf[12];
    char esc;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                    SIG-GAMES | Pesquisar cliente                  |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Informe o CPF do cliente: ");
        scanf("%[0-9.-]", cpf);
        getchar();

        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                     1. Pesquisar outro cliente                    |  \n");
        printf("  |                     0. Voltar                                     |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
    } while(esc != '0');
    telaCliente();   
}

void telaEditarCliente(void){
    char cpf[12];
    char esc;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                     SIG-GAMES | Editar cliente                    |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Informe o CPF do cliente : ");
        scanf("%[0-9.-]", cpf);
        getchar();
        
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                      1. Editar outro cliente                      |  \n");
        printf("  |                      0. Voltar                                    |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
    } while(esc != '0');

    telaCliente();
}

void telaRemoverCliente(void){
    char cpf[12];
    char esc;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                     SIG-GAMES | Remover cliente                   |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Informe o CPF do cliente: ");
        scanf("%[0-9.-]", cpf);
        getchar();
        printf("                     Cliente removido.");

        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                       1. Remover outro cliente                    |  \n");
        printf("  |                       0. Voltar                                   |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
    } while(esc != '0');
    telaCliente();
}


//TELAS FUNCIONARIO
void telaFuncionario(void){
    char esc;

    system("clear||cls");
    printf("  ---------------------------------------------------------------------  \n");
    printf("  |                    SIG-GAMES | Menu Funcionario                   |  \n");
    printf("  ---------------------------------------------------------------------  \n");
    printf("  |                     1. Adicionar Funcionario                      |  \n");
    printf("  |                     2. Pesquisar Funcionario                      |  \n");
    printf("  |                     3. Editar Funcionario                         |  \n");
    printf("  |                     4. Remover Funcionario                        |  \n");
    printf("  |                     0. Voltar                                     |  \n");
    printf("  ---------------------------------------------------------------------  \n");
    printf("                     Digite a opcao desejada: ");
    scanf("%c", &esc);
    getchar();
    switch(esc){
        case '1':
            telaAdicionarFuncionario();
            break;
        case '2':
            telaPesquisarFuncionario();
            break;
        case '3':
            telaEditarFuncionario();
            break;
        case '4':
            telaRemoverFuncionario();
            break;
        case '0':
            break;
    }
}

void telaAdicionarFuncionario(void){
    char nome[100];
    char cargo[34];
    char dataNasc[11];
    char email[100];
    char cpf[12];
    char endereco[100];
    char esc;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                    SIG-GAMES | Adicionar funcionario              |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Nome completo: ");
        scanf("%[A-ZÇÁÉÍÓÚÂÊÔÃÕÀ a-zçáéíóúâêôãõà]", nome);
        getchar();
        printf("                     Cargo: ");
        scanf("%[A-Z a-z]", cargo);
        getchar();
        printf("                     Data de nascimento (DD/MM/AA): ");
        scanf("%[0-9/]", dataNasc);
        getchar();
        printf("                     Endereco: ");
        scanf("%[A-ZÇÁÉÍÓÚÂÊÔÃÕ a-zçáéíóúâêôãõ0-9./-]", endereco);
        getchar();
        printf("                     Email: ");
        scanf("%[A-Za-z@._]", email);
        getchar();
        printf("                     CPF (Apenas numeros): ");
        scanf("%[0-9.-]", cpf);
        getchar();
        printf("                     Funcionario adicionado.\n");

        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                    1. Cadastrar outro funcionario                 |  \n");
        printf("  |                    0. Voltar                                      |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
    } while(esc != '0');
    telaFuncionario();
}

void telaPesquisarFuncionario(void){
    char cpf[12];
    char esc;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                 SIG-GAMES | Pesquisar funcionario                 |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Informe o CPF do funcionario: \n");
        scanf("%c", cpf);
        getchar();

        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                  1. Pesquisar outro funcionario                   |  \n");
        printf("  |                  0. Voltar                                        |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
    } while(esc != '0');
    telaFuncionario();
}

void telaEditarFuncionario(void){
    char cpf[12];
    char esc;
    
    do{ 
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                   SIG-GAMES | Editar funcionario                  |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Informe o CPF do funcionario: ");
        scanf("%[0-9.-]", cpf);
        getchar();

        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                    1. Editar outro funcionario                    |  \n");
        printf("  |                    0. Voltar                                      |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
    } while(esc != '0');

    telaFuncionario();
}

void telaRemoverFuncionario(void){
    char cpf[12];
    char esc;
    
    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                  SIG-GAMES | Remover funcionario                  |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Informe o CPF do funcionario: ");
        scanf("%[0-9.-]", cpf);
        getchar();
        printf("                     Funcionario removido.\n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                   1. Remover outro funcionario                    |  \n");
        printf("  |                   0. Voltar                                       |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
    }while(esc != '0');
    telaFuncionario();
}

//TELAS JOGO
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
    char nome[100];
    char dataLanc[11];
    char resumo[2048];
    unsigned int id;
    char esc;

    do{
        system("clear||cls");
        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                     SIG-GAMES | Adicionar jogo                    |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Nome: ");
        scanf("%[A-ZÇÁÉÍÓÚÂÊÔÃÕÀ a-zçáéíóúâêôãõà]", nome);
        getchar();
        printf("                     Data de lancamento (DD/MM/AA): ");
        scanf("%[0-9/]", dataLanc);
        getchar();
        printf("                     Resumo: ");
        scanf("%[A-ZÇÁÉÍÓÚÂÊÔÃÕ a-zçáéíóúâàêôãõ0-9./-]", resumo);
        getchar();
        printf("                     ID: ");
        scanf("%d", &id);
        getchar();
        printf("                     Jogo adicionado.\n");

        printf("  ---------------------------------------------------------------------  \n");
        printf("  |                     1. Adicionar outro jogo                       |  \n");
        printf("  |                     0. Voltar                                     |  \n");
        printf("  ---------------------------------------------------------------------  \n");
        printf("                     Digite a opcao desejada: ");
        scanf("%c", &esc);
        getchar();
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
    printf("                         1. jogo1");
    printf("                         2. jogo2");
    printf("                         3. jogo3");
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

