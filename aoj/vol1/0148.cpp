#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n;
	while(scanf(" %d", &n) != EOF){
		int p=n%39;
		
		printf("3C");
		if(p==0) printf("39\n");
		else if(p < 10) printf("0%d\n", p);
		else printf("%d\n", p);
	}

	return 0;
} 