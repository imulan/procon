#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		int n, m;
		int r[501][501]={0}; //relationship
		int invite[501]={0};
		
		scanf(" %d %d", &n, &m);
		if(n==0) break;
		for(int i=0; i<m; ++i){
			int a, b;
			scanf(" %d %d", &a, &b);	
			r[a][b]=r[b][a]=1;	
		}
		
		int ans=0;
		for(int i=2; i<=n; ++i){
			if(r[1][i]==1){	
				
				if(invite[i]==0){
					invite[i]=1;
					++ans; //友達を招待
				}
				
				for(int j=2; j<=n; ++j){
					if(r[i][j]==1 && invite[j]==0){	
						invite[j]=1;
						++ans; //友達の友達を招待
					}
				}
			}
		}
		printf("%d\n", ans);
		
	}
	return 0;
}