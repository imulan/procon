#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n;
	scanf(" %d", &n);
	
	for(int i=0; i<n; ++i){
		int k, p;
		scanf(" %d %d", &k, &p);
		
		if(k%p==0) printf("%d\n", p);
		else printf("%d\n", k%p);
	}
	
	return 0;
}