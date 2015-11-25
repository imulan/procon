#include <iostream>
#include <cstdio>

void swap(int *p, int *q){
	int temp = *p;
	*p = *q;
	*q = temp;
}

int main(){
	int a[3]={1,0,0};
	char x, y;
	while( scanf(" %c,%c", &x, &y) != EOF ){
		//printf("x=%c, y=%c\n", x, y);
		swap(&a[(int)(x-'A')], &a[(int)(y-'A')]);
	}

	for(int i=0; i<3; ++i)
		if(a[i]==1) printf("%c\n", 'A'+i);

	return 0;
}