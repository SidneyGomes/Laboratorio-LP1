#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluninhos.h"

int cont_alun = 0;

// Cria aluno retornando uma Struct apelidada de Aluno.
Aluno criar_aluno(long long int cpf, long long int matricula, char nome[], char curso[]){
	Aluno p;
	
	p.cpf = cpf;
	p.matricula = matricula;
	strcpy(p.nome, nome);
	strcpy(p.curso, curso);

	return p;

}

// Salva o Aluno no vetor de Struct guardar_alunos.
void salvar_aluno(Aluno p){
	guardar_alunos[cont_alun] = p;
	cont_alun++;
	
}

// Procura um Aluno pela matricula no vetor de struct guardar_alunos.
int procurar_aluno(long long int matricula){
	int i, x;
	
	for(i = 0; i < cont_alun; i++){
		if(guardar_alunos[i].matricula == matricula){
			x = i;
			
			return x;
		}
	}
	
	return -1;
}


// Edita um aluno ja cadastrado, trocando seu valor diretamente no vetor de Struct guardar_alunos.
void editar_aluno(long long int matricula, long long int nova_matricula, long long int cpf, char nome[], char curso[]){
	int x;
	
	x = procurar_aluno(matricula);
	
	
	guardar_alunos[x].cpf = cpf;
	guardar_alunos[x].matricula = nova_matricula;
	strcpy(guardar_alunos[x].nome, nome);
	strcpy(guardar_alunos[x].curso, curso);
	
}

// Retira 1 aluno do vetor de Struct procurando qual remover pela matricula.
void remover_aluno(long long int matricula){
	int x, i;
	
	x = procurar_aluno(matricula);
	
	if(x == cont_alun - 1){
		cont_alun--;
	}
	
	else{
		for(i = x+1; i < cont_alun; i++){
			guardar_alunos[i-1] = guardar_alunos[i];
			
		}
		cont_alun--;
	}
	
}

// Mostra todos os alunos cadastrados.
char *retorno_nome_aluno(int i){
	return guardar_alunos[i].nome;
}

long long int matricula_retorno_aluno(int i){
	return guardar_alunos[i].matricula;
}

// printar 1 aluno isolado

