#include <stdio.h>

int main(void){
	long n, i, a, y, count=0;
	
	scanf("%ld", &n);
	
	for(i=0; i<n; i++){
		scanf(" %ld", &a);
		int flag=0;
		
		for(y=1; 2*y*(y+1)<=a; y++){
			if((a-2*y*(y+1))%(2*y+1)==0){
				flag=1;
				break;
			}
		}
		
		if(flag==0) ++count;
	
	}
	printf("%ld\n", count);

	return 0;
}