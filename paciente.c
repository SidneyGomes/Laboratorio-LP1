#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"

int cont_paciente = 0;

// Cria um paciente retornando uma Struct apelidada de paciente.
Paciente criar_paciente(long long int cod, long long int cpf, char nascimento[], char endereco[], char nome[]){
	Paciente p;
	
	p.cpf = cpf;
	p.cod = cod;
		
	strcpy(p.nascimento, nascimento);
	strcpy(p.nome, nome);
	strcpy(p.endereco, endereco);
	
	return p;
}


// Adiciona o paciente a um vetor de Struct Paciente.
void salvar_paciente(Paciente p){
	guardar_pacientes[cont_paciente] = p;
	cont_paciente++;
}

// Procura um paciente pelo codigo.
int procurar_paciente(long long int cod){
	int i;
	
	for(i = 0; i < cont_paciente; i++){
		if(guardar_pacientes[i].cod == cod)
			return i;
	}
	
	return -1;	
}

// Edita um Paciente do diretamento no vetor de Struct.
void editar_paciente(long long int cod, char nome [], char nascimento[], char endereco[], long long int new_cod, long long int cpf){
	
	int x;
	
	x = procurar_paciente(cod);
	
	strcpy(guardar_pacientes[x].endereco, endereco);
	strcpy(guardar_pacientes[x].nascimento, nascimento);
	strcpy(guardar_pacientes[x].nome, nome);
	guardar_pacientes[x].cod = new_cod;
	guardar_pacientes[x].cpf = cpf;
	
	
}

// Remove um paciente.
void remover_paciente(long long int cod){
	int x, i;
	
	x = procurar_paciente(cod);
	
	if(x == cont_paciente - 1){
		cont_paciente--;
	
	}
	
	else{
		for(i = x+1; i < cont_paciente; i++){
			guardar_pacientes[i-1] = guardar_pacientes[i];
			
		}
		cont_paciente--;		
	}
		
}

// Mostra todos os Pacientes.

// Retorna nome do paciente.
char *nome_paciente(int i){
	return guardar_pacientes[i].nome;
}

// Retorna  codigo do paciente.
long long int cod_paciente(int i){
	return guardar_pacientes[i].cod;
}
