#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

string s;
int mct=0;
long dp[1001][1001]; //現在位置、命令の処理位置

long rec(int x, int y){ //座標0を500とする
	if(y==s.size()) return 0;
	if(dp[x][y]>=0) return dp[x][y];
	
	long ret;
	char order=s[y];
	
	if(order=='+') ret = rec(x, y+1) + (x-500);
	else if(order=='-') ret = rec(x,y+1) - (x-500);
	else{ //移動
		if(x==0) ret = rec(x+1, y+1);
		else if(x==1000) ret = rec(x-1, y+1);
		else{
			ret = max(rec(x+1,y+1), rec(x-1,y+1));
		}
	}
	
	printf("x:%d, y:%d :::ret%ld\n", x, y, ret);

			
	return dp[x][y]=ret;	
} 


int main(){
	memset(dp, -1, sizeof(dp));
	//printf("go\n");
	
	cin >> s;
	for(int i=0; i<s.size(); ++i){
		if(s[i]=='M') mct++;	
	}
	
	cout <<"size=" << s.size() <<endl;
	
	if(mct==s.size()) printf("0\n");
	else{
		long t=rec(500,0);
		printf("%ld\n", t);
		printf("%ld\n", dp[500][s.size()]);
		
		for(int i=0; i<s.size(); ++i){
			printf("  %ld\n", dp[500][i]);
			
		}	
	}
	
}