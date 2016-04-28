#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int a, b, c;
	while(scanf(" %d %d %d", &a, &b, &c) != EOF){
		int now=a+b, count=0;
		
		for(int i=1; i<=10; i++){
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