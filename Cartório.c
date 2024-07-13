#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar dos string
#include <ctype.h> // biblioteca para funções de manipulação de caracteres

// Função para validar o CPF
int validarCPF(const char *cpf) {
    int i; // declaração da variável para uso nos loops
    
    // Verifica se o comprimento do CPF é diferente de 11
    if (strlen(cpf) != 11) {
        return 0; // CPF inválido
    }

    // Verifica se todos os caracteres são dígitos
    for (i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) { // Função isdigit verifica se o caractere é um dígito
            return 0; // CPF inválido
        }
    }

    // Cálculo do primeiro dígito verificador
    int soma = 0; // Inicializa a soma
    for (i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i); // Converte caractere para inteiro e multiplica pela posição
    }

    int digito1 = 11 - (soma % 11); // Calcula o primeiro dígito verificador
    if (digito1 >= 10) {
        digito1 = 0; // Se o resultado for 10 ou 11, o dígito é 0
    }

    // Verifica se o primeiro dígito verificador está correto
    if (digito1 != (cpf[9] - '0')) {
        return 0; // CPF inválido
        
        
    }

// Função para verificar se CPF já está cadastrado
int cpfCadastrado(const char *cpf) {
    char nomeArquivo[50];
    sprintf(nomeArquivo, "%s.", cpf); // Nome do arquivo será o CPF com extensão .txt

    FILE *file;
    file = fopen(nomeArquivo, "r");
    if (file != NULL) {
        fclose(file);
        return 1; // CPF já cadastrado
    }

    return 0; // CPF não cadastrado
}


}
// Função para verificar se CPF já está cadastrado
int cpfCadastrado(const char *cpf) {
    char nomeArquivo[50];
    sprintf(nomeArquivo, "%s.", cpf); // Nome do arquivo será o CPF com extensão .txt

    FILE *file;
    file = fopen(nomeArquivo, "r");
    if (file != NULL) {
        fclose(file);
        return 1; // CPF já cadastrado
    }

    return 0; // CPF não cadastrado
}

int Registro() 
{
    char arquivo[50];   // Define uma variável para armazenar o nome do arquivo onde os dados serão gravados
    char cpf[15];       // Define uma variável para armazenar o CPF digitado pelo usuário
    char nome[40];      // Define uma variável para armazenar o nome digitado pelo usuário
    char sobrenome[40]; // Define uma variável para armazenar o sobrenome digitado pelo usuário
    char cargo[40];     // Define uma variável para armazenar o cargo digitado pelo usuário

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf); // Solicita e lê o CPF digitado pelo usuário

   
    if (!validarCPF(cpf)) {  // Valida o CPF antes de continuar
        printf("CPF inválido! Por favor, insira um CPF válido com 11 dígitos numéricos.\n");
        system("pause");
        return 1; // Retorna com erro se o CPF não for válido
    }

    // Verifica se o CPF já está cadastrado
    if (cpfCadastrado(cpf)) {
        printf("CPF já cadastrado! Não é possível cadastrar o mesmo CPF novamente.\n");
        system("pause");
        return 1; // Retorna com erro se o CPF já estiver cadastrado
    }

    sprintf(arquivo, "%s", cpf); // Nome do arquivo será o CPF com extensão .txt

    FILE *file;
    file = fopen(arquivo, "w"); // Abre o arquivo para escrita
    
    if (file == NULL) {
        printf("Erro ao criar o arquivo para o CPF informado.\n");
        system("pause");
        return 1; // Retorna com erro se não conseguir abrir o arquivo
    }

    fprintf(file, "CPF: %s\n", cpf); // Escreve o CPF no arquivo

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome); // Solicita e lê o nome digitado pelo usuário
    fprintf(file, "NOME: %s\n", nome); // Escreve o nome no arquivo

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome); // Solicita e lê o sobrenome digitado pelo usuário
    fprintf(file, "SOBRENOME: %s\n", sobrenome); // Escreve o sobrenome no arquivo

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo); // Solicita e lê o cargo digitado pelo usuário
    fprintf(file, "CARGO: %s\n", cargo); // Escreve o cargo no arquivo

    fclose(file); // Fecha o arquivo

    printf("Cadastro realizado com sucesso!\n");
    system("pause");
    return 0; // Retorna com sucesso
}


int Consulta() // Função para consultar informações
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem pra Português

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file; // Declaração da variável do tipo do arquivo
    file = fopen(cpf, "r"); ; // Abre o arqrivo para leitura

    if (file == NULL) {
        printf(" Usuário não encontrado. \n");
        system("pause");
        return 1; // Sai da função após exibir a mensagem
    }

    printf("\nEssas são as informações do usuário:\n");

    while (fgets(conteudo, 200, file) != NULL) {
        printf("%s", conteudo); // Exibe as informações do usua´rio contidas no arquivo
        printf("\n\n");
    }
    
    fclose(file); // Fecha o arquivo após leitura 
    system("pause");
    return 0; // Retorna com sucesso
}

int Deletar() // Função para deletar informações de usuários
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem para Português

    char cpf[40];
    char conteudo[200];
    char confirmacao;

    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);

    FILE *file; //Declaração de variável do tipo arquivo
    file = fopen(cpf, "r"); // Abre o arquivo para leitura

    if (file == NULL) {
        printf("Usuário não encontrado.\n");
        system("pause");
        return 1; // Sai da função após exibir a mensagem se o arquivo não existe
    }

    printf("\nEssas são as informações do usuário:\n");

    while (fgets(conteudo, 200, file) != NULL) {
        printf("%s", conteudo); // Exibe as informações do usuário contidas no arquivo
    }

    fclose(file); // Fecha o arquivo após leitura

    printf("\nDeseja realmente deletar este usuário? (s/n): ");
    scanf(" %c", &confirmacao); // Pergunta ao usuário se deseja deletar o usuário

    if (confirmacao == 's' || confirmacao == 'S') {
        remove(cpf); // Deleta o arquivo do usuário
        printf("Usuário deletado com sucesso.\n");
    } else {
        printf("Operação de exclusão cancelada.\n"); // Exibe mensagem se a deleção for cancelada
    }

    system("pause");
    return 0; // Retorna sucesso
}


int main()
{
    int opcao = 0; // Definindo as variáveis
    int laco = 1;
    for (laco = 1; laco == 1;) // corrigido o operador de comparação
    {
        system("cls");

        setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem

        printf("###Cartório da EBAC###\n\n"); // Início do Menu
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
      
        printf("Opção: "); // Fim do menu

        scanf("%d", &opcao); // Armazenando a escolha do usuário

        system("cls"); // responsável por limpar a tela

        switch (opcao) // início da seleção do menu
        {
        case 1:
            Registro(); // chamada de funções
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
            printf("Essa opção não está disponível!\n");
            system("pause");
            break;
        }
    }
}
