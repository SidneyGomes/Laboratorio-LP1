#include "bibliotecas.h"
 
 
int cod_atendimento = 10000;
int cont_atendimento = 0;
 
 
// Cria atendimento pegando de outras Structs e da entrada.
Atendimento criar_atendimento(long long int cod, long long int matricula, long long int cod_prof, char data_atendimento[]){
    int x, y, z;
 
    x = procurar_codigo_agendamento(cod);
    y = procurar_aluno(matricula);
    z = procurar_professor(cod_prof);
     
    Atendimento p;
     
 
    p.cod_agend = cod_agendamento(x);
    strcpy(p.nome_paciente, nome_agendamento(x));
    p.cod_pacie = cod_agendamento_paciente(x);
    strcpy(p.data_agendamento, data_agendamento(x));
    
    strcpy(p.data_atendimento, data_atendimento);
    p.cod_atend = cod_atendimento;
    strcpy(p.serv_prestado, area_consulta(x));
         
    strcpy(p.nome_aluno, retorno_nome_aluno(y));
    p.cod_aluno = matricula_retorno_aluno(y);
         
    strcpy(p.nome_supervisor, nome_professor(z));
    p.cod_super = cod_professor(z);
 
 
    return p;
}
 
// Adiciona o atendimento ao vetor de Struct guardar_atendimento.
void salvar_atendimento(Atendimento p){
    guardar_atendimentos[cont_atendimento] = p;
    cont_atendimento++;
    cod_atendimento++;
     
}
// Procurar algum atendimento.
int procurar_atendimento(long long int cod){
    int i;
     
    for(i = 0; i < cont_atendimento; i++){
        if(guardar_atendimentos[i].cod_atend == cod)
            return i;
    }
     
    return -1;  
}
     

// Remove 1 atendimento pelo cod.
void remover_atendimento(long long int cod){
     
    int x, i;
     
    x = procurar_atendimento(cod);
     
    if(x == cont_atendimento - 1){
        cont_atendimento--;
     
    }
     
    else{
        for(i = x+1; i < cont_atendimento; i++){
            guardar_atendimentos[i-1] = guardar_atendimentos[i];
             
        }
        cont_atendimento--;     
    }
         
}
 
 
 
// printa todos os atendimentos.

 
 
int cont_qtd_area(char area[]){
	int i, cont;
	
	for(i = 0; i < cont_atendimento; i++){
		if(strcmp(guardar_atendimentos[i].serv_prestado, area) == 0){
			cont++;
		}
	}
	return cont;
	
}
 
// printa todos os atendimentos por area.

 
// printar um atendimento pelo paciente especifico.

int cont_qtd_pacie(long long int cod){
	
	int i, cont = 0;
	
	for(i = 0; i < cont_atendimento; i++){
		if(guardar_atendimentos[i].cod_pacie == cod){
			cont++;
		}
	}
	
	
	return cont;
}


 
int cont_qtd_aluno(long long int cod){
	
	int i, cont = 0;
	
	for(i = 0; i < cont_atendimento; i++){
		if(guardar_atendimentos[i].cod_aluno == cod){
			cont++;
		}
	}
	
	
	return cont;
}
 
 
 
// printar um atendimento pelo aluno especifico.



	
