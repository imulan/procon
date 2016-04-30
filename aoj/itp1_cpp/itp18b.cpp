#include <cstdio>

int main(){
	char num[1001];
	while(1){
		int sum=0, i=0;
	
		scanf("%s", num);
		if(num[0]=='0') break;
	
		while(num[i]!='\0'){
			//printf("%d\n", sum);
			sum += num[i]-'0';
			++i;
		}
		
		printf("%d\n", sum);
	}
	
	return 0;
}