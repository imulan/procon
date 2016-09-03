#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int r, c, k;
	char f[510][510];
	
	scanf(" %d %d %d", &r, &c, &k);
	
	for(int i=1; i<=r; ++i)
	for(int j=1; j<=c; ++j)
	scanf(" %c",  &f[i][j]);
	
	long ans=0;
	int t=k-1;
	
	for(int x=k; x<=r-k+1; ++x){
		for(int y=k; y<=c-k+1; ++y){
			
			bool g=true;
			int s=0;
			
			for(int i=x-t; i<x; ++i){
				for(int j=y-s; j<=y+s; ++j){
					if(f[i][j]=='x'){
						g=false;
						break;
					}						
				}
				++s;
				if(!g) break;
			}
			if(!g) continue;
			
			//printf("s= %d\n", s);
			
			for(int i=y-t; i<=y+t; ++i){
				if(f[x][i]=='x'){
					g=false;
					break;	
				}
			}
			if(!g) continue;
			
			--s;
			for(int i=x+1; i<=x+t; ++i){
				for(int j=y-s; j<=y+s; ++j){
					if(f[i][j]=='x'){
						g=false;
						break;
					}
				}
				--s;
				if(!g) break;
			}
			//printf("s= %d\n", s);

			
			if(g) ++ans;
		}
	}
	
	printf("%ld\n", ans);
	return 0;
}