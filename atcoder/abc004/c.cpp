#include <iostream>
#include <cstdio>
using namespace std;

void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int main(){
	int num[6]={1, 2, 3, 4, 5, 6};
	long n;	
	
	scanf(" %ld", &n);
	
	for(long i=0; i<n%720; ++i) swap(&num[(i%5)], &num[(i%5)+1]);
	
	for(int i=0; i<6; ++i) printf("%d", num[i]);
	printf("\n");
	
	return 0;
}