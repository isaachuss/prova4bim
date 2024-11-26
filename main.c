#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int main() {
    int escolha;
    do {
        printf("\n==== Menu ====\n");
        printf("1. Ver bateria\n");
        printf("2. Mensagens\n");
        printf("3. Contatos\n");
        printf("4. Fazer ligação\n");
        printf("5. Histórico de chamadas\n");
        printf("6. Ver saldo\n");
        printf("7. Ver operadora\n");
        printf("0. Sair\n");
        printf("================\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            printf("\nBateria atual: %d%%\n", energia);
            if (energia <= 0) {
                printf("Aviso: A bateria está vazia! O telefone desligará.\n");
                break;
            }
        } else if (escolha == 2) {
            int opcaoMensagem;
            printf("\n== Mensagens ==\n");
            if (totalMensagens == 0) {
                printf("Nenhuma mensagem.\n");
            } else {
                for (int i = 0; i < totalMensagens; i++) {
                    printf("[%d] %s\n", i + 1, mensagens[i]);
                }
            }
            printf("\n1. Enviar nova mensagem\n");
            printf("0. Voltar\n");
            printf("Escolha: ");
            scanf("%d", &opcaoMensagem);

            if (opcaoMensagem == 1) {
                if (saldo > 0 && totalMensagens < 10) {
                    printf("Digite a mensagem: ");
                    scanf(" %[^\n]s", mensagens[totalMensagens]);
                    totalMensagens++;
                    saldo--;
                    printf("Mensagem enviada! Saldo atual: %d\n", saldo);
                } else {
                    printf("Sem saldo ou espaço para mensagens.\n");
                }
            }
        } else if (escolha == 3) {
            int opcaoContato;
            printf("\n== Contatos ==\n");
            if (totalContatos == 0) {
                printf("Nenhum contato salvo.\n");
            } else {
                for (int i = 0; i < totalContatos; i++) {
                    printf("[%d] Nome: %s | Telefone: %s\n", i + 1, contatosNomes[i], contatosFones[i]);
                }
            }
            printf("\n1. Adicionar contato\n");
            printf("0. Voltar\n");
            printf("Escolha: ");
            scanf("%d", &opcaoContato);

            if (opcaoContato == 1) {
                if (totalContatos < 10) {
                    printf("Digite o nome do contato: ");
                    scanf(" %[^\n]s", contatosNomes[totalContatos]);
                    printf("Digite o telefone: ");
                    scanf(" %[^\n]s", contatosFones[totalContatos]);
                    totalContatos++;
                    printf("Contato salvo!\n");
                } else {
                    printf("Agenda cheia.\n");
                }
            }
        } else if (escolha == 4) {
            if (saldo >= 2) {
                char numero[20];
                printf("Digite o número para ligar: ");
                scanf(" %[^\n]s", numero);
                saldo -= 2;
                printf("Ligando para %s...\n", numero);
                sleep(2);
                printf("Ligação encerrada.\n");
                snprintf(registroLigacoes[totalLigacoes], 100, "Ligação para %s", numero);
                totalLigacoes++;
            } else {
                printf("Saldo insuficiente para fazer ligações.\n");
            }
        } else if (escolha == 5) {
            printf("\n== Histórico de Chamadas ==\n");
            if (totalLigacoes == 0) {
                printf("Sem chamadas registradas.\n");
            } else {
                for (int i = 0; i < totalLigacoes; i++) {
                    printf("[%d] %s\n", i + 1, registroLigacoes[i]);
                }
            }
        } else if (escolha == 6) {
            printf("\nSaldo disponível: %d\n", saldo);
        } else if (escolha == 7) {
            printf("\nSua operadora é: %s\n", provedor);
        } else if (escolha != 0) {
            printf("\nOpção inválida.\n");
        }

        energia -= 1;
        if (energia <= 0) {
            printf("\nBateria esgotada! O telefone desligará.\n");
            break;
        }

    } while (escolha != 0);

    printf("Encerrando o programa...\n");
    return 0;
}
