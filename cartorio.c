#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsalvél por cuidar das string
		
int registro() //Função responsavel por cadastrar os usários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	
	printf("Digite o CPF a ser cadastrado: "); //colettando informação do usuário
	scanf("%s", cpf); //%s refere-se a string 
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" siginifica escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // buscando o arquivo 
	fprintf(file,",");
	fclose(file); //encerrando o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //função para busca o nome 
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome); //salva nome 
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //função para busca o cpf e nome 
	scanf("%s",sobrenome); //%s para trazer o sobrenome 
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //função para definir o cargo 
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //busca arquivos
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

}

int consulta()
{

   setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
   char cpf[40];
   char conteudo[100];
	
   printf("Digite o CPF a ser consultado: "); // função de consulta
   scanf("%s",cpf);
  	
   FILE *file;
   file = fopen(cpf,"r");
  	
   if(file == NULL) //quando não existir
  {
	printf("Não foi possivel abrir o arquivo, não localizado!.\n"); //messagem para notificar o cliente 
  }
	
   while(fgets(conteudo, 200, file) != NULL) //função nula 
  {
	printf("\n Essas são as informações do usuário: "); // buscando informações 
	printf("%s", conteudo); //buscando conteudo
	printf("\n\n"); 
  }
  	
   system ("pause"); // dando um time para o cliente 
}


int deletar()
{
char cpf[40];

printf("Digite o CPF do usuário a ser deletado: "); //deletar cpf
scanf("%s",cpf);

remove(cpf);

FILE *file;
file = fopen(cpf,"r");

if(file == NULL)
{
	printf("O usuário não se encontra no sistema!.\n"); //messagem para notificar o cliente quando não existir o cpf ou quando for deleteado
	system("pause");
}
	
}


	
int main()
	{
	int opcao=0; //Definindo variaveis
	int laco=1; 
	
	for(laco=1;laco=1;)
	{

		system("cls");

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu\n\n"); // cabeçorio do menu de opções 
		printf("\t1 - Registrar nomes\n"); // função de resgistra nomes 
		printf("\t2 - Consultar nomes\n"); // funçao de consultar nomes 
		printf("\t3 - Deletar nomes\n\n"); // função de deletar nomes 
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usuario
		
		system("cls"); //responsavel por limpar a tela 
	
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
			
			case 4:
				printf("obrigado por utilizar o sistema!\n");
				return 0;
				break;
				
		
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
		} //fim da seleção
			
	}	
}
