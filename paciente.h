struct paciente{
	long long int cod, cpf;
	char nascimento[30], nome[30], endereco[30];
};


typedef struct paciente Paciente;

int cont_paciente;

Paciente guardar_pacientes[100];

Paciente criar_paciente(long long int cod, long long int cpf, char nascimento[], char endereco[], char nome[]);

void salvar_paciente(Paciente p);

int procurar_paciente(long long int cod);

void editar_paciente(long long int x , char nome [], char nascimento[], char endereco[], long long int new_cod, long long int cpf);

void remover_paciente(long long int cod);

int printar_all_paciente(int x, int y);

char *nome_paciente(int i);

long long int cod_paciente(int i);

void printar_1_paciente(int i, int x, int y);
