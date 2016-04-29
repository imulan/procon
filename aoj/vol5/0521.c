#include <stdio.h>

int main(void){
	int n, i;
	while( scanf(" %d", &n) * n != 0){
		int c = 1000-n;
		int ans=0;
		int a[6]={500,100,50,10,5,1};
		
		for(i=0; i<6; i++){
			while(c>=a[i]){
				c-=a[i];
				++ans;
			}
		}
	
		printf("%d\n", ans);
	}

	return 0;
}