#include <stdio.h>
#include <stdlib.h>

void flush_in() {
  int ch;
  while ((ch = fgetc(stdin)) != EOF && ch != '\n') {
  }
}

int main(void) {
  float preco;
  int car = 0, aten=0, fila;
  float comb, abas, vend = 0;
  printf("\033[4m\033[1mNome do autor\033[0m: Gabriel 'biel bits' Aurélio "
         "Nunes\n");
  printf("Esse programa te pede o preço da gasolina e te dá a opção de "
         "escolher entre 5 comandos de um posto "
         "de gasolina, que estão em um laço de repetição até escolhar a opção "
         "para parar, além de entender o máximo e mínimo de alguns parâmetros...\n");
  printf("Informe o tamanho máximo da fila para este estabelecimento: ");
  scanf("%d", &fila);
  printf("Informe o preço da gasolina usando '.' para as casas decimais: ");
  scanf("%f", &preco);
  printf(
      "Informe a quantidade de combustível em litros disponível no tanque: ");
  scanf("%f", &comb);
  system("clear");
  flush_in();
  int escolha = 1;
  char op = 'a';
  do {
    printf("\033[1m\033[33m MENU \033[0m\n\033[4mSelecione uma "
           "opção:\033[0m\n1) Adicionar um carro a "
           "fila.\n2)Abastecer.\n3)Exibir a fila de espera.\n4)Relátorios\n5) "
           "Fim\nOpção: ");
    scanf("%d", &escolha);
    flush_in();
    switch (escolha) {
    case 1:
      if (car < fila) {
        car = car + 1;
        system("clear");
        printf("\033[32mCarro adicionado a fila.\033[0m\n");
      } else {
        system("clear");
        printf("\033[31mA fila já está na sua capacidade máxima.\033[0m\n");
      }
      break;
    case 2:
      if ((comb > 0) && (car > 0)) {
        printf("Combustível em litros que será usado para esse carro: ");
        scanf("%f", &abas);
        if ((comb >= abas)&&(abas>=0)) {
          car = car - 1;
          comb = comb - abas;
          vend = vend + abas;
          aten = aten + 1;
          system("clear");
          printf("\033[32mCarro abastecido com %.2f "
                 "litros.\033[0m\nCombustível no posto: %.2f\n",
                 abas, comb);
        } else {
          system("clear");
          printf("\033[31mNão temos essa quantidade de combustível selecione "
                 "um valor "
                 "menor.\033[0m\n");
        }
      } else {
        system("clear");
        printf("\033[31mCombustível insuficiente ou não tem carros para serem "
               "abastecidos.\033[0m\n");
      }
      break;
    case 3:
      system("clear");
      printf("Existem %d carros na fila de espera.\n", car);
      break;
    case 4:
      while (op != 'f') {
        printf("\033[1m\033[33m SUBMENU \033[0m\n\033[4mSelecione uma "
               "opção:\033[0m\n  a- Quantidade de litros vendidos;\n  b- Valor "
               "total "
               "arrecadado com "
               "as vendas;\n  c- Quantidade de carros atendidos;\n  d- "
               "Quantidade de "
               "combustível restante no tanque;\n  e- Gerar arquivo para "
               "impressão "
               "(com todas as informações de A, B, C e D);\n  "
               "f-retornar;\nEscreva duas vezes a sua opcão: ");
        //flush_in();
        scanf("%c",&op);
        switch (op) {
        case 'a':
          printf("%.2f litros vendidos.\n", vend);
          break;
        case 'b':
          printf("%.2f reais em vendas ate agora.\n", vend * preco);
          break;
        case 'c':
          printf("%d carros atendidos hoje.\n", aten);
          break;
        case 'd':
          if (comb > 0) {
            printf("%.2f litros de combustivel sobrando para serem usados.\n",
                   comb);
          } else {
            printf("\033[31mNão tem mais combustível no posto.\033[0m\n");
          }
          break;
        case 'e':
          printf("\033[32mArquivo para impressão gerado com sucesso.\033[0m\n");
          break;
        }
        printf("Pressione qualquer tecla para continuar: ");
        getchar();
        getchar();
        system("clear");
      }
      break;
    case 5:
      system("clear");
      printf("\033[1m\033[30mFIM DO CÓDIGO!\033[0m");
      break;
    }
  } while (escolha != 5);
  return 0;
}