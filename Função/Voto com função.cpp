#include <stdio.h>

int main (){
	int Idade=0, Nascimento=0, Resp=0;
	
	do{
	printf("Digite o seu ano de nascimento:\n");
	scanf("%d", &Nascimento);
	
	void voto(int X);
	voto (Nascimento);
	
	printf("Deseja continuar? Digite 1 para sim ou qualquer outro valor para nao:\n");
	scanf("%d", &Resp);
	
	} while (Resp == 1);
	
	return 0;
}

void voto(int X){
	int Atual = 2020 - X;
	if(Atual < 16){
		printf("Pessoas com %d anos nao votam!\n", Atual);
	}
	if(Atual >= 16 && Atual < 18){
		printf("Para pessoas com %d anos o voto e opcional!\n", Atual);
	}
	if(Atual >= 18){
		printf("Para pessoas com %d anos o voto e obrigatorio!\n", Atual);
	}
}
