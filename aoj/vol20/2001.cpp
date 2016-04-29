#include <cstdio>
#include <iostream>
#include <utility>
using namespace std;

typedef struct{
	int height;
	int p;
	int q;
}info;

int main(){
	while(1){
		int n, m, a;
		info b[1000];
		
		scanf(" %d %d %d", &n, &m, &a);	
		if(n==0) break;
		for(int i=0; i<m; ++i) scanf(" %d %d %d", &b[i].height, &b[i].p, &b[i].q);
		
		for(int i=0; i<m; ++i){
			for(int j=i; j<m; ++j){
				if(b[i].height < b[j].height) swap(b[i], b[j]);		
			}
		}
		
		int amida[101];
		for(int i=1; i<=n; ++i) amida[i]=i;
		
		//高い方から順に処理
		for(int i=0; i<m; ++i)
			swap( amida[b[i].p], amida[b[i].q] );		
			
		for(int i=1; i<=n; ++i){
			if(a==amida[i]){
				printf("%d\n", i);
				break;	
			}	
		}
		
	}
	return 0;
}