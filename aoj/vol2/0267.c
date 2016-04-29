#include <stdio.h>

int main(void){
	while(1){
		int n, i, j;
		int b[5050]={0};
		int count=0;
		
		scanf(" %d", &n);
		if(n==0) break;
		
		for(i=0; i<n; i++)
			scanf(" %d", &b[i]);
	
		int now = n;
	
		while(1){
			//printf("%d\n", now);
			int flag=0;
			
			//for(i=0; i<now; i++)
				//printf("%d ", b[i]);
			//printf("\n");
		
			if(count>10000) break;
			for(i=0; i<now; i++){
				if(b[i] != i+1) {
					flag=1;
					break;
				}
			}
			if(flag==0) break;
			
			int k = now; //変化前の値を保存
			
			for(i=0; i<k; i++)
				--b[i];
			
			++now;		
			b[now-1] = k;	
			
			for(i=0; i<now; i++){
				if(b[i]==0) {
					for(j=i; j<now; j++) b[j] = b[j+1];
					--now;
					--i;
				}
			}				
			
			++count;
		}
		
		if(count>10000) printf("-1\n");	
		else printf("%d\n", count);
	}

	return 0;
}