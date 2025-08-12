Verificador de Palíndromos em C 
------------------------------------------------------------------------
Visão Geral

Este programa implementa um algoritmo para verificação de palíndromos, utilizando manipulação de strings e estruturas de controle fundamentais da linguagem C. Um palíndromo é uma palavra, frase ou sequência que 
mantém o mesmo significado quando lida de frente para trás, ignorando diferenças entre maiúsculas e minúsculas.

Arquitetura e Design

- Estruturas de Dados

- Arrays de caracteres (char[]): Utilizados para armazenamento das strings original e invertida

- Variáveis auxiliares: Controle de índices e armazenamento de resultados de comparação


Bibliotecas Utilizadas

- <stdio.h>: Operações de entrada/saída (I/O)

- <string.h>: Funções para manipulação de strings (strlen, strcmp)

- <ctype.h>: Funções para classificação de caracteres (tolower)

Lógica do Algoritmo

Fase 1: Aquisição de Dados

cfgets(palindromo, 50, stdin);

O programa utiliza fgets() em vez de scanf() para garantir a captura segura de strings com espaços, limitando a entrada a 49 caracteres úteis mais o terminador nulo.

Fase 2: Sanitização da Entrada

```
if (palindromo[rev - 1] == '\n'){

    palindromo[rev - 1] = '\0';
    rev--;
}    
```

Justificativa técnica: A função fgets() preserva o caractere de nova linha (\n) na string capturada. Esta etapa remove esse caractere indesejado e ajusta o contador de comprimento, evitando interferência na análise posterior.

Fase 3: Normalização Case-Insensitive

```
for(int i = 0; i < rev; i++){

    palindromo[i] = tolower(palindromo[i]);
}
```

Implementação robusta: A conversão para minúsculas garante que palavras como "Arara", "RADAR" ou "AbA" sejam corretamente identificadas como palíndromos, independentemente da variação tipográfica na entrada.

Fase 4: Algoritmo de Inversão

```
for(int i = 0; i < rev; i++){

    rev_palindromo[i] = palindromo[rev - 1 - i];
}
```

Complexidade: O(n) em tempo e espaço

Lógica: Para cada posição i na string invertida, atribui-se o caractere da posição (comprimento - 1 - i) da string original, criando o espelhamento completo da sequência.

Fase 5: Comparação e Validação

cint resultado = strcmp(palindromo, rev_palindromo);

Eficiência: Utiliza a função otimizada strcmp() da biblioteca padrão C, que compara lexicograficamente as strings byte por byte até encontrar uma diferença ou atingir o final de ambas.


Características Técnicas

Vantagens da Implementação


- Segurança de memória: Uso de fgets() previne buffer overflow

- Robustez: Tratamento adequado de caracteres especiais (quebra de linha)

- Flexibilidade: Suporte a case-insensitive matching

- Clareza: Algoritmo linear e intuitivo


Casos de Teste Sugeridos
Casos Positivos

- "radar" → Palíndromo simples
- "A" → Palíndromo de um caractere
- "AbA" → Teste case-insensitive
- "aabbaa" → Palíndromo com repetições

Casos Negativos

- "hello" → String comum
- "abcd" → Sequência sem simetria
- "" → String vazia (edge case)

