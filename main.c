#include <stdio.h>
#include <stdlib.h>

#define DEFAULT "\033[0m"
#define BOLD "\033[1m"
#define UNDERLINED "\033[4m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

struct Tcarro{
  char marca[22];
  char modelo[22];
  int ano;
  char cor[22];
};

void flush_in() {
  int ch;
  while ((ch = fgetc(stdin)) != EOF && ch != '\n') {
  }
}
void Inicio() {
  printf("%s%sNome do autor%s: Gabriel 'biel bits' Aurélio "
         "Nunes\n", UNDERLINED, BOLD, DEFAULT);
  printf("%sEsse programa te pede o preço da gasolina e te dá a opção de "
         "escolher entre 5 comandos de um posto de gasolina, que estão em um "
         "laço de repetição até escolhar a opção para parar, além de entender "
         "o máximo e mínimo de alguns parâmetros...%s\n", BLUE, DEFAULT);
}
void Menu() {
  printf("%s%s MENU %s\n%sSelecione uma opção:%s\n1)Adicionar um carro a fila.\n2)Abastecer.\n3)Exibir a fila de espera e a quantidade de gasolina disponível.\n4)Relátorios\n5)Lavar o carro\n6)Fim\n%sOpção:%s ", BOLD, YELLOW, DEFAULT, UNDERLINED, DEFAULT, UNDERLINED, DEFAULT);
}

void FilEsp(int car, float comb) {
  system("clear");
  printf("Existem %d carros na fila de espera.\n", car);
  printf("O posto tem %.2f litros de gasolina disponível.\n",comb);
}
void LitVend(float vend) { 
  printf("%.2f litros vendidos.\n", vend); 
}

void Lucros(float vend, float preco, int lucro) {
  printf("%.2f reais em vendas até agora.\n", vend * preco); 
  printf("%d reais em carros lavados até agora\n", lucro);
}

void CombRest(float comb) {
  if (comb > 0) {
    printf("%.2f litros de combustivel sobrando para serem usados.\n", comb);
  } else {
    printf("%sNão tem mais combustível no posto.%s\n", RED, DEFAULT);
  }
}
void Imp() {
  printf("%sArquivo para impressão gerado com sucesso.%s\n", GREEN, DEFAULT);
}

void SubMenu() {
  printf(" %s%sSUBMENU%s\n%sSelecione uma "
         "opção:%s\n  a- Quantidade de litros vendidos;\n  b- Valor "
         "total "
         "arrecadado com "
         "as vendas;\n  c- Quantidade de carros atendidos;\n  d- "
         "Quantidade de "
         "combustível restante no tanque;\n  e- Gerar arquivo para "
         "impressão "
         "(com todas as informações de A, B, C e D);\n  "
         "f-retornar;\n%sEscreva duas vezes a sua opcão:%s ", UNDERLINED, YELLOW, DEFAULT, UNDERLINED, DEFAULT, UNDERLINED, DEFAULT);
}
int MenuLC(int lc) {
  printf("Bem-vindo ao %s%sLava-car do Biel%s, o preço da lavagem é de 100R$ para "
         "carros pequenos, 150R$ para carros médios e 200R$ para carros "
         "grandes.\nEscolha o tamanho do carro ou para retornar: "
         "\n1) Pequeno \n2) Médio \n3) Grande \n4)Retornar\n%sOpção:%s ", UNDERLINED, YELLOW, DEFAULT, UNDERLINED, DEFAULT);
  scanf("%d", &lc);
  return lc;
}
int LimpCar(int car) {
  car--;
  printf("%sSeu carro está limpo agora!%s\n", GREEN, DEFAULT);
  return car;
}

void FilVaz(){ 
  printf("%sNão tem nenhum carro na fila!%s\n", RED, DEFAULT); 
}

void TcarroAdd(int c, struct Tcarro fil[]) {
  printf("Escreva a marca do carro: ");
  fgets(fil[c].marca, 22, stdin);
  fil[c].marca[strcspn(fil[c].marca, "\n")] = 0;
  printf("Escreva o modelo do carro: ");
  fgets(fil[c].modelo, 22, stdin);
  fil[c].modelo[strcspn(fil[c].modelo, "\n")] = 0;
  printf("Escreva a cor do carro: ");
  fgets(fil[c].cor, 22, stdin);
  fil[c].cor[strcspn(fil[c].cor, "\n")] = 0;
  printf("Escreva o ano de fabricamento do carro: ");
  scanf("%d", &fil[c].ano);
  system("clear");
  printf("%sCarro adicionado à fila!%s",GREEN, DEFAULT);
}

void TCarroAtendidos(int a, struct Tcarro at[]) {
  printf("Carros atendidos:\n");
  for (int i=0; i<a; i++) {
    printf("Carro n° %d", i);
    printf("\nMarca: %s\nModelo: %s\nCor: %s\nAno: %d\n", at[i].marca, at[i].modelo, at[i].cor, at[i].ano);
  }
}

void Atendidos(int a, struct Tcarro at[], struct Tcarro f[]) {
  at[a] = f[0];
  f[0] = f[1];
  f[1] = f[2];
}

int main(void) {
  struct Tcarro fil[3], atendidos[22];
  float preco;
  int car = 0, aten = 0, limp = 0, lucro = 0;
  float comb, abas, vend = 0;
  Inicio();
  printf("O tamanho da fila foi setado para 3 e o número de carros atendidos tem um máximo de 22.");
  printf("\nInforme o preço da gasolina usando '.' para as casas decimais: ");
  scanf("%f", &preco);
  printf("Informe a quantidade de combustível em litros disponível no tanque: ");
  scanf("%f", &comb);
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
      if(car<=2){
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
          Atendidos(aten,atendidos, fil);
          car--;
          comb = comb - abas;
          vend = vend + abas;
          aten++;
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
            Atendidos(aten,atendidos, fil);
            car--;
            aten++;
            
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
            Atendidos(aten,atendidos, fil);
            car--;
            aten++;
            
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
            Atendidos(aten,atendidos, fil);
            car--;
            aten++;
            
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