#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "bibliotecas.h"

/* Projeto: Clinica Escola UEPB
   Aluno: Sidney Gomes Barbosa
   Ciencia da Computacao
   Professor: Danilo de Abreu
   Disciplina: Laboratorio de Programacao 1
   
*/


LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);



HMENU hMenu;
HWND hEdit[20];
void Adic_menus(HWND);



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR args, int ncmdshow){
	
	WNDCLASSW wc = {0};
	
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor= LoadCursor(NULL,IDC_ARROW);
	wc.hInstance = hInstance;
	wc.lpszClassName = L"MinhaJanela";
	wc.lpfnWndProc = WindowProcedure;
	
	
	if(!RegisterClassW(&wc)){
		return -1;
	}

	CreateWindowW(L"MinhaJanela", L"Clinica Escola - UEPB", WS_OVERLAPPEDWINDOW | 
				  WS_VISIBLE, 100,100, 800,600, NULL, NULL, NULL, NULL);
				
	
	MSG msg  = {0};
	
	while(GetMessage(&msg, NULL,0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return 0;
}



void printar_atendimentos(char * out, int x){
	char codigo[30];
	
	sprintf(codigo, "%d", guardar_atendimentos[x].cod_agend);
	strcat(out, "\r\n-Codigo(Agendamento): ");
	strcat(out, codigo);
	sprintf(codigo, "%llu", guardar_atendimentos[x].cod_pacie);
	strcat(out, "\r\n-Codigo(Paciente): ");
	strcat(out, codigo);
	strcat(out, "\r\n-Nome(Paciente): ");
	strcat(out, guardar_atendimentos[x].nome_paciente);
	strcat(out, "\r\n-Area(Atendimento): ");
	strcat(out, guardar_atendimentos[x].serv_prestado);
	strcat(out, "\r\n-Nome(Aluno): ");
	strcat(out, guardar_atendimentos[x].nome_aluno);
	strcat(out, "\r\n-Codigo(Aluno): ");
	sprintf(codigo, "%llu", guardar_atendimentos[x].cod_aluno);
	strcat(out, codigo);
	strcat(out, "\r\n-Nome(Professor): ");
	strcat(out, guardar_atendimentos[x].nome_supervisor);
	strcat(out, "\r\n-Codigo(Professor): ");
	sprintf(codigo, "%llu", guardar_atendimentos[x].cod_super);
	strcat(out, codigo);
	strcat(out, "\r\n-Data(Atendimento): ");
	strcat(out, guardar_atendimentos[x].data_atendimento);
	strcat(out, "\r\n-Data(Agendamento): ");
	strcat(out, guardar_atendimentos[x].data_agendamento);
	strcat(out, "\r\n \r\n");

}
	


void create_aluno(HWND hWnd){
	hEdit[0] = CreateWindowW(L"static", L"Preencha os dados abaixo:", WS_VISIBLE | WS_CHILD, 250,50,200,17, hWnd,NULL,NULL, NULL);
						
	hEdit[1] = CreateWindowW(L"static", L"Matricula:", WS_VISIBLE | WS_CHILD, 95,100,100,20, hWnd,NULL,NULL, NULL);
	hEdit[2] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 165,100,400,20, hWnd,NULL,NULL, NULL);
	
	hEdit[3] = CreateWindowW(L"static", L"Nome:", WS_VISIBLE | WS_CHILD, 95,128,100,20, hWnd,NULL,NULL, NULL);
	hEdit[4] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 165,128,400,20, hWnd,NULL,NULL, NULL);

	hEdit[5] = CreateWindowW(L"static", L"Cpf:", WS_VISIBLE | WS_CHILD , 95,156,400,20, hWnd,NULL,NULL, NULL);
	hEdit[6] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 165,156,400,20, hWnd,NULL,NULL, NULL);
	
	hEdit[7] = CreateWindowW(L"static", L"Curso", WS_VISIBLE | WS_CHILD , 95,184,400,20, hWnd,NULL,NULL, NULL);
	hEdit[8] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 165,184,400,20, hWnd,NULL,NULL, NULL);
	
	hEdit[9] = CreateWindowW(L"Button", L"Cadastrar", WS_VISIBLE  | WS_CHILD, 300, 250, 100, 50, hWnd, (HMENU)20, NULL,NULL);


}


void create_paciente(HWND hWnd){
	hEdit[0] = CreateWindowW(L"static", L"Preencha os dados abaixo:", WS_VISIBLE | WS_CHILD, 250,50,200,17, hWnd,NULL,NULL, NULL);
						
	hEdit[1] = CreateWindowW(L"static", L"Codigo:", WS_VISIBLE | WS_CHILD, 95,100,100,20, hWnd,NULL,NULL, NULL);
	hEdit[2] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 240,100,400,20, hWnd,NULL,NULL, NULL);
	
	hEdit[3] = CreateWindowW(L"static", L"Nome:", WS_VISIBLE | WS_CHILD, 95,128,100,20, hWnd,NULL,NULL, NULL);
	hEdit[4] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 240,128,400,20, hWnd,NULL,NULL, NULL);

	hEdit[5] = CreateWindowW(L"static", L"Nascimento:", WS_VISIBLE | WS_CHILD , 95,156,400,20, hWnd,NULL,NULL, NULL);
	hEdit[6] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 240,156,400,20, hWnd,NULL,NULL, NULL);
	
	hEdit[7] = CreateWindowW(L"static", L"Cpf:", WS_VISIBLE | WS_CHILD , 95,184,400,20, hWnd,NULL,NULL, NULL);
	hEdit[8] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 240,184,400,20, hWnd,NULL,NULL, NULL);
	
	
	hEdit[9] = CreateWindowW(L"static", L"Endereco(Rua, Num):", WS_VISIBLE | WS_CHILD , 95,212,400,20, hWnd,NULL,NULL, NULL);
	hEdit[10] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 240,212,400,20, hWnd,NULL,NULL, NULL);
	
	hEdit[11] = CreateWindowW(L"Button", L"Cadastrar", WS_VISIBLE  | WS_CHILD, 350, 250, 100, 50, hWnd, (HMENU)25, NULL,NULL);
}


