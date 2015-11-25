#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		int n, m;
		int f[21][21]; //field
		
		for(int i=0; i<=20; ++i)
		for(int j=0; j<=20; ++j)
		f[i][j]=0;
		
		scanf(" %d", &n);
		if(n==0) break;
		for(int i=0; i<n; ++i){
			int x, y;	
			scanf(" %d %d", &x, &y);
			f[y][x]=1; //宝石あり
		}
		
		int count=0, nx=10, ny=10;
		if(f[ny][nx]==1){
			++count;	
			f[ny][nx]=0;
		}
		
		scanf(" %d", &m);
		for(int i=0; i<m; ++i){
			char d; //direction
			int value;
			scanf(" %c %d", &d, &value);
			
			if(d=='N' || d=='S'){
				int t=-1;
				if(d=='N') t=1;
				
				for(int j=0; j<value; ++j){
					ny+=t;				
					if(f[ny][nx]==1){
						++count;	
						f[ny][nx]=0;
					}			
				}
			}
			else if(d=='E' || d=='W'){
				int t=1;
				if(d=='W') t=-1;
				
				for(int j=0; j<value; ++j){
					nx+=t;				
					if(f[ny][nx]==1){
						++count;	
						f[ny][nx]=0;
					}			
				}
			}
			
		}
		
		if(count==n) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}