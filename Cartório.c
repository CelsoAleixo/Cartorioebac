#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar dos string

int Registro() // função responsavel por cadastrar os usuários no sistema
{
	// inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores da string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,"\nCPF:");
	fprintf(file,cpf); // salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file," \nNOME:");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," \nSOBRENOME:");
	
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " \nCARGO: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen (arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");



	
}

int Consulta()
{
	setlocale (LC_ALL, "Portuguese"); // Definindo a Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não foi localizado!. \n");
	}
	
		printf("\nEssas são as informações do usuário:\n");
		
	
	while(fgets(conteudo, 200,file)!= NULL)
	{
		printf("%s", conteudo);
		printf("\n\n");
	}


	
	system ("pause");
}

int Deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
    
}



int main()
{
	int opcao=0; //Definindo as variaveis
	int laco=1;
	for(laco=1;laco=1;)
	{
	
	system("cls");
	
	
	setlocale (LC_ALL, "Portuguese"); // Definindo a Linguagem
	
	printf ("###Cartório da EBAC###\n\n");// Inicio do Menu
	printf ("Escolha a opção desejada do menu:\n\n");
	printf ("\t1 - Registrar nomes\n");
	printf ("\t2 - Consultar nomes\n");
	printf ("\t3 - Deletar nomes\n\n");
	printf ("Opção: "); // Fim do menu
	
    scanf("%d",&opcao);// Armazenando a escolha do usuário
    
    system("cls"); // responsavel por limpar a tela
    
    switch(opcao) // inicio da seleção do menu
    {
    	case 1:
    	Registro();	// chamada de funções
		break;	
    	
		case 2:
	    Consulta(); 
	    break; 	
	    
	    case 3:
	    Deletar();
	    break;	
	    
	    default:
	    printf("Essa opção não está disponivel!\n");
		system("pause");
		break;   
	}
    

    }

}

