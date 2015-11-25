#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	while(1){
		int n, m;
		int lt[201][201], st[201][201];
		
		scanf(" %d %d", &n, &m);
		if(n==0) break;
		
		memset(lt, -1, sizeof(lt));
		memset(st, -1, sizeof(st));
		
		for(int i=0; i<m; ++i){
			int x, y, t;
			char sl;
			scanf(" %d %d %d %c", &x, &y, &t, &sl);
			
			if(sl=='L') lt[x][y]=lt[y][x]=t;
			else if(sl=='S') st[x][y]=st[y][x]=t;	
		}
		
		int r;
		
		scanf(" %d", &r);
			
	}
}