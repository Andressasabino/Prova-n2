#include <stdio.h>
#include <string.h>

int main()
{
	FILE *arq;
	
	// Declarando as variáveis
	char vogais[] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
	char arquivo[200];
	char arquivonovo[200];
	
	int i = 0, j = 0;
	
	// Primeiro arquivo
	arq = fopen("arquivo.txt", "w");
	
	if(arq == NULL) {
		printf("Erro ao abrir o arquivo. Tente novamente.");
	}
	
	// Escrevendo no arquivo 1
	printf("Insira uma frase: ");
	gets(arquivo);
	fputs(arquivo, arq);
	
	// Fechando os arquivos
	fclose(arq);
	
	arq = fopen("arquivo.txt", "r");
	
	if(arq == NULL) {
		printf("Erro ao abrir o arquivo.");
	}
	
	fgets(arquivonovo, 200, arq);
	
	fclose(arq);
	
	// Substituindo as vogais
	for(i=0; i < strlen(arquivonovo); i++)
	{
	    for(j=0; j < strlen(vogais); j++)
	    {
	        if(vogais[j] == arquivonovo[i])
	        {
	            arquivonovo[i] = '*';
	        }
	    }
	}
	
	// Abre o novo arquivo para escreta e depois fecha
	arq = fopen("arquivo-novo.txt", "w");
	
	fputs(arquivonovo, arq);
	
	fclose(arq);
	
	return 0;
}
