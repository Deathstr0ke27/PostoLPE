#include <stdio.h>
#include <stdlib.h>

void flush_in() {
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n') {
    }
}
void Inicio() {
    printf("\033[4m\033[1mNome do autor\033[0m: Gabriel 'biel bits' Aurélio Nunes\n");
    printf("Esse programa te pede o preço da gasolina e te dá a opção de escolher entre 5 comandos de um posto de gasolina, que estão em um laço de repetição até escolhar a opção para parar, além de entender o máximo e mínimo de alguns parâmetros...\n");
}
void Menu() {
    printf("\033[1m\033[33m MENU \033[0m\n\033[4mSelecione uma opção:\033[0m\n1) Adicionar um carro a fila.\n2)Abastecer.\n3)Exibir a fila de espera.\n4)Relátorios\n5) Lavar o carro\n6) Fim\nOpção: ");
}
int CarAdd(int fila, int car) {
    if (car < fila) {
        car++;
        system("clear");
        printf("\033[32mCarro adicionado a fila.\033[0m\n");
    } else {
        system("clear");
        printf("\033[31mA fila já está na sua capacidade máxima.\033[0m\n");
    }
    return car;
}
void FilEsp(int car) {
  system("clear");
  printf("Existem %d carros na fila de espera.\n", car);
}
void LitVend(float vend) {
  printf("%.2f litros vendidos.\n", vend);
}
void Lucros(float vend, float preco, int lucro) {
  printf("%.2f reais em vendas até agora.\n", vend * preco);
  printf("%d reais em carros lavados até agora\n", lucro);
}
void Atend(int aten, int limp) {
  printf("%d carros atendidos hoje.\n", aten);
  printf("%d carros lavados hoje.\n", limp);
}
void CombRest(float comb) {
  if (comb > 0) {
  printf("%.2f litros de combustivel sobrando para serem usados.\n", comb);
  } else {
  printf("\033[31mNão tem mais combustível no posto.\033[0m\n");
  }
}
void Imp() {
  printf("\033[32mArquivo para impressão gerado com sucesso.\033[0m\n");
}

void SubMenu() {
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
}
int MenuLC(int lc) {
  printf("Bem-vindo ao Lava-car do Biel, o preço da lavagem é de 100R$ para carros pequenos, 150R$ para carros médios e 200R$ para carros grandes.\nEstamos oferecendo um desconto de 30R$ para os primeiros 10 clientes do dia.\nEscolha o tamanho do carro ou para retornar: \n1) Pequeno \n2) Médio \n3) Grande \n4)Retornar\nOpção: ");
  scanf("%d",&lc);
  return lc;
}
int LimpCar(int car) {
  car--;
  printf("\033[32mSeu carro está limpo agora!\033[0m\n");
  return car;
}
void FilVaz() {
  printf("\033[31mNão tem nenhum carro na fila!\033[0m\n");
}

int main(void) {
    float preco;
    int car = 0, aten = 0, limp = 0, lucro=0, fila;
    float comb, abas, vend = 0;
    Inicio();
    printf("Informe o tamanho máximo da fila para este estabelecimento: ");
    scanf("%d", &fila);
    printf("Informe o preço da gasolina usando '.' para as casas decimais: ");
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
                car = CarAdd(fila, car);
                break;
            case 2:
                if ((comb > 0) && (car > 0)) {
                    printf("Combustível em litros que será usado para esse carro: ");
                    scanf("%f", &abas);
                    if ((comb >= abas)&&(abas>=0)) {
                        car--;
                        comb = comb - abas;
                        vend = vend + abas;
                        aten++;
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
                FilEsp(car);
                break;
            case 4:
                op='a';
                system("clear");
                while (op != 'f') {
                    SubMenu();
                    //flush_in();
                    scanf("%c",&op);
                    switch (op) {
                        case 'a':
                            LitVend(vend);
                            break;
                        case 'b':
                            Lucros(vend, preco, lucro);
                            break;
                        case 'c':
                            Atend(aten, limp);
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
                switch(lc) {
                  case 1:
                    system("clear");
                    if(car>0){
                      car = LimpCar(car);
                      lucro = lucro + 100;
                      limp++;
                    }else{
                      FilVaz();
                    }
                    break;
                  case 2:
                    system("clear");
                    if(car>0){
                      car = LimpCar(car);
                      lucro = lucro + 150;
                      limp++;
                    }else{
                      FilVaz();
                    }
                    break;
                  case 3:
                    system("clear");
                    if(car>0){
                      car = LimpCar(car);
                      lucro = lucro + 200;
                      limp++;
                    }else{
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
                printf("\033[1m\033[30mFIM DO CÓDIGO!\033[0m");
                break;
        }
    }
    return 0;
}