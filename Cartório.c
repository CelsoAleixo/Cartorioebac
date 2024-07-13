#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar dos string
#include <ctype.h> // biblioteca para fun��es de manipula��o de caracteres

// Fun��o para validar o CPF
int validarCPF(const char *cpf) {
    int i; // declara��o da vari�vel para uso nos loops
    
    // Verifica se o comprimento do CPF � diferente de 11
    if (strlen(cpf) != 11) {
        return 0; // CPF inv�lido
    }

    // Verifica se todos os caracteres s�o d�gitos
    for (i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) { // Fun��o isdigit verifica se o caractere � um d�gito
            return 0; // CPF inv�lido
        }
    }

    // C�lculo do primeiro d�gito verificador
    int soma = 0; // Inicializa a soma
    for (i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i); // Converte caractere para inteiro e multiplica pela posi��o
    }

    int digito1 = 11 - (soma % 11); // Calcula o primeiro d�gito verificador
    if (digito1 >= 10) {
        digito1 = 0; // Se o resultado for 10 ou 11, o d�gito � 0
    }

    // Verifica se o primeiro d�gito verificador est� correto
    if (digito1 != (cpf[9] - '0')) {
        return 0; // CPF inv�lido
        
        
    }

// Fun��o para verificar se CPF j� est� cadastrado
int cpfCadastrado(const char *cpf) {
    char nomeArquivo[50];
    sprintf(nomeArquivo, "%s.", cpf); // Nome do arquivo ser� o CPF com extens�o .txt

    FILE *file;
    file = fopen(nomeArquivo, "r");
    if (file != NULL) {
        fclose(file);
        return 1; // CPF j� cadastrado
    }

    return 0; // CPF n�o cadastrado
}


}
// Fun��o para verificar se CPF j� est� cadastrado
int cpfCadastrado(const char *cpf) {
    char nomeArquivo[50];
    sprintf(nomeArquivo, "%s.", cpf); // Nome do arquivo ser� o CPF com extens�o .txt

    FILE *file;
    file = fopen(nomeArquivo, "r");
    if (file != NULL) {
        fclose(file);
        return 1; // CPF j� cadastrado
    }

    return 0; // CPF n�o cadastrado
}

int Registro() 
{
    char arquivo[50];   // Define uma vari�vel para armazenar o nome do arquivo onde os dados ser�o gravados
    char cpf[15];       // Define uma vari�vel para armazenar o CPF digitado pelo usu�rio
    char nome[40];      // Define uma vari�vel para armazenar o nome digitado pelo usu�rio
    char sobrenome[40]; // Define uma vari�vel para armazenar o sobrenome digitado pelo usu�rio
    char cargo[40];     // Define uma vari�vel para armazenar o cargo digitado pelo usu�rio

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf); // Solicita e l� o CPF digitado pelo usu�rio

   
    if (!validarCPF(cpf)) {  // Valida o CPF antes de continuar
        printf("CPF inv�lido! Por favor, insira um CPF v�lido com 11 d�gitos num�ricos.\n");
        system("pause");
        return 1; // Retorna com erro se o CPF n�o for v�lido
    }

    // Verifica se o CPF j� est� cadastrado
    if (cpfCadastrado(cpf)) {
        printf("CPF j� cadastrado! N�o � poss�vel cadastrar o mesmo CPF novamente.\n");
        system("pause");
        return 1; // Retorna com erro se o CPF j� estiver cadastrado
    }

    sprintf(arquivo, "%s", cpf); // Nome do arquivo ser� o CPF com extens�o .txt

    FILE *file;
    file = fopen(arquivo, "w"); // Abre o arquivo para escrita
    
    if (file == NULL) {
        printf("Erro ao criar o arquivo para o CPF informado.\n");
        system("pause");
        return 1; // Retorna com erro se n�o conseguir abrir o arquivo
    }

    fprintf(file, "CPF: %s\n", cpf); // Escreve o CPF no arquivo

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome); // Solicita e l� o nome digitado pelo usu�rio
    fprintf(file, "NOME: %s\n", nome); // Escreve o nome no arquivo

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome); // Solicita e l� o sobrenome digitado pelo usu�rio
    fprintf(file, "SOBRENOME: %s\n", sobrenome); // Escreve o sobrenome no arquivo

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo); // Solicita e l� o cargo digitado pelo usu�rio
    fprintf(file, "CARGO: %s\n", cargo); // Escreve o cargo no arquivo

    fclose(file); // Fecha o arquivo

    printf("Cadastro realizado com sucesso!\n");
    system("pause");
    return 0; // Retorna com sucesso
}


int Consulta() // Fun��o para consultar informa��es
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem pra Portugu�s

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file; // Declara��o da vari�vel do tipo do arquivo
    file = fopen(cpf, "r"); ; // Abre o arqrivo para leitura

    if (file == NULL) {
        printf(" Usu�rio n�o encontrado. \n");
        system("pause");
        return 1; // Sai da fun��o ap�s exibir a mensagem
    }

    printf("\nEssas s�o as informa��es do usu�rio:\n");

    while (fgets(conteudo, 200, file) != NULL) {
        printf("%s", conteudo); // Exibe as informa��es do usua�rio contidas no arquivo
        printf("\n\n");
    }
    
    fclose(file); // Fecha o arquivo ap�s leitura 
    system("pause");
    return 0; // Retorna com sucesso
}

int Deletar() // Fun��o para deletar informa��es de usu�rios
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem para Portugu�s

    char cpf[40];
    char conteudo[200];
    char confirmacao;

    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s", cpf);

    FILE *file; //Declara��o de vari�vel do tipo arquivo
    file = fopen(cpf, "r"); // Abre o arquivo para leitura

    if (file == NULL) {
        printf("Usu�rio n�o encontrado.\n");
        system("pause");
        return 1; // Sai da fun��o ap�s exibir a mensagem se o arquivo n�o existe
    }

    printf("\nEssas s�o as informa��es do usu�rio:\n");

    while (fgets(conteudo, 200, file) != NULL) {
        printf("%s", conteudo); // Exibe as informa��es do usu�rio contidas no arquivo
    }

    fclose(file); // Fecha o arquivo ap�s leitura

    printf("\nDeseja realmente deletar este usu�rio? (s/n): ");
    scanf(" %c", &confirmacao); // Pergunta ao usu�rio se deseja deletar o usu�rio

    if (confirmacao == 's' || confirmacao == 'S') {
        remove(cpf); // Deleta o arquivo do usu�rio
        printf("Usu�rio deletado com sucesso.\n");
    } else {
        printf("Opera��o de exclus�o cancelada.\n"); // Exibe mensagem se a dele��o for cancelada
    }

    system("pause");
    return 0; // Retorna sucesso
}


int main()
{
    int opcao = 0; // Definindo as vari�veis
    int laco = 1;
    for (laco = 1; laco == 1;) // corrigido o operador de compara��o
    {
        system("cls");

        setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem

        printf("###Cart�rio da EBAC###\n\n"); // In�cio do Menu
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
      
        printf("Op��o: "); // Fim do menu

        scanf("%d", &opcao); // Armazenando a escolha do usu�rio

        system("cls"); // respons�vel por limpar a tela

        switch (opcao) // in�cio da sele��o do menu
        {
        case 1:
            Registro(); // chamada de fun��es
            break;

        case 2:
            Consulta();
            break;

        case 3:
            Deletar();
            break;

        case 4:
            printf("Obrigado por utilizar o sistema!\n");
            return 0;

        default:
            printf("Essa op��o n�o est� dispon�vel!\n");
            system("pause");
            break;
        }
    }
}
