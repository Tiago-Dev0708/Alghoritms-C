#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char segmento[50];
    float precoCompra;
    float precoVenda;
    char unidadeComercial[10];
    int quantidadeEstoque;
} Produto;

Produto *create_produto(char nome[], char segmento[], float precoCompra, float precoVenda, char unidadeComercial[], int quantidadeEstoque) {
    Produto *produto = (Produto *) malloc(sizeof(Produto));
    strcpy(produto->nome, nome);
    strcpy(produto->segmento, segmento);
    produto->precoCompra = precoCompra;
    produto->precoVenda = precoVenda;
    strcpy(produto->unidadeComercial, unidadeComercial);
    produto->quantidadeEstoque = quantidadeEstoque;
    return produto;
}

int main() {

    Produto *produtos = (Produto *) malloc(10 * sizeof(Produto));
    char nome[50];
    char segmento[50];
    float precoCompra;
    float precoVenda;
    char unidadeComercial[10];
    int quantidadeEstoque;

    printf("Digite os dados dos produtos que deseja cadastrar\n");
    printf("_________________________________________________________\n\n");
    for (int i = 0; i < 10; i++) {
        printf("Digite o nome do produto %d: ", i + 1);
        scanf(" %[^\n]", nome);
        printf("Digite o segmento do produto %d: ", i + 1);
        scanf("%s", segmento);
        printf("Digite o preco de compra do produto %d: ", i + 1);
        scanf("%f", &precoCompra);
        printf("Digite o preco de venda do produto %d: ", i + 1);
        scanf("%f", &precoVenda);
        printf("Digite a unidade comercial do produto %d: ", i + 1);
        scanf("%s", unidadeComercial);
        printf("Digite a quantidade em estoque do produto %d: ", i + 1);
        scanf("%d", &quantidadeEstoque);

        produtos[i] = *create_produto(nome, segmento, precoCompra, precoVenda, unidadeComercial, quantidadeEstoque);
    }
    printf("\n\n");
    printf("Cadastro realizado com sucesso!\n");
    printf("_________________________________________________________\n\n");
 


    printf("--------------------------Relatório de produtos---------------------------\n\n");

    for (int i = 0; i < 10; i++) {
        printf("_________________________________________________________\n");
        printf("Produto %d:\n", i + 1);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Segmento: %s\n", produtos[i].segmento);
        printf("Preco de compra: %.2f\n", produtos[i].precoCompra);
        printf("Preco de venda: %.2f\n", produtos[i].precoVenda);
        printf("Unidade comercial: %s\n", produtos[i].unidadeComercial);
        printf("Quantidade em estoque: %d\n", produtos[i].quantidadeEstoque);
        printf("_________________________________________________________\n");
    }

    free(produtos);

    return 0;

}