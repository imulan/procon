#include <stdio.h>

typedef struct{
	int name;
	int p;
	int q;
	int r;
	int cal;
}sweet;

int main(void){
	while(1){
		int n, i, a, b, c;
		int s, t, u, v;
		sweet sw[1000];	
			
		scanf(" %d", &n);
		if(n==0) break;
	
		for(i=0; i<n; i++){
			scanf(" %d %d %d %d", &sw[i].name, &sw[i].p, &sw[i].q, &sw[i].r);		
			sw[i].cal = 4*sw[i].p + 9*sw[i].q + 4*sw[i].r;
		}
		
		scanf(" %d %d %d %d", &s, &t, &u, &v);
		
		int flag=0;
		for(i=0; i<n; i++){
			if(sw[i].p<=s && sw[i].q<=t && sw[i].r<=u && sw[i].cal<=v){
				flag=1;
				printf("%d\n", sw[i].name);
			}
		}
		
		if(flag==0) printf("NA\n");

	}

	return 0;
}