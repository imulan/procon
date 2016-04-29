#include <stdio.h>
#include <math.h>

typedef struct{
	int num;
	double money;
}bank;

int main(void){
	while(1){
		int n, y, r, t, i;
		bank b[50];
		
		scanf(" %d", &n);
		if(n==0) break;
		
		scanf(" %d", &y);
		for(i=0; i<n; i++){
			scanf(" %d %d %d", &b[i].num, &r, &t);
			
			if(t==1){
				b[i].money = 1 + y*r/100.0;
			}
			else if(t==2){
				b[i].money = pow( (1+r/100.0), y);
			}
			
		}
		
		double max = b[0].money;
		int index = 0;
		
		for(i=0; i<n; i++){
			if(max < b[i].money){
				max=b[i].money;
				index = i;
			}
		}
			
		printf("%d\n", b[index].num);
	
	}

	return 0;
}