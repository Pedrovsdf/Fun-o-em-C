#include<stdio.h>

int peso1=0, peso2=0, peso3=0;

int main(){
	int k=1;
	float n1=0, n2=0, n3=0, Media_Aritmetica, Media_Ponderada, Media_Harmonica;
	char Escolher;
	
	printf("Digite as 3 notas do aluno:\n");
	scanf("%f\n%f\n%f", &n1, &n2, &n3);
	
	do{
	printf("Digite : \n A - Para calcular a media aritmetica \n P - Para calcular a media ponderada \n H - Para calcular a media hamonica:\n");
	scanf("%s", &Escolher);
	
	if(Escolher == 'A' || Escolher == 'a'){
		float Calculo_M_A (float nota1,float nota2,float nota3);
		Media_Aritmetica = Calculo_M_A (n1,n2,n3);
		printf("A media aritmetica eh: %.2f", Media_Aritmetica);
	}else if(Escolher == 'P' || Escolher == 'p'){
		float Calculo_M_P (float nota_1,float nota_2,float nota_3);
		printf("Digite os 3 pesos:\n");
		scanf("%d\n%d\n%d", &peso1, &peso2, &peso3);
		
		Media_Ponderada = Calculo_M_P (n1,n2,n3);
		printf("A media ponderada eh: %.2f", Media_Ponderada);
	}else if(Escolher == 'H' || Escolher == 'h'){
		float Calculo_M_H (float nota1,float nota2,float nota3);
		Media_Harmonica = Calculo_M_H (n1,n2,n3);
		printf("A media harmonica eh: %.2f", Media_Harmonica);
	}else{
		printf("Digite um valor valido!\n");
	}
	printf("\nDeseja fazer outra operacao? Digite 1 para sim ou qualquer outro valor para nao: ");
	scanf("%d", &k);
	
	} while (k == 1);
	
	return 0;
}

float Calculo_M_A (float nota1,float nota2,float nota3){
	float media_aritmetica = (nota1+nota2+nota3)/3;
	return media_aritmetica;
}

float Calculo_M_P (float nota_1,float nota_2,float nota_3){
	float media_ponderada = (nota_1*peso1 + nota_2*peso2 + nota_3*peso3)/(peso1+peso2+peso3);
	return media_ponderada;
}

float Calculo_M_H (float nota1,float nota2,float nota3){
	float media_harmonica = 3/((1/nota1) + (1/nota2) + (1/nota3));
	return media_harmonica;
}
