typedef struct Aluno {
	int matricula;
	char* nome;
	float notas[3];
}Aluno;

void imprimeAluno(Aluno* aluno);