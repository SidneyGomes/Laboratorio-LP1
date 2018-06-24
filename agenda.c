#include "bibliotecas.h"

int cont_agen = 0;
int cod_age = 1000;


// Cria a struct agendamento 
Agenda criar_agenda(long long int cod, char area[], char data[]){
	int x;
	Agenda pont;
	
	
	x = procurar_paciente(cod);

	strcpy(pont.nome, nome_paciente(x));
	strcpy(pont.data, data);
	strcpy(pont.area, area);
	pont.cod_agend = cod_age;
	pont.codigo = cod_paciente(x);
	
	return pont;
}


// Salvar paciente no vetor
void salvar_paciente_agenda(Agenda ponteiro){
	guardar_agendamentos[cont_agen] = ponteiro;
	cont_agen++;
	cod_age++;
}


// Procura um codigo de agendamento no vetor
int procurar_codigo_agendamento(int cod_agendamento){
	int i;
	
	for(i = 0; i < cont_agen; i++){
		if(guardar_agendamentos[i].cod_agend == cod_agendamento)
			return i;
	}
	
	return -1;	
	
	
}


int procurar_codigo_agenda(long long int cod){
	int i;
	
	for(i = 0; i < cont_agen; i++){
		if(guardar_agendamentos[i].codigo == cod)
			return i;
	}
	
	return -1;	
}

// Remove um paciente do vetor
void remover_paciente_agenda(int cod){
	int i, x;
	
	x = procurar_codigo_agendamento(cod);
	
	if(x == cont_agen - 1){
		cont_agen--;
	
	}
	
	else{
		for(i = x+1; i < cont_agen; i++){
			guardar_agendamentos[i-1] = guardar_agendamentos[i];
			
		}
		cont_agen--;		
	}
		
}
	


// Inicio dos valores para retornar no atender paciente
long long int cod_agendamento(int i){
	return guardar_agendamentos[i].cod_agend;
}

char *data_agendamento(int i){
	return guardar_agendamentos[i].data;
}


char *nome_agendamento(int i){
	return guardar_agendamentos[i].nome;
}

long long int cod_agendamento_paciente(int i){
	return guardar_agendamentos[i].codigo;
}

char *area_consulta(int i){
	return guardar_agendamentos[i].area;
}

// fim do returno dos valores



