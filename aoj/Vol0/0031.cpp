#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int n;
	while( scanf(" %d", &n) != EOF ){
		int use[10]={0};
		int count=0, m=0;
		for(int i=9; i>=0; --i){
			if(n >= (int)pow(2.0, i)){
				use[i]=1;
				n-=(int)pow(2.0, i);
				++count;
			}
		}
				
		for(int i=0; i<10; ++i){
			if(use[i]==1){
				printf("%d", (int)pow(2.0, i));
				if(m<count-1){
					printf(" ");
					++m;
				}
			}
		} 
	
		printf("\n");
	}

	return 0;
}