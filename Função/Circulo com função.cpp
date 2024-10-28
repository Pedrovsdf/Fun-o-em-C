#include <stdio.h>
#include <math.h>

int main(){
	float raio, dia, circ, area;

	printf("Digite o valor do raio do circulo: ");

	scanf("%f", &raio);

	float diametro(float raio);
	float circunferencia(float raio);
	float Area(float raio);

	dia = diametro(raio);
	circ = circunferencia(raio);
	area = Area(raio);

	printf("Diamento: %.2f\n", dia);
	printf("Circunferencia: %.2f\n", circ);
	printf("Area: %.2f\n", area);

	return 0;
}

float diametro(float raio){
	return (2 * raio);
}

float circunferencia(float raio){
	return (2 * 3.14 * raio);
}

float Area(float raio){
	return (3.14 * raio * raio);
}
