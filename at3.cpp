#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//*********

 struct Produto {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

// ******************* 
float valor_total(Produto p) {
    return p.preco * p.quantidade;
}

// Funçao quantidade em estoque de um produto com base em uma compra
void atualizar_estoque(Produto *p, int compra) {
    if (compra > p->quantidade) {
        printf("Não há estoque suficiente para essa compra.\n");
    } else {
        p->quantidade -= compra;
        printf("Compra realizada com sucesso.\n");
    }
    
    
}

// Função que exibe o menu de opções e retorna a escolha do usuário 
int menu() {
    int opcao;
    printf("Menu de opções:\n");
    printf("1 - Realizar uma compra\n");
    printf("2 - Consultar estoque\n");
    printf("3 - Sair do programa\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);
    return opcao;
}


int main() {
    
    Produto p;
    strcpy(p.nome, "Caneta");
    p.preco = 1.5;
    p.quantidade = 100;

    
    int op, compra;


    do {
        
        op = menu();

        
        switch (op) {
            case 1:
                printf("Digite a quantidade que deseja comprar: ");
                scanf("%d", &compra);
                atualizar_estoque(&p, compra);
                break;
            case 2:
                printf("O produto %s tem %d unidades em estoque e vale R$ %.2f cada.\n", p.nome, p.quantidade, p.preco);
                printf("O valor total em estoque é R$ %.2f.\n", valor_total(p));
                break;
            case 3:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (op != 3);

    return 0;
}

