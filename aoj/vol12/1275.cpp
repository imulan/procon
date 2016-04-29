//ヨセフスの問題

#include <cstdio>
#include <iostream>
using namespace std;

int f(int n, int k){
	if(n==1) return 0;	
	return (f(n-1,k)+k)%n;
}

int main(){
	while(1){
		int n, k, m;
		scanf(" %d %d %d", &n, &k, &m);
		if(n==0) break;
			
		printf("%d\n", (f(n-1,k)+m)%n+1);
	}
}