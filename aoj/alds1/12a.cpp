#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const long INF=1000000000;

int main(){
	int n;
	long a[100][100];
	
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			long p;
			scanf(" %ld", &p);
			if(p==-1) a[i][j]=INF;
			else a[i][j]=p;
		}
	}
	
	//prim
	
	int visit[100]={0}; //未訪問で初期化
	
	int p[100]; //MSTにおける親
	p[0]=-1;
	
	int d[100];
	for(int i=0; i<n; ++i) d[i]=INF;
	d[0]=0; //頂点番号0の位置からスタート
	
	int u;
	while(1){
		long mincost=INF;
		
		for(int i=0; i<n; ++i){
			if(visit[i]!=-1 && d[i]<mincost){
				mincost=d[i];
				u=i;	
			}
		}
		
		if(mincost==INF) break; //これ以上辺は必要ない
		
		visit[u]=-1; //訪問済み
		
		for(int i=0; i<n; ++i){
			if(visit[i]!=-1 && a[u][i]<d[i]){
				d[i]=a[u][i];
				p[i]=u;
				visit[i]=1; //次訪問する奴の候補
			}
		}
		
	}
	
	long ans=0;
	for(int i=0; i<n; ++i){
		if(p[i]!=-1) ans+=a[i][p[i]];
		
	}
	printf("%ld\n", ans);
}