#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEIS 6
#define CINCO 5
#define QUATRO 4
#define TRES 3
#define DOIS 2
#define UM 1

void lancar_dados (int*, int*, int*, int*, int*);
int aval_general (int*, int*, int*, int*, int*);
int aval_full (int*, int*, int*, int*, int*);
int aval_sequencia (int*, int*, int*, int*, int*);
int aval_seis (int*, int*, int*, int*, int*);
int aval_cinco (int*, int*, int*, int*, int*);
int aval_quatro (int*, int*, int*, int*, int*);
int aval_tres (int*, int*, int*, int*, int*);
int aval_dois(int*, int*, int*, int*, int*);
int aval_um (int*, int*, int*, int*, int*);
void ordenar (int*, int*);

int main(){

	int d1,d2,d3,d4,d5, g, f, seq, s, c, q, t, d, u, op, total = 0;

	printf("---------ESCOLHA UMA ENTRADA---------\n");
	printf("1 - Aleatório\n");
	printf("2 - Manual\n");
	printf("3 - SAIR\n:");
	__fpurge(stdin);
	scanf("%d",&op);

	if(op == 1){
		lancar_dados (&d1, &d2, &d3, &d4, &d5);
	}
	else if(op == 2){
		printf("\n:");
		__fpurge(stdin);
		scanf("%d",&d1);
		if(d1 < 1 || d1 > 6)
		{
			printf("Dado invalido\n");
			main();
			return 0;
		}

		printf("\n:");
		__fpurge(stdin);
		scanf("%d",&d2);
		if(d2 < 1 || d2 > 6)
		{
			printf("Dado invalido\n");
			main();
			return 0;
		}

		printf("\n:");
		__fpurge(stdin);
		scanf("%d",&d3);
		if(d3 < 1 || d3 > 6)
		{
			printf("Dado invalido\n");
			main();
			return 0;
		}

		printf("\n:");
		__fpurge(stdin);
		scanf("%d",&d4);
		if(d4 < 1 || d4 > 6)
		{
			printf("Dado invalido\n");
			main();
			return 0;
		}

		printf("\n:");
		__fpurge(stdin);
		scanf("%d",&d5);
		if(d5 < 1 || d5 > 6)
		{
			printf("Dado invalido\n");
			main();
			return 0;
		}
	}
	else if(op == 3){
		return 0;
	}
	else{
		main();
	}

	g = aval_general (&d1, &d2, &d3, &d4, &d5);
	f = aval_full (&d1, &d2, &d3, &d4, &d5);
	seq = aval_sequencia (&d1, &d2, &d3, &d4, &d5);
	s = aval_seis (&d1, &d2, &d3, &d4, &d5);
	c = aval_cinco (&d1, &d2, &d3, &d4, &d5);
	q = aval_quatro (&d1, &d2, &d3, &d4, &d5);
	t = aval_tres (&d1, &d2, &d3, &d4, &d5);
	d = aval_dois (&d1, &d2, &d3, &d4, &d5);
	u = aval_um (&d1, &d2, &d3, &d4, &d5);

	total = g + f + seq + s + c + q + t + d + u;
	

	//RELATORIO

	printf("\n\n---------------------\n");
	printf("| %d | %d | %d | %d | %d |\n",d1,d2,d3,d4,d5);
	printf("---------------------\n");
	printf("GENERAL: %d\n", g);
	printf("FULL: %d\n", f);
	printf("SEQUENCIA: %d\n", seq);
	printf("6: %d\n", s);
	printf("5: %d\n", c);
	printf("4: %d\n", q);
	printf("3: %d\n", t);
	printf("2: %d\n", d);
	printf("1: %d\n", u);
	printf("----------\n");
	printf("TOTAL: %d|\n", total);
	printf("----------\n");

	return 0;
}

void lancar_dados(int* a1, int* a2, int* a3, int* a4, int* a5){

	srand(time(NULL));
	*a1 = 1 + (rand() % 6);
	*a2 = 1 + (rand() % 6);
	*a3 = 1 + (rand() % 6);
	*a4 = 1 + (rand() % 6);
	*a5 = 1 + (rand() % 6);	
}
int aval_general(int* x1, int* x2, int* x3, int* x4, int* x5){

	if(*x1 == *x2 && *x2 == *x3 && *x3 == *x4 && *x4 == *x5)
		return 50;
	
	else
		return 0;
}

