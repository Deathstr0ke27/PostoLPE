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
void flush_in();
float MaiorZero(float x);
void Inicio();
void Menu();
void FilEsp(int car, float comb);
void LitVend(float vend);
void Lucros(float vend, float preco, int lucro);
void CombRest(float comb);
void Imp();
void Filas(int a, struct Tcarro at[], FILE *f);
int Impressao(float vend, float preco, float comb, int lucro, int aten, int tam, struct Tcarro Atendidos[], int limp, struct Tcarro Lavados[]);
void Imprimir(float vend, float preco, float comb, int lucro, int aten, int tam, struct Tcarro at[], int l, struct Tcarro lv[]);
void SubMenu();
int MenuLC(int lc);
int LimpCar(int car);
void FilVaz();
void TcarroAdd(int c, struct Tcarro fil[]);
void Atendidos(int a,int tam ,struct Tcarro at[], struct Tcarro f[]);