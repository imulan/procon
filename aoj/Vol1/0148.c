#include <stdio.h>

int main(void){
	int n;
	while(scanf(" %d", &n) != EOF){
		printf("3C");
		if(n%39==0) printf("39\n");
		else if(n%39 < 10) printf("0%d\n", n%39);
		else printf("%d\n", n%39);
	}

	return 0;
}