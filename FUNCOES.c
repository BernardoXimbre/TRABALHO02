#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "FUNCOES.h"

void sorteio_personagem(){


	FILE* arquivo= fopen("personagens.txt" ,"r");
	int i,j,contador=0,sorteio_ordem[Npersonagens],total_personagens=0;
	char personagens[Npersonagens][50],c;
	srand(time(NULL));

	/*DESCOBRIR QUANTOS PERSONAGENS ESTAO DISPONIVEIS NO ARQUIVO*/
	do{
		c= (char)fgetc(arquivo);
		if(c ==',')
			contador++;
		if(contador==5){
			total_personagens++;
			contador=0;
		}
	}while(c != EOF);
	printf("TOTAL DE PERSONAGENS DISPONIVEIS: %d\n", total_personagens);
	rewind(arquivo);
	/*----------------------------------------------------------*/
	/*SORTEIO DA ORDEM DO PERSONAGENS*/
	for(i=0;i<Npersonagens;i++){
		sorteio_ordem[i]= 1+(rand()% total_personagens);
		for(j=i-1;j>=0;j--){
			while(sorteio_ordem[i]==sorteio_ordem[j]){
				sorteio_ordem[i]= 1+(rand()% total_personagens);
				j=i-1;
			}		
		}
	}
	printf("SORTEIO FINAL ");
	for(i=0;i<Npersonagens;i++){
		printf("[%d]", sorteio_ordem[i]);
	}
	printf("\n");
	/*----------------------------------------------------------*/
	/*PROCURAR NO ARQUIVO PERSONAGEM REFERENTE*/
	for(i=0;i<Npersonagens;i++,contador=0){
		rewind(arquivo);
		for(;sorteio_ordem[i]>0;sorteio_ordem[i]--){
			contador=0;
			for(j=0;contador!=5;j++){
				personagens[i][j]= (char) fgetc(arquivo);
				if(personagens[i][j]==',')
					contador++;
				if(contador==5){
					j++;
					personagens[i][j]= (char) fgetc(arquivo);				
					do{
						j++;
						personagens[i][j]= (char) fgetc(arquivo);				
					}while(personagens[i][j]!='\n');
				}
			}
		}
	}
	for(i=0;i<Npersonagens;i++,contador=0){
		for(j=0;personagens[i][j]!='\n';j++){
			printf("%c", personagens[i][j]);
		}
		printf("\n");
	}
	/*----------------------------------------------------------*/
	

	
		
	

	fclose(arquivo);

}