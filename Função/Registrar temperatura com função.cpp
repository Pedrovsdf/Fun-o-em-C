#include <stdio.h>

enum Dias_semana{Domingo=0, Segunda, Terca, Quarta, Quinta, Sexta, Sabado};

char matriz[][20] =
{
"Domingo",
"Segunda",
"Terca",
"Quarta",
"Quinta",
"Sexta",
"Sabado"
};

int j=0, qtd=0;
float Temp[7], media=0;
enum Dias_semana Semana;
enum Dias_semana Dia;

int main (){
	
	void Registro_Dias ();
	Registro_Dias ();
	
	media=media/7;
	
	printf ("\nA media eh: %.2f\n", media);

	void Qtd_Dias ();
	Qtd_Dias ();
	
	printf ("\nA quantidade de dias da semana em que a temperatura esteve acima da media eh de %d dias", qtd);
	
	return 0;
}

void Registro_Dias (){
	for(Dia = Domingo; Dia <= Sabado; Dia++){
		if( Dia == Domingo || Dia == Sabado){
		printf("Digite a temperatura registrada no %s: \n", matriz[Semana+j]);
		scanf("%f", &Temp[Dia]);
		media=media + Temp[Dia];
		j++;
		}else{
		printf("Digite a temperatura registrada na %s: \n", matriz[Semana+j]);
		scanf("%f", &Temp[Dia]);
		media=media + Temp[Dia];
		j++;
		}
	}
}

void Qtd_Dias (){
	for(Dia = Domingo; Dia <= Sabado; Dia++){
		if(Temp[Dia] > media){
			qtd++;
		}
	}
}
