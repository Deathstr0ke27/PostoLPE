#include <stdio.h>

int main(void) {
  printf("Nome do autor: Gabriel 'biel bits' Aurélio Nunes\n");
  printf("Esse programa lê o valor do combustível e o tamanho da fila de "
         "espera do posto de gaasolina...\n");
  printf("Informe o valor do combustivel:");
  float preco;
  int fila;
  scanf("%f", &preco);
  printf("Informe o tamanho da fila que o estabelecimento suportará:");
  scanf("%d", &fila);
  return 0;
}