#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n;
long dp[290][18];

long rec(int a, int b){ //今の合計a,前に足した数b
	if(dp[a][b]>=0) return dp[a][b];
	
	long ret=0;	
	
	if(a==n) ret=1;
	else{
		for(int i=b; a+i*i<=n; ++i)	ret+=rec(a+i*i, i);
	}
	
	return dp[a][b]=ret;
}

int main(){
	while(1){
		scanf(" %d", &n);
		if(n==0) break;	
		
		memset(dp, -1, sizeof(dp));
		printf("%ld\n", rec(0,1));
	}
}