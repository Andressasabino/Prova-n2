#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *arq;
	
	char vogais[] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
	char frase[200];
	char fraseDoArquivo[200];
	
	int i = 0, j = 0;
	
	// Primeiro arquivo
	arq = fopen("arquivo.txt", "w");
	
	if(arq == NULL) {
		printf("Erro ao abrir o arquivo.");
	}
	
	// Escrevendo no arquivo 1
	printf("Insira uma frase: ");
	gets(frase);
	fputs(frase, arq);
	
	// Fechando os arquivos
	fclose(arq);
	
	arq = fopen("arquivo.txt", "r");
	
	if(arq == NULL) {
		printf("Erro ao abrir o arquivo.");
	}
	
	fgets(fraseDoArquivo, 200, arq);
	
	fclose(arq);
	
	// Substituindo as vogais
	for(i=0; i < strlen(fraseDoArquivo); i++)
	{
	    for(j=0; j < strlen(vogais); j++)
	    {
	        if(vogais[j] == fraseDoArquivo[i])
	        {
	            fraseDoArquivo[i] = '*';
	        }
	    }
	}
	
  //Abre o novo arquivo para escreta e depois fecha
	arq = fopen("arquivo-novo.txt", "w");
	
	fputs(fraseDoArquivo, arq);
	
	fclose(arq);
	
	return 0;
}
