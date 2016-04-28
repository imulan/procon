#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	bool first=false;
	while(1){
		int a, b;
		bool flag=true;
		
		scanf(" %d %d", &a, &b);
		if(a==0 && b==0) break;
		
		if(first) printf("\n");
		
		for(int i=a; i<=b; ++i){
			if( (i%4==0 && i%100!=0) || (i%4==0 && i%100==0 && i%400==0) ){
				printf("%d\n", i);
				flag = false;
			}
		}

		if(flag) printf("NA\n");

		first=true;
	}
	return 0;
}