#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ContaBancaria {
    int numero_conta;
    char nome_titular[50];
    float saldo;
    char tipo_conta[20];
};
//***************


void depositar(struct ContaBancaria *conta, float valor) {
    conta->saldo += valor;
}
//****************************
void sacar(struct ContaBancaria *conta, float valor) {
    if (conta->saldo >= valor) {
        conta->saldo -= valor;
    } else {
        printf("Saldo insuficiente.\n");
    }
}

//*****************

void imprimir_saldo(struct ContaBancaria conta) {
    printf("O saldo atual da conta %d é R$ %.2f.\n", conta.numero_conta, conta.saldo);
}
//*************************
int main() {
    struct ContaBancaria conta;
    int opcao;
    float valor;

    printf("Digite o número da conta: ");
    scanf("%d", &conta.numero_conta);
    printf("Digite o nome do titular da conta: ");
    scanf("%s", conta.nome_titular);
    printf("Digite o tipo da conta (poupança ou corrente): ");
    scanf("%s", conta.tipo_conta);
    printf("Digite o saldo inicial da conta: ");
    scanf("%f", &conta.saldo);

    while (1) {
        printf("\nEscolha uma opção:\n");
        printf("1 - Depositar dinheiro\n");
        printf("2 - Sacar dinheiro\n");
        printf("3 - Imprimir saldo\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser depositado: ");
                scanf("%f", &valor);
                depositar(&conta, valor);
                printf("Depósito realizado com sucesso.\n");
                break;
            case 2:
                printf("Digite o valor a ser sacado: ");
                scanf("%f", &valor);
                sacar(&conta, valor);
                break;
            case 3:
                imprimir_saldo(conta);
                break;
            case 0:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida.\n");
                break;
        }
    }
}

