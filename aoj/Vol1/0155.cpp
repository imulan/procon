//最小の距離がうまくも止まらない

#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const long INF=1000000000;

typedef struct{
	int num;
	int x;
	int y;
}building;

int sqMove(building p, building q){
	int dx=p.x-q.x;
	int dy=p.y-q.y;
	
	//距離が50以下なら移動可
	int ret=dx*dx+dy*dy;
	if(ret > 50*50) ret=-1;
	
	return ret;
}

int main(){
	while(1){
		int n;
		long b[1001][1001];
		building a[1000];
						
		scanf(" %d", &n);
		if(n==0) break;
		for(int i=0; i<n; ++i)
			scanf(" %d %d %d", &a[i].num, &a[i].x, &a[i].y);
		
		//初期化
		memset(b, -1, sizeof(b));
		
		//接続されていたらコストは距離の2乗	
		for(int i=0; i<n; ++i){
			b[a[i].num][a[i].num]=0;
			for(int j=i+1; j<n; ++j){
				int dist=sqMove(a[i], a[j]);
				b[a[i].num][a[j].num]=dist;	
				b[a[j].num][a[i].num]=dist;	
			}
		}
		
		//クエリの処理
		int m;
		scanf(" %d", &m);
		for(int i=0; i<m; ++i){
			int s, g;
			scanf(" %d %d", &s, &g);
			
			//ダイクストラ法
			long d[1001];
			int prev[1001];
			
			for(int j=0; j<=1000; ++j) d[j]=INF;
			d[s]=0;
			memset(prev, -1, sizeof(prev));
			
			queue<int> que;
			bool remain[1001]; //探索対象になっているか
			for(int j=0; j<=1000; ++j) remain[j]=false;
			
			for(int j=0; j<n; ++j){
				que.push(a[j].num);
				remain[a[j].num]=true;
			}
			
			int ct=0;
			while(ct<n){
				int pp=-1;
				int min=INF;
				
				for(int j=0; j<n; ++j){	
					int nj=a[j].num;
					if(remain[nj]){
						if(min>d[nj]){
							pp=nj;	
							min=d[nj];
						}
					}	
				}
				
				int u=pp;
				remain[u]=false;
				
				for(int j=0; j<n; ++j){
					int nj=a[j].num;
					if(b[u][nj]>0 && d[nj]>d[u]+b[u][nj]){		
						d[nj]=d[u]+b[u][nj];
						prev[nj]=u;	
					}
				}
				//printf(" pp=%d\n", pp);
				ct++;
			}
			
			if(d[g]==INF) printf("NA\n");
			else{
				int now=1;
				int ans[1000];
				ans[0]=g;
				
				int bb=g;
				while(prev[bb] != s){
					ans[now++]=prev[bb];	
					bb=prev[bb];
				}
				ans[now]=s;
				
				for(int i=now; i>=0; --i){
					if(i!=now) printf(" ");	
					printf("%d", ans[i]);
				}
				printf("\n");
			}
			
		}
		
	}
}