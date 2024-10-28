#include <stdio.h>
#include <string.h>

struct Personagens
{
	char Nome[30];//Nome do personagem.
	int Poder_Atk_Total;//Poder de ataque total, o poder de ataque base será somado ao ataque da classe e armazenado aqui.
	int Poder_Def_Total;//Poder de defesa total, o poder de defesa base será somado a defesa da classe e armazenado aqui.
	int Poder_Atk_Base;//Poder de ataque base, o usuário irá digitar.
	int Poder_Def_Base;//Poder de defesa base, o usuário irá digitar.
	int Nivel;//Nível do personagem.
};

struct Classe_Guerreiro
{
	int Ataque;//Ataque base de cada classe: Barbaro +25 atk, Espadachim +15 atk, Lefou +5 atk.
	int Defesa;//Defesa base de cada classe: Barbaro +5 def, Espadachim +15 def, Lefou +25 def.
	char Habilidade_de_Classe[30];//Habilidade característica de cada classe: Barbaro, Fúria; Espadachim, Espada Divina; Lefou, Sangue Ácido.
};

struct Guerreiros
{
	struct Personagens Personagem;
	struct Classe_Guerreiro Classe;
}
Guerreiro[3];

int i=0, j=0, Atk[3], Def[3];//Variáveis globais, usadas no main e nas funções.

int main(){
	int k=1;//Variável para checar se o usuário digitou uma classe válida, se sim, ela receberá o valor 0.
	char classe[20];//Variável para armazenar a classe escolhida.
	
	for(i = 0; i < 3; i++){
		printf("\nDigite o nome do personagem %d: ", i+1);//Print e scan para obter o nome do personagem na posição i.
		scanf("%s", &Guerreiro[i].Personagem.Nome);
		
		do{
		printf("Digite a raca do personagem %d: ", i+1);//Print e scan para obter a classe do personagem na posição i.
		scanf("%s", &classe);
		
		if( strcmp (classe,"Barbaro")==0){//Se o usuário digitar "Barbaro" irá entrar nesse if.
			printf("A classe escolhida foi Barbaro\n");//Print para mostrar a classe escolhida.
			Guerreiro[i].Classe.Ataque = 25;//A variável "Ataque" dentro da struct "Classe" irá armazenar o ataque base de um Barbaro.
			Guerreiro[i].Classe.Defesa = 5;//A variável "Defesa" dentro da struct "Classe" irá armazenar a defesa base de um Barbaro.
			strcpy(Guerreiro[i].Classe.Habilidade_de_Classe, "Furia");//A variável "Habilidade_de_Classe" dentro da struct "Classe" irá armazenar "Furia".
			k = 0;
		}
		else if( strcmp (classe,"Espadachim")==0){//Se o usuário digitar "Espadachim" irá entrar nesse if.
			printf("A classe escolhida foi Espadachim\n");//Print para mostrar a classe escolhida.
			Guerreiro[i].Classe.Ataque = 15;//A variável "Ataque" dentro da struct "Classe" irá armazenar o ataque base de um Espadachim.
			Guerreiro[i].Classe.Defesa = 15;//A variável "Defesa" dentro da struct "Classe" irá armazenar a defesa base de um Espadachim.
			strcpy(Guerreiro[i].Classe.Habilidade_de_Classe, "Espada_Divina");//A variável "Habilidade_de_Classe" dentro da struct "Classe" irá armazenar "Espada_Divina".
			k = 0;
		}
		else if( strcmp (classe,"Lefou")==0){//Se o usuário digitar "Lefou" irá entrar nesse if.
			printf("A classe escolhida foi Lefou\n");//Print para mostrar a classe escolhida.
			Guerreiro[i].Classe.Ataque = 5;//A variável "Ataque" dentro da struct "Classe" irá armazenar o ataque base de um Lefou.
			Guerreiro[i].Classe.Defesa = 25;//A variável "Defesa" dentro da struct "Classe" irá armazenar a defesa base de um Lefou.
			strcpy(Guerreiro[i].Classe.Habilidade_de_Classe, "Sangue_Acido");//A variável "Habilidade_de_Classe" dentro da struct "Classe" irá armazenar "Sangue_Acido".
			k = 0;
		}
		else{
			printf("Essa classe nao existe, digite uma classe valida.\n");//Print caso o usuário não tiver digitado uma classe válida, então irá repetir a operação.
			k=1;
		}
		}while (k==1);
		
		printf("Insira o poder de ataque do personagem %d: ", i+1);//Print e scan para armazenar o ataque base do personagem.
		scanf("%d", &Guerreiro[i].Personagem.Poder_Atk_Base);
		printf("Insira o poder de defesa do personagem %d: ", i+1);//Print e scan para armazenar a defesa base do personagem.
		scanf("%d", &Guerreiro[i].Personagem.Poder_Def_Base);
		printf("Digite o nivel do personagem %d: ", i+1);//Print e scan para armazenar o nível do personagem.
		scanf("%d", &Guerreiro[i].Personagem.Nivel);
		
		Guerreiro[i].Personagem.Poder_Atk_Total = Guerreiro[i].Personagem.Poder_Atk_Base + Guerreiro[i].Classe.Ataque;//A variável "Poder_Atk_Total" dentro da struct "Personagem" irá armazenar o ataque base somado com o ataque da classe.
		Guerreiro[i].Personagem.Poder_Def_Total = Guerreiro[i].Personagem.Poder_Def_Base + Guerreiro[i].Classe.Defesa;//A variável "Poder_Def_Total" dentro da struct "Personagem" irá armazenar a defesa base somado com a defesa da classe.
		
		Atk[i] = Guerreiro[i].Personagem.Poder_Atk_Total;//O vetor Atk na posição i irá armazenar o valor do ataque total do guerreiro na posição i.
		Def[i] = Guerreiro[i].Personagem.Poder_Def_Total;//O vetor Def na posição i irá armazenar o valor da defesa total do guerreiro na posição i.
	}
	
	void bubble_sort (int vetor[], int n);//Declaração da função "bubble_sort".
	bubble_sort (Atk, 3);//O vetor Atk será ordenado dentro da função "bubble_sort", em ordem decrescente.
	bubble_sort (Def, 3);//O vetor Def será ordenado dentro da função "bubble_sort", em ordem decrescente.
	
	void Posicao_Atk (void);//Declaração da função "Posicao_Atk".
	Posicao_Atk ();//Chamando a função "Posição_Atk".
	
	printf("\n");
	
	void Posicao_Def (void);//Declaração da função "Posicao_Def".
	Posicao_Def ();//Chamando a função "Posição_Def".
	
	return 0;//Fim do programa.
}

