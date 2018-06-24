#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas.h"

/* Referencia: 
	
	https://www.youtube.com/watch?v=LNu-0bzxpos
	https://www.youtube.com/watch?v=ueg-IE8cZH4&t=9s
	https://www.youtube.com/watch?v=uYymG_oUPeY

*/


// salvar aluno. 
void escrever_arquivo_aluno(Aluno guardar_alunos[]){
	int i;
	FILE *arq;
	
	arq = fopen("..\\database\\aluno.txt", "wb");
	
	if(arq != NULL){
		
		for(i = 0; i < cont_alun; i++){
			fwrite(&guardar_alunos[i], sizeof(Aluno), 1, arq);
		}
		fclose(arq);
	}
	
	else
		printf("Falhou :(\n");
}


void ler_arquivo_aluno(Aluno guardar_alunos[]){
	
	
	FILE * arq = fopen("..\\database\\aluno.txt", "rb");
	
	if (arq != NULL){
		
		cont_alun = 0;
		
		while(1){
			
			Aluno p;
			
			size_t r = fread(&p, sizeof(Aluno), 1, arq);
			
			if (r < 1)
				break;
			
			else
				guardar_alunos[cont_alun++] = p;
		}
		
		fclose(arq);
	}
	
	else{
		printf("Erro\n");
		exit(1);
	}
		
}

// end salvar aluno


// salvar paciente
void escrever_arquivo_paciente(Paciente guardar_pacientes[]){
	int i;
	FILE *arq;
	
	arq = fopen("..\\database\\paciente.txt", "wb");
	
	if(arq != NULL){
		
		for(i = 0; i < cont_paciente; i++){
			fwrite(&guardar_pacientes[i], sizeof(Paciente), 1, arq);
		}
		fclose(arq);
	}
	
	else
		printf("Falhou :(\n");
}


void ler_arquivo_paciente(Paciente guardar_pacientes[]){
	
	
	FILE * arq = fopen("..\\database\\paciente.txt", "rb");
	
	if (arq != NULL){
		
		cont_paciente = 0;
		
		while(1){
			
			Paciente p;
			
			size_t r = fread(&p, sizeof(Paciente), 1, arq);
			
			if (r < 1)
				break;
			
			else
				guardar_pacientes[cont_paciente++] = p;
		}
		
		fclose(arq);
	}
	
	else{
		printf("Erro\n");
		exit(1);
	}
		
}

//end salvar paciente



// salvar professor
void escrever_arquivo_professor(Professores guardar_professores[]){
	int i;
	FILE *arq;
	
	arq = fopen("..\\database\\professor.txt", "wb");
	
	if(arq != NULL){
		
		for(i = 0; i < cont_professores; i++){
			fwrite(&guardar_professores[i], sizeof(Professores), 1, arq);
		}
		fclose(arq);
	}
	
	else
		printf("Falhou :(\n");
}


void ler_arquivo_professor(Professores guardar_professores[]){
	
	
	FILE * arq = fopen("..\\database\\professor.txt", "rb");
	
	if (arq != NULL){
		
		cont_professores = 0;
		
		while(1){
			
			Professores p;
			
			size_t r = fread(&p, sizeof(Professores), 1, arq);
			
			if (r < 1)
				break;
			
			else
				guardar_professores[cont_professores++] = p;
		}
		
		fclose(arq);
	}
	
	else{
		printf("Erro\n");
	}
		
}

// end salvar professor


// salvar atendimento

void escrever_arquivo_atendimento(Atendimento guardar_atendimentos[]){

	int i;
	FILE *arq;
	
	arq = fopen("..\\database\\atendimento.txt", "wb");
	
	if(arq != NULL){
		
		for(i = 0; i < cont_atendimento; i++){
			fwrite(&guardar_atendimentos[i], sizeof(Atendimento), 1, arq);
		}
		
		fclose(arq);
	}
	
	else
		printf("Falhou :(\n");
}


void ler_arquivo_atendimento(Atendimento guardar_atendimentos[]){
	
	
	FILE * arq = fopen("..\\database\\atendimento.txt", "rb");
	
	if (arq != NULL){
		
		cont_atendimento = 0;
		
		while(1){
			
			Atendimento p;
			
			size_t r = fread(&p, sizeof(Atendimento), 1, arq);
			
			if (r < 1)
				break;
			
			else
				guardar_atendimentos[cont_atendimento++] = p;
		}
		
		fclose(arq);
	}
	
	else{
		printf("Erro\n");
		
	}
		
}


// end of salvar atendimento

// salvar agendamento

void escrever_arquivo_agendamento(Agenda guardar_agendamentos[]){
	int i;
	FILE *arq;
	
	arq = fopen("..\\database\\agendamento.txt", "wb");
	
	if(arq != NULL){
		
		for(i = 0; i < cont_agen; i++){
			fwrite(&guardar_agendamentos[i], sizeof(Agenda), 1, arq);
		}
		fclose(arq);
	}
	
	else
		printf("Falhou :(\n");
}


void ler_arquivo_agendamento(Agenda guardar_agendamentos[]){
	
	
	FILE * arq = fopen("..\\database\\agendamento.txt", "rb");
	
	if (arq != NULL){
		
		cont_agen = 0;
		
		while(1){
			
			Agenda p;
			
			size_t r = fread(&p, sizeof(Agenda), 1, arq);
			
			if (r < 1)
				break;
			
			else
				guardar_agendamentos[cont_agen++] = p;
		}
		
		fclose(arq);
	}
	
	else{
		printf("Erro\n");
	}
		
}

// end salvar agenda

// salvar conts_cadastro

void escrever_arquivo_cods(){
	int i;
	FILE *arq;
	
	arq = fopen("..\\database\\contagem_dos_cods.txt", "wb");
	
	if(arq != NULL){
		
		fwrite(&cod_age, sizeof(cod_age), 1, arq);
		fwrite(&cod_atendimento, sizeof(cod_atendimento), 1, arq);
	}
	
	else
		printf("Falhou :(\n");
		
		
	fclose(arq);
}


void ler_arquivo_cods(){
	int i;
	
	FILE * arq = fopen("..\\database\\contagem_dos_cods.txt", "rb");
	
	if (arq != NULL){
		
		for(i = 0; i < 2; i++){
			
			int p;
			
			size_t r = fread(&p, sizeof(p), 1, arq);
			
			if(i == 0)
				cod_age = p;
			else
				cod_atendimento = p;
		}
		
	}
	
	else{
		printf("Erro\n");
	}
	
	fclose(arq);
}

// end salvar cods


