#include <stdio.h>
#include <stdlib.h>
#include <string.h>




//******************************

struct Aluno {
    char nome[50];
    char data_nascimento[11];
    float nota1;
    float nota2;
    float media;
};

float calcularMedia(struct Aluno aluno) {
    return (aluno.nota1 + aluno.nota2) / 2;
}

int main() {
    struct Aluno alunos[5];
    int i;

    for (i = 0; i < 5; i++) {
    	
    printf("Digite o nome do aluno %d: ", i + 1);
        gets ( alunos[i].nome);
    printf("Digite a data de nascimento do %d° aluno : ", i + 1);
        gets ( alunos[i].data_nascimento);
    printf("Digite a primeira nota do aluno %d°: ", i + 1);
        scanf("%f", &alunos[i].nota1);
    printf("Digite a segunda nota do aluno %d°: ", i + 1);
    scanf("%f", &alunos[i].nota2);
        alunos[i].media = calcularMedia(alunos[i]);
    printf("Média do aluno %d: %.2f\n", i + 1, alunos[i].media);
    }

    printf("\n");

    for (i = 0; i < 5; i++) {
        printf("O aluno %s está ", alunos[i].nome);
        if (alunos[i].media >= 7.0) {
            printf("aprovado.\n");
        } else {
            printf("reprovado.\n");
        }
    }

    return 0;
}

