#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	while(1){
		int n, a;
		cin >> n;
		if(n==0) break;
		for(int i=0; i<9; ++i){
			scanf(" %d", &a);
			n-=a;
		}
	
		printf("%d\n", n);
	}
	return 0;
}