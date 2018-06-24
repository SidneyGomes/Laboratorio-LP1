struct agenda{
	long long int cod_agend, codigo;
	char nome[30], area[30], data[30];	
		
};

typedef struct agenda Agenda;

int cont_agen;

int cod_age;

Agenda guardar_agendamentos[100];

Agenda criar_agenda(long long int matri, char area[], char data[]);

void salvar_paciente_agenda(Agenda agenda);

int printar_all_agenda(int x, int y);

void remover_paciente_agenda(int cod);

int procurar_codigo_agenda(long long int cod);

long long int cod_agendamento(int i);

char *nome_agendamento(int i);

char *data_agendamento(int i);

long long int cod_agendamento_paciente(int i);

void printar_1_agendamento(int i, int x, int y);

void printar_dados_cadastro(int i, int x, int y);

int procurar_codigo_agendamento(int cod_agendamento);
