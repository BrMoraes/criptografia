#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (int argc, string argv[])
{
//Verificar se há argumento na linha de comando
if (argc != 2)
{
printf("Usage: ./substitution key\n");
return 1;
}
//Checar se a chave contém apenas números
string key = argv[1];
for (int i = 0; i < strlen(key); i++)
{
    if (!isalpha(key[i]))
    {
        printf("Escreva: ./substituicao chavecom26caracteres\n");
        return 1;
    }
}

//Validar se a chave consiste de 26 caracteres
if (strlen(key) != 26)
{
    printf("Key must contain 26 characters.\n");
    return 1;
}

//Checar se não há letras repetidas
for (int i = 0; i < strlen(key); i++)
{
    for (int j = i + 1; j < strlen(key); j++)
    {
        if (toupper(key[i]) == toupper(key[j]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
}

//Solicitar do usuário: Plaintext
string plaintext = get_string("Plaintext: ");

//Converter letras maiusculas
for (int i = 0; i < strlen(key); i++)
{
    if(islower(key[i]))
    {
        key[i] = key[i] -3;
    }
}

//Imprimir ciphertext
printf("Ciphertext: ");

for (int i = 0; i < strlen(plaintext); i++)
{
    if (isupper(plaintext[i]))
    {
        int letter = plaintext[i] - 65;
        printf("%c", key[letter]);
    }
    else if (islower(plaintext[i]))
    {
        int letter = plaintext[i] - 97;
        printf("%c", key[letter] + 32);
    }
    else
    printf("%c", plaintext[i]);
}
printf("\n");
}