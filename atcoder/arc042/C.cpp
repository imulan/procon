#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int n,p;
int a[5000]; //値段
int b[5000]; //満足度

int dp[5001][5200]; //お菓子の種類、累計の値段

int rec(int x, int y){
	if(dp[x][y]>=0) return dp[x][y];
	
	int ret;
	
	//全てのお菓子を見終わった
	if(x==n){
		ret=0;
	}
	//お菓子値段オーバー
	else if(y>p){
		ret=0;
	}
	else {
	//入れるか入れないか選ぶ
		ret = max( rec(x+1, y) , rec(x+1, y+a[x])+b[x] );
	}
	
	return dp[x][y] = ret;
}


int main(){
	memset(dp, -1, sizeof(dp));
	
	scanf(" %d %d", &n, &p);
	vector<pair<int,int> > s(n);
	
	for(int i=0; i<n; ++i) cin >> s[i].first >> s[i].second;
	sort(s.begin(), s.end());
	
	//降順にわたす
	for(int i=0; i<n; ++i){
		a[i]=s[n-1-i].first;
		b[i]=s[n-1-i].second;
		//printf("%d %d\n", a[i], b[i]);
	}
	
	printf("%d\n", rec(0,0));
}