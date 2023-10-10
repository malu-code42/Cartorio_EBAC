#include <stdio.h> //biblioteca de comuni��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o e manipula��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar da string

int registro() //inicio da fun��o respons�vel pelo registro
{
	setlocale(LC_ALL, "Portuguese"); //determina a lingua das entradas de texto para a bliblioteca
	
	// cria��o da string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	printf("Informe o seu CPF: "); //apresenta e solicita ao usu�rio informa��es
	scanf("%s", cpf); //%s se da porque est� salvando dados dentro de uma string
	
	strcpy(arquivo, cpf); //coleta os dados guardados na vari�vel cpf e os copia para a vari�vel arquivo
	
	FILE *file; //cria o arquivo que far� parte do banco de dados
	file = fopen(arquivo, "w"); // abre o arquivo e fica pronto para "w" escrever
	fprintf(file, cpf); //escreve no arquivo o dado salvado na primary key cpf
	fclose(file); //fecha o arquivo
	
	fopen(arquivo, "a"); //"a" atualizar
	fprintf(file, ", ");
	fclose(file);
	
	printf("Informe o seu nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Informe seu sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Informe seu cargo: ");
	scanf ("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
			
	FILE *file;
	file = fopen(cpf, "r"); //busque o dado equivalente nos arquivos criados a partir do "r" ler
	
	if(file == NULL) //se o resultado da veficia��o for nulo
	{
		printf("CPF n�o registrado!\n\n");
	}
	
	while(fgets(conteudo,100,file) != NULL) //enquanto o conte�do for diferente de nulo
	{
		printf("\nEsses s�o os dados cadastrados: ");
		printf("%s", conteudo); //mostre ao usu�rio as informa��es presentes na vari�vel conte�do
		printf("\n\n");
	}
	
	system("pause"); //comando para o sistema pausar a apresenta��o ap�s a execu��o do printf da fun��o if ou da fun��o while
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF que deseja excluir:");
	scanf("%s", cpf);
	
	remove(cpf); //ao localizar dado equivalente do gravado na vari�vel cpf, exluir
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" ler
	
	if(file == NULL);
	{
		printf("\nCadastro localizado e exclu�do!\n\n");
		system("pause");
	}	
}

int main() //fun��o principal - sempre � iniciado por ela
{
	int opcao=0; //definindo espa�o ocupado pela vari�vel	
	int laco=1; //definindo inicio do operador de repeti��o for
	
	for(laco=1;laco=1;) // operdor de repeti��o para o usu�rio sempre retornar ao menu inicial
	{
		
		system ("cls"); //apaga todas as informa��es na tela do cliente, para manter a utiliza��o clara
		
		setlocale(LC_ALL, "Portuguese"); 
		
		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
		printf("Escolha a op��oo desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar os nomes\n\n");
		printf("\t4- Sair do sistema\n\n");
		printf("Selecione a op��o desejada: "); //final do menu
	
		scanf("%d", &opcao); //a vari�vel dessa vez � iniciada com o & pois agora estamos dentro de uma fun��o sem a presen�a de uma string
		//nesse caso o comando sempre ser� referenciado para o primeiro membro da string, no caso era a vari�vel arquivo
		//mas nesse caso, precisamos do ampersand para comunicar ao computador o local da vari�vel op��o
		
		system("cls"); //apaga no momento que selecionar a op��o
		
		switch(opcao) //inicio da sele��o
		{ 
			case 1: //se comunica com a fun��o
			registro(); //nome da fun��o que vai entrar em contato e executar
			break; // essencial pois informa que ap�s a execu��o dever� parar
		
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf ("Obrigado por utilizar nosso sistema!");
			return 0;
			break;
			
			default: //se n�o foi selecionado um dos cases acima
			printf ("Op��o n�o dispon�vel.\n\n");
			system("pause");
			break;
		} //fim da sele��o
	}
}

