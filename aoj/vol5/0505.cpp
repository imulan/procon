#include <iostream>
#include <cstdio>
using namespace std;

const int N=1000;
const int M=100;

int main(){
	while(1){
		int n, m, a;
		int trip[M];
		int ans[M];
		
		scanf(" %d %d", &n, &m);
		if(n==0 && m==0) break;
		
		for(int i=0; i<m; ++i) trip[i]=0;
		
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				scanf(" %d", &a);		
				trip[j]+=a;
			}
		}
	
		for(int i=0; i<m; ++i) ans[i]=-1;
		
		int count=0;
		for(int i=n; i>=0; --i){
			for(int j=0; j<m; ++j){
				if(trip[j]==i){
					ans[count]=j+1;	
					++count;
				}
			}
		}

		for(int i=0; i<m; ++i){
			if(i>0) printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	
	}
	return 0;
}