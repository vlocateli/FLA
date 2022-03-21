/*
 * Nome: Victor Seixas Locateli
 * TIA: 41924983
 * Nome: Hugo Amorim 
 * TIA: 4199118-4
 * Nome:Gabriel Gutierrez Pereira
 * TIA: 31952682
 * Nome: Luana Brugnaro de Souza Braga
 * TIA: 31945325
 * Nome: Isabelle Ramos de Azevedo Ferreira
 * TIA: 4193066-5
 * compilador: gcc
 * opções de compilação: -Wall -Wextra -Werror -pedantic -ansi
*/  

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define REJEITA 0
#define ACEITA 1
#define P_FLUTUANTE 2
#define INTEIRO 3

typedef int32_t s32;
typedef size_t usize;
/*
 * @func: is_digit
 * @arg: um inteiro arg que representa uma letra 
 * @return: 1 se o número estiver entre '0' e '9', caso contrário 0
 * --- 
 * Checa se determinado argumento é um digito
*/ 
int is_digit(int arg)
{
	return '0'<= arg && arg <= '9'?1:0;
}
/*
 * @func: scanner_ 
 * @arg: palavra, um ponteiro constante de caracteres  
 * @return: 0 se a palavra foi rejeitada, 1 se ela foi aceita, 2 se ela for 
 * ponto flutuante, e 3 se ela for inteiro
 * ---
 * Checa se a palavra é ou inteiro ou um número de ponto flutuante, implementa-
 * ção do AFD 
*/ 
s32 scanner_( const char *palavra )
{
    char letra;
    usize posicao = 0;
    letra         = palavra[posicao];
    goto q0;
q0:
    if( is_digit( letra ) )
    {
        letra = palavra[++posicao];
        goto q1;
    }
    if( letra == '+' || letra == '-' )
    {
        letra = palavra[++posicao];
        goto q2;
    }
    else
    {
        goto poco;
    }
q1:
    if( is_digit( letra ) )
    {
        letra = palavra[++posicao];
        goto q1;
    }
    if( letra == '.' )
    {
        letra = palavra[++posicao];
        goto q3;
    }
    if( letra == '\0' )
    {
        return INTEIRO;
    }
    else
    {
        goto poco;
    }
q2:
    if( is_digit( letra ) )
    {
        letra = palavra[++posicao];
        goto q1;
    }
    else
    {
        goto poco;
    }
q3:
    if( is_digit( letra ) )
    {
        letra = palavra[++posicao];
        goto q4;
    }
    else
    {
        goto poco;
    }
q4:
    if( is_digit( letra ) )
    {
        letra = palavra[++posicao];
        goto q4;
    }
    if( letra == '\0' )
    {
        return P_FLUTUANTE;
    }
    else
    {
        goto poco;
    }
poco:
    return REJEITA;
}

int main( void )
{
    char *palavra = "3.14159";
	if( scanner_( palavra ) == 0 )
    {
        printf( "REJEITA\n" );
    }
    else if( scanner_( palavra ) == 1 )
    {
        printf( "ACEITA\n" );
    }
    else if( scanner_( palavra ) == 2 )
    {
        printf( "P_FLUTUANTE\n" );
    }
    else if( scanner_( palavra ) == 3 )
    {
        printf( "INTEIRO\n" );
    }
	else
	{
		assert(0 && "inacessível\n");
	}
    return 0;
}
