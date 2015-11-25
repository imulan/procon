#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int dp[1001][8][3];
int n;
string s;

int rec(int a, int b, int c){ //a日目,参加状況b,鍵を持ってる人c
	if(dp[a][b][c]>=0) return dp[a][b][c];
	int ret=0;
	
	int ch=0;
	if(s[a]=='J') ch=0;
	else if(s[a]=='O') ch=1;
	else if(s[a]=='I') ch=2;
	
	if(a==n) ret=1;
	else{
		for(int i=1; i<=7; ++i){
			for(int j=0; j<=2; ++j){
				if((1<<c) & i & 1) ret=0;
				else if((1<<ch) & i & 1) ret=0;
				else{
					printf("go\n");

					ret+=rec(a+1, i, j);
					ret%=10007;		
				}
			}
		}
	}
	
	return dp[a][b][c]=ret%10007;
}

int main(){
	cin >> n >> s;
	memset(dp, -1, sizeof(dp));
	printf("%d\n", rec(0, 7, 0));
}