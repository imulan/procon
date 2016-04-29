#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		int n;
		bool know[100][100]; //構成員firstはsecondの情報を持つか
		
		for(int i=0; i<100; ++i)
		for(int j=0; j<100; ++j)
		know[i][j]=false;
		
		scanf(" %d", &n);
		if(n==0) break;
		for(int i=0; i<n; ++i){
			int m;
			scanf(" %d", &m);
				
			for(int j=0; j<m; ++j){
				int p;
				scanf(" %d", &p);
				know[i][p]=true; //iはpの情報を知っている
			}
		}	
		
		int k, list[100];
		scanf(" %d", &k);
		for(int i=0; i<k; ++i) scanf(" %d", &list[i]);
		
		int ans=-1;
		for(int i=0; i<n; ++i){
			bool flag=true;
			
			for(int j=0; j<k; ++j){
				if(!know[i][list[j]]){
					flag=false;
					break;
				}	
			}	
			
			if(flag){
				if(ans==-1) ans=i+1;
				else{ //複数いる
					ans=-1;	
					//printf("db\n");
					break;
				}
			}
		}
		
		printf("%d\n", ans);
	}
	return 0;
}