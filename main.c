#include <stdio.h>
#include <stdlib.h>
#include "header.h"


int main(void) {
  struct Tcarro *fil, *atendidos;
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
          TCarroAtendidos(aten, atendidos);
          break;
        case 'd':
          CombRest(comb);
          break;
        case 'e':
          Imp();
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
            Atendidos(aten, tam, atendidos, fil);
            car--;
            aten++;
            atendidos = (struct Tcarro *) realloc (atendidos, (aten + 1) * sizeof(struct Tcarro));
            lucro = lucro + 100;
            limp++;
          } else {
            FilVaz();
          }
          break;
        case 2:
          system("clear");
          if (car > 0) {
            //car = LimpCar(car);
            printf("%sSeu carro está limpo agora!%s\n", GREEN, DEFAULT);
            Atendidos(aten, tam, atendidos, fil);
            car--;
            aten++;
            atendidos = (struct Tcarro *) realloc (atendidos, (aten + 1) * sizeof(struct Tcarro));
            lucro = lucro + 150;
            limp++;
          } else {
            FilVaz();
          }
          break;
        case 3:
          system("clear");
          if (car > 0) {
            //car = LimpCar(car);
            printf("%sSeu carro está limpo agora!%s\n", GREEN, DEFAULT);
            Atendidos(aten, tam, atendidos, fil);
            car--;
            aten++;
            atendidos = (struct Tcarro *) realloc (atendidos, (aten + 1) * sizeof(struct Tcarro));
            lucro = lucro + 200;
            limp++;
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