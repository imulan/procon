#include <stdio.h>

int main(void){
	while(1){
		int a[5], x, y, i, flag=0, max=0, p=-1;;
		
		for(i=0; i<5; i++) {
			scanf(" %d %d", &x, &y);
			if(x==0 && y==0) {
				flag=1;
				break;
			}
				
			a[i] = x+y;
			if(max < a[i]) {
				max = a[i];
				p=i;
			}
			
		}
		if(flag==1) break;
		
		printf("%c %d\n", 'A'+p, a[p]);	
	}

	return 0;
}