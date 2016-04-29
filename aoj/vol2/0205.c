#include <stdio.h>

int main(void){
	while(1){
		int a[5], b[3]={0}, i, flag=1, count=0;	
		
		for(i=0; i<5; i++){
			scanf(" %d", &a[i]);
			if(a[i]==0){
				flag=0;
				break;
			}
			if(b[a[i]-1]==0) count++;
			b[a[i]-1]++;
		}
		if(flag==0) break;
		
		if(count==2){
			int memo;
			for(i=0; i<3; i++){
				if(b[i]==0) memo=i+1;
			}	
			
			//printf("memo=%d\n", memo);
			
			for(i=0; i<5; i++){
				if(a[i] == ( ((memo+1)%3==0) ? 3:(memo+1)%3) ) a[i]=1;
				else a[i]=2;
			}
		
		}
		else{
			for(i=0; i<5; i++)
				a[i] = 3;
		}
		
		for(i=0; i<5; i++)
			printf("%d\n", a[i]);
	
	}
	return 0;
}