#include <stdio.h>
#include <stdlib.h>//Biblioteca para usar o rand.
#include <time.h>//Biblioteca para usar o "time"

int i=0;//Variável global usada no for dentro das funções.

int main(){
	int Escolha=0, n=0, k=0, Item[10], Chances=10;//Declaração de variáveis.
	
	do{
	srand(time(NULL));//Sempre irá gerar um valor aleatório novo para o rand.
	
	printf("\nVoce tem %d chances restantes\n", Chances);//Print para mostrar quantas chances o usuário ainda tem para poder entrar nas Masmorras.
	printf("\nEm qual Masmorra voce deseja entrar?\nPara entrar na Masmorra 1 digite 1.\nPara entrar na Masmorra 2 digite 2:\n");//Print para perguntar ao usuário em qual Masmorra ele deseja entrar, 1 ou 2.
	scanf("%d", &Escolha);//Scan para armazenar na variável "Escolha" o valor da Masmorra que o usuário deseja entrar.
	
	if(Escolha != 1 && Escolha != 2){
		do{//Enquanto o usuário não digitar um valor válido, 1 ou 2, o programa continuará pedindo para ele digitar.
		printf("Digite um valor valido!\n");
		scanf("%d", &Escolha);
		} while (Escolha != 1 && Escolha != 2);
	}
	
	printf("Quantas vezes voce deseja participar da Masmorra %d?\n", Escolha);//Print perguntando quantas vezes o usuário deseja participar da Masmorra selecionada.
	scanf("%d", &n);//Scan para armazenar na variável "n" o número de vezes que o usuário deseja participar da Masmorra selecionada.
	
	if(n > Chances){//Se "n" for maior que o número de chances restantes, "n" receberá "Chances".
		n = Chances;
	}
	
	Chances = Chances - n;//A variável "Chances" será subtraída pelo número de vezes que o usuário participou da Masmorra.
	
	void Gerar_Itens(int vetor[], int x, int y);//Declaração da função "Gerar_Itens".
	void Itens_M1(int vetor[], int x, int y);//Declaração da função "Itens_M1".
	void Itens_M2(int vetor[], int x, int y);//Declaração da função "Itens_M2".
	
	int j = k + n;//Variável "j" irá receber k + n.
	
	if(Escolha == 1){//Se a variável "Escolha" tiver valor 1 irá entrar nesse if.
		Gerar_Itens(Item, j, k);//Chamando a função "Gerar_Itens" para gerar os valores aleatórios.
		printf("\nVoce entrou na Masmorra 1 e ganhou:\n");//Print para mostrar a Masmorra escolhida e quais itens o usuário ganhou.
		Itens_M1(Item, j, k);//Chamando a função "Itens_M1" para mostrar os itens obtidos na Masmorra 1.
	}
	
	if(Escolha == 2){//Se a variável "Escolha" tiver valor 2 irá entrar nesse if.
		Gerar_Itens(Item, j, k);//Chamando a função "Gerar_Itens" para gerar os valores aleatórios.
		printf("\nVoce entrou na Masmorra 2 e ganhou:\n");//Print para mostrar a Masmorra escolhida e quais itens o usuário ganhou.
		Itens_M2(Item, j, k);//Chamando a função "Itens_M2" para mostrar os itens obtidos na Masmorra 2.
	}
	
	if(Chances == 0){//Se a variável "Chances" tiver valor 0 irá entrar nesse if.
		printf("\nSuas chances acabaram!\n");//Print para mostrar que as chances acabaram.
		return 0;
	}
	
	k = k + n;//A variável "k" irá armazenar ela mesma somada com a variável "n"
	} while (Chances >= 0);
	
	return 0;
}

void Gerar_Itens(int vetor[], int x, int y){//Função para gerar valores aleatórios.
	for(i = y; i < x; i++){//for iniciando da posição y e parando antes de chegar em x.
		vetor[i]= rand() % 11;//O vetor na posição i irá armazenar um valor aleatório entre 0 e 10, gerado pelo rand.
	}
}

void Itens_M1(int vetor[], int x, int y){//Função para gerar os itens da Masmorra 2.
	for(i = y; i < x; i++){//for iniciando da posição y e parando antes de chegar em x.
		if(vetor[i] >= 0 && vetor[i] <= 3){//Se o valor aleatório armazenado no vetor na posição i for maior ou igual a 0 e maior ou igual a 3 entrará nesse if.
			printf("Espada comum, com 5 de ataque fisico e 1 de ataque a distancia\n");//Print para mostrar que o usuário obteve uma espada comum, mostrando também seus atributos.
		}
		if(vetor[i] >= 4 && vetor[i] <= 7){//Se o valor aleatório armazenado no vetor na posição i for maior ou igual a 4 e maior ou igual a 7 entrará nesse if.
			printf("Espada rara, com 10 de ataque fisico e 2 de ataque a distancia\n");//Print para mostrar que o usuário obteve uma espada rara, mostrando também seus atributos.
		}
		if(vetor[i] >= 8 && vetor[i] <= 10){//Se o valor aleatório armazenado no vetor na posição i for maior ou igual a 8 e maior ou igual a 10 entrará nesse if.
			printf("Espada lendaria, com 20 de ataque fisico e 3 de ataque a distancia\n");//Print para mostrar que o usuário obteve uma espada lendária, mostrando também seus atributos.
		}
	}
}

void Itens_M2(int vetor[], int x, int y){//Função para gerar os itens da Masmorra 2.
	for(i = y; i < x; i++){//for iniciando da posição y e parando antes de chegar em x.
		if(vetor[i] >= 0 && vetor[i] <= 3){//Se o valor aleatório armazenado no vetor na posição i for maior ou igual a 0 e maior ou igual a 3 entrará nesse if.
			printf("Arco comum, com 1 de ataque fisico e 5 de ataque a distancia\n");//Print para mostrar que o usuário obteve um arco comum, mostrando também seus atributos.
		}
		if(vetor[i] >= 4 && vetor[i] <= 7){//Se o valor aleatório armazenado no vetor na posição i for maior ou igual a 4 e maior ou igual a 7 entrará nesse if.
			printf("Arco raro, com 2 de ataque fisico e 10 de ataque a distancia\n");//Print para mostrar que o usuário obteve um arco raro, mostrando também seus atributos.
		}
		if(vetor[i] >= 8 && vetor[i] <= 10){//Se o valor aleatório armazenado no vetor na posição i for maior ou igual a 8 e maior ou igual a 10 entrará nesse if.
			printf("Arco lendario, com 3 de ataque fisico e 20 de ataque a distancia\n");//Print para mostrar que o usuário obteve um arco lendário, mostrando também seus atributos.
		}
	}
}
