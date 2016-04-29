#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, k, p[101];
int dp[102][4][10]; //(1)日目,その日のパスタは(2),(3)日連続

int rec(int x, int y, int z){
	if(dp[x][y][z]>=0) return dp[x][y][z];
	
	int ret=0;
	
	if(z>=2) ret=0;
	else if(x==n+1) ret=1;	
	else{
		if(p[x]==0){ //その日のパスタは未定
			for(int i=1; i<=3; ++i){
				if(i==y) ret+=rec(x+1, i, z+1);
				else ret+=rec(x+1, i, 0);
					
			}
		}	
		else{
			if(y==p[x]) ret+=rec(x+1, p[x], z+1);
			else ret+=rec(x+1, p[x], 0);
		}
	}
	
	return dp[x][y][z]=ret%10000;
}

int main(){
	scanf(" %d %d", &n, &k);
	
	memset(p, 0, sizeof(p)); //初期化
	
	for(int i=0; i<k; ++i){
		int a, b;
		scanf(" %d %d", &a, &b);	
		p[a]=b; //a日目のpastaはb
	}
	
	memset(dp, -1, sizeof(dp));
	printf("%d\n", rec(1, 0, 0));
}