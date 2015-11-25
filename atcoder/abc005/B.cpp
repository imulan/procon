#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n, a, ans=1000;

	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		scanf(" %d", &a);
		if(a<ans) ans=a;	
	}
	
	printf("%d\n", ans);
	return 0;
}