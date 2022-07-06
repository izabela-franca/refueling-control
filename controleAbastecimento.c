#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
	
float mediaConsumo, capacidadeMax, trechoPlanejado ,trechoAlternativo, combustAeronave;
float trechoTotal, trechoComMargem, qntCombustivel, abastecimento;

float somaTrechoFinal(){
	trechoTotal = trechoPlanejado + trechoAlternativo;
	trechoComMargem = trechoTotal * 1.3;
	return trechoComMargem;
	
}

float calculoCombustivel (){
	qntCombustivel = mediaConsumo * trechoComMargem;
	return qntCombustivel;
}

float calculoAbastecimento (){
	abastecimento = qntCombustivel - combustAeronave;
	return abastecimento;
}

void verificaVoo(){;
	if (qntCombustivel <= capacidadeMax){
		printf ("Voo aprovado, bom voo!\n");
		printf ("O valor do trecho principal é: %.2f \n", trechoPlanejado);
		printf ("O valor do trecho alternativo é: %.2f \n", trechoAlternativo);
		printf ("O total do trecho com a margem de segurança é: %.2f \n",trechoComMargem);
		printf ("A quantidade de combustível necessário para o trecho é: %.2f \n", qntCombustivel);
		printf ("A quantidade de combustível necessário para o abastecimento é: %.2f \n", abastecimento);	
	} else {
		printf ("Voo reprovado, reveja seu planejamento.\n");
	}
}

int main(){
	setlocale(LC_ALL,"Portuguese"); 

	printf ("Informe a média de consumo da aeronave em litros por quilômetro: \n");
	scanf ("%f", &mediaConsumo);
	fflush(stdin);
	printf ("Informe a capacidade máxima em litros do tanque da aeronave: \n");
	scanf ("%f", &capacidadeMax);
	fflush(stdin);
	printf ("Informe a quantidade de quilômetros do trecho planejado: \n");
	scanf ("%f", &trechoPlanejado);
	fflush(stdin);
	printf ("Informe a quantidade de quilômetros do trecho alternativo: \n");
	scanf ("%f", &trechoAlternativo);
	fflush(stdin);
	printf ("Informe a quantidade de combustível já presente na aeronave: \n");
	scanf ("%f", &combustAeronave);	
	
	trechoComMargem = somaTrechoFinal();
	qntCombustivel = calculoCombustivel();
	abastecimento = calculoAbastecimento();
	verificaVoo();
	return 0;
}