void create_professores(HWND hWnd){
	hEdit[0] = CreateWindowW(L"static", L"Preencha os dados abaixo:", WS_VISIBLE | WS_CHILD, 250,50,200,17, hWnd,NULL,NULL, NULL);
						
	hEdit[1] = CreateWindowW(L"static", L"Codigo:", WS_VISIBLE | WS_CHILD, 95,100,100,20, hWnd,NULL,NULL, NULL);
	hEdit[2] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 150,100,400,20, hWnd,NULL,NULL, NULL);
	
	hEdit[3] = CreateWindowW(L"static", L"Nome:", WS_VISIBLE | WS_CHILD, 95,128,100,20, hWnd,NULL,NULL, NULL);
	hEdit[4] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 150,128,400,20, hWnd,NULL,NULL, NULL);

	hEdit[5] = CreateWindowW(L"static", L"Curso:", WS_VISIBLE | WS_CHILD , 95,156,400,20, hWnd,NULL,NULL, NULL);
	hEdit[6] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 150,156,400,20, hWnd,NULL,NULL, NULL);
	
	hEdit[7] = CreateWindowW(L"Button", L"Cadastrar", WS_VISIBLE  | WS_CHILD, 300, 200, 100, 50, hWnd, (HMENU)30, NULL,NULL);
	
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg,  WPARAM a, LPARAM b){
	ler_arquivo_aluno(guardar_alunos);
	ler_arquivo_paciente(guardar_pacientes);
	ler_arquivo_professor(guardar_professores);
	ler_arquivo_agendamento(guardar_agendamentos);
	ler_arquivo_atendimento(guardar_atendimentos);
	ler_arquivo_cods();
	
	Aluno p;
	Paciente q;
	Professores r;
	Agenda s;
	Atendimento t;
	
	int i, pesquisa, val, pesquisa_2, flag, contador = 0;
	char codigo[30], nome[30], idade[30], cpf[30], curso[30], endereco[40], out[300] = "-", nova_matricula[30], data[30], area[30], a1[30], b1[30], c1[30];
	long long int novo_cod, cod, cpf_1, code, codinho;
	
	switch(msg){
		case WM_COMMAND:
			switch(a){
					case 1:
						for(i = 0; i < 20; i++){
							DestroyWindow(hEdit[i]);
						}
					
						
						create_aluno(hWnd);
						
						break;
					
					case 20:						
						GetWindowText(hEdit[2], codigo, 30);
						GetWindowText(hEdit[4], nome, 30);
						GetWindowText(hEdit[6], cpf, 30);
						GetWindowText(hEdit[8], curso, 30);
						
			
						if(strlen(codigo)== 0 || strlen(nome) == 0 || strlen(cpf) == 0 || strlen(curso) == 0){
							val = MessageBoxW(hWnd,L"Campo nao preenchido", L"Alunos", MB_OK | MB_ICONINFORMATION);		
						}
						
						else{
							cod = atoll(codigo);
							cpf_1 = atoll(cpf);
							pesquisa = procurar_aluno(cod);
							if (pesquisa == -1){
								p = criar_aluno(cpf_1, cod, nome, curso);
								salvar_aluno(p);
								escrever_arquivo_aluno(guardar_alunos);
								val = MessageBoxW(hWnd,L"Aluno cadastrado", L"Alunos", MB_OK | MB_ICONINFORMATION);	
							}
							else{
								val = MessageBoxW(hWnd,L"Aluno ja cadastrado", L"Alunos", MB_OK | MB_ICONINFORMATION);	
							}
							
						}
						
						break;
					
					case 2:
						for(i = 0; i < 20; i++){
							DestroyWindow(hEdit[i]);
						}
						hEdit[0] = CreateWindowW(L"static", L"Digite a matricula do aluno que quer remover:", WS_VISIBLE | WS_CHILD , 200,50,350,17, hWnd,NULL,NULL, NULL);
						
						hEdit[1] = CreateWindowW(L"static", L"Matricula:", WS_VISIBLE | WS_CHILD, 95,100,100,20, hWnd,NULL,NULL, NULL);
						hEdit[2] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 165,100,400,20, hWnd,NULL,NULL, NULL);
						
						hEdit[4] = CreateWindowW(L"Button", L"Mostrar", WS_VISIBLE  | WS_CHILD, 300, 130, 100, 25, hWnd, (HMENU)21,NULL,NULL);
						
						break;
					
					case 21:
					
						GetWindowText(hEdit[2], codigo, 30);
						cod = atoll(codigo);
						
						if(strlen(codigo) == 0){
							val = MessageBoxW(hWnd,L"Campo nao preenchido", L"Alunos", MB_OK | MB_ICONINFORMATION);					
						}
						
						else{
							pesquisa = procurar_aluno(cod);
							if (pesquisa == -1){
				
								val = MessageBoxW(hWnd,L"Aluno nao cadastrado", L"Alunos", MB_OK | MB_ICONINFORMATION);	
							}
							else{
								hEdit[5] = CreateWindowW(L"Button", L"Remover", WS_VISIBLE | WS_CHILD, 250, 320, 200, 50, hWnd, (HMENU)22, NULL, NULL);
								hEdit[6] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | WS_BORDER | ES_MULTILINE , 165,200,400,100, hWnd,NULL,NULL, NULL);
								
								sprintf(cpf, "%llu", guardar_alunos[pesquisa].cpf);
								strcat(out, "Nome: ");
								strcat(out, guardar_alunos[pesquisa].nome);
								strcat(out, "\r\nCpf: ");
								strcat(out, cpf);
								strcat(out, "\r\nCurso: ");
								strcat(out, guardar_alunos[pesquisa].curso);
								
								SetWindowText(hEdit[6], out);	
							}
						}	
						break;
						
					case 22:
						GetWindowText(hEdit[2], codigo, 300);
						cod = atoll(codigo);
						
						if(procurar_aluno(cod) != - 1){
							remover_aluno(cod);
							escrever_arquivo_aluno(guardar_alunos);
							val = MessageBoxW(hWnd,L"Aluno removido", L"Alunos", MB_OK | MB_ICONINFORMATION);
							DestroyWindow(hEdit[5]);	
							DestroyWindow(hEdit[6]);
						}
						
						else{
							val = MessageBoxW(hWnd,L"Nao inserido ou nao cadastrado", L"Alunos", MB_OK | MB_ICONINFORMATION);
						}
						
						break;
					
					
					case 3:
						for(i = 0; i < 20; i++){
							DestroyWindow(hEdit[i]);
						}
						
						hEdit[0] = CreateWindowW(L"static", L"Digite a matricula do aluno que quer editar:", WS_VISIBLE | WS_CHILD , 200,50,350,17, hWnd,NULL,NULL, NULL);
						hEdit[1] = CreateWindowW(L"static", L"Matricula:", WS_VISIBLE | WS_CHILD, 95,100,100,20, hWnd,NULL,NULL, NULL);
						hEdit[2] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 165,100,400,20, hWnd,NULL,NULL, NULL);
						hEdit[4] = CreateWindowW(L"Button", L"Procurar", WS_VISIBLE  | WS_CHILD, 300, 130, 100, 25, hWnd, (HMENU)23,NULL,NULL);
			
						
						break;
					
					case 23:
						GetWindowText(hEdit[2], codigo, 300);
						
						if(strlen(codigo) == 0){
							val = MessageBoxW(hWnd,L"Campo nao preenchido", L"Alunos", MB_OK | MB_ICONINFORMATION);	
						}
						
						else{
							cod = atoll(codigo);
							if(procurar_aluno(cod) == -1){
								val = MessageBoxW(hWnd,L"Aluno nao cadastrado", L"Alunos", MB_OK | MB_ICONINFORMATION);	
							}
							else{
								
								hEdit[7] = CreateWindowW(L"static", L"Matricula:", WS_VISIBLE | WS_CHILD, 95,160,100,20, hWnd,NULL,NULL, NULL);
								hEdit[8] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 165,160,400,20, hWnd,NULL,NULL, NULL);
								
								hEdit[9] = CreateWindowW(L"static", L"Nome:", WS_VISIBLE | WS_CHILD, 95,188,100,20, hWnd,NULL,NULL, NULL);
								hEdit[10] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 165,188,400,20, hWnd,NULL,NULL, NULL);

								hEdit[11] = CreateWindowW(L"static", L"Cpf:", WS_VISIBLE | WS_CHILD , 95,216,400,20, hWnd,NULL,NULL, NULL);
								hEdit[12] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 165,216,400,20, hWnd,NULL,NULL, NULL);
								
								hEdit[13] = CreateWindowW(L"static", L"Curso", WS_VISIBLE | WS_CHILD , 95,244,400,20, hWnd,NULL,NULL, NULL);
								hEdit[14] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 165,244,400,20, hWnd,NULL,NULL, NULL);
								
								hEdit[15] = CreateWindowW(L"Button", L"Editar", WS_VISIBLE  | WS_CHILD, 300, 280, 100, 50, hWnd, (HMENU)24, NULL,NULL);
							}
						}
						break;
					
					case 24:
						
						GetWindowText(hEdit[2], codigo, 30);
						GetWindowText(hEdit[8], nova_matricula, 30);
						GetWindowText(hEdit[10], nome, 30);
						GetWindowText(hEdit[12], cpf, 30);
						GetWindowText(hEdit[14], curso, 30);
						
						
						if(strlen(nova_matricula)== 0 || strlen(nome) == 0 || strlen(cpf) == 0 || strlen(curso) == 0){
							val = MessageBoxW(hWnd,L"Campo nao preenchido", L"Alunos", MB_OK | MB_ICONINFORMATION);		
						}
						
						else{
							cod = atoll(codigo);
							novo_cod = atoll(nova_matricula);
							cpf_1 = atoll(cpf);
							if(procurar_aluno(novo_cod) != -1)
								val = MessageBoxW(hWnd,L"Ja existe aluno com esse codigo", L"Alunos", MB_OK | MB_ICONINFORMATION);
							else{
								editar_aluno(cod, novo_cod, cpf_1, nome, curso);
								escrever_arquivo_aluno(guardar_alunos);
							
								val = MessageBoxW(hWnd,L"Aluno Editado", L"Alunos", MB_OK | MB_ICONINFORMATION);
								
								
								for(i = 7; i <= 15; i++){
									DestroyWindow(hEdit[i]);
								}	
							}
						}
						
						break;
						
					case 4:
						for(i = 0; i < 20; i++){
							DestroyWindow(hEdit[i]);
						}
						
						hEdit[0] = CreateWindowW(L"static", L"Alunos Cadastrados:", WS_VISIBLE | WS_CHILD , 300,50,350,17, hWnd,NULL,NULL, NULL);
						hEdit[2] = CreateWindowW(L"Edit", L"", WS_VISIBLE | ES_AUTOVSCROLL | WS_CHILD | WS_BORDER | ES_MULTILINE , 125,100,500,400, hWnd,NULL,NULL, NULL);
						
						if(cont_alun == 0){
							SetWindowText(hEdit[2], "                                           Nenhum aluno cadastrado");
						}
						
						else{
							for(i = 0; i < cont_alun; i++){
								sprintf(codigo,"%llu", guardar_alunos[i].matricula);
								if(i == 0)
									strcat(out, "Matricula: ");
								else
									strcat(out, "-Matricula: ");
								
								strcat(out, codigo);
								sprintf(cpf, "%llu", guardar_alunos[i].cpf);
								strcat(out, "\r\n-Nome: ");
								strcat(out, guardar_alunos[i].nome);
								strcat(out, "\r\n-Cpf: ");
								strcat(out, cpf);
								strcat(out, "\r\n-Curso: ");
								strcat(out, guardar_alunos[i].curso);
								strcat(out, "\r\n \r\n");
								
								
								SetWindowText(hEdit[2], out);	
								
							}
						}
							
						break;
					case 5:
						for(i = 0; i < 20; i++){
							DestroyWindow(hEdit[i]);
						}
						create_paciente(hWnd);
