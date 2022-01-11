#include <stdio.h>
#include <stdlib.h>
#include "sobre.h"
#include "cliente.h"
#include "funcionario.h"
#include "jogo.h"
#include "validacao.h"
char telaPrincipal(void);


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
    do{
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
    } while(!checkDigit(esc));
    

    return esc;
}
