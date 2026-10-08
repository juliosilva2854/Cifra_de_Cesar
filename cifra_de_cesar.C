#include <stdio.h>  // Biblioteca padrão para entrada/saída (printf, fgets)
#include <string.h> // Biblioteca para manipular strings (strlen, strcspn)

// Função que aplica a Cifra de César na mensagem

void cifrar_mensagem(char mensagem[], int chave) {
    int i = 0;

    // Percorre cada caractere da string até encontrar o fim da mensagem ('\0')
    
    while (mensagem[i] != '\0') {
        char caractere = mensagem[i];

        // Verifica se o caractere é uma letra maiúscula (ASCII entre 'A' e 'Z')
        
        if (caractere >= 'A' && caractere <= 'Z') {
            // Ajusta o caractere para base 0 ('A' vira 0), 
            //aplica a chave e usa o módulo % 26 para voltar ao alfabeto se passar de 'Z'
            mensagem[i] = (caractere - 'A' + chave) % 26 + 'A';
        } 
        // Verifica se o caractere é uma letra minúscula (ASCII entre 'a' e 'z')
        else if (caractere >= 'a' && caractere <= 'z') {
            // Aplica a mesma lógica de rotação para letras minúsculas
            mensagem[i] = (caractere - 'a' + chave) % 26 + 'a';
        }
        
        // Caracteres especiais, espaços e números não são alterados
        i++; // Avança para o próximo caractere da array
    }
}

int main() {
    char mensagem[100]; // Reserva um espaço de memória para até 99 caracteres + '\0'
    int chave = 3;      // Define o número de posições a deslocar (chave de criptografia)

    printf("===========================================\n");
    printf("   SISTEMA DE CRIPTOGRAFIA (CIFRA DE CÉSAR) \n");
    printf("===========================================\n\n");

    printf("Digite a mensagem secreta: ");
    
    // fgets lê a entrada do usuário com limite de tamanho (evita Buffer Overflow)
    fgets(mensagem, sizeof(mensagem), stdin);

    // Remove a quebra de linha ('\n') inserida pelo fgets ao pressionar Enter
    mensagem[strcspn(mensagem, "\n")] = '\0';

    printf("\n[1] Mensagem Original: %s\n", mensagem);

    // Chama a função para cifrar a mensagem utilizando a chave
    cifrar_mensagem(mensagem, chave);

    printf("[2] Mensagem Cifrada:  %s\n", mensagem);

    return 0; // Indica que o programa finalizou com sucesso
}
