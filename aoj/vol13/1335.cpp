#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long dp[21][156][21]; //dp[何個目まで足したか][残ってる数][前に足した数]
int n, k;

long rec(int a, int b, int c){ //a番目,残りb,前に足した数c
	if(dp[a][b][c]>=0) return dp[a][b][c];
	
	long ret=0;
	if(a==k && b>=0){
		if(b==0) ret=1;
		else ret=0;	
	}
	else if(b<0) ret=0;
	else{
		for(int i=c-1; i>0; --i) ret+=rec(a+1, b-i, i);
		//printf("%d %d = %ld\n", a, b, ret);
	}
	//printf("ret dp[%d][%d] = %ld\n", a, b, ret);
	return dp[a][b][c]=ret;
}

int main(){
	while(1){
		int s;
		scanf(" %d %d %d", &n, &k, &s);
		if(n==0) break;	
		
		memset(dp, -1, sizeof(dp));
		printf("%ld\n", rec(0, s, n+1) );
	}
	return 0;
}