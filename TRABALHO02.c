#include<stdio.h>
#include<stdlib.h>
#include"FUNCOES.h"

int main()
{
	
	char escolha;

	do{
		printf("MENU SIMPLES\n");
		printf("1- JOGAR\n");
		printf("0 - SAIR\n");
		printf("ESCOLHA: ");
		scanf("%c", &escolha);
		printf("\n");

		if(escolha=='1'){
			escolha_personagem();
		}
	}while(escolha!='0');
	return 0;
}