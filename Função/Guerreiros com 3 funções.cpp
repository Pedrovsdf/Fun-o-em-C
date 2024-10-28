#include <stdio.h>
#include <string.h>

struct Personagens
{
	char Nome[30];//Nome do personagem.
	int Poder_Atk_Total;//Poder de ataque total, o poder de ataque base ser� somado ao ataque da classe e armazenado aqui.
	int Poder_Def_Total;//Poder de defesa total, o poder de defesa base ser� somado a defesa da classe e armazenado aqui.
	int Poder_Atk_Base;//Poder de ataque base, o usu�rio ir� digitar.
	int Poder_Def_Base;//Poder de defesa base, o usu�rio ir� digitar.
	int Nivel;//N�vel do personagem.
};

struct Classe_Guerreiro
{
	int Ataque;//Ataque base de cada classe: Barbaro +25 atk, Espadachim +15 atk, Lefou +5 atk.
	int Defesa;//Defesa base de cada classe: Barbaro +5 def, Espadachim +15 def, Lefou +25 def.
	char Habilidade_de_Classe[30];//Habilidade caracter�stica de cada classe: Barbaro, F�ria; Espadachim, Espada Divina; Lefou, Sangue �cido.
};

struct Guerreiros
{
	struct Personagens Personagem;
	struct Classe_Guerreiro Classe;
}
Guerreiro[3];

int i=0, j=0, Atk[3], Def[3];//Vari�veis globais, usadas no main e nas fun��es.

