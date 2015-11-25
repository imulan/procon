#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int n, w[1000], s;
int a[1000], d[10001]; //destination 

long solve(){
	long ret=0;	
	
	bool v[1000];
	for(int i=0; i<n; ++i){
		a[i]=w[i];
		v[i]=false;	
	}
	sort(a, a+n); //a[]にはw[]の最終形が入る
	
	//重さa[i]の荷物が行くべき場所をd[]に入れる
	for(int i=0; i<n; ++i) d[a[i]]=i;
	
	for(int i=0; i<n; ++i){
		if(v[i]) continue; //既に他のサイクルに含まれているのでソート済みになっている
		
		//サイクルを探す
		int cur=i; //現在位置
		int sum=0;
		int m=10000; //サイクルの中の値の最小値
		int an=0; //サイクルの大きさ
		
		while(1){
			v[cur]=true; //訪問済みに設定
			an++;
			int z=w[cur];
			sum+=z;
			m=min(m, z);
			cur=d[z]; //次の位置
			if(v[cur]) break; //一周した
		}
		
		ret += min(sum+(an-2)*m , m+sum+(an+1)*s);	
	}
	return ret;
}

int main(){
	scanf(" %d", &n);
	
	s=10000;
	for(int i=0; i<n; ++i){
		scanf(" %d", &w[i]);
		s=min(s, w[i]); //sはw[]の中の最小の要素
	}
	
	printf("%ld\n", solve());
}