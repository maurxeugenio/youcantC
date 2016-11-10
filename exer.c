#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    char** nome;
    char* nomeAux = (char*) malloc(50*sizeof(char));

    int nota[10], hdisciplina[10], faltas[10];
    int x, i, aux, count, atual, j, discAtual, faltasAtual;

    nome = (char**) malloc(10*sizeof(char*));

    for (i = 0; i < 10; i++)
    {
       printf ("digite o nome do aluno %d :\n", i);
       nome[i] = (char*) malloc(50*sizeof(char));
       scanf("%s", nome[i]);

       printf ("carga horária da disciplina do aluno %d :\n", i);
       scanf("%d", &hdisciplina[i]);

       printf ("faltas aluno %d :\n", i);
       scanf("%d", &faltas[i]);

       printf ("nota aluno %d :\n", i);
       scanf("%d", &nota[i]);

    }


	for (i = 1; i < 10; i++)
	{
        nomeAux = nome[i];
        atual = nota[i];
		discAtual = hdisciplina[i];
		faltasAtual = faltas[i];

		j = i - 1;

		while ((j >= 0) && (atual > nota[j]))
		{
            nome[j+1] = nome[j];
 			nota[j + 1] = nota[j];
			faltas[j + 1] = faltas[j];
			hdisciplina[j + 1] = hdisciplina[j];
            j = j - 1;

		}
		nome[j+1] = nomeAux;
		nota[j+1] = atual;
		faltas[j + 1] = faltasAtual;
		hdisciplina[j + 1] = discAtual;

	}

    printf("# - Alunos Reprovados por nota - # \n ");
        for (i=0; i < 10; i++){
            if(nota[i] < 60){
            printf("Aluno, %s nota, %d \n", nome[i], nota[i]);
            }
        }

    printf("# - Alunos Reprovados por falta - # \n");
        for(i=0; i < 10; i++){
            if(faltas[i] >= (hdisciplina[i] * .25)){
            printf("Aluno: %s Faltas: %d \n", nome[i], faltas[i]);
            }
        }

    printf("# - Aluno com a maior nota - # \n");
        printf("Aluno: %s Nota: %d \n", nome[0], nota[0]);

    printf("# - Dez alunos com melhores notas - # \n");
        for(i=0; i < 10; i++){
            printf("Aluno: %s Nota: %d \n", nome[i], nota[i]);
        }

    return 0;
}