//**********************************************************************//
//					FUNÇÃO MAIS DIFICIL DO JOGO							//
//**********************************************************************//
int aval_full(int* x1, int* x2, int* x3, int* x4, int* x5){
	/*
	-------------------------------------------------------------------
	combinações possiveis
	00011
	00101
	01001
	01010
	01100
	00110
	10001
	10010
	10100
	11000
	----------------------------------------------------
	cada trinca forma mais 2 dulas com um termo central
	
	1 *x1 == *x2 && *x2 == *x3 || termo *x2
	2 *x1 == *x2 && *x2 == *x4 || termo *x2
	3 *x1 == *x3 && *x3 == *x4 || termo *x3
	4 *x1 == *x3 && *x3 == *x5 || termo *x3
	5 *x1 == *x4 && *x4 == *x5 || termo *x4
	6 *x1 == *x2 && *x2 == *x5 || termo *x2
	7 *x2 == *x3 && *x3 == *x4 || termo *x3
	8 *x2 == *x3 && *x3 == *x4 || termo *x3
	9 *x2 == *x4 && *x4 == *x5 || termo *x4
	10 *x3 == *x4 && *x4 == *x5	  termo *x4
	---------------------------------------------------
	*/
	//1 teste 00011
	if(*x1 == *x2 && *x2 == *x3){

		if(*x4 == *x5 && *x4 != *x2){
			return 40;
		}
		else{
			return 0;
		}
	}
	//2 teste 00101
	else if(*x1 == *x2 && *x2 == *x4){

		if(*x3 == *x5 && *x3 != *x2){
			return 40;
		}
		else{
			return 0;
		}
	}
	//3 teste 01001
	else if(*x1 == *x3 && *x3 == *x4){

		if(*x2 == *x5 && *x2 != *x3){
			return 40;
		}
		else{
			return 0;
		}
	}
	//4 teste 01010
	else if(*x1 == *x3 && *x3 == *x5){
		if(*x2 == *x4 && *x2 != *x3){
			return 40;
		}
		else{
			return 0;
		}
	}
	//5 teste 01100
	else if(*x1 == *x4 && *x4 == *x5)
	{
		if(*x2 == *x3 && *x2 != *x4){
			return 40;
		}
		else{
			return 0;
		}
	}
	//6 teste 00110
	else if(*x1 == *x2 && *x2 == *x5){

		if(*x3 == *x4 && *x3 != *x2){
			return 40;
		}
		else{
			return 0;
		}
	}
	//7 teste 10001
	else if(*x2 == *x3 && *x3 == *x4){

		if(*x1 == *x5 && *x1 != *x3){
			return 40;
		}
		else{
			return 0;
		}
	}
	//8 teste 10010
	else if(*x2 == *x3 && *x3 == *x5){

		if(*x1 == *x4 && *x1 != *x3){
			return 40;
		}
		else{
			return 0;
		}
	}
	//9 teste 10100
	else if(*x2 == *x4 && *x4 == *x5){

		if(*x1 == *x3 && *x1 != *x4){
			return 40;
		}
		else{
			return 0;
		}
	}
	//10 teste 11000
	else if(*x3 == *x4 && *x4 == *x5){

		if(*x1 == *x2 && *x1 != *x4){
			return 40;
		}
		else{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

int aval_sequencia (int* x1, int* x2, int* x3, int* x4, int* x5){

	int i,t,aux = 0;
	int vet[5] = {*x1,*x2,*x3,*x4,*x5};

	t = 5;

	ordenar(vet, &t);

//	printf("\nordenado\n");
	for (i = 0; i < 5; i++)
	{
		aux += vet[i];
	}
//	printf("\n");

	if(((aux == 15) || (aux == 20)) && (vet[1] == vet [0]+1 && vet[2] == vet[1]+1 && vet[3] == vet [2]+1 && vet[4] == vet[3]+1)){
		return 30;
	}
	else{

		return 0;
	}
}

void ordenar(int v[], int* x){

	int i, j, aux = 0;

	for (i = 1; i < *x; i++){
		j = i;

		while (j > 0 && v[j - 1] > v[j]){
			aux = v[j]; 
			v[j] = v[j - 1];
			v[j - 1] = aux;
			j--;
		}
	}
 		/*		1º aux recebe o que esta em [1]
				o [1] = o que esta em [0]
				e [0] = o que esta em aux
				j decrementa, é > que 0,
				mas [0] !> que [1]; 		*/
}

int aval_seis (int* x1, int* x2, int* x3, int* x4, int* x5){
	
	int i, aux = 0;
	int vet[5] = {*x1,*x2,*x3,*x4,*x5};

	for(i = 0; i < 5; i++){
		if(vet[i] == SEIS){
			aux++;
		}
	}
	return aux * SEIS;
}

int aval_cinco (int* x1, int* x2, int* x3, int* x4, int* x5){
	
	int i, aux = 0;
	int vet[5] = {*x1,*x2,*x3,*x4,*x5};

	for(i = 0; i < 5; i++){
		if(vet[i] == CINCO){
			aux++;
		}
	}
	return aux * CINCO;
}

int aval_quatro (int* x1, int* x2, int* x3, int* x4, int* x5){
	
	int i, aux = 0;
	int vet[5] = {*x1,*x2,*x3,*x4,*x5};

	for(i = 0; i < 5; i++){
		if(vet[i] == QUATRO){
			aux++;
		}
	}
	return aux * QUATRO;
}

int aval_tres (int* x1, int* x2, int* x3, int* x4, int* x5){
	
	int i, aux = 0;
	int vet[5] = {*x1,*x2,*x3,*x4,*x5};

	for(i = 0; i < 5; i++){
		if(vet[i] == TRES){
			aux++;
		}
	}
	return aux * TRES;
}

int aval_dois (int* x1, int* x2, int* x3, int* x4, int* x5){
	
	int i, aux = 0;
	int vet[5] = {*x1,*x2,*x3,*x4,*x5};

	for(i = 0; i < 5; i++){
		if(vet[i] == DOIS){
			aux++;
		}
	}
	return aux * DOIS;
}

int aval_um (int* x1, int* x2, int* x3, int* x4, int* x5){
	
	int i, aux = 0;
	int vet[5] = {*x1,*x2,*x3,*x4,*x5};

	for(i = 0; i < 5; i++){
		if(vet[i] == UM){
			aux++;
		}
	}
	return aux * UM;
}