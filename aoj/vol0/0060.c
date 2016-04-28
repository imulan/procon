#include <stdio.h>

int main(void){
	int a, b, c;
	while(scanf(" %d %d %d", &a, &b, &c) != EOF){
		int i, now=a+b;
		int count=0;
		
		for(i=1; i<=10; i++){
			if(i==a || i==b || i==c) continue;
			else{
				if(now+i<=20) count++;	
			}
		}

		if(count>=4) printf("YES\n");
		else printf("NO\n");

	}

	return 0;
}