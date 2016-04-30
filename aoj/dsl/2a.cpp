//セグメント木で実装しよう

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int a[100000];

int find(int s, int t){
	int b[100000];
	for(int i=0; i<=t-s; ++i) b[i]=a[s+i];	
	sort(b, b+t-s+1);
	
	return b[0];
}	

int main(){
	int n, q;
	
	scanf(" %d %d", &n, &q);
	
	//initialize
	for(int i=0; i<n; ++i) a[i]=(1<<31)-1;
	
	//calculte
	for(int i=0; i<q; ++i){
		int com, x, y;
		scanf(" %d %d %d", &com, &x, &y);	
		if(com==0) a[x]=y;
		else printf("%d\n", find(x,y));
	}
}