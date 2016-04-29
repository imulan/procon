#include <stdio.h>

int main(void){
	char key[1000];
	int i=0;
	
	scanf("%s", key);
	while(key[i] != '\0'){
		if(key[i] >= 'D') printf("%c", key[i]-3);
		else printf("%c", key[i]+23);
		++i;
	}
	printf("\n");

	return 0;
}