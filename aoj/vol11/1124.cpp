#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		int n, q;
		int date[101];
		
		scanf(" %d %d", &n, &q); //会議にはq人以上必要
		if(n==0) break;	
		
		//初期化
		for(int i=0; i<=101; ++i) date[i]=0;
		
		for(int i=0; i<n; ++i){
			int m;
			scanf(" %d", &m);
			
			for(int j=0; j<m; ++j){
				int d;
				scanf(" %d", &d);
				date[d]++;
			}
		}
		
		int ans=0;
		for(int i=0; i<=101; ++i){
			if(date[i]>=q && date[ans] < date[i]) ans=i;	
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}