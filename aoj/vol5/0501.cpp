#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		int n, m;
		char a[1000][3];	
		
		scanf(" %d", &n);
		if(n==0) break;
		for(int i=0; i<n; ++i){
			scanf(" %c %c", &a[i][0], &a[i][1]);	
		}
		
		scanf(" %d", &m);
		for(int i=0; i<m; ++i){
			char c;	
			scanf(" %c", &c);
			
			for(int j=0; j<n; ++j){
				if(c==a[j][0]){
					c=a[j][1];	
					break;
				}
			}
			
			printf("%c", c);
		}
		
		printf("\n");
	}
	return 0;
}