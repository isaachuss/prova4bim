#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

int energia = 100;              
int saldo = 10;                 
char mensagens[10][100];        
int totalMensagens = 0;         
char contatosNomes[10][50];     
char contatosFones[10][20];     
int totalContatos = 0;          
char registroLigacoes[10][100];
int totalLigacoes = 0;          
char provedor[50] = "Tim";      

void exibirMenu();
void verificarEnergia();
void gerenciarMensagens();
void verificarOperadora();
void gerenciarContatos();
void realizarChamada();
void verificarSaldo();
void acessarHistorico();
void reduzirEnergia();

void exibirMenu() {
    printf("\n==== Menu ====\n");
    printf("1. Ver nível de bateria\n");
    printf("2. Mensagens\n");
    printf("3. Histórico de chamadas\n");
    printf("4. Fazer ligação\n");
    printf("5. Contatos\n");
    printf("6. Ver saldo\n");
    printf("7. Consultar operadora\n");
    printf("0. Sair\n");
    printf("================\n");
}

void verificarEnergia() {
    printf("\nBateria atual: %d%%\n", energia);
    printf("Pode durar mais uns %d minutos\n", energia * 5);
}

void verificarOperadora() {
    printf("\nSua operadora é: %s\n", provedor);
}

void verificarSaldo() {
    printf("\nSaldo disponível: %d\n", saldo);
    printf("Você pode enviar até %d mensagens ou fazer %d ligações\n", saldo, saldo / 2);
}

void reduzirEnergia() {
    static int contador = 0;
    contador++;
    if (contador % 5 == 0) {
        energia--;
        if (energia < 0) {
            energia = 0;
        }
        printf("Aviso: sua bateria caiu para %d%%\n", energia);
    }
}

void gerenciarMensagens() {
    int escolha = -1;
    while (escolha != 0) {
        printf("\n== Mensagens ==\n");
        if (totalMensagens == 0) {
            printf("Você ainda não tem mensagens\n");
        } else {
            for (int i = 0; i < totalMensagens; i++) {
                printf("[%d] %s\n", i + 1, mensagens[i]);
            }
        }

        printf("\n1. Nova mensagem\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            if (totalMensagens < 10) {
                if (saldo > 0) {
                    printf("Digite sua mensagem: ");
                    scanf(" %[^\n]s", mensagens[totalMensagens]);
                    totalMensagens++;
                    saldo--;
                    printf("Mensagem enviada! Saldo atual: %d\n", saldo);
                } else {
                    printf("Você não tem saldo suficiente para enviar mensagens\n");
                }
            } else {
                printf("A lista de mensagens está cheia\n");
            }
        } else if (escolha != 0) {
            printf("Opção inválida. Tente novamente\n");
        }
    }
}

void gerenciarContatos() {
    int escolha = -1;
    while (escolha != 0) {
        printf("\n== Contatos ==\n");
        if (totalContatos == 0) {
            printf("Nenhum contato salvo\n");
        } else {
            for (int i = 0; i < totalContatos; i++) {
                printf("[%d] Nome: %s | Telefone: %s\n", i + 1, contatosNomes[i], contatosFones[i]);
            }
        }

        printf("\n1. Novo contato\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            if (totalContatos < 10) {
                printf("Nome do contato: ");
                scanf(" %[^\n]s", contatosNomes[totalContatos]);
                printf("Telefone do contato: ");
                scanf(" %[^\n]s", contatosFones[totalContatos]);
                totalContatos++;
                printf("Contato adicionado!\n");
            } else {
                printf("A agenda está cheia\n");
            }
        } else if (escolha != 0) {
            printf("Opção inválida. Tente novamente\n");
        }
    }
}

void realizarChamada() {
    if (saldo < 2) {
        printf("\nVocê não tem saldo suficiente para fazer uma ligação\n");
        return;
    }

    char numero[20];
    printf("Digite o número para ligar: ");
    scanf(" %[^\n]s", numero);

    saldo -= 2;
    printf("Ligação realizada para %s. Saldo restante: %d\n", numero, saldo);
    snprintf(registroLigacoes[totalLigacoes], 100, "Ligação para %s - Duração: 5 segundos", numero);
    totalLigacoes++;
}

void acessarHistorico() {
    int escolha = -1;
    while (escolha != 0) {
        printf("\n== Histórico de Chamadas ==\n");
        if (totalLigacoes == 0) {
            printf("Sem chamadas registradas\n");
        } else {
            for (int i = 0; i < totalLigacoes; i++) {
                printf("[%d] %s\n", i + 1, registroLigacoes[i]);
            }
        }

        printf("\n0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        if (escolha != 0) {
            printf("Opção inválida. Tente novamente\n");
        }
    }
}

int main() {
    int escolha = -1;

    while (escolha != 0) {
        exibirMenu();
        printf("Escolha: ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            verificarEnergia();
        } else if (escolha == 2) {
            gerenciarMensagens();
        } else if (escolha == 3) {
            acessarHistorico();
        } else if (escolha == 4) {
            realizarChamada();
        } else if (escolha == 5) {
            gerenciarContatos();
        } else if (escolha == 6) {
            verificarSaldo();
        } else if (escolha == 7) {
            verificarOperadora();
        } else if (escolha == 0) {
            printf("Encerrando o programa...\n");
        } else {
            printf("Opção inválida. Tente novamente\n");
        }

        reduzirEnergia();
        sleep(1);
    }

    return 0;
}