int main(){
	int k=1;//Vari�vel para checar se o usu�rio digitou uma classe v�lida, se sim, ela receber� o valor 0.
	char classe[20];//Vari�vel para armazenar a classe escolhida.
	
	for(i = 0; i < 3; i++){
		printf("\nDigite o nome do personagem %d: ", i+1);//Print e scan para obter o nome do personagem na posi��o i.
		scanf("%s", &Guerreiro[i].Personagem.Nome);
		
		do{
		printf("Digite a raca do personagem %d: ", i+1);//Print e scan para obter a classe do personagem na posi��o i.
		scanf("%s", &classe);
		
		if( strcmp (classe,"Barbaro")==0){//Se o usu�rio digitar "Barbaro" ir� entrar nesse if.
			printf("A classe escolhida foi Barbaro\n");//Print para mostrar a classe escolhida.
			Guerreiro[i].Classe.Ataque = 25;//A vari�vel "Ataque" dentro da struct "Classe" ir� armazenar o ataque base de um Barbaro.
			Guerreiro[i].Classe.Defesa = 5;//A vari�vel "Defesa" dentro da struct "Classe" ir� armazenar a defesa base de um Barbaro.
			strcpy(Guerreiro[i].Classe.Habilidade_de_Classe, "Furia");//A vari�vel "Habilidade_de_Classe" dentro da struct "Classe" ir� armazenar "Furia".
			k = 0;
		}
		else if( strcmp (classe,"Espadachim")==0){//Se o usu�rio digitar "Espadachim" ir� entrar nesse if.
			printf("A classe escolhida foi Espadachim\n");//Print para mostrar a classe escolhida.
			Guerreiro[i].Classe.Ataque = 15;//A vari�vel "Ataque" dentro da struct "Classe" ir� armazenar o ataque base de um Espadachim.
			Guerreiro[i].Classe.Defesa = 15;//A vari�vel "Defesa" dentro da struct "Classe" ir� armazenar a defesa base de um Espadachim.
			strcpy(Guerreiro[i].Classe.Habilidade_de_Classe, "Espada_Divina");//A vari�vel "Habilidade_de_Classe" dentro da struct "Classe" ir� armazenar "Espada_Divina".
			k = 0;
		}
		else if( strcmp (classe,"Lefou")==0){//Se o usu�rio digitar "Lefou" ir� entrar nesse if.
			printf("A classe escolhida foi Lefou\n");//Print para mostrar a classe escolhida.
			Guerreiro[i].Classe.Ataque = 5;//A vari�vel "Ataque" dentro da struct "Classe" ir� armazenar o ataque base de um Lefou.
			Guerreiro[i].Classe.Defesa = 25;//A vari�vel "Defesa" dentro da struct "Classe" ir� armazenar a defesa base de um Lefou.
			strcpy(Guerreiro[i].Classe.Habilidade_de_Classe, "Sangue_Acido");//A vari�vel "Habilidade_de_Classe" dentro da struct "Classe" ir� armazenar "Sangue_Acido".
			k = 0;
		}
		else{
			printf("Essa classe nao existe, digite uma classe valida.\n");//Print caso o usu�rio n�o tiver digitado uma classe v�lida, ent�o ir� repetir a opera��o.
			k=1;
		}
		}while (k==1);
		
		printf("Insira o poder de ataque do personagem %d: ", i+1);//Print e scan para armazenar o ataque base do personagem.
		scanf("%d", &Guerreiro[i].Personagem.Poder_Atk_Base);
		printf("Insira o poder de defesa do personagem %d: ", i+1);//Print e scan para armazenar a defesa base do personagem.
		scanf("%d", &Guerreiro[i].Personagem.Poder_Def_Base);
		printf("Digite o nivel do personagem %d: ", i+1);//Print e scan para armazenar o n�vel do personagem.
		scanf("%d", &Guerreiro[i].Personagem.Nivel);
		
		Guerreiro[i].Personagem.Poder_Atk_Total = Guerreiro[i].Personagem.Poder_Atk_Base + Guerreiro[i].Classe.Ataque;//A vari�vel "Poder_Atk_Total" dentro da struct "Personagem" ir� armazenar o ataque base somado com o ataque da classe.
		Guerreiro[i].Personagem.Poder_Def_Total = Guerreiro[i].Personagem.Poder_Def_Base + Guerreiro[i].Classe.Defesa;//A vari�vel "Poder_Def_Total" dentro da struct "Personagem" ir� armazenar a defesa base somado com a defesa da classe.
		
		Atk[i] = Guerreiro[i].Personagem.Poder_Atk_Total;//O vetor Atk na posi��o i ir� armazenar o valor do ataque total do guerreiro na posi��o i.
		Def[i] = Guerreiro[i].Personagem.Poder_Def_Total;//O vetor Def na posi��o i ir� armazenar o valor da defesa total do guerreiro na posi��o i.
	}
	
	void bubble_sort (int vetor[], int n);//Declara��o da fun��o "bubble_sort".
	bubble_sort (Atk, 3);//O vetor Atk ser� ordenado dentro da fun��o "bubble_sort", em ordem decrescente.
	bubble_sort (Def, 3);//O vetor Def ser� ordenado dentro da fun��o "bubble_sort", em ordem decrescente.
	
	void Posicao_Atk (void);//Declara��o da fun��o "Posicao_Atk".
	Posicao_Atk ();//Chamando a fun��o "Posi��o_Atk".
	
	printf("\n");
	
	void Posicao_Def (void);//Declara��o da fun��o "Posicao_Def".
	Posicao_Def ();//Chamando a fun��o "Posi��o_Def".
	
	return 0;//Fim do programa.
}

void bubble_sort (int vetor[], int n){
    int aux;//Vari�vel auxiliar.

    for(i = 1; i < n; i++){
        for(j = 0; j < n-1; j++){
            if(vetor[j] < vetor[j+1]){//Se o vetor na posi��o j for menor que o vetor na posi��o j+1 entrar� nesse if.
                aux = vetor[j];//A vari�vel auxiliar ir� receber o valor do vetor na posi��o j.
                vetor[j] = vetor[j+1];//O vetor na posi��o j ir� receber o valor do vetor na posi��o j+1.
                vetor[j+1] = aux;//O vetor na posi��o j+1 ir� receber o valor da vari�vel auxiliar.
            }
        }
    }
}

