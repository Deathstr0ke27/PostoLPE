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
};
float MaiorZero(float x) {
  while(x<=0){
    printf("Informe um valor maior que 0: ");
    scanf("%f", &x);
  }
  return x;
};
void Inicio() {
  printf("%s%sNome do autor%s: Gabriel 'biel bits' Aurélio "
         "Nunes\n", UNDERLINED, BOLD, DEFAULT);
  printf("%sEsse programa te pede o preço da gasolina e te dá a opção de "
         "escolher entre 5 comandos de um posto de gasolina, que estão em um "
         "laço de repetição até escolhar a opção para parar, além de entender "
         "o máximo e mínimo de alguns parâmetros...%s\n", BLUE, DEFAULT);
};



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
  printf("%.2f reais em combustível até agora.\n", vend * preco); 
  printf("%d reais em carros lavados até agora\n", lucro);
}

void CombRest(float comb) {
  if (comb > 0) {
    printf("%.2f litros de combustivel sobrando para serem usados.\n", comb);
  } else {
    printf("%sNão tem mais combustível no posto.%s\n", RED, DEFAULT);
  }
}
void Filas(int a, struct Tcarro at[], FILE *f) {
  for (int i=0; i<a; i++) {
    fprintf(f, "Carro n° %d", i);
    fprintf(f, "\nMarca: %s", at[i].marca);
    fprintf(f, "\nModelo: %s", at[i].modelo);
    fprintf(f, "\nCor: %s", at[i].cor);
    fprintf(f, "\nAno: %d\n", at[i].ano);
  }
}
int Impressao(float vend, float preco, float comb, int lucro, int aten, int tam, struct Tcarro atendidos[], int limp, struct Tcarro lavados[]) {
  FILE *txt;
  txt = fopen("relatorio.txt", "w");
  if (txt == NULL) {
    printf("não foi possível criar arquivo de relatório");

    return 1;
  };
  fprintf(txt, "Litros vendidos: %.2f\n", vend);
  fprintf(txt, "Valor total arrecadado: R$ %.2f\n", preco * vend);
  fprintf(txt, "Atendidos: %d carro(s)\n", aten);
  fprintf(txt, "Gasolina na bomba: %.2f\n", comb);
  fprintf(txt, "Caixa atual combustível: R$ %.2f\nCaixa atual carros lavados: R$ %d\n", vend * preco, lucro);
  fprintf(txt, "Tamanho maximo da fila: %d carro(s)\n", tam);
  fprintf(txt, "Preço da Gasolina: R$ %.2f/Litro\n", preco);
  fprintf(txt, "\nFILA DE CARROS ABASTECIDOS:\n");
  Filas(aten, atendidos, txt);
  fprintf(txt, "\nFILA DE CARROS LAVADOS:\n");
  Filas(limp, lavados, txt);
  fclose(txt);
  return 0;
}

void Imprimir(float vend, float preco, float comb, int lucro, int aten, int tam, struct Tcarro at[], int l, struct Tcarro lv[]) {
  printf("\n%sLitros vendidos: %.2f%s\n", BLUE, vend ,DEFAULT);
  printf("%sValor total arrecadado: R$ %.2f%s\n", BLUE, preco * vend, DEFAULT);
  printf("%sAtendidos: %d%s carro(s)\n", BLUE, aten, DEFAULT);
  printf("%sGasolina no tanque: %.2f%s\n\n", BLUE, comb, DEFAULT);
  printf("%sTamanho maximo da fila: %d %scarro(s)\n", BLUE, tam, DEFAULT);
  printf("%sPreço da Gasolina: R$ %.2f litro%s\n", BLUE, preco, DEFAULT);
  printf("%sCaixa atual combustível: R$ %.2f\nCaixa atual carros lavados: R$ %d%s\n",BLUE, vend * preco, lucro, DEFAULT);

  printf("Carros abastecidos:\n");
  for (int i=0; i<aten; i++) {
    printf("Carro n° %d", i);
    printf("\nMarca: %s\nModelo: %s\nCor: %s\nAno: %d\n", at[i].marca, at[i].modelo, at[i].cor, at[i].ano);
  }

  printf("Carros lavados:\n");
  for (int i=0; i<l; i++) {
    printf("Carro n° %d", i);
    printf("\nMarca: %s\nModelo: %s\nCor: %s\nAno: %d\n", lv[i].marca, lv[i].modelo, lv[i].cor, lv[i].ano);
  }

  FILE *fp = fopen("registro.txt", "w");

      //fprintf, e não printf!
  fprintf(fp, "Litros vendidos: %.2f\n", vend);
  fprintf(fp, "Valor total arrecadado: R$ %.2f\n", preco * vend);
  fprintf(fp, "Atendidos: %d carro(s)\n", aten);
  fprintf(fp, "Gasolina na bomba: %.2f\n", comb);
  fprintf(fp, "Caixa atual combustível: R$ %.2f\nCaixa atual carros lavados: R$ %d\n", vend * preco, lucro);
  fprintf(fp, "Tamanho maximo da fila: %d carro(s)\n", tam);
  fprintf(fp, "Preço da Gasolina: R$ %.2f/Litro\n", preco);
  fclose(fp);
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
void Atendidos(int a,int tam ,struct Tcarro at[], struct Tcarro f[]) {
  at[a] = f[0];
  for (int i=1; i<tam; i++) {
    f[i-1] = f[i];
    }
}