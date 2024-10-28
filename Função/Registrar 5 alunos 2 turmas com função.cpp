#include <stdio.h>

struct Registro_Nascimento
{
	int Dia;
	int Mes;
	int Ano;
};

struct Registro_Alunos
{
	char Nome[100];
	float Notas[3];
	struct Registro_Nascimento Data;
	float mediaind;
}
Aluno[2][5];

struct Media_Turmas{
	float mediatotal;
}
Turma[2];

int i=0, j=0;

int main(){
	
	printf("\n---------- Cadastro de alunos ----------\n\n");
	
	void Registrar_Alunos ();
	Registrar_Alunos ();
	
	void Media_Total ();
	Media_Total ();
	
	printf("\n---------- Leitura dos dados ----------\n\n");
	
	for(j=0; j<2; j++){
		printf("A media total da turma %d eh: %.2f\n", j+1, Turma[j].mediatotal);
	}
	
	void Resultado ();
	Resultado ();
	
	return 0;
}

void Registrar_Alunos (){
	for(j=0; j<2; j++){
		for(i=0; i<5; i++){
		printf("\nInsira o nome do aluno %d da turma %d: ", i+1, j+1);
		scanf("%s", &Aluno[j][i].Nome);
		
		printf("Digite as 3 notas do aluno(a) %d da turma %d:\n", i+1, j+1);
		scanf("%f", &Aluno[j][i].Notas[0]);
		scanf("%f", &Aluno[j][i].Notas[1]);
		scanf("%f", &Aluno[j][i].Notas[2]);
		
		Aluno[j][i].mediaind = (Aluno[j][i].Notas[0] + Aluno[j][i].Notas[1] + Aluno[j][i].Notas[2])/3;
		Turma[j].mediatotal = Aluno[j][i].mediaind + Turma[j].mediatotal;
	
		printf("Digite a data de nascimento da do aluno(a) %d da turma %d, composto por dia, mes e ano:\n", i+1, j+1);
		scanf("%d", &Aluno[j][i].Data.Dia);
		scanf("%d", &Aluno[j][i].Data.Mes);
		scanf("%d", &Aluno[j][i].Data.Ano);
		}
	}
}

void Media_Total (){
	for(j=0; j<2; j++){
		Turma[j].mediatotal = Turma[j].mediatotal/5;
	}
}

void Resultado (){
	for(j=0; j<2; j++){
		printf("--Turma %d--", j+1);
		for(i=0; i<5; i++){
			if(Aluno[j][i].mediaind >= Turma[j].mediatotal){
				printf("\nAluno(a): %s\nEsta acima da media, com media: %.2f\nSua data de nascimento eh: %d/%d/%d\nSuas notas sao: %.2f, %.2f e %.2f\n", Aluno[j][i].Nome, Aluno[j][i].mediaind, Aluno[j][i].Data.Dia, Aluno[j][i].Data.Mes, Aluno[j][i].Data.Ano, Aluno[j][i].Notas[0], Aluno[j][i].Notas[1], Aluno[j][i].Notas[2]);
			}
		}
	}
}
