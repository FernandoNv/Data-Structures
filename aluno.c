#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

void imprimeAluno(Aluno* aluno){
	if(!aluno) return;
	printf("Nome: %s \nMatricula: %i\n", aluno->nome, aluno->matricula);
	for(int i = 0; i < 3; i++){
		printf("Nota %i: %f\n", i+1, aluno->notas[i]);
	}
}