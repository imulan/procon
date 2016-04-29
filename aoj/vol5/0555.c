#include <stdio.h>

int main(void){
	int n, i, j, k, len=0, count=0, flag;
	char seek[12], ring[12];
	
	scanf(" %s", seek);
	scanf(" %d", &n);
	
	while(seek[len] != '\0') ++len;
	
	for(i=0; i<n; i++){
		scanf(" %s", ring);
		flag=0;
		
		for(j=0; j<10 && flag==0; j++) {
			flag=1;
			for(k=0; k<len; k++){
				if(ring[(j+k)%10] != seek[k]){
					flag=0;
					break;
				}
			}	
		}
		
		count += flag;
	}
	
	printf("%d\n", count);
	
	return 0;
}