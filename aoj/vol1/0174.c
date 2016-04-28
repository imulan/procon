#include <stdio.h>
#include <string.h>

int main(void){
	while(1){
		char str[110];
		int a=0, b=0, i=1;
		
		scanf(" %s", str);
		if(strcmp(str, "0") == 0) break;
		
		while(str[i] != '\0'){
			if(str[i] == 'A') a++;	
			else if(str[i] == 'B') b++;
			i++;
			
			//printf("%d : %d\n", a, b);
		}
		
		if(a<b) b++;
		else a++;
		
		printf("%d %d\n", a, b);
	}

	return 0;
}