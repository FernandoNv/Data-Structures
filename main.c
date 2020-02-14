#include <stdio.h>
#include <stdlib.h>
#include "pilha-estatica.h"

int main() {
	Aluno alu;
	alu.matricula = 105;
	alu.nome = "Vieira";
	alu.notas[0] = 9.00;
	alu.notas[1] = 5.00;
	alu.notas[2] = 7.00;

	Aluno alu1;
	alu1.matricula = 100;
	alu1.nome = "Batata";
	alu1.notas[0] = 9.00;
	alu1.notas[1] = 5.00;
	alu1.notas[2] = 7.00;

	Aluno alu2;
	alu2.matricula = 101;
	alu2.nome = "Monstro";
	alu2.notas[0] = 1.00;
	alu2.notas[1] = 1.00;
	alu2.notas[2] = 1.00;

	Aluno alu3;
	alu3.matricula = 107;
	alu3.nome = "Nascinento";
	alu3.notas[0] = 10.00;
	alu3.notas[1] = 10.00;
	alu3.notas[2] = 7.00;

	PilhaEstatica* pilha = criaPilhaEstatica();
	inserePilhaEstatica(pilha, alu);
	inserePilhaEstatica(pilha, alu1);
	inserePilhaEstatica(pilha, alu2);
	inserePilhaEstatica(pilha, alu3);

	Aluno alu4;
	// removeFila(fila);
	
	// consultaFila(fila, &alu4);
	// imprimeAluno(&alu4);
	printf("Tamanho: %i\n", tamanhoPilhaEstatica(pilha));
	buscaPilhaEstatica(pilha, &alu4);
	imprimeAluno(&alu4);
	removePilhaEstatica(pilha);
	
	liberaPilhaEstatica(pilha);
	return 0;
}