#include <stdio.h>
#include <stdlib.h>

typedef struct{
	long num;
	long yn;
}people;

int cmp(const void *a, const void *b){
	people p1 = *(people*)a;	
	people p2 = *(people*)b;
	
	long t1 = p1.yn;
	long t2 = p2.yn;
	
	return t1-t2;
}

int main(void){
	long n, k, i, j;
	people x[100000];

	scanf(" %ld %ld", &n, &k);
	for(i=0; i<n; i++){
		x[i].num=i+1;
		scanf(" %ld", &x[i].yn);
	}
	
	qsort(x, k-1, sizeof(people), (int(*)(const void*, const void*))cmp);
	long now = k-1;
	
	printf("%ld\n", x[now].num); 
		
	for(i=k; i<n; i++){
		if(x[i].yn < x[now].yn){
			people tmp = x[i];
			long y=0;
			while(x[y].yn < x[i].yn) ++y;
			printf("y=%ld\n",y);
			for(j=k-1; j>=y; j--){
				x[j+1] = x[j];
			}
			x[y] = tmp;
		}
		
		printf("%ld\n", x[now].num);
			
	}

	return 0;
}