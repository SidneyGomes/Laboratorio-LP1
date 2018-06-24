struct aluno{
	char nome[30], curso[30];
	long long int cpf, matricula;
	
};

typedef struct aluno Aluno;

int cont_alun;

Aluno guardar_alunos[100];

void salvar_aluno(Aluno p);

Aluno criar_aluno(long long int cpf, long long int matricula, char nome[], char curso[]);

int procurar_aluno(long long int matricula);

void remover_aluno(long long int matricula);

void editar_aluno(long long int matricula, long long int nova_matricula, long long int cpf, char nome[], char curso[]);

int printar_all_alunos(int x, int y);

char *retorno_nome_aluno(int i);

long long int matricula_retorno_aluno(int i);

void printar_1_aluno(int i, int x, int y);
