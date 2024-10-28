#include <stdio.h>
#include <math.h>//Biblioteca para a fun��o sqrt.

int main(){
	float x1, x2, y1, y2, Distancia;//Vari�veis para armazenar as coordenadas x e y dos pontos 1 e 2, e a dist�ncia entre elas.
	
	printf("Digite as coordenadas X e Y do ponto 1:\n");//Print e scan para obter os valores das coordenadas x e y do ponto 1.
	scanf("%f\n%f", &x1, &y1);

	printf("Digite as coordenadas X e Y do ponto 2:\n");//Print e scan para obter os valores das coordenadas x e y do ponto 1.
	scanf("%f\n%f", &x2, &y2);

	float Calcular_Distancia(float Dx1, float Dx2, float Dy1, float Dy2);//Declara��o da vari�vel "Calcular_Distancia".
	Distancia = Calcular_Distancia(x1, x2, y1, y2);//A vair�vel "Distancia" ir� receber o resultado que foi retornado da fun��o Calcular_Distancia.
	
	printf("A distancia entre os pontos eh: %f\n", Distancia);//Print para mostrar a distancia entre os pontos.
	return 0;
}

float Calcular_Distancia(float Dx1, float Dx2, float Dy1, float Dy2){
	float a, b, c, d;
	a = Dx1 - Dx2; //Armazena a distancia entre os pontos x1 e x2 na vari�vel "a".
	b = Dy1 - Dy2; //Armazena a distancia entre os pontos y1 e y2 na vari�vel "b".
	c = a * a + b * b; //Armazena na vari�vel "c" a soma de "a" vezes "a" com "b" vezes "b".
	d = sqrt(c); //Armazena a raiz da vari�vel "c" na vari�vel "d".
	return d; //Retorna o resultado armazenado na vari�vel "d".
}
