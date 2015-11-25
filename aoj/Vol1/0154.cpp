#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int m, a[7], b[7];
int n;
long dp[8][2000];

long rec(int x, long y){ //x番目のカードについて考える, 今の合計はy
	if(dp[x][y]>=0) return dp[x][y];
	
	long ret=0;
	
	if(y>n) return 0;
	else if(y==n) return 1;
	else if(x==m) return 0;
	else{
		for(int i=0; i<=b[x]; ++i) ret+=rec(x+1, y+i*a[x]);
	}
	
	return dp[x][y]=ret;
}

int main(){
	while(1){	
		scanf(" %d", &m);
		if(m==0) break;
		for(int i=0; i<m; ++i) scanf(" %d %d", &a[i], &b[i]);
		
		int g;
		scanf(" %d", &g);
		for(int i=0; i<g; ++i){
			scanf(" %d", &n);	
			memset(dp, -1, sizeof(dp));
			printf("%ld\n", rec(0, 0));
		}
			
	}
}