;						
						break;
		
					case 25:
						GetWindowText(hEdit[2], codigo, 30);
						GetWindowText(hEdit[4], nome, 30);
						GetWindowText(hEdit[6], curso, 30);
						GetWindowText(hEdit[8], cpf, 30);
						GetWindowText(hEdit[10], endereco, 50);
						
						if(strlen(codigo)== 0 || strlen(nome) == 0 || strlen(cpf) == 0 || strlen(curso) == 0 || strlen(endereco) == 0){
							val = MessageBoxW(hWnd,L"Campo nao preenchido", L"Pacientes", MB_OK | MB_ICONINFORMATION);		
						}
						
						else{
							cod = atoll(codigo);
							cpf_1 = atoll(cpf);
							pesquisa = procurar_paciente(cod);
							if (pesquisa == -1){
								q = criar_paciente(cod, cpf_1, curso, endereco, nome);
								salvar_paciente(q);
								escrever_arquivo_paciente(guardar_pacientes);
								val = MessageBoxW(hWnd,L"Paciente cadastrado", L"Pacientes", MB_OK | MB_ICONINFORMATION);	
							}
							else{
								val = MessageBoxW(hWnd,L"Paciente ja cadastrado", L"Pacientes", MB_OK | MB_ICONINFORMATION);	
							}
						}						
						
						break;
					case 6:
						for(i = 0; i < 20; i++){
							DestroyWindow(hEdit[i]);
						}
						
						hEdit[0] = CreateWindowW(L"static", L"Digite a matricula do Paciente que quer remover:", WS_VISIBLE | WS_CHILD , 200,50,350,17, hWnd,NULL,NULL, NULL);
						
						hEdit[1] = CreateWindowW(L"static", L"Codigo:", WS_VISIBLE | WS_CHILD, 95,100,100,20, hWnd,NULL,NULL, NULL);
						hEdit[2] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 165,100,400,20, hWnd,NULL,NULL, NULL);
						
						hEdit[4] = CreateWindowW(L"Button", L"Mostrar", WS_VISIBLE  | WS_CHILD, 300, 130, 100, 25, hWnd, (HMENU)26,NULL,NULL);
						
						
						break;
					
					case 26:
						GetWindowText(hEdit[2], codigo, 30);
						cod = atoll(codigo);
						
						if(strlen(codigo) == 0){
							val = MessageBoxW(hWnd,L"Campo nao preenchido", L"Pacientes", MB_OK | MB_ICONINFORMATION);					
						}
						
						else{
							pesquisa = procurar_paciente(cod);
							if (pesquisa == -1){
				
								val = MessageBoxW(hWnd,L"Paciente nao cadastrado", L"Pacientes", MB_OK | MB_ICONINFORMATION);	
							}
							else{
								hEdit[5] = CreateWindowW(L"Button", L"Remover", WS_VISIBLE | WS_CHILD, 250, 320, 200, 50, hWnd, (HMENU)27, NULL, NULL);
								hEdit[6] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | WS_BORDER | ES_MULTILINE , 165,200,400,100, hWnd,NULL,NULL, NULL);
								
								sprintf(cpf, "%llu", guardar_pacientes[pesquisa].cpf);
								strcat(out, "Nome: ");
								strcat(out, guardar_pacientes[pesquisa].nome);
								strcat(out, "\r\n-Cpf: ");
								strcat(out, cpf);
								strcat(out, "\r\n-Nascimento: ");
								strcat(out, guardar_pacientes[pesquisa].nascimento);
								strcat(out, "\r\n-Endereco: ");
								strcat(out, guardar_pacientes[pesquisa].endereco);
								
								SetWindowText(hEdit[6], out);	
							}
						}	
						break;
						
						
					case 27:
						GetWindowText(hEdit[2], codigo, 300);
						cod = atoll(codigo);
						
						if(procurar_paciente(cod) != - 1){
							remover_paciente(cod);
							escrever_arquivo_paciente(guardar_pacientes);
							val = MessageBoxW(hWnd,L"Paciente Removido", L"Pacientes", MB_OK | MB_ICONINFORMATION);	
							DestroyWindow(hEdit[5]);
							DestroyWindow(hEdit[6]);
						}
						
						else{
							val = MessageBoxW(hWnd,L"Nao inserido ou nao cadastrado", L"Pacientes", MB_OK | MB_ICONINFORMATION);	
						}
						
						break;
					case 7:
						for(i = 0; i < 20; i++){
							DestroyWindow(hEdit[i]);
						}
						
						hEdit[0] = CreateWindowW(L"static", L"Digite o codigo do paciente que quer editar:", WS_VISIBLE | WS_CHILD , 200,50,350,17, hWnd,NULL,NULL, NULL);
						hEdit[1] = CreateWindowW(L"static", L"Codigo:", WS_VISIBLE | WS_CHILD, 95,100,100,20, hWnd,NULL,NULL, NULL);
						
						hEdit[2] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 240,100,400,20, hWnd,NULL,NULL, NULL);
						
						hEdit[3] = CreateWindowW(L"Button", L"Procurar", WS_VISIBLE  | WS_CHILD, 350, 130, 100, 25, hWnd, (HMENU)28,NULL,NULL);
						
						break;
					
					case 28:
						
						GetWindowText(hEdit[2], codigo, 30);
						
						if(strlen(codigo) == 0){
							val = MessageBoxW(hWnd,L"Campo nao preenchido", L"Alunos", MB_OK | MB_ICONINFORMATION);	
						}
						
						else{
							cod = atoll(codigo);
							if(procurar_paciente(cod) == -1){
								val = MessageBoxW(hWnd,L"Aluno nao cadastrado", L"Alunos", MB_OK | MB_ICONINFORMATION);	
							}
							else{
								hEdit[4] = CreateWindowW(L"static", L"Codigo:", WS_VISIBLE | WS_CHILD, 95,166,100,20, hWnd,NULL,NULL, NULL);
								hEdit[5] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 240,166,400,20, hWnd,NULL,NULL, NULL);
								
								hEdit[6] = CreateWindowW(L"static", L"Nome:", WS_VISIBLE | WS_CHILD, 95,194,100,20, hWnd,NULL,NULL, NULL);
								hEdit[7] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 240,194,400,20, hWnd,NULL,NULL, NULL);
							
								hEdit[8] = CreateWindowW(L"static", L"Nascimento:", WS_VISIBLE | WS_CHILD , 95,222,400,20, hWnd,NULL,NULL, NULL);
								hEdit[9] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 240,222,400,20, hWnd,NULL,NULL, NULL);
								
								hEdit[10] = CreateWindowW(L"static", L"Cpf:", WS_VISIBLE | WS_CHILD , 95,250,400,20, hWnd,NULL,NULL, NULL);
								hEdit[11] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 240,250,400,20, hWnd,NULL,NULL, NULL);
								
								
								hEdit[12] = CreateWindowW(L"static", L"Endereco(Rua, Num):", WS_VISIBLE | WS_CHILD , 95,278,400,20, hWnd,NULL,NULL, NULL);
								hEdit[13] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 240,278,400,20, hWnd,NULL,NULL, NULL);
								
								hEdit[14] = CreateWindowW(L"Button", L"Editar", WS_VISIBLE  | WS_CHILD, 350, 320, 100, 50, hWnd, (HMENU)29, NULL,NULL);
							}
						}
						
						break;
					
					case 29:
						GetWindowText(hEdit[2], codigo, 30);
						cod = atoll(codigo);
						
						GetWindowText(hEdit[5], nova_matricula, 30);
						GetWindowText(hEdit[7], nome, 30);
						GetWindowText(hEdit[9], curso, 30);
						GetWindowText(hEdit[11], cpf, 30);
						GetWindowText(hEdit[13], endereco, 50);
						
						if(strlen(nova_matricula)== 0 || strlen(nome) == 0 || strlen(cpf) == 0 || strlen(curso) == 0 || strlen(endereco) == 0){
							val = MessageBoxW(hWnd,L"Campo nao preenchido", L"Pacientes", MB_OK | MB_ICONINFORMATION);		
						}
						
						else{
							novo_cod = atoll(nova_matricula);
							cpf_1 = atoll(cpf);
							if(procurar_paciente(novo_cod) != -1)
								val = MessageBoxW(hWnd, L"Ja existe paciente com esse codigo", L"Pacientes", MB_OK | MB_ICONINFORMATION);
							else{
								editar_paciente(cod, nome, curso, endereco, novo_cod, cpf_1);
								escrever_arquivo_paciente(guardar_pacientes);
							
								val = MessageBoxW(hWnd,L"Paciente Editado", L"Pacientes", MB_OK | MB_ICONINFORMATION);
								
								for(i = 4; i <= 14; i++){
									DestroyWindow(hEdit[i]);
								}	
							}
						}
						
						break;
					
					
					
					case 8:
						for(i = 0; i < 20; i++){
							DestroyWindow(hEdit[i]);
						}
						
						hEdit[0] = CreateWindowW(L"static", L"Pacientes Cadastrados:", WS_VISIBLE | WS_CHILD , 300,50,350,17, hWnd,NULL,NULL, NULL);
						hEdit[2] = CreateWindowW(L"Edit", L"", WS_VISIBLE | ES_AUTOVSCROLL | WS_CHILD | WS_BORDER | ES_MULTILINE , 125,100,500,400, hWnd,NULL,NULL, NULL);
						
						if(cont_paciente == 0){
							SetWindowText(hEdit[2], "                                           Nenhum paciente cadastrado");
						}
						
						else{
							for(i = 0; i < cont_paciente; i++){
								sprintf(codigo,"%llu", guardar_pacientes[i].cod);
								sprintf(cpf, "%llu", guardar_pacientes[i].cpf);
								if(i == 0)
									strcat(out, "Codigo: ");
								else
									strcat(out, "-Codigo: ");
								
								strcat(out, codigo);
								strcat(out, "\r\n-Nome: ");
								strcat(out, guardar_pacientes[i].nome);
								strcat(out, "\r\n-Cpf: ");
								strcat(out, cpf);
								strcat(out, "\r\n-Nascimento: ");
								strcat(out, guardar_pacientes[i].nascimento);
								strcat(out, "\r\n-Endereco: ");
								strcat(out, guardar_pacientes[i].endereco);
								strcat(out, "\r\n \r\n");
								
								
								SetWindowText(hEdit[2], out);	
								
							}
						}
						break;
					case 9:
						for(i = 0; i < 20; i++){
							DestroyWindow(hEdit[i]);
						}
						
						create_professores(hWnd);
						

	
						
						break;
					
					case 30:
						GetWindowText(hEdit[2], codigo, 30);
						GetWindowText(hEdit[4], nome, 30);
						GetWindowText(hEdit[6], curso, 30);
						
			
						if(strlen(codigo) == 0 || strlen(nome) == 0 || strlen(curso) == 0){
							val = MessageBoxW(hWnd,L"Campo nao preenchido", L"Professores", MB_OK | MB_ICONINFORMATION);		
						}
						
						else{
							cod = atoll(codigo);
							pesquisa = procurar_professor(cod);
							if (pesquisa == -1){
								r = criar_professor(nome, curso, cod);
								salvar_professor(r);
								escrever_arquivo_professor(guardar_professores);
								val = MessageBoxW(hWnd,L"Professor cadastrado", L"Professores", MB_OK | MB_ICONINFORMATION);	
							}
							else{
								val = MessageBoxW(hWnd,L"Professor ja cadastrado", L"Professores", MB_OK | MB_ICONINFORMATION);	
							}
							
						}
						break;
					
					
					case 10:
						for(i = 0; i < 100; i++){
							DestroyWindow(hEdit[i]);
						}
						hEdit[0] = CreateWindowW(L"static", L"Digite a matricula do professor que quer remover:", WS_VISIBLE | WS_CHILD , 200,50,350,17, hWnd,NULL,NULL, NULL);
						
						hEdit[1] = CreateWindowW(L"static", L"Codigo:", WS_VISIBLE | WS_CHILD, 95,100,100,20, hWnd,NULL,NULL, NULL);
						hEdit[2] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 165,100,400,20, hWnd,NULL,NULL, NULL);
						
						hEdit[3] = CreateWindowW(L"Button", L"Mostrar", WS_VISIBLE  | WS_CHILD, 300, 130, 100, 25, hWnd, (HMENU)31,NULL,NULL);
						
						break;
					
					case 31:
						GetWindowText(hEdit[2], codigo, 30);
						cod = atoll(codigo);
						
						if(strlen(codigo) == 0){
							val = MessageBoxW(hWnd,L"Campo nao preenchido", L"Professores", MB_OK | MB_ICONINFORMATION);					
						}
						
						else{
							pesquisa = procurar_professor(cod);
							if (pesquisa == -1){
				
								val = MessageBoxW(hWnd,L"Professor nao cadastrado", L"Professores", MB_OK | MB_ICONINFORMATION);	
							}
							else{
								
								hEdit[10] = CreateWindowW(L"Button", L"Remover", WS_VISIBLE | WS_CHILD, 250, 320, 200, 50, hWnd, (HMENU)32, NULL, NULL);
								hEdit[11]= CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | WS_BORDER | ES_MULTILINE , 165,200,400,100, hWnd,NULL,NULL, NULL);
								
								strcat(out, "Nome: ");
								strcat(out, guardar_professores[pesquisa].nome);
								strcat(out, "\r\n-Curso: ");
								strcat(out, guardar_professores[pesquisa].curso);
								
								SetWindowText(hEdit[11], out);	
							}
						}	
						
						break;
							
					case 32:
						GetWindowText(hEdit[2], codigo, 30);							
						cod = atoll(codigo);
						
						if(procurar_professor(cod) != - 1){
							remover_professor(cod);
							escrever_arquivo_professor(guardar_professores);
							val = MessageBoxW(hWnd,L"Professor removido", L"professores", MB_OK | MB_ICONINFORMATION);
							DestroyWindow(hEdit[10]);	
							DestroyWindow(hEdit[11]);
						}
						
						else{
							val = MessageBoxW(hWnd,L"Nao inserido ou nao cadastrado", L"Alunos", MB_OK | MB_ICONINFORMATION);
						}
						
						break;
					
					
					case 11:
						for(i = 0; i < 20; i++){
							DestroyWindow(hEdit[i]);
						}
						
						hEdit[0] = CreateWindowW(L"static", L"Digite a matricula do professor que quer editar:", WS_VISIBLE | WS_CHILD , 200,50,350,17, hWnd,NULL,NULL, NULL);
						hEdit[1] = CreateWindowW(L"static", L"Codigo:", WS_VISIBLE | WS_CHILD, 95,100,100,20, hWnd,NULL,NULL, NULL);
						hEdit[2] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 165,100,400,20, hWnd,NULL,NULL, NULL);
						hEdit[3] = CreateWindowW(L"Button", L"Procurar", WS_VISIBLE  | WS_CHILD, 300, 130, 100, 25, hWnd, (HMENU)33,NULL,NULL);
			
						
						break;
						
					case 33:
						GetWindowText(hEdit[2], codigo, 30);
						
						if(strlen(codigo) == 0){
							val = MessageBoxW(hWnd,L"Campo nao preenchido", L"Professores", MB_OK | MB_ICONINFORMATION);	
						}
						
						else{
							cod = atoll(codigo);
							if(procurar_professor(cod) == -1){
								val = MessageBoxW(hWnd,L"Professor nao cadastrado", L"Professores", MB_OK | MB_ICONINFORMATION);	
							}
							else{
								
								hEdit[4] = CreateWindowW(L"static", L"Codigo:", WS_VISIBLE | WS_CHILD, 95,160,100,20, hWnd,NULL,NULL, NULL);
								hEdit[5] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 165,160,400,20, hWnd,NULL,NULL, NULL);
								
								hEdit[6] = CreateWindowW(L"static", L"Nome:", WS_VISIBLE | WS_CHILD, 95,188,100,20, hWnd,NULL,NULL, NULL);
								hEdit[7] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 165,188,400,20, hWnd,NULL,NULL, NULL);

								hEdit[8] = CreateWindowW(L"static", L"Curso", WS_VISIBLE | WS_CHILD , 95,212,400,20, hWnd,NULL,NULL, NULL);
								hEdit[9] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 165,212,400,20, hWnd,NULL,NULL, NULL);
								
								hEdit[10] = CreateWindowW(L"Button", L"Editar", WS_VISIBLE  | WS_CHILD, 300, 250, 100, 50, hWnd, (HMENU)34, NULL,NULL);
							}
						}
						
						break;
					case 34:
						GetWindowText(hEdit[2], codigo, 30);
						GetWindowText(hEdit[5], nova_matricula, 30);
						GetWindowText(hEdit[7], nome, 30);
						GetWindowText(hEdit[9], curso, 30);
						
						
						if(strlen(nova_matricula)== 0 || strlen(nome) == 0 || strlen(curso) == 0){
							val = MessageBoxW(hWnd,L"Campo nao preenchido", L"Professores", MB_OK | MB_ICONINFORMATION);		
						}
						
						else{
							cod = atoll(codigo);
							novo_cod = atoll(nova_matricula);
							if(procurar_professor(novo_cod) != -1)
								val = MessageBoxW(hWnd,L"Ja existe professor com esse codigo", L"Professores", MB_OK | MB_ICONINFORMATION);
							else{
								editar_professor(cod, nome, curso, novo_cod);
								escrever_arquivo_professor(guardar_professores);
							
								val = MessageBoxW(hWnd,L"Professor Editado", L"Professores", MB_OK | MB_ICONINFORMATION);
								
								
								for(i = 4; i <= 10; i++){
									DestroyWindow(hEdit[i]);
								}	
							}
						}
						
						break;

					case 12:
						for(i = 0; i < 20; i++){
							DestroyWindow(hEdit[i]);
						}
						
						hEdit[0] = CreateWindowW(L"static", L"Professores Cadastrados:", WS_VISIBLE | WS_CHILD , 300,50,350,17, hWnd,NULL,NULL, NULL);
						hEdit[2] = CreateWindowW(L"Edit", L"", WS_VISIBLE | ES_AUTOVSCROLL | WS_CHILD | WS_BORDER | ES_MULTILINE , 125,100,500,400, hWnd,NULL,NULL, NULL);
						
						if(cont_professores == 0){
							SetWindowText(hEdit[2], "                                        Nenhum professores cadastrado");
						}
						
						else{
							for(i = 0; i < cont_professores; i++){
								sprintf(codigo,"%llu", guardar_professores[i].cod);
								if(i == 0)
									strcat(out, "Codigo: ");
								else
									strcat(out, "-Codigo: ");
								
								strcat(out, codigo);
								strcat(out, "\r\n-Nome: ");
								strcat(out, guardar_professores[i].nome);
								strcat(out, "\r\n-Curso: ");
								strcat(out, guardar_alunos[i].curso);
								strcat(out, "\r\n \r\n");
								
								SetWindowText(hEdit[2], out);	
								
							}
						}
						
						break;
					case 13:
						for(i = 0; i < 20; i++){
							DestroyWindow(hEdit[i]);
						}
						
						hEdit[0] = CreateWindowW(L"static", L"Preencha os dados abaixo:", WS_VISIBLE | WS_CHILD, 250,50,200,17, hWnd,NULL,NULL, NULL);
	
						hEdit[1] = CreateWindowW(L"static", L"Codigo(Paciente):", WS_VISIBLE | WS_CHILD, 95,100,140,20, hWnd,NULL,NULL, NULL);
						hEdit[2] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER, 230,100,400,20, hWnd,NULL,NULL, NULL);
						
						hEdit[3] = CreateWindowW(L"Button", L"Mostrar", WS_VISIBLE  | WS_CHILD, 380, 130, 110, 25, hWnd, (HMENU)35, NULL,NULL);
						
						break;
					
					case 35:
						GetWindowText(hEdit[2], codigo, 30);
						cod = atoll(codigo);
						
						if(strlen(codigo) == 0){
							val = MessageBoxW(hWnd,L"Campos nao preenchido", L"Agendamentos", MB_OK | MB_ICONINFORMATION);
						}
						
						else{
							pesquisa = procurar_paciente(cod);
							if(pesquisa == -1){
								val = MessageBoxW(hWnd,L"Paciente nao cadastrado", L"Agendamentos", MB_OK | MB_ICONINFORMATION);
							
							}
							
							else{
								hEdit[5] = CreateWindowW(L"Edit", L"", WS_VISIBLE | ES_AUTOVSCROLL | WS_CHILD | WS_BORDER | ES_MULTILINE , 175,200,400,100, hWnd,NULL,NULL, NULL);
								sprintf(nova_matricula,"%d", cod_age);
								if(i == 0)
									strcat(out, "Codigo(Agendamento): ");
								else
									strcat(out, "-Codigo(Agendamento): ");
								
								strcat(out, nova_matricula);
								strcat(out, "\r\n-Nome(Paciente): ");
								strcat(out, guardar_pacientes[pesquisa].nome);
						
								
								SetWindowText(hEdit[5], out);
								
								hEdit[6] = CreateWindowW(L"static", L"Data(agendamento):", WS_VISIBLE | WS_CHILD, 95,160,150,20, hWnd,NULL,NULL, NULL);
								hEdit[7] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 230,160,400,20, hWnd,NULL,NULL, NULL);
								
								hEdit[8] = CreateWindowW(L"Button", L"Fisioterapia", WS_VISIBLE  | WS_CHILD, 200, 340, 100, 20, hWnd, (HMENU)36, NULL,NULL);
								hEdit[9] = CreateWindowW(L"Button", L"Odontologia", WS_VISIBLE  | WS_CHILD,  320, 340, 100, 20, hWnd, (HMENU)37, NULL,NULL);
								hEdit[10] = CreateWindowW(L"Button", L"Psicologia", WS_VISIBLE  | WS_CHILD, 440, 340, 100, 20, hWnd, (HMENU)38, NULL,NULL);	
								hEdit[11] = CreateWindowW(L"static", L"Escolha a area", WS_BORDER | WS_VISIBLE  | WS_CHILD, 330, 310, 100, 20, hWnd, NULL, NULL,NULL);	
								
							}
						}	
							
							break;
						
						
						case 36:
							GetWindowText(hEdit[7], data, 30);
							if(strlen(data) == 0){
								val = MessageBoxW(hWnd,L"Data(Agendamento) nao preenchida", L"Agendamentos", MB_OK | MB_ICONINFORMATION);	
							}
							
							else{
								strcpy(area, "Fisioterapia");
								GetWindowText(hEdit[2], codigo, 30);
								
								cod = atoll(codigo);
	
								pesquisa_2 = procurar_codigo_agenda(cod);
								flag = 0;
								if(pesquisa_2 != -1){
									for(i = 0; i < cont_agen; i++){
										if(guardar_agendamentos[i].codigo == cod){
											if(strcmp(guardar_agendamentos[i].area, area ) == 0){
												flag = 1;
											}
										}
									}
								}
								
								if(flag == 1){
									val = MessageBoxW(hWnd,L"Paciente com agendamento nessa area", L"Agendamentos", MB_OK | MB_ICONINFORMATION);
									for(i = 4; i <= 11; i++){
										DestroyWindow(hEdit[i]);
									}
									
									break;
								}
								
								s = criar_agenda(cod, area, data);
								salvar_paciente_agenda(s);
								escrever_arquivo_agendamento(guardar_agendamentos);
								escrever_arquivo_cods();
							
								val = MessageBoxW(hWnd,L"Agendamento Salvo", L"Agendamentos", MB_OK | MB_ICONINFORMATION);	
							
								for(i = 4; i <= 11; i++){
									DestroyWindow(hEdit[i]);
								}
							}
					
							break;
							
						case 37:
							GetWindowText(hEdit[7], data, 30);
							if(strlen(data) == 0){
								val = MessageBoxW(hWnd,L"Data(Agendamento) nao preenchida", L"Agendamentos", MB_OK | MB_ICONINFORMATION);	
							}
							
							else{
								strcpy(area, "Odontologia");
								GetWindowText(hEdit[2], codigo, 30);
								
								cod = atoll(codigo);
	
								pesquisa_2 = procurar_codigo_agenda(cod);
								flag = 0;
								if(pesquisa_2 != -1){
									for(i = 0; i < cont_agen; i++){
										if(guardar_agendamentos[i].codigo == cod){
											if(strcmp(guardar_agendamentos[i].area, area ) == 0){
												flag = 1;
											}
										}
									}
								}
								
								if(flag == 1){
									val = MessageBoxW(hWnd,L"Paciente com agendamento nessa area", L"Agendamentos", MB_OK | MB_ICONINFORMATION);
									for(i = 4; i <= 11; i++){
										DestroyWindow(hEdit[i]);
									}
									
									break;
								}
								
								s = criar_agenda(cod, area, data);
								salvar_paciente_agenda(s);
								escrever_arquivo_agendamento(guardar_agendamentos);
							
								val = MessageBoxW(hWnd,L"Agendamento Salvo", L"Agendamentos", MB_OK | MB_ICONINFORMATION);	
							
								for(i = 4; i <= 11; i++){
									DestroyWindow(hEdit[i]);
								}
							}
					
							break;
						
						case 38:
							GetWindowText(hEdit[7], data, 30);
							if(strlen(data) == 0){
								val = MessageBoxW(hWnd,L"Data(Agendamento) nao preenchida", L"Agendamentos", MB_OK | MB_ICONINFORMATION);	
							}
							
							else{
								strcpy(area, "Psicologia");
								GetWindowText(hEdit[2], codigo, 30);
								
								cod = atoll(codigo);
	
								pesquisa_2 = procurar_codigo_agenda(cod);
								flag = 0;
								if(pesquisa_2 != -1){
									for(i = 0; i < cont_agen; i++){
										if(guardar_agendamentos[i].codigo == cod){
											if(strcmp(guardar_agendamentos[i].area, area ) == 0){
												flag = 1;
											}
										}
									}
								}
								
								if(flag == 1){
									val = MessageBoxW(hWnd,L"Paciente com agendamento nessa area", L"Agendamentos", MB_OK | MB_ICONINFORMATION);
									for(i = 4; i <= 11; i++){
										DestroyWindow(hEdit[i]);
									}
									
									break;
								}
								
								s = criar_agenda(cod, area, data);
								salvar_paciente_agenda(s);
								escrever_arquivo_agendamento(guardar_agendamentos);
							
								val = MessageBoxW(hWnd,L"Agendamento Salvo", L"Agendamentos", MB_OK | MB_ICONINFORMATION);	
							
								for(i = 4; i <= 11; i++){
									DestroyWindow(hEdit[i]);
								}
							}
					
							break;
							
						
						
						case 14:
							for(i = 0; i < 20; i++){
								DestroyWindow(hEdit[i]);
							}
						
							hEdit[0] = CreateWindowW(L"static", L"Digite o codigo do agendamento que quer remover:", WS_VISIBLE | WS_CHILD , 200,50,350,17, hWnd,NULL,NULL, NULL);
						
							hEdit[1] = CreateWindowW(L"static", L"Codigo(Agendamento):", WS_VISIBLE | WS_CHILD, 80,100,150,20, hWnd,NULL,NULL, NULL);
							hEdit[2] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 230,100,400,20, hWnd,NULL,NULL, NULL);
						
							hEdit[3] = CreateWindowW(L"Button", L"Mostrar", WS_VISIBLE  | WS_CHILD, 350, 130, 100, 25, hWnd, (HMENU)39,NULL,NULL);
						
							break;
							
						case 39:
							GetWindowText(hEdit[2], codigo, 30);
							cod = atoll(codigo);
						
							if(strlen(codigo) == 0){
								val = MessageBoxW(hWnd,L"Campo nao preenchido", L"Agendamentos", MB_OK | MB_ICONINFORMATION);					
							}
						
							else{
								pesquisa = procurar_codigo_agendamento(cod);
								if (pesquisa == -1){
									val = MessageBoxW(hWnd,L"Agendamento nao cadastrado", L"Agendamentos", MB_OK | MB_ICONINFORMATION);	
								}
							
							else{
								hEdit[5] = CreateWindowW(L"Button", L"Remover", WS_VISIBLE | WS_CHILD, 250, 320, 200, 50, hWnd, (HMENU)40, NULL, NULL);
								hEdit[6] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | WS_BORDER | ES_MULTILINE , 165,200,400,100, hWnd,NULL,NULL, NULL);
								
								sprintf(codigo, "%llu", guardar_agendamentos[pesquisa].codigo);
								strcat(out, "Codigo(Paciente): ");
								strcat(out, codigo);
								strcat(out, "\r\n-Nome: ");
								strcat(out, guardar_agendamentos[pesquisa].nome);
								strcat(out, "\r\n-Area(Atendimento): ");
								strcat(out, guardar_agendamentos[pesquisa].area);
								strcat(out, "\r\n-Data(Consulta): ");
								strcat(out, guardar_agendamentos[pesquisa].data);
								
								
								
								SetWindowText(hEdit[6], out);	
							}
						}	
						
							break;
						
						case 40:
							GetWindowText(hEdit[2], codigo, 30);
							cod = atoll(codigo);
						
							if(procurar_codigo_agendamento(cod) != - 1){
								remover_paciente_agenda(cod);
								escrever_arquivo_agendamento(guardar_agendamentos);
								val = MessageBoxW(hWnd,L"Aluno removido", L"Agendamentos", MB_OK | MB_ICONINFORMATION);
								DestroyWindow(hEdit[5]);	
								DestroyWindow(hEdit[6]);
							}
						
							else{
								val = MessageBoxW(hWnd,L"Nao inserido ou nao cadastrado", L"Agendamentos", MB_OK | MB_ICONINFORMATION);
							}
						
							break;
						
						case 15:
							for(i = 0; i < 20; i++){
								DestroyWindow(hEdit[i]);
							}
						
							hEdit[0] = CreateWindowW(L"static", L"Alunos Cadastrados:", WS_VISIBLE | WS_CHILD , 300,50,350,17, hWnd,NULL,NULL, NULL);
							hEdit[2] = CreateWindowW(L"Edit", L"", WS_VISIBLE | ES_AUTOVSCROLL | WS_CHILD | WS_BORDER | ES_MULTILINE , 125,100,500,400, hWnd,NULL,NULL, NULL);
						
							if(cont_agen == 0){
								SetWindowText(hEdit[2], "                                Nenhum agendamento cadastrado");
							}
							
								
							else{
								for(i = 0; i < cont_agen; i++){
									if(i == 0)
										strcat(out, "Codigo(Agendamento): ");
									else
										strcat(out, "-Codigo(Agendamento): ");
									
									sprintf(codigo,"%llu", guardar_agendamentos[i].cod_agend);
									strcat(out, codigo);
									strcat(out, "\r\n-Codigo(Paciente): ");
									sprintf(codigo, "%llu", guardar_agendamentos[i].codigo);
									strcat(out, codigo);
									strcat(out, "\r\n-Nome: ");
									strcat(out, guardar_agendamentos[i].nome);
									strcat(out, "\r\n-Area(Atendimento): ");
									strcat(out, guardar_agendamentos[i].area);
									strcat(out, "\r\n-Data(Consulta): ");
									strcat(out, guardar_agendamentos[i].data);
									strcat(out, "\r\n \r\n");
									
									
									SetWindowText(hEdit[2], out);
								}	
							}
							
							break;
						
						case 16:
							for(i = 0; i < 20; i++){
								DestroyWindow(hEdit[i]);
						}
						
						
							hEdit[0] = CreateWindowW(L"static", L"Preencha os dados abaixo:", WS_VISIBLE | WS_CHILD, 250,50,200,17, hWnd,NULL,NULL, NULL);
	
							hEdit[1] = CreateWindowW(L"static", L"Codigo(Agendamento):", WS_VISIBLE | WS_CHILD, 90,100,150,20, hWnd,NULL,NULL, NULL);
							hEdit[2] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER, 240,100,400,20, hWnd,NULL,NULL, NULL);
							hEdit[3] = CreateWindowW(L"Button", L"Mostrar", WS_VISIBLE  | WS_CHILD, 380, 130, 110, 25, hWnd, (HMENU)41, NULL,NULL);
							
							break;
							
						case 41:
							GetWindowText(hEdit[2], codigo, 30);
							cod = atoll(codigo);
						
							if(strlen(codigo) == 0){
								val = MessageBoxW(hWnd,L"Campos nao preenchido", L"Atendimentos", MB_OK | MB_ICONINFORMATION);
							}
						
							else{
								pesquisa = procurar_codigo_agendamento(cod);
								if(pesquisa == -1){
									val = MessageBoxW(hWnd,L"Agendamento nao cadastrado", L"Atendimentos", MB_OK | MB_ICONINFORMATION);
								}
							
								else{
									hEdit[4] = CreateWindowW(L"Edit", L"", WS_VISIBLE | ES_AUTOVSCROLL | WS_CHILD | WS_BORDER | ES_MULTILINE , 175,160,400,100, hWnd,NULL,NULL, NULL);
									if(i == 0)
										strcat(out, "Codigo(Atendimento): ");
									else
										strcat(out, "-Codigo(Atendimento): ");
									
									sprintf(curso, "%d", cod_atendimento);
									strcat(out, curso);
									strcat(out, "\r\n-Nome(Paciente): ");
									strcat(out, guardar_agendamentos[pesquisa].nome);
									strcat(out, "\r\n-Codigo(Paciente): ");
									sprintf(curso, "%llu", guardar_agendamentos[pesquisa].codigo);
									strcat(out, curso);
									strcat(out, "\r\n-Area: ");
									strcat(out, guardar_agendamentos[pesquisa].area);
									strcat(out, "\r\n-Data(Agendamento): ");
									strcat(out, guardar_agendamentos[pesquisa].data);
									
									SetWindowText(hEdit[4], out);
									
									hEdit[5] = CreateWindowW(L"static", L"Data(Atendimento):", WS_VISIBLE | WS_CHILD, 95,270,150,20, hWnd,NULL,NULL, NULL);
									hEdit[6] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 240,270,400,20, hWnd,NULL,NULL, NULL);
									
									hEdit[7] = CreateWindowW(L"static", L"Matricula(Aluno):", WS_VISIBLE | WS_CHILD, 95,298,150,20, hWnd,NULL,NULL, NULL);
									hEdit[8] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 240,298,400,20, hWnd,NULL,NULL, NULL);
									
									hEdit[9] = CreateWindowW(L"static", L"Codigo(Professor):", WS_VISIBLE | WS_CHILD, 95,326,150,20, hWnd,NULL,NULL, NULL);
									hEdit[10] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 240,326,400,20, hWnd,NULL,NULL, NULL);
									
									hEdit[11] = CreateWindowW(L"Button", L"Cadastrar", WS_VISIBLE  | WS_CHILD, 350, 354, 100, 25, hWnd, (HMENU)42,NULL,NULL);
								}
							}	
						
								break;
					
							case 42:
								GetWindowText(hEdit[2], codigo, 30);
								GetWindowText(hEdit[6], data, 30);
								GetWindowText(hEdit[8], a1, 30);
								GetWindowText(hEdit[10], b1, 30);
								
								if(strlen(data) == 0 || strlen(a1) == 0 || strlen(b1) == 0){
									val = MessageBoxW(hWnd,L"Campo nao preenchido", L"Atendimentos", MB_OK | MB_ICONINFORMATION);		
								}
								
								else{
									cod = atoll(codigo);
									code = atoll(a1);
									codinho = atoll(b1);
									if(procurar_aluno(code) == -1 || procurar_professor(codinho) == -1){
										val = MessageBoxW(hWnd,L"Aluno ou Professor nao existe", L"Atendimentos", MB_OK | MB_ICONINFORMATION);
									}
									
									else{
										val = MessageBoxW(hWnd,L"Atendimento cadastrado", L"Atendimentos", MB_OK | MB_ICONINFORMATION);
										t = criar_atendimento(cod, code, codinho, data);
										salvar_atendimento(t);
										remover_paciente_agenda(cod);
										escrever_arquivo_agendamento(guardar_agendamentos);
										escrever_arquivo_atendimento(guardar_atendimentos);
										escrever_arquivo_cods();
									}
								}
								
								
								break;
					
							case 17:
								for(i = 0; i < 20; i++){
									DestroyWindow(hEdit[i]);
								}
								
								hEdit[0] = CreateWindowW(L"static", L"Digite o codigo do atendimento que quer remover:", WS_VISIBLE | WS_CHILD , 200,50,350,17, hWnd,NULL,NULL, NULL);
						
								hEdit[1] = CreateWindowW(L"static", L"Codigo(Atendimento):", WS_VISIBLE | WS_CHILD, 80,100,150,20, hWnd,NULL,NULL, NULL);
								hEdit[2] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | SS_CENTER | WS_BORDER , 230,100,400,20, hWnd,NULL,NULL, NULL);
							
								hEdit[3] = CreateWindowW(L"Button", L"Mostrar", WS_VISIBLE  | WS_CHILD, 350, 130, 100, 25, hWnd, (HMENU)43,NULL,NULL);
						
								
								break;
							
							
							case 43:
								GetWindowText(hEdit[2], codigo, 30);
								cod = atoll(codigo);
							
								if(strlen(codigo) == 0){
									val = MessageBoxW(hWnd,L"Campo nao preenchido", L"Agendamentos", MB_OK | MB_ICONINFORMATION);					
								}
							
								else{
									pesquisa = procurar_atendimento(cod);
									if (pesquisa == -1){
										val = MessageBoxW(hWnd,L"Atendimento nao cadastrado", L"Agendamentos", MB_OK | MB_ICONINFORMATION);	
									}
								
								else{
									hEdit[5] = CreateWindowW(L"Button", L"Remover", WS_VISIBLE | WS_CHILD, 250, 420, 250, 50, hWnd, (HMENU)44, NULL, NULL);
									hEdit[6] = CreateWindowW(L"Edit", L"", WS_VISIBLE  | WS_CHILD | WS_BORDER | ES_MULTILINE , 165,200,400,200, hWnd,NULL,NULL, NULL);
									
									
							
									sprintf(codigo, "%d", guardar_atendimentos[pesquisa].cod_agend);
									strcat(out, "Codigo(Agendamento): ");
									strcat(out, codigo);
									sprintf(codigo, "%llu", guardar_atendimentos[pesquisa].cod_pacie);
									strcat(out, "\r\n-Codigo(Paciente): ");
									strcat(out, codigo);
									strcat(out, "\r\n-Nome(Paciente): ");
									strcat(out, guardar_atendimentos[pesquisa].nome_paciente);
									strcat(out, "\r\n-Area(Atendimento): ");
									strcat(out, guardar_atendimentos[pesquisa].serv_prestado);
									strcat(out, "\r\n-Nome(Aluno): ");
									strcat(out, guardar_atendimentos[pesquisa].nome_aluno);
									strcat(out, "\r\n-Codigo(Aluno): ");
									sprintf(codigo, "%llu", guardar_atendimentos[pesquisa].cod_aluno);
									strcat(out, codigo);
									strcat(out, "\r\n-Nome(Professor): ");
									strcat(out, guardar_atendimentos[pesquisa].nome_supervisor);
									strcat(out, "\r\n-Codigo(Professor): ");
									sprintf(codigo, "%llu", guardar_atendimentos[pesquisa].cod_super);
									strcat(out, "\r\n-Data(Atendimento): ");
									strcat(out, guardar_atendimentos[pesquisa].data_atendimento);
									strcat(out, "\r\n-Data(Agendamento): ");
									strcat(out, guardar_atendimentos[pesquisa].data_agendamento);
								
									
									SetWindowText(hEdit[6], out);	
								}
							}	
								break;
									
							case 44:
								GetWindowText(hEdit[2], codigo, 30);
								cod = atoll(codigo);
								
								
								if(strlen(codigo) == 0){
									val = MessageBoxW(hWnd,L"Campo nao preenchido", L"Atendimentos", MB_OK | MB_ICONINFORMATION);	
								}
								
								else{
									
									remover_atendimento(cod);
									escrever_arquivo_atendimento(guardar_atendimentos);
									val = MessageBoxW(hWnd,L"Atendimento removido", L"Atendiemntos", MB_OK | MB_ICONINFORMATION);
									
									for(i = 4; i <= 6; i++){
										DestroyWindow(hEdit[i]);
									}
								}
								
								break;
							
							case 18:
								for(i = 0; i <= 20; i++){
										DestroyWindow(hEdit[i]);
									}
									
								hEdit[0] = CreateWindowW(L"static", L"Atendimentos Cadastrados:", WS_VISIBLE | WS_CHILD , 300,50,350,17, hWnd,NULL,NULL, NULL);
								hEdit[2] = CreateWindowW(L"Edit", L"", WS_VISIBLE | ES_AUTOVSCROLL | WS_CHILD | WS_BORDER | ES_MULTILINE , 125,100,500,400, hWnd,NULL,NULL, NULL);
						
								if(cont_atendimento == 0){
									SetWindowText(hEdit[2], "                                           Nenhum atendimento cadastrado");
								}
						
								else{
								
									for(i = 0; i < cont_atendimento; i++){
										sprintf(codigo,"%d", guardar_atendimentos[i].cod_atend);
										if(i == 0)
											strcat(out, "Codigo(Atendimento): ");
										else
											strcat(out, "-Codigo(Atendimento): ");
											
											strcat(out, codigo);
										
										printar_atendimentos(out, i);
										
										SetWindowText(hEdit[2], out);
									}
								}
								
								break;
							case 19:
								for(i = 0; i <= 20; i++){
										DestroyWindow(hEdit[i]);
									}
									
								hEdit[0] = CreateWindowW(L"static", L"Atendimentos Cadastrados(Area):", WS_VISIBLE | WS_CHILD , 250,50,350,17, hWnd,NULL,NULL, NULL);
								hEdit[1] = CreateWindowW(L"static", L"Digite a area abaixo (Fisioterapia, Odontologia ou Psicologia) :", WS_VISIBLE | WS_CHILD , 160,100,500,17, hWnd,NULL,NULL, NULL);
								hEdit[2] = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 200,125,350,25, hWnd,NULL,NULL, NULL);
								hEdit[3] = CreateWindowW(L"Button", L"Mostrar", WS_VISIBLE  | WS_CHILD, 340, 150, 110, 25, hWnd, (HMENU)45, NULL,NULL);
					
								break;
							
							case 45:
								contador = 0;
								GetWindowText(hEdit[2], codigo, 30);
								
								
								if(strlen(codigo) == 0){
									val = MessageBoxW(hWnd,L"Campo nao preenchido", L"Atendimentos", MB_OK | MB_ICONINFORMATION);	
								}
								
								else{
									if(strcmp(codigo, "Fisioterapia") == 0  || strcmp(codigo, "Odontologia") == 0 || strcmp(codigo, "Psicologia") == 0){
										for(i = 0; i < cont_atendimento; i++){
												if(strcmp(guardar_atendimentos[i].serv_prestado, codigo) == 0){
													contador++;
												}
											}
											
											if(contador == 0){
												val = MessageBoxW(hWnd,L"Atendimento nao cadastrados", L"Atendimentos", MB_OK | MB_ICONINFORMATION);	
											}
											
											else{
												hEdit[4] = CreateWindowW(L"Edit", L"", WS_VISIBLE | ES_AUTOVSCROLL | WS_CHILD | WS_BORDER | ES_MULTILINE , 125,200,500,300, hWnd,NULL,NULL, NULL);
												for(i = 0; i < cont_atendimento; i++){
													if(strcmp(guardar_atendimentos[i].serv_prestado, codigo) == 0){
														sprintf(codigo,"%d", guardar_atendimentos[i].cod_atend);
														if(i == 0)
															strcat(out, "Codigo(Atendimento): ");
														else
															strcat(out, "-Codigo(Atendimento): ");
												
														strcat(out, codigo);
														printar_atendimentos(out, i);
											
														SetWindowText(hEdit[4], out);
													
													}
												}
											}	
										}		 
								
									
									else{
										val = MessageBoxW(hWnd,L"Area digitada incorreta", L"Atendimentos", MB_OK | MB_ICONINFORMATION);	
								
									}
								}
							
								break;
							
							case 70:
								for(i = 0; i <= 20; i++){
										DestroyWindow(hEdit[i]);
									}
									
								hEdit[0] = CreateWindowW(L"static", L"Atendimentos Cadastrados(Area):", WS_VISIBLE | WS_CHILD , 250,50,350,17, hWnd,NULL,NULL, NULL);
								hEdit[1] = CreateWindowW(L"static", L"Digite a Codigo(Aluno): ", WS_VISIBLE | WS_CHILD , 90,100,500,17, hWnd,NULL,NULL, NULL);
								hEdit[2] = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 250,100,350,20, hWnd,NULL,NULL, NULL);
								hEdit[3] = CreateWindowW(L"Button", L"Mostrar", WS_VISIBLE  | WS_CHILD, 370, 125, 110, 25, hWnd, (HMENU)46, NULL,NULL);
								
								break;
							
							case 46:
					
								contador = 0;
								GetWindowText(hEdit[2], codigo, 30);
								cod = atoll(codigo);
							
								if(strlen(codigo) == 0){
									val = MessageBoxW(hWnd,L"Campo nao preenchido", L"Atendimentos", MB_OK | MB_ICONINFORMATION);	
								}
							
								else{
									for(i = 0; i < cont_atendimento; i++){
										if(guardar_atendimentos[i].cod_aluno == cod){
											contador++;
											}
										}
									
										if(contador == 0){
											val = MessageBoxW(hWnd,L"Atendimento nao cadastrados", L"Atendimentos", MB_OK | MB_ICONINFORMATION);	
										}
										
										else{
											hEdit[4] = CreateWindowW(L"Edit", L"", WS_VISIBLE | ES_AUTOVSCROLL | WS_CHILD | WS_BORDER | ES_MULTILINE , 125,200,500,300, hWnd,NULL,NULL, NULL);
											for(i = 0; i < cont_atendimento; i++){
												if(guardar_atendimentos[i].cod_aluno == cod){
													sprintf(codigo,"%d", guardar_atendimentos[i].cod_atend);
													if(i == 0)
														strcat(out, "Codigo(Atendimento): ");
													else
														strcat(out, "-Codigo(Atendimento): ");
											
													strcat(out, codigo);
													printar_atendimentos(out, i);
										
													SetWindowText(hEdit[4], out);
												
												}
											}
										}	
									}		 
								break;
								
							case 71:
								for(i = 0; i <= 20; i++){
									DestroyWindow(hEdit[i]);
								}
									
								hEdit[0] = CreateWindowW(L"static", L"Atendimentos Cadastrados(Area):", WS_VISIBLE | WS_CHILD , 250,50,350,17, hWnd,NULL,NULL, NULL);
								hEdit[1] = CreateWindowW(L"static", L"Digite o Codigo(Paciente): ", WS_VISIBLE | WS_CHILD , 90,100,500,17, hWnd,NULL,NULL, NULL);
								hEdit[2] = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 270,100,350,20, hWnd,NULL,NULL, NULL);
								hEdit[3] = CreateWindowW(L"Button", L"Mostrar", WS_VISIBLE  | WS_CHILD, 370, 125, 110, 25, hWnd, (HMENU)47, NULL,NULL);
									
								break;	
								
							case 47:
								contador = 0;
								GetWindowText(hEdit[2], codigo, 30);
								cod = atoll(codigo);
							
								if(strlen(codigo) == 0){
									val = MessageBoxW(hWnd,L"Campo nao preenchido", L"Atendimentos", MB_OK | MB_ICONINFORMATION);	
								}
							
								else{
									for(i = 0; i < cont_atendimento; i++){
										if(guardar_atendimentos[i].cod_pacie == cod){
											contador++;
											}
										}
									
										if(contador == 0){
											val = MessageBoxW(hWnd,L"Atendimento nao cadastrados", L"Atendimentos", MB_OK | MB_ICONINFORMATION);	
										}
										
										else{
											hEdit[4] = CreateWindowW(L"Edit", L"", WS_VISIBLE | ES_AUTOVSCROLL | WS_CHILD | WS_BORDER | ES_MULTILINE , 125,200,500,300, hWnd,NULL,NULL, NULL);
											for(i = 0; i < cont_atendimento; i++){
												if(guardar_atendimentos[i].cod_pacie == cod){
													sprintf(codigo,"%d", guardar_atendimentos[i].cod_atend);
													if(i == 0)
														strcat(out, "Codigo(Atendimento): ");
													else
														strcat(out, "-Codigo(Atendimento): ");
											
													strcat(out, codigo);
													printar_atendimentos(out, i);
										
													SetWindowText(hEdit[4], out);
												
												}
											}
										}	
									}		 
								break;
								
							case 72:
								for(i = 0; i <= 20; i++){
										DestroyWindow(hEdit[i]);
									}
								
								hEdit[0] = CreateWindowW(L"static", L"Criador: Sidney Gomes Barbosa", WS_VISIBLE | WS_CHILD , 250,50,350,17, hWnd,NULL,NULL, NULL);
								hEdit[1] = CreateWindowW(L"static", L"Curso: Ciencia da Computacao", WS_VISIBLE | WS_CHILD , 250,70,350,17, hWnd,NULL,NULL, NULL);
								hEdit[2] = CreateWindowW(L"static", L"Matricula: 171080238", WS_VISIBLE | WS_CHILD , 250,70,350,17, hWnd,NULL,NULL, NULL);
								hEdit[3] = CreateWindowW(L"static", L"Versao: 2.0", WS_VISIBLE | WS_CHILD , 700,500,350,17, hWnd,NULL,NULL, NULL);
								
					
							
								
								
						break;
				}
			
			case WM_CREATE:
				Adic_menus(hWnd);		
				break;

			case WM_DESTROY:
				PostQuitMessage(0);
				break;
		
			default:
				DefWindowProcW(hWnd, msg, a, b);	
	}
}


