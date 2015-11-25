#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n, t, e, x[100];
	
	scanf(" %d %d %d", &n, &t, &e);
	for(int i=0; i<n; ++i) scanf(" %d", &x[i]);
	
	int ans=-1;
	for(int i=t-e; i<=t+e; ++i){
		for(int j=0; j<n; ++j){
			if(i%x[j]==0){
				ans=j+1;
				break;			
			}
		}	
		
		if(ans!=-1) break;
	}
	
	printf("%d\n", ans);
}	