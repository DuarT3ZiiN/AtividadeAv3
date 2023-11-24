#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char descricao[50];
    int quantidade;
    float valor;
} Produto;

typedef struct Node
{
    Produto produto;
    struct Node *proximo;
} Node;

Node *inicializarLista()
{
    return NULL;
}

Node *adicionarProduto(Node *lista)
{
    Produto novoProduto;

    printf("Digite o código do produto: ");
    scanf("%d", &novoProduto.codigo);

    printf("Digite a descrição do produto: ");
    scanf("%s", novoProduto.descricao);

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &novoProduto.quantidade);

    printf("Digite o valor do produto: ");
    scanf("%f", &novoProduto.valor);

    Node *novoNo = (Node *)malloc(sizeof(Node));
    novoNo->produto = novoProduto;
    novoNo->proximo = lista;

    return novoNo;
}

void relatorioProdutos(Node *lista)
{
    printf("Relatório de Produtos:\n");
    while (lista != NULL)
    {
        printf("Código: %d\n", lista->produto.codigo);
        printf("Descrição: %s\n", lista->produto.descricao);
        printf("Quantidade: %d\n", lista->produto.quantidade);
        printf("Valor: %.2f\n\n", lista->produto.valor);
        lista = lista->proximo;
    }
}

void pesquisarProduto(Node *lista)
{
    int codigo;
    printf("Digite o código do produto a ser pesquisado: ");
    scanf("%d", &codigo);

    while (lista != NULL)
    {
        if (lista->produto.codigo == codigo)
        {
            printf("Produto encontrado:\n");
            printf("Código: %d\n", lista->produto.codigo);
            printf("Descrição: %s\n", lista->produto.descricao);
            printf("Quantidade: %d\n", lista->produto.quantidade);
            printf("Valor: %.2f\n", lista->produto.valor);
            return;
        }
        lista = lista->proximo;
    }

    printf("Produto não encontrado.\n");
}

Node *removerProduto(Node *lista)
{
    int codigo;
    printf("Digite o código do produto a ser removido: ");
    scanf("%d", &codigo);

    Node *atual = lista;
    Node *anterior = NULL;

    while (atual != NULL)
    {
        if (atual->produto.codigo == codigo)
        {
            if (anterior == NULL)
            {

                Node *proximo = atual->proximo;
                free(atual);
                return proximo;
            }
            else
            {

                anterior->proximo = atual->proximo;
                free(atual);
                return lista;
            }
        }
        anterior = atual;
        atual = atual->proximo;
    }

    printf("Produto não encontrado.\n");
    return lista;
}

void liberarLista(Node *lista)
{
    while (lista != NULL)
    {
        Node *proximo = lista->proximo;
        free(lista);
        lista = proximo;
    }
}

int main()
{
    Node *lista = inicializarLista();
    char opcao;

    do
    {
        printf("\nEscolha uma opção:\n");
        printf("1. Adicionar produto\n");
        printf("2. Relatório de produtos\n");
        printf("3. Pesquisar produto\n");
        printf("4. Remover produto\n");
        printf("0. Sair\n");
        scanf(" %c", &opcao);

        switch (opcao)
        {
        case '1':
            lista = adicionarProduto(lista);
            break;
        case '2':
            relatorioProdutos(lista);
            break;
        case '3':
            pesquisarProduto(lista);
            break;
        case '4':
            lista = removerProduto(lista);
            break;
        case '0':
            printf("Saindo do programa. Até mais!\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != '0');

    liberarLista(lista);

    return 0;
}