#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int matricula;
    char nome[50];
    char curso[50];
    char endereco[100];
    bool ativo;     
} Aluno;

Aluno *create_aluno(int matricula, char nome[50], char curso[50], char endereco[100], bool ativo){
    Aluno *aluno = (Aluno *) malloc(sizeof(Aluno));
    aluno->matricula = matricula;
    strcpy(aluno->nome, nome);
    strcpy(aluno->curso, curso);
    strcpy(aluno->endereco, endereco);
    aluno->ativo = ativo;
    return aluno;
}

Aluno *MatricularAluno(Aluno *alunos, int *size){

    int count, add, matricula;
    char nome[50];
    char curso[50];
    char endereco[100];
    bool ativo;
    
    printf("Deseja adicionar quantos Alunos: ");
    scanf("%d", &add);

    alunos = (Aluno *) realloc(alunos, (*size + add)*sizeof(Aluno));
    if(alunos){
        printf("Digite os dados do aluno que deseja cadastrar\n\n");
        for(count = 0; count < add ; count++ ){
            printf("Digite a matricula do aluno %d: ", count + 1);
            scanf("%d", &matricula);
            printf("Digite o nome do aluno %d: ", count + 1);
            scanf("%s", nome);
            printf("Digite o curso do aluno %d: ", count + 1);
            scanf("%s", curso);
            printf("Digite o endereco do aluno %d: ", count + 1);
            scanf("%s", endereco);
            alunos->ativo = true;

            alunos[count+*size] = *create_aluno(matricula, nome, curso, endereco, ativo);
    }
        *size += add;
        printf("O(s) Aluno(s) foram cadastrado(s) com sucesso!\n");
    }
    else{
        printf("Espaço em memória insuficiente\n");
        free(alunos);
        exit(1);
    }
    return alunos;
}

void ImprimirAtivos(Aluno *alunos, int size){
    printf("-----------------ALUNOS COM MATRICULA ATIVA-----------------\n");
    for(int i = 1; i < size; i++){
        if(alunos[i].ativo == true){
            printf("INFORMAÇÕES DO ALUNO\n\n");
            printf("Matricula: %d", alunos[i].matricula);
            printf("\n");
            printf("Nome: %s", alunos[i].nome);
            printf("\n");
            printf("Curso: %s", alunos[i].curso);
            printf("\n");
            printf("Endereço: %s", alunos[i].endereco);
            printf("\n");
        }
    }
}

void RemoverAluno(Aluno *alunos, int size) {
    int matcmp;
    printf("Digite a matricula do aluno que deseja remover: ");
    scanf("%d", &matcmp);
    for(int i = 1; i < size; i++){
        if(alunos[i].matricula == matcmp){
            alunos[i].ativo = false;
        }
    }
}


void AlterarCurso(Aluno *alunos, int size){
    int matcmp;
    char curso[50];
    printf("Digite a matricula do aluno que deseja alterar o curso: ");
    scanf("%d", &matcmp);
    for(int i = 1; i < size; i++){
        if(alunos[i].matricula == matcmp){
            printf("Digite o novo curso: ");
            scanf("%s", curso);
            strcpy(alunos[i].curso, curso);
            printf("O curso foi alterado!");
        }
    }
}

void AlterarEndereco(Aluno *alunos, int size){
    int matcmp;
    char endereco[100];
    printf("Digite a matricula do aluno que deseja alterar o endereco: ");
    scanf("%d", &matcmp);
    for(int i = 1; i < size; i++){
        if(alunos[i].matricula == matcmp){
            printf("Digite o novo endereco: ");
            scanf("%s", endereco);
            strcpy(alunos[i].endereco, endereco);
            printf("O endereço foi alterado!");
        }
    }
}

int main (){

    int escolha, size;
    Aluno *alunos = NULL;

    while(1){

        printf("-----------------FACULDADE-----------------\n0 - Sair\n1 - Cadastrar Aluno\n2 - Remover Aluno\n3 - Alterar Curso\n4 - Alterar Endereço\n5 - Relatório de Alunos Ativos\nDigite a opcao desejada: \n");
        scanf("%d", &escolha);
        if(escolha == 0){
            break;
        }
        else if(escolha == 1){
            alunos = MatricularAluno(alunos, &size);
        }
        else if(escolha == 2){
            RemoverAluno(alunos, size);
        }
        else if(escolha ==3){
            AlterarCurso(alunos, size);
        }
        else if(escolha == 4){
            AlterarEndereco(alunos, size);
        }
        else if(escolha == 5){
            ImprimirAtivos(alunos, size);
        }
        else{
            printf("Opcao invalida\n");
        }
        printf("\n\n");

    }
    printf("Encerrando o sistema\n");
    free(alunos);
    return 0;


}




