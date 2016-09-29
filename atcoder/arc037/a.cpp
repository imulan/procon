#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n, ans=0;
	
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		int m;
		scanf(" %d", &m);	
		
		if(m<80) ans+=80-m;
	}
	
	printf("%d\n", ans);
}