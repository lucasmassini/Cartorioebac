#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsalv�l por cuidar das string
		
int registro() //Fun��o responsavel por cadastrar os us�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	
	printf("Digite o CPF a ser cadastrado: "); //colettando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string 
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" siginifica escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // buscando o arquivo 
	fprintf(file,",");
	fclose(file); //encerrando o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //fun��o para busca o nome 
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome); //salva nome 
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //fun��o para busca o cpf e nome 
	scanf("%s",sobrenome); //%s para trazer o sobrenome 
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //fun��o para definir o cargo 
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
	
   printf("Digite o CPF a ser consultado: "); // fun��o de consulta
   scanf("%s",cpf);
  	
   FILE *file;
   file = fopen(cpf,"r");
  	
   if(file == NULL) //quando n�o existir
  {
	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); //messagem para notificar o cliente 
  }
	
   while(fgets(conteudo, 200, file) != NULL) //fun��o nula 
  {
	printf("\n Essas s�o as informa��es do usu�rio: "); // buscando informa��es 
	printf("%s", conteudo); //buscando conteudo
	printf("\n\n"); 
  }
  	
   system ("pause"); // dando um time para o cliente 
}


int deletar()
{
char cpf[40];

printf("Digite o CPF do usu�rio a ser deletado: "); //deletar cpf
scanf("%s",cpf);

remove(cpf);

FILE *file;
file = fopen(cpf,"r");

if(file == NULL)
{
	printf("O usu�rio n�o se encontra no sistema!.\n"); //messagem para notificar o cliente quando n�o existir o cpf ou quando for deleteado
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
			
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu\n\n"); // cabe�orio do menu de op��es 
		printf("\t1 - Registrar nomes\n"); // fun��o de resgistra nomes 
		printf("\t2 - Consultar nomes\n"); // fun�ao de consultar nomes 
		printf("\t3 - Deletar nomes\n\n"); // fun��o de deletar nomes 
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usuario
		
		system("cls"); //responsavel por limpar a tela 
	
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
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
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
		} //fim da sele��o
			
	}	
}
