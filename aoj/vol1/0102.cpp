#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	while(1){
		int n;	
		int a[12][12];
		
		scanf(" %d", &n);
		if(n==0) break;
		
		a[n][n]=0;
		for(int i=0; i<n; ++i){
			a[i][n]=0;
			for(int j=0; j<n; ++j){
				scanf(" %d", &a[i][j]);
				a[i][n]+=a[i][j];
			}
			a[n][n]+=a[i][n];
		}
		
		for(int i=0; i<n; ++i){
			a[n][i]=0;
			for(int j=0; j<n; ++j){
				a[n][i]+=a[j][i];
			}
		}
		
		for(int i=0; i<=n; ++i){ 
			for(int j=0; j<=n; ++j){
				printf("%5d", a[i][j]);
			}
			printf("\n");
		}
				
	}
	return 0;
}