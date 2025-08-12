#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    // Declara um array para armazenar a palavra digitada pelo usuário (máximo 49 caracteres + '\0')
    char palindromo[50];
    
    // Lê uma linha do teclado (incluindo espaços) e armazena em 'palindromo'
    fgets(palindromo, 50, stdin);

    // Obtém o comprimento da string lida
    int rev = strlen(palindromo);
    
    // Declara um array para armazenar a palavra invertida
    char rev_palindromo[50];

    // Remove o caractere de nova linha ('\n') que o fgets adiciona automaticamente
    // se ele estiver presente no final da string
    if(palindromo[rev - 1] == '\n'){
        palindromo[rev - 1] = '\0';  // Substitui '\n' por terminador nulo
        rev--;                       // Ajusta o comprimento da string
    }
   
    // Converte todos os caracteres da string para minúsculas
    // Isso garante que a comparação seja case-insensitive (Ex: "Aba" = "aba")
    for(int i = 0; i < rev; i++){
        palindromo[i] = tolower(palindromo[i]);
    }

    // Cria a versão invertida da string original
    // Copia cada caractere de 'palindromo' para 'rev_palindromo' na ordem reversa
    for(int i = 0; i < rev; i++){
        rev_palindromo[i] = palindromo[rev - 1 - i];
    }

    // Código de teste comentado - útil para debug
    // printf("%s", rev_palindromo);
   
    // Adiciona o terminador nulo no final da string invertida
    // Isso é essencial para que a string seja válida em C
    rev_palindromo[rev] = '\0';

    // Compara a string original (em minúsculas) com sua versão invertida
    // strcmp() retorna 0 se as strings forem idênticas
    int resultado = strcmp(palindromo, rev_palindromo);
    
    // Verifica o resultado da comparação e exibe a mensagem apropriada
    if(resultado == 0){
        printf("Esta palavra e um palindromo\n");
    }
    else{
        printf("Esta palavra nao e um palindromo\n");
    }

    return 0;
}