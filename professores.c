#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professores.h"


int cont_professores = 0;

// Retorna uma struct do tipo Professores.
Professores criar_professor(char nome[], char curso[], long long int cod){
	Professores p;
	
	strcpy(p.nome, nome);
	strcpy(p.curso, curso);
	p.cod = cod;
	
	return p;	
	
}


// Adiciona um professor ao vetor de Struct guardar_professores.
void salvar_professor(Professores p){
	guardar_professores[cont_professores] = p;
	cont_professores++;
}

// Procura um professor no vetor de Struct.
int procurar_professor(long long int cod){
	int i;
	
	for(i = 0; i < cont_professores; i++){
		if(guardar_professores[i].cod == cod)
			return i;
	}
	
	return -1;
}


// Remove um professor no vetor de Struct.
void remover_professor(long long int cod){
	int x, i;
	
	x = procurar_professor(cod);
	
	if(x == cont_professores - 1){
		cont_professores--;
	
	}
	
	else{
		for(i = x+1; i < cont_professores; i++){
			guardar_professores[i-1] = guardar_professores[i];
			
		}
		cont_professores--;		
	}
		
}


// Edita um professor diretamente no vetor de Struct.
void editar_professor(long long int cod, char nome[], char curso[], long long int novo_cod){
	int x;
	
	x = procurar_professor(cod);
	
	strcpy(guardar_professores[x].nome, nome);
	strcpy(guardar_professores[x].curso, curso);
	guardar_professores[x].cod = novo_cod;
	
}

// Retorna cod_professores
long long int cod_professor(int i){
	return guardar_professores[i].cod;
}

// Retorna nome dos professores.
char *nome_professor(int i){
	return guardar_professores[i].nome;
}


// Printa todos os alunos.



