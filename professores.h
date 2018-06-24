struct professores{
	char nome[30], curso[30];
	long long int cod;
	
};

typedef struct professores Professores;

int cont_professores;

Professores guardar_professores[100];

Professores criar_professor(char nome[], char curso[], long long int cod);

int printar_all_professores(int x, int y);

void salvar_professor(Professores p);

int procurar_professor(long long int cod);

void remover_professor(long long int cod);

void editar_professor(long long int cod, char nome[], char curso[], long long int novo_cod);

long long int cod_professor(int i);

char *nome_professor(int i);

void printar_1_professor(int i, int x, int y);