void Posicao_Atk (void){
	for(i = 0; i < 3; i++){
		printf("\n--- Personagem com posicao %d em ataque ---\n\n", i+1);//Print para mostrar que personagem est� em determinada posi��o no ranking de ataque.
		for(j = 0; j < 3; j++)
		if(Atk[i] == Guerreiro[j].Personagem.Poder_Atk_Total){//Se o vetor Atk na posi��o i tiver o valor igual a vari�vel "Poder_Atk_Total" ir� entrar no if.
			printf("Nome: %s\n", Guerreiro[j].Personagem.Nome);//Ir� imprimir o nome do personagem na posi��o j.
			
			if( strcmp (Guerreiro[j].Classe.Habilidade_de_Classe,"Furia")==0){//Se a habilidade de classe do personagem na posi��o j for "Furia" ir� mostrar que ele � um Barbaro.
				printf("Classe: Barbaro\n");
			}
			else if( strcmp (Guerreiro[j].Classe.Habilidade_de_Classe,"Espada_Divina")==0){//Se a habilidade de classe do personagem na posi��o j for "Espada_Divina" ir� mostrar que ele � um Espadachim.
				printf("Classe: Espadachim\n");
			}
			else if( strcmp (Guerreiro[j].Classe.Habilidade_de_Classe,"Sangue_Acido")==0){//Se a habilidade de classe do personagem na posi��o j for "Sangue_Acido" ir� mostrar que ele � um Lefou.
				printf("Classe: Lefou\n");
			}
			
			printf("Habilidade de classe: %s\n", Guerreiro[j].Classe.Habilidade_de_Classe);//Ir� imprimir a habilidade de classe do personagem na posi��o j.
			printf("Poder de ataque: %d\n", Guerreiro[j].Personagem.Poder_Atk_Total);//Ir� imprimir o valor de ataque total do personagem na posi��o j.
			printf("Poder de defesa: %d\n", Guerreiro[j].Personagem.Poder_Def_Total);//Ir� imprimir o valor de defesa total do personagem na posi��o j.
			printf("Nivel: %d", Guerreiro[j].Personagem.Nivel);//Ir� imprimir o n�vel do personagem na posi��o j.
		}
	}
}

void Posicao_Def (void){
	for(i = 0; i < 3; i++){
		printf("\n--- Personagem com posicao %d em defesa ---\n\n", i+1);//Print para mostrar que personagem est� em determinada posi��o no ranking de defesa.
		for(j = 0; j < 3; j++)
		if(Def[i] == Guerreiro[j].Personagem.Poder_Def_Total){//Se o vetor Def na posi��o i tiver o valor igual a vari�vel "Poder_Def_Total" ir� entrar no if.
			printf("Nome: %s\n", Guerreiro[j].Personagem.Nome);//Ir� imprimir o nome do personagem na posi��o j.
			
			if( strcmp (Guerreiro[j].Classe.Habilidade_de_Classe,"Furia")==0){//Se a habilidade de classe do personagem na posi��o j for "Furia" ir� mostrar que ele � um Barbaro.
				printf("Classe: Barbaro\n");
			}
			else if( strcmp (Guerreiro[j].Classe.Habilidade_de_Classe,"Espada_Divina")==0){//Se a habilidade de classe do personagem na posi��o j for "Espada_Divina" ir� mostrar que ele � um Espadachim.
				printf("Classe: Espadachim\n");
			}
			else if( strcmp (Guerreiro[j].Classe.Habilidade_de_Classe,"Sangue_Acido")==0){//Se a habilidade de classe do personagem na posi��o j for "Sangue_Acido" ir� mostrar que ele � um Lefou.
				printf("Classe: Lefou\n");
			}
			
			printf("Habilidade de classe: %s\n", Guerreiro[j].Classe.Habilidade_de_Classe);
			printf("Poder de ataque: %d\n", Guerreiro[j].Personagem.Poder_Atk_Total);//Ir� imprimir o valor de ataque total do personagem na posi��o j.
			printf("Poder de defesa: %d\n", Guerreiro[j].Personagem.Poder_Def_Total);//Ir� imprimir o valor de defesa total do personagem na posi��o j.
			printf("Nivel: %d", Guerreiro[j].Personagem.Nivel);//Ir� imprimir o n�vel do personagem na posi��o j.
		}
	}
}
