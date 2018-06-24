struct atendimento{
	long long int cod_atend, cod_agend, cod_pacie, cod_aluno, cod_super;
	char nome_aluno[30], nome_paciente[30], data_atendimento[30], serv_prestado[30], nome_supervisor[30], data_agendamento[30];
	
};

typedef struct atendimento Atendimento;

Atendimento criar_atendimento(long long int cod, long long int matricula, long long int cod_prof, char data_atendimento[]);

int cod_atendimento;

int cont_atendimento;

Atendimento guardar_atendimentos[100];

void salvar_atendimento(Atendimento p);

void remover_atendimento(long long int cod);

void printar_all_serv(char serv_prestado);

int printar_all_atendimentos(int x, int y);

int printar_pacient_espec(long long int cod, int x, int y);

int procurar_atendimento(long long int cod);

void printar_1_atendimento(int i, int x, int y);

int cont_qtd_pacie(long long int cod);

int cont_qtd_aluno(long long int cod);

int printar_aluno_espec(long long int cod, int x, int y);

int cont_qtd_area(char area[]);

int printar_all_area(char area[], int x, int y);
