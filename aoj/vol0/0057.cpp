#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n;
	while( scanf(" %d", &n) != EOF){
		long ans=2;	
		for(int i=1; i<n; ++i) ans+=i+1;
		printf("%ld\n", ans);
	}
	return 0;
}