void Adic_menus(HWND hWnd){
	hMenu = CreateMenu();
	HMENU hAlunoMenu = CreateMenu();
	HMENU hPacienteMenu = CreateMenu();
	HMENU hProfessorMenu = CreateMenu();
	HMENU hAgendamentoMenu = CreateMenu();
	HMENU hAtendimentoMenu = CreateMenu();
	HMENU hSobreMenu = CreateMenu();
	
	AppendMenu(hAlunoMenu, MF_STRING, 1, "Cadastrar");
	AppendMenu(hAlunoMenu, MF_STRING, 2, "Remover");
	AppendMenu(hAlunoMenu, MF_STRING, 3, "Editar");
	AppendMenu(hAlunoMenu, MF_STRING, 4, "Visualizar");
	
	AppendMenu(hPacienteMenu, MF_STRING, 5, "Cadastrar");
	AppendMenu(hPacienteMenu, MF_STRING, 6, "Remover");
	AppendMenu(hPacienteMenu, MF_STRING, 7, "Editar");
	AppendMenu(hPacienteMenu, MF_STRING, 8, "Visualizar");
	
	AppendMenu(hProfessorMenu, MF_STRING, 9, "Cadastrar");
	AppendMenu(hProfessorMenu, MF_STRING, 10, "Remover");
	AppendMenu(hProfessorMenu, MF_STRING, 11, "Editar");
	AppendMenu(hProfessorMenu, MF_STRING, 12, "Visualizar");
	
	AppendMenu(hAgendamentoMenu, MF_STRING, 13, "Cadastrar");
	AppendMenu(hAgendamentoMenu, MF_STRING, 14, "Remover");
	AppendMenu(hAgendamentoMenu, MF_STRING, 15, "Visualizar");
	
	AppendMenu(hAtendimentoMenu, MF_STRING, 16, "Cadastrar");
	AppendMenu(hAtendimentoMenu, MF_STRING, 17, "Remover");
	AppendMenu(hAtendimentoMenu, MF_STRING, 18, "Visualizar Todos");
	AppendMenu(hAtendimentoMenu, MF_STRING, 19, "Visualizar Area");
	AppendMenu(hAtendimentoMenu, MF_STRING, 70, "Visualizar Aluno");
	AppendMenu(hAtendimentoMenu, MF_STRING, 71, "Visualizar Paciente");
	
	AppendMenu(hSobreMenu, MF_STRING, 72, "Creditos");

	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hAlunoMenu, "Alunos");
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hPacienteMenu, "Pacientes");
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hProfessorMenu, "Professores");
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hAgendamentoMenu, "Agendamentos");
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hAtendimentoMenu, "Atendimentos");
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSobreMenu, "Sobre");
	
	SetMenu(hWnd, hMenu);
		
}




