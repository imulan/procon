#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n, m ,x, y;
	bool relate[13][13];
	
	//関係性の初期化
	for(int i=0; i<13; ++i){
		for(int j=0; j<13; ++j){
			relate[i][j]=false;		
		}
	}
	
	//入力
	scanf(" %d %d", &n ,&m);
	for(int i=0; i<m; ++i){
		scanf(" %d %d", &x, &y);
			relate[x][y] = relate[y][x] = true;
	}
	
	int ans=0;
	for(int a=1<<n; a>0; --a){
		//最初にaの2進数は1をいくつ含むか見る，そもそも現時点の最大値より足りなければそこで終わり。
		int t=0;
		for(int i=0; i<n; ++i){
			if(a>>i & 1) ++t;
		}
		//printf("%d\n", t);
		
		bool correct=true;
		for(int i=0; i<n;++i){
			for(int j=0; j<i; ++j){
				// iとjはどちらもこのaという派閥に属しているが，関係が存在しない場合
				if(a>>i & a>>j & 1 && !relate[i+1][j+1]) correct=false;
			}
		}
		if(correct && ans<t) ans=t;
	}
	
	printf("%d\n", ans);
	
	return 0;
}