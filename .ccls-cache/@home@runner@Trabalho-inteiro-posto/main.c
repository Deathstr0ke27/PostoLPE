#include <stdio.h>
#include <stdlib.h>
#include "header.h"


int main(void) {
  struct Tcarro *fil, *atendidos, *lavados;
  float preco;
  int car = 0, aten = 0, limp = 0, lucro = 0, tam;
  float comb, abas, vend = 0;
  Inicio();
  printf("\nInforme o preço da gasolina usando '.' para as casas decimais: ");
  scanf("%f", &preco);
  preco = MaiorZero(preco);
  printf("Informe a quantidade de combustível em litros disponível no tanque: ");
  scanf("%f", &comb);
  comb = MaiorZero(comb);
  printf("Informe o tamanho da fila de carros: ");
  scanf("%d",&tam);
  while(tam<=0){
    printf("Informe um valor maior que 0 para o tamanho da fila: ");
    scanf("%d", &tam);
  };
  fil = (struct Tcarro *) malloc (tam * sizeof(struct Tcarro));
  atendidos = (struct Tcarro *) malloc (1 * sizeof(struct Tcarro));
  lavados = (struct Tcarro *) malloc (1 * sizeof(struct Tcarro));
  system("clear");
  flush_in();
  int escolha = 1, lc = 1;
  char op = 'a';
  while (escolha != 6) {
    Menu();
    scanf("%d", &escolha);
    flush_in();
    switch (escolha) {
    case 1:
      if(car<tam){
        TcarroAdd(car, fil);
        car++;
        } else{
            system("clear");
            printf("%sA fila já está em capacidade máxima, volte outra hora!%s\n", RED, DEFAULT);
        };
      break;
    case 2:
      if ((comb > 0) && (car > 0)) {
        printf("Combustível disponível: '%.2f'\nQuanto vai querer usar para abastecer em litros esse carro: ", comb);
        scanf("%f", &abas);
        if ((comb >= abas) && (abas >= 0)) {
          Atendidos(aten, tam, atendidos, fil);
          car--;
          comb = comb - abas;
          vend = vend + abas;
          aten++;
          atendidos = (struct Tcarro *) realloc (atendidos, (aten + 1) * sizeof(struct Tcarro));
          system("clear");
          printf("%sCarro abastecido com %.2f litros.%s\n%sCombustível no posto: %.2f%s\n", GREEN, abas, DEFAULT, BLUE ,comb, DEFAULT);
        } else {
          system("clear");
          printf("%sNão temos essa quantidade de combustível, você ainda "
                 "está na fila se quiser sair selecione 0 litros e se quiser "
                 "abastecer selecione um valor menor ou igual a %.2f.%s\n", RED,
                 comb, DEFAULT);
        }
      } else {
        system("clear");
        printf("%sCombustível insuficiente ou não tem carros para serem "
               "abastecidos. Por favor verifique esses parâmetros.%s\n", RED, DEFAULT);
      }
      break;
    case 3:
      FilEsp(car,comb);
      printf("Carros na fila:\n");
      Filas(car, fil, stdout);
      break;
    case 4:
      op = 'a';
      system("clear");
      while (op != 'f') {
        SubMenu();
        // flush_in();
        scanf("%c", &op);
        switch (op) {
        case 'a':
          LitVend(vend);
          break;
        case 'b':
          Lucros(vend, preco, lucro);
          break;
        case 'c':
          printf("\nCarros Abastecidos\n");
          Filas(aten, atendidos, stdout);
          printf("\nCarros Lavados\n");
          Filas(limp, lavados, stdout);
          break;
        case 'd':
          CombRest(comb);
          break;
        case 'e':
          printf("Litros vendidos: %.2f\n", vend);
          printf("Valor total arrecadado: R$ %.2f\n", preco * vend);
          printf("Atendidos: %d carro(s)\n", aten);
          printf("Gasolina na bomba: %.2f\n", comb);
          printf("Caixa atual combustível: R$ %.2f\nCaixa atual carros lavados: R$ %d\n", vend * preco, lucro);
          printf("Tamanho maximo da fila: %d carro(s)\n", tam);
          printf("Preço da Gasolina: R$ %.2f/Litro\n", preco);
          printf("\nFILA DE CARROS ABASTECIDOS:\n");
          Filas(aten, atendidos, stdout);
          printf("\nFILA DE CARROS LAVADOS:\n");
          Filas(limp, lavados, stdout);
          Impressao(vend, preco, comb, lucro, aten, tam, atendidos, limp, lavados);
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
      lc = 1;
      while (lc != 4) {
        lc = MenuLC(lc);
        switch (lc) {
        case 1:
          system("clear");
          if (car > 0) {
            //car = LimpCar(car);
            printf("%sSeu carro está limpo agora!%s\n", GREEN, DEFAULT);
            Atendidos(limp, tam, lavados, fil);
            car--;
            limp++;
            lavados = (struct Tcarro *) realloc (lavados, (limp + 1) * sizeof(struct Tcarro));
            lucro = lucro + 100;
          } else {
            FilVaz();
          }
          break;
        case 2:
          system("clear");
          if (car > 0) {
            //car = LimpCar(car);
            printf("%sSeu carro está limpo agora!%s\n", GREEN, DEFAULT);
            Atendidos(limp, tam, lavados, fil);
            car--;
            limp++;
            lavados = (struct Tcarro *) realloc (lavados, (limp + 1) * sizeof(struct Tcarro));
            lucro = lucro + 150;
          } else {
            FilVaz();
          }
          break;
        case 3:
          system("clear");
          if (car > 0) {
            //car = LimpCar(car);
            printf("%sSeu carro está limpo agora!%s\n", GREEN, DEFAULT);
            Atendidos(limp, tam, lavados, fil);
            car--;
            limp++;
            lavados = (struct Tcarro *) realloc (lavados, (limp + 1) * sizeof(struct Tcarro));
            lucro = lucro + 200;
          } else {
            FilVaz();
          }
          break;
        case 4:
          system("clear");
          break;
        }
      }
      break;
    case 6:
      system("clear");
      printf("%s%sFIM DO CÓDIGO!%s", BOLD, BLACK, DEFAULT);
      break;
    }
  }
  return 0;
}