#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
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
/*
E -> S$
S -> T K
K -> + T K
K -> - T K
K -> e
T -> F Z
Z -> F Z
Z -> / F Z
Z -> e 
F -> (S)
F -> X
F -> X
X -> 1D|2D|3D|4D|5D|6D|7D|8D|9D
D -> 0D|1D|2D|3D|4D|5D|6D|7D|8D|9D
D -> e
e: palavra vazia
*/
int E(char palavra[],int *pos);
int S(char palavra[],int *pos);
int K(char palavra[],int *pos);
int T(char palavra[],int *pos);
int Z(char palavra[],int *pos);
int F(char palavra[],int *pos);
int F(char palavra[],int *pos);
int X(char palavra[],int *pos);
int D(char palavra[],int *pos);


char lookahead;
int  match(char t, char palavra[], int *pos){
	if (lookahead == t){
		lookahead= palavra[++(*pos)];
		return(1);
	}
	return(0);
}

void trataErro(int pos){
	fprintf(stderr,"[Erro] - Erro de sintaxe\n");
	fprintf(stderr,"Erro na posicao %d \n",pos);
}
/*
* E -> S$
*/
int E(char palavra[],int *pos)
{
	if(S(palavra,pos) && match('$',palavra,pos))
	{
		return 1;
	}
	return 0;
}
/*
* S -> T K
*/
int S(char palavra [],int *pos)
{
	if(T(palavra,pos) && K(palavra,pos))
	{
		return 1;
	}
	return 0;
}
/*
* K -> + T K
* K -> - T K
* K -> e
*/
int K(char palavra[],int *pos)
{
	if(lookahead == '+' || lookahead == '-')
	{
		if(match(lookahead,palavra,pos) && T(palavra,pos) && K(palavra,pos))
		{
			return 1;
		}
		return 0;
	}
	return 1; /* nullable */ 
}
/*
* T -> F Z
*/
int T(char palavra[],int *pos)
{
	if(F(palavra,pos) && Z(palavra,pos))
	{
		return 1;
	}
	return 0;
}
/*
* Z -> F Z
* Z -> / F Z
* Z -> e 
*/
int Z(char palavra[],int *pos)
{
	if(lookahead == '*' || lookahead == '/')
	{
		if(match(lookahead,palavra,pos) && F(palavra,pos) && Z(palavra,pos))
		{
			return 1;
		}
		return 0;
	}
	return 1;
	
}
/*
* F -> (S)
* F -> X
* F -> X
*/
int F(char palavra[],int *pos)
{
	if(lookahead == '(' )
	{
		if(match(lookahead,palavra,pos) && S(palavra,pos) && match(')',palavra,pos))
		{
			return 1;
		}
		return 0;
	}
	else if(X(palavra,pos) || (match('-',palavra,pos) && X(palavra,pos)) )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/*
* X -> 1D|2D|3D|4D|5D|6D|7D|8D|9D
*/
int X(char palavra[],int *pos)
{
	if(isdigit(lookahead) && lookahead != 0)
	{
		if(match(lookahead,palavra,pos) && D(palavra,pos))
		{
			return 1;
		}
		return 0;
	}
	return 0;
}
/*
* D -> 0D|1D|2D|3D|4D|5D|6D|7D|8D|9D
* D -> e
*/
int D(char palavra[],int *pos)
{
	if(isdigit(lookahead))
	{
		if(match(lookahead,palavra,pos) && D(palavra,pos))
		{
			return 1;
		}
		return 0;
	}
	return 1; /* nullable */ 

}


int main(void)
{

	char palavra[] = "((1*(5-3)/2+(1*(3/2))))$";
	int pos = 0;
	lookahead = palavra[pos];
	if(E(palavra,&pos))
	{
		fprintf(stdout,"Palavra %s reconhecida\n",palavra);	
	}
	else{
		trataErro(pos);
	}
	return EXIT_SUCCESS;
}
