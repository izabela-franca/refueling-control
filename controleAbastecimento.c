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
		printf ("O valor do trecho principal �: %.2f \n", trechoPlanejado);
		printf ("O valor do trecho alternativo �: %.2f \n", trechoAlternativo);
		printf ("O total do trecho com a margem de seguran�a �: %.2f \n",trechoComMargem);
		printf ("A quantidade de combust�vel necess�rio para o trecho �: %.2f \n", qntCombustivel);
		printf ("A quantidade de combust�vel necess�rio para o abastecimento �: %.2f \n", abastecimento);	
	} else {
		printf ("Voo reprovado, reveja seu planejamento.\n");
	}
}

int main(){
	setlocale(LC_ALL,"Portuguese"); 

	printf ("Informe a m�dia de consumo da aeronave em litros por quil�metro: \n");
	scanf ("%f", &mediaConsumo);
	fflush(stdin);
	printf ("Informe a capacidade m�xima em litros do tanque da aeronave: \n");
	scanf ("%f", &capacidadeMax);
	fflush(stdin);
	printf ("Informe a quantidade de quil�metros do trecho planejado: \n");
	scanf ("%f", &trechoPlanejado);
	fflush(stdin);
	printf ("Informe a quantidade de quil�metros do trecho alternativo: \n");
	scanf ("%f", &trechoAlternativo);
	fflush(stdin);
	printf ("Informe a quantidade de combust�vel j� presente na aeronave: \n");
	scanf ("%f", &combustAeronave);	
	
	trechoComMargem = somaTrechoFinal();
	qntCombustivel = calculoCombustivel();
	abastecimento = calculoAbastecimento();
	verificaVoo();
	return 0;
}
