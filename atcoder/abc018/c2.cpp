#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int r, c, k;
	char f[510][510];
	int up[510][510], down[510][510];
	
	scanf(" %d %d %d", &r, &c, &k);
	
	for(int i=1; i<=r; ++i)
	for(int j=1; j<=c; ++j)
	scanf(" %c",  &f[i][j]);
	
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			up[i][j]=0;
			for(int d=0; i-d>0; ++d){
				if(f[i-d][j]=='x') break;	
				++up[i][j];
			}
		}
	}
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			down[i][j]=0;
			for(int d=0; i+d<=r; ++d){
				if(f[i+d][j]=='x') break;	
				++down[i][j];
			}
		}
	}
	
	/*
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			printf(" %d/%d", up[i][j], down[i][j]);
		}
		printf("\n");
	}
	*/
	
	
	long ans=0;
	int t=k-1;
	
	for(int x=k; x<=r-k+1; ++x){
		for(int y=k; y<=c-k+1; ++y){
			
			bool g=true;
			for(int z=y-t; z<=y+t; ++z){
				if(up[x][z]>=k-fabs(z-y) && down[x][z]>=k-fabs(z-y)) continue;
				else{
					g=false;
					break;
				}
			}
	
			if(g) ++ans;
		}
	}
	
	printf("%ld\n", ans);
	return 0;
}