#include <stdio.h>
#include <math.h>

int main (){
	int Resp=1, Escolha=0;
	float Num=0;
	
	printf("Digite um numero:\n");
	scanf("%f", &Num);
	
	do{
	printf("Digite:\n1 - Para calcular a potencia na base 2;\n2 - Para calcular a raiz quadrada;\n3 - Para dividir por 9:\n");
	scanf("%d", &Escolha);
	
	void valor (float x, float y);
	valor (Num, Escolha);
	
	printf("\n\nDeseja continuar? Digite 1 para sim ou qualquer outro valor para nao:\n");
	scanf("%d", &Resp);
	} while (Resp == 1);
	
	return 0;
}

void valor (float x, float y){
	if (y == 1){
		printf("%.2f foi o numero digitado\nSua potencia na base 2 eh: %.2f", x, x*x);
	}else if (y == 2){
		printf("%.2f foi o numero digitado\nSua raiz quadrada eh: %.2f", x, sqrt(x));
	}else if (y == 3){
		printf("%.2f foi o numero digitado\nSua divisao por 9 eh: %.2f", x, x/9);
	}else{
		printf("Valor invalido!\n");
	}
}
