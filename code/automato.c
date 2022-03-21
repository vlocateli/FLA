#include<stdio.h>
#include<stdlib.h>
typedef int32_t s32;
typedef size_t usize;
#define ACEITA 1
#define REJEITA 0
s32 scanner(const char palavra[])
{
	char letra;
	usize posicao = 0;
	q0:
		letra = palavra[palavra[++posicao]];
		switch(letra)
		{
			case 'a':
				{
					palavra[++posicao];
					goto q1;
					break;
				}
			case 'b':
					palavra[++posicao];
					goto q0;
					break;
			case '\0':
					return REJEITA;
			default:
					goto poco;
					break;
		}
	q1:
		letra = palavra[palavra[++posicao]];
		switch(letra)
		{
			case 'a':
				{
					palavra[++posicao];
					goto q1;
					break;
				}
			case 'b':
					{
						palavra[++posicao];
						goto q0;
						break;
					}
			case '\0':
					{
						return ACEITA;
						break;
					}
			default:
					{
					goto poco;
					break;
					}

		}

	poco:
		return REJEITA;
}

