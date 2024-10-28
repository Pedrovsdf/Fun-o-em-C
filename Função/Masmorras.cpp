#include <stdio.h>
#include <stdlib.h>//Biblioteca para usar o rand.
#include <time.h>//Biblioteca para usar o "time"

int i=0;//Vari�vel global usada no for dentro das fun��es.

int main(){
	int Escolha=0, n=0, k=0, Item[10], Chances=10;//Declara��o de vari�veis.
	
	do{
	srand(time(NULL));//Sempre ir� gerar um valor aleat�rio novo para o rand.
	
	printf("\nVoce tem %d chances restantes\n", Chances);//Print para mostrar quantas chances o usu�rio ainda tem para poder entrar nas Masmorras.
	printf("\nEm qual Masmorra voce deseja entrar?\nPara entrar na Masmorra 1 digite 1.\nPara entrar na Masmorra 2 digite 2:\n");//Print para perguntar ao usu�rio em qual Masmorra ele deseja entrar, 1 ou 2.
	scanf("%d", &Escolha);//Scan para armazenar na vari�vel "Escolha" o valor da Masmorra que o usu�rio deseja entrar.
	
	if(Escolha != 1 && Escolha != 2){
		do{//Enquanto o usu�rio n�o digitar um valor v�lido, 1 ou 2, o programa continuar� pedindo para ele digitar.
		printf("Digite um valor valido!\n");
		scanf("%d", &Escolha);
		} while (Escolha != 1 && Escolha != 2);
	}
	
	printf("Quantas vezes voce deseja participar da Masmorra %d?\n", Escolha);//Print perguntando quantas vezes o usu�rio deseja participar da Masmorra selecionada.
	scanf("%d", &n);//Scan para armazenar na vari�vel "n" o n�mero de vezes que o usu�rio deseja participar da Masmorra selecionada.
	
	if(n > Chances){//Se "n" for maior que o n�mero de chances restantes, "n" receber� "Chances".
		n = Chances;
	}
	
	Chances = Chances - n;//A vari�vel "Chances" ser� subtra�da pelo n�mero de vezes que o usu�rio participou da Masmorra.
	
	void Gerar_Itens(int vetor[], int x, int y);//Declara��o da fun��o "Gerar_Itens".
	void Itens_M1(int vetor[], int x, int y);//Declara��o da fun��o "Itens_M1".
	void Itens_M2(int vetor[], int x, int y);//Declara��o da fun��o "Itens_M2".
	
	int j = k + n;//Vari�vel "j" ir� receber k + n.
	
	if(Escolha == 1){//Se a vari�vel "Escolha" tiver valor 1 ir� entrar nesse if.
		Gerar_Itens(Item, j, k);//Chamando a fun��o "Gerar_Itens" para gerar os valores aleat�rios.
		printf("\nVoce entrou na Masmorra 1 e ganhou:\n");//Print para mostrar a Masmorra escolhida e quais itens o usu�rio ganhou.
		Itens_M1(Item, j, k);//Chamando a fun��o "Itens_M1" para mostrar os itens obtidos na Masmorra 1.
	}
	
	if(Escolha == 2){//Se a vari�vel "Escolha" tiver valor 2 ir� entrar nesse if.
		Gerar_Itens(Item, j, k);//Chamando a fun��o "Gerar_Itens" para gerar os valores aleat�rios.
		printf("\nVoce entrou na Masmorra 2 e ganhou:\n");//Print para mostrar a Masmorra escolhida e quais itens o usu�rio ganhou.
		Itens_M2(Item, j, k);//Chamando a fun��o "Itens_M2" para mostrar os itens obtidos na Masmorra 2.
	}
	
	if(Chances == 0){//Se a vari�vel "Chances" tiver valor 0 ir� entrar nesse if.
		printf("\nSuas chances acabaram!\n");//Print para mostrar que as chances acabaram.
		return 0;
	}
	
	k = k + n;//A vari�vel "k" ir� armazenar ela mesma somada com a vari�vel "n"
	} while (Chances >= 0);
	
	return 0;
}

void Gerar_Itens(int vetor[], int x, int y){//Fun��o para gerar valores aleat�rios.
	for(i = y; i < x; i++){//for iniciando da posi��o y e parando antes de chegar em x.
		vetor[i]= rand() % 11;//O vetor na posi��o i ir� armazenar um valor aleat�rio entre 0 e 10, gerado pelo rand.
	}
}

void Itens_M1(int vetor[], int x, int y){//Fun��o para gerar os itens da Masmorra 2.
	for(i = y; i < x; i++){//for iniciando da posi��o y e parando antes de chegar em x.
		if(vetor[i] >= 0 && vetor[i] <= 3){//Se o valor aleat�rio armazenado no vetor na posi��o i for maior ou igual a 0 e maior ou igual a 3 entrar� nesse if.
			printf("Espada comum, com 5 de ataque fisico e 1 de ataque a distancia\n");//Print para mostrar que o usu�rio obteve uma espada comum, mostrando tamb�m seus atributos.
		}
		if(vetor[i] >= 4 && vetor[i] <= 7){//Se o valor aleat�rio armazenado no vetor na posi��o i for maior ou igual a 4 e maior ou igual a 7 entrar� nesse if.
			printf("Espada rara, com 10 de ataque fisico e 2 de ataque a distancia\n");//Print para mostrar que o usu�rio obteve uma espada rara, mostrando tamb�m seus atributos.
		}
		if(vetor[i] >= 8 && vetor[i] <= 10){//Se o valor aleat�rio armazenado no vetor na posi��o i for maior ou igual a 8 e maior ou igual a 10 entrar� nesse if.
			printf("Espada lendaria, com 20 de ataque fisico e 3 de ataque a distancia\n");//Print para mostrar que o usu�rio obteve uma espada lend�ria, mostrando tamb�m seus atributos.
		}
	}
}

void Itens_M2(int vetor[], int x, int y){//Fun��o para gerar os itens da Masmorra 2.
	for(i = y; i < x; i++){//for iniciando da posi��o y e parando antes de chegar em x.
		if(vetor[i] >= 0 && vetor[i] <= 3){//Se o valor aleat�rio armazenado no vetor na posi��o i for maior ou igual a 0 e maior ou igual a 3 entrar� nesse if.
			printf("Arco comum, com 1 de ataque fisico e 5 de ataque a distancia\n");//Print para mostrar que o usu�rio obteve um arco comum, mostrando tamb�m seus atributos.
		}
		if(vetor[i] >= 4 && vetor[i] <= 7){//Se o valor aleat�rio armazenado no vetor na posi��o i for maior ou igual a 4 e maior ou igual a 7 entrar� nesse if.
			printf("Arco raro, com 2 de ataque fisico e 10 de ataque a distancia\n");//Print para mostrar que o usu�rio obteve um arco raro, mostrando tamb�m seus atributos.
		}
		if(vetor[i] >= 8 && vetor[i] <= 10){//Se o valor aleat�rio armazenado no vetor na posi��o i for maior ou igual a 8 e maior ou igual a 10 entrar� nesse if.
			printf("Arco lendario, com 3 de ataque fisico e 20 de ataque a distancia\n");//Print para mostrar que o usu�rio obteve um arco lend�rio, mostrando tamb�m seus atributos.
		}
	}
}