void bubble_sort (int vetor[], int n){
    int aux;//Variável auxiliar.

    for(i = 1; i < n; i++){
        for(j = 0; j < n-1; j++){
            if(vetor[j] < vetor[j+1]){//Se o vetor na posição j for menor que o vetor na posição j+1 entrará nesse if.
                aux = vetor[j];//A variável auxiliar irá receber o valor do vetor na posição j.
                vetor[j] = vetor[j+1];//O vetor na posição j irá receber o valor do vetor na posição j+1.
                vetor[j+1] = aux;//O vetor na posição j+1 irá receber o valor da variável auxiliar.
            }
        }
    }
}

void Posicao_Atk (void){
	for(i = 0; i < 3; i++){
		printf("\n--- Personagem com posicao %d em ataque ---\n\n", i+1);//Print para mostrar que personagem está em determinada posição no ranking de ataque.
		for(j = 0; j < 3; j++)
		if(Atk[i] == Guerreiro[j].Personagem.Poder_Atk_Total){//Se o vetor Atk na posição i tiver o valor igual a variável "Poder_Atk_Total" irá entrar no if.
			printf("Nome: %s\n", Guerreiro[j].Personagem.Nome);//Irá imprimir o nome do personagem na posição j.
			
			if( strcmp (Guerreiro[j].Classe.Habilidade_de_Classe,"Furia")==0){//Se a habilidade de classe do personagem na posição j for "Furia" irá mostrar que ele é um Barbaro.
				printf("Classe: Barbaro\n");
			}
			else if( strcmp (Guerreiro[j].Classe.Habilidade_de_Classe,"Espada_Divina")==0){//Se a habilidade de classe do personagem na posição j for "Espada_Divina" irá mostrar que ele é um Espadachim.
				printf("Classe: Espadachim\n");
			}
			else if( strcmp (Guerreiro[j].Classe.Habilidade_de_Classe,"Sangue_Acido")==0){//Se a habilidade de classe do personagem na posição j for "Sangue_Acido" irá mostrar que ele é um Lefou.
				printf("Classe: Lefou\n");
			}
			
			printf("Habilidade de classe: %s\n", Guerreiro[j].Classe.Habilidade_de_Classe);//Irá imprimir a habilidade de classe do personagem na posição j.
			printf("Poder de ataque: %d\n", Guerreiro[j].Personagem.Poder_Atk_Total);//Irá imprimir o valor de ataque total do personagem na posição j.
			printf("Poder de defesa: %d\n", Guerreiro[j].Personagem.Poder_Def_Total);//Irá imprimir o valor de defesa total do personagem na posição j.
			printf("Nivel: %d", Guerreiro[j].Personagem.Nivel);//Irá imprimir o nível do personagem na posição j.
		}
	}
}

void Posicao_Def (void){
	for(i = 0; i < 3; i++){
		printf("\n--- Personagem com posicao %d em defesa ---\n\n", i+1);//Print para mostrar que personagem está em determinada posição no ranking de defesa.
		for(j = 0; j < 3; j++)
		if(Def[i] == Guerreiro[j].Personagem.Poder_Def_Total){//Se o vetor Def na posição i tiver o valor igual a variável "Poder_Def_Total" irá entrar no if.
			printf("Nome: %s\n", Guerreiro[j].Personagem.Nome);//Irá imprimir o nome do personagem na posição j.
			
			if( strcmp (Guerreiro[j].Classe.Habilidade_de_Classe,"Furia")==0){//Se a habilidade de classe do personagem na posição j for "Furia" irá mostrar que ele é um Barbaro.
				printf("Classe: Barbaro\n");
			}
			else if( strcmp (Guerreiro[j].Classe.Habilidade_de_Classe,"Espada_Divina")==0){//Se a habilidade de classe do personagem na posição j for "Espada_Divina" irá mostrar que ele é um Espadachim.
				printf("Classe: Espadachim\n");
			}
			else if( strcmp (Guerreiro[j].Classe.Habilidade_de_Classe,"Sangue_Acido")==0){//Se a habilidade de classe do personagem na posição j for "Sangue_Acido" irá mostrar que ele é um Lefou.
				printf("Classe: Lefou\n");
			}
			
			printf("Habilidade de classe: %s\n", Guerreiro[j].Classe.Habilidade_de_Classe);
			printf("Poder de ataque: %d\n", Guerreiro[j].Personagem.Poder_Atk_Total);//Irá imprimir o valor de ataque total do personagem na posição j.
			printf("Poder de defesa: %d\n", Guerreiro[j].Personagem.Poder_Def_Total);//Irá imprimir o valor de defesa total do personagem na posição j.
			printf("Nivel: %d", Guerreiro[j].Personagem.Nivel);//Irá imprimir o nível do personagem na posição j.
		}
	}
}
