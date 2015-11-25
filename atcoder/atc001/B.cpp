//union-find

#include <cstdio>
#include <iostream>
using namespace std;

const int N=100000;
int parent[N]; //そのノードの親番号

//n要素で初期化
void init(int n){
	for(int i=0; i<n; ++i) parent[i]=i; //最初はみんな独立
}

//根の番号を求める
int root(int x){
	if(parent[x]==x) return x; //これが根になる
	else return parent[x]=root(parent[x]); //更に根の方へ向かう，その途中で経路を圧縮
}

//同じ集合にあるかどうか
bool same(int x, int y){
	return root(x)==root(y);	
}

//結合させる
void unite(int x, int y){
	x=root(x);
	y=root(y);
	
	if(x==y) return; //既につながってたら何もしない
	
	parent[x]=y; //そうでなければ一方の根をもう一方の根につなぐ
}

int main(){
	int n, q;
	
	scanf(" %d %d", &n, &q);
	init(n);
	for(int i=0; i<q; ++i){
		int p, a, b;
		scanf(" %d %d %d", &p, &a, &b);
		if(p==0) unite(a,b);
		else{
			if(same(a,b)) printf("Yes\n");
			else printf("No\n");
		}
	}
	
}