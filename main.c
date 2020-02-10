#include <stdio.h>
#include <stdlib.h>
#include "lista-dinamica-encadeada-dupla.h"

int main() {
	Aluno* alu = malloc(sizeof(Aluno));
	alu->matricula = 100;
	alu->nome = "Fernando do Nascimento";
	alu->notas[0] = 10.00;
	alu->notas[1] = 10.00;
	alu->notas[2] = 10.00;

	Aluno* alu2 = malloc(sizeof(Aluno));
	alu2->matricula = 101;
	alu2->nome = "Nascimento";
	alu2->notas[0] = 9.00;
	alu2->notas[1] = 5.00;
	alu2->notas[2] = 7.00;

	Aluno* alu3 = malloc(sizeof(Aluno));
	alu3->matricula = 102;
	alu3->nome = "Batata";
	alu3->notas[0] = 9.00;
	alu3->notas[1] = 5.00;
	alu3->notas[2] = 7.00;

	Aluno* alu4 = malloc(sizeof(Aluno));
	alu4->matricula = 105;
	alu4->nome = "Vieira";
	alu4->notas[0] = 9.00;
	alu4->notas[1] = 5.00;
	alu4->notas[2] = 7.00;

	Aluno* alu5 = malloc(sizeof(Aluno));
	alu5->matricula = 107;
	alu5->nome = "Nan";
	alu5->notas[0] = 9.00;
	alu5->notas[1] = 5.00;
	alu5->notas[2] = 7.00;


	ListaDupla* lista = criaListaDupla();
	printf("Tamanho: %i\n", tamanhoListaDupla(lista));
	printf("Vazio: %i\n", vazioListaDupla(lista));
	printf("Cheio: %i\n", cheioListaDupla(lista));
	return 0;
}