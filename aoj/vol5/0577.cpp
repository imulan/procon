#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	int n, a[200][3], p[3][101], ans[200];
	
	scanf(" %d", &n);
	memset(p, 0, sizeof(p));
	memset(ans, 0, sizeof(ans));
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<3; ++j){
			scanf(" %d", &a[i][j]);
			p[j][ a[i][j] ]++;	
		}
	}
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<3; ++j){
			if(p[j][a[i][j]]==1){
				ans[i]+=a[i][j];	
			}		
		}
	}
	
	for(int i=0; i<n; ++i) printf("%d\n", ans[i]);
}