/*
N個のノードで構成される木Tがある。
ノードは1~Nまで番号がついていて，1が根になる。
Tに対して以下の2つの操作を考える:
	
M v:ノードvをマークする
Q v:vに最も近いマークされた祖先の番号を出力する

最初は根だけがマークされている(つまり1だけ)。
出力されるべき値の合計の値を出力せよ。

ノードの数:N<=100000
クエリの数:Q<=100000

最初の1行:NとQ
その次のN-1行:2~Nのノードの親
次のQ行:クエリ(M v or Q v)の形
*/

#include <cstdio>
#include <iostream>
using namespace std;

long const long N=100000;

long par[N+1];
long tree[N+1]; //木の構造

long find(long x){
	//printf(" x=%ld\n", x);
	if(par[x]==x) return x;
	else return find(par[x]);	
}

int main(){
	while(1){
		long n, q;
		scanf(" %ld %ld", &n, &q);
		if(n==0) break;
			
		par[1]=1;
		for(long i=2; i<=n; ++i) scanf(" %ld", &par[i]);
		
		long ans=0;
		for(long i=0; i<q; ++i){
			char req;
			long m;
			
			scanf(" %c %ld", &req, &m);
			if(req=='M') par[m]=m; //ここで打ち止まるようにする
			else if(req=='Q') ans+=find(m);
			//printf("%ld\n", ans);
		}
			
		printf("%ld\n", ans);
	}
}