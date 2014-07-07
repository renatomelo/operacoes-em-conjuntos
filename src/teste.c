#include <stdio.h>

void troca(int *a, int *b){
	(*a)++;
	(*b)++;
}

int
main (int argc, char *argv[])
{
	int a = 10;
	int b = 20;
	int *pa = &a, *pb = &b;
	troca(&a,&b);
	troca(&a,&b);
	troca(&a,&b);
	printf("A: %d, B: %d\n",a,b);
	return 0;
}
