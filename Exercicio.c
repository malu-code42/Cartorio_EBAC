#include <stdio.h> //biblioteca de comunição com o usuário
#include <stdlib.h> //biblioteca de alocação e manipulação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar da string

int registro() //inicio da função responsável pelo registro
{
	setlocale(LC_ALL, "Portuguese"); //determina a lingua das entradas de texto para a bliblioteca
	
	// criação da string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	printf("Informe o seu CPF: "); //apresenta e solicita ao usuário informações
	scanf("%s", cpf); //%s se da porque está salvando dados dentro de uma string
	
	strcpy(arquivo, cpf); //coleta os dados guardados na variável cpf e os copia para a variável arquivo
	
	FILE *file; //cria o arquivo que fará parte do banco de dados
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
	
	if(file == NULL) //se o resultado da veficiação for nulo
	{
		printf("CPF não registrado!\n\n");
	}
	
	while(fgets(conteudo,100,file) != NULL) //enquanto o conteúdo for diferente de nulo
	{
		printf("\nEsses são os dados cadastrados: ");
		printf("%s", conteudo); //mostre ao usuário as informações presentes na variável conteúdo
		printf("\n\n");
	}
	
	system("pause"); //comando para o sistema pausar a apresentação após a execução do printf da função if ou da função while
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF que deseja excluir:");
	scanf("%s", cpf);
	
	remove(cpf); //ao localizar dado equivalente do gravado na variável cpf, exluir
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" ler
	
	if(file == NULL);
	{
		printf("\nCadastro localizado e excluído!\n\n");
		system("pause");
	}	
}

int main() //função principal - sempre é iniciado por ela
{
	int opcao=0; //definindo espaço ocupado pela variável	
	int laco=1; //definindo inicio do operador de repetição for
	
	for(laco=1;laco=1;) // operdor de repetição para o usuário sempre retornar ao menu inicial
	{
		
		system ("cls"); //apaga todas as informações na tela do cliente, para manter a utilização clara
		
		setlocale(LC_ALL, "Portuguese"); 
		
		printf("### Cartório da EBAC ###\n\n"); //inï¿½cio do menu
		printf("Escolha a opçãoo desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar os nomes\n\n");
		printf("\t4- Sair do sistema\n\n");
		printf("Selecione a opção desejada: "); //final do menu
	
		scanf("%d", &opcao); //a variável dessa vez é iniciada com o & pois agora estamos dentro de uma função sem a presença de uma string
		//nesse caso o comando sempre será referenciado para o primeiro membro da string, no caso era a variável arquivo
		//mas nesse caso, precisamos do ampersand para comunicar ao computador o local da variável opção
		
		system("cls"); //apaga no momento que selecionar a opção
		
		switch(opcao) //inicio da seleção
		{ 
			case 1: //se comunica com a função
			registro(); //nome da função que vai entrar em contato e executar
			break; // essencial pois informa que após a execução deverá parar
		
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
			
			default: //se não foi selecionado um dos cases acima
			printf ("Opção não disponível.\n\n");
			system("pause");
			break;
		} //fim da seleção
	}
}

