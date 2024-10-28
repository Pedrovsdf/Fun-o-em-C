#include <stdio.h>

int main (){
	int m=0, Resp=1;
	
	do{
	printf("Digite um numero:\n");
	scanf("%d", &m);
	
	void Valor(int num);
	Valor(m);
	
	printf("Deseja continuar? Digite 1 para sim ou qualquer outro valor para nao:\n");
	scanf("%d", &Resp);
	} while (Resp == 1);
	
	return 0;
}

void Valor(int num){
	if(num >= 0 && num % 2 == 0){
		printf("O numero %d eh par!\n", num);
	}
	if(num < 0 && num % 2 == 0){
		printf("O numero %d eh par e seu valor absoluto eh %d.\n", num, num*(-1));
	}
	if(num >= 0 && num % 2 != 0){
		printf("O numero %d eh impar!\n", num);
	}
	if(num < 0 && num % 2 != 0){
		printf("O numero %d eh impar e seu valor absoluto eh %d.\n", num, num*(-1));
	}
}
