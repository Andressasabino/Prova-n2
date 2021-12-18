/*
 * Faça um programa em C que crie uma struct chamada info_aluno com os campos
 * nome, número de matrícula, nota1, nota2 e média. Crie um vetor de 20 elementos do
 * tipo into_aluno. Leia as informações de cada aluno pelo teclado, calcule a média
 * aritmética e grave o vetor num arquivo binário. Faça outro programa que deverá ler as
 * informações desse arquivo e exibir na tela a lista de alunos com o nome completo, o
 * número de matrícula, as notas e a média aritmética de cada aluno um em cada linha.
 */
#include <stdio.h>
#include <string.h>

#define MAX 2
// Formando a struct
struct info_aluno
{
    char nome[100];
    int matricula;
    float nota1;
    float nota2;
    float media;
} Aluno;

int main()
{
   // Definindo variáveis arquivos e ponteiro
    struct info_aluno alunos[MAX];
    struct info_aluno aluno;
    FILE *arq;
    int i = 0;
    
  // Abrindo o arquivo
    arq = fopen("arquivo.bin", "wb");
	  
    // Fazendo o loop
    printf("\nAo preecher, coloque os primeiro e segundo nomes.\n");
    while (i < MAX) {
    	fflush(stdin);
	    printf("Aluno [%d] => Nome do aluno: ", i+1);
        gets(alunos[i].nome);
        fflush(stdin);

        printf("Aluno [%d] => Número da matrícula: ", i+1);
        scanf("%d", &alunos[i].matricula);
        
        printf("Aluno [%d] => Nota 1: ", i+1);
        scanf("%f", &alunos[i].nota1);

        printf("Aluno [%d] => Nota 2: ", i+1);
        scanf("%f", &alunos[i].nota2);

        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2)/2.0;

        i++;
    }

    i = 0;
	
    while (i < MAX)
    {
        fwrite(&alunos[i], sizeof(Aluno), 1, arq);
        
        i++;
    }
    
    // Fechando o arquivo
    fclose(arq);
  
    arq = fopen("arquivo.bin", "rb");

    printf("Nome\t\t\tMatricula\t\tNota 1\tNota 2\tMedia");

    while (fread(&aluno, sizeof(Aluno), 1, arq))
    {
        printf("\n%s\t\t%d\t\t\t%.2f\t%.2f\t%.2f", aluno.nome, aluno.matricula, aluno.nota1, aluno.nota2, aluno.media);
    }
    
    printf("\n");
    // Fechando o arquivo
    fclose(arq);
    
    return 0;
}
