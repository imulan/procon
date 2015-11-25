#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const long INF=1000000000;

int main(){
	int n, m, k;
	int city[401][401];
	
	memset(city, -1, sizeof(city));
	
	scanf(" %d %d", &n, &m);
	
	for(int i=0; i<m; ++i){
		int a, b, c;
		scanf(" %d %d %d", &a, &b, &c);
		city[a][b]=city[b][a]=c;
		//printf(" in %d\n", city[a][b]);
	}
	
	long s=0;
	for(int i=1; i<=n; ++i){
		//各町からダイクストラ	
		long d[401];
		int prev[401];
		int b[401];
		
		for(int j=0; j<=400; ++j) d[j]=INF;
		d[i]=0;
		memset(prev, -1, sizeof(prev));
		
		memset(b, -1, sizeof(b));
		for(int j=1; j<=n; ++j) b[j]=1;
		
		int now=0;
		while(now<n){
			int u=0;
			int dd=INF;
			for(int j=1; j<=n; ++j){
				if(b[j]==-1) continue;
				
				if(dd>d[j]){
					u=j;
					dd=d[j];
				}
			}
		
			b[u]=-1;
			++now;
			for(int j=1; j<=n; ++j){
				if(city[u][j]>=0 && d[j]>d[u]+city[u][j]){
					d[j]=d[u]+city[u][j];
					prev[j]=u;	
				}	
			}
					
		}
		
		
		for(int j=1; j<=n; ++j) s+=d[j];
	}
	
	s/=2;
	
	scanf(" %d", &k);
	
	for(int g=0; g<k; ++g){
		int x, y, z;
		scanf(" %d %d %d", &x, &y, &z);
		
		if(city[x][y]==-1 || city[x][y]>z){
			city[x][y]=city[y][x]=z;
			
			long tmp=0;
			for(int i=1; i<=n; ++i){
				//各町からダイクストラ	
				long d[401];
				int prev[401];
				int b[401];
				
				for(int j=0; j<=400; ++j) d[j]=INF;
				d[i]=0;
				memset(prev, -1, sizeof(prev));
				
				memset(b, -1, sizeof(b));
				for(int j=1; j<=n; ++j) b[j]=1;
				
				int now=0;
				while(now<n){
					int u=0;
					int dd=INF;
					for(int j=1; j<=n; ++j){
						if(b[j]==-1) continue;
						
						if(dd>d[j]){
							u=j;
							dd=d[j];
						}
					}
				
					b[u]=-1;
					++now;
					for(int j=1; j<=n; ++j){
						if(city[u][j]>=0 && d[j]>d[u]+city[u][j]){
							d[j]=d[u]+city[u][j];
							prev[j]=u;	
						}	
					}
							
				}
				
				for(int j=1; j<=n; ++j) tmp+=d[j];
			}	
			
			tmp/=2;
			if(s>tmp) s=tmp;	
		}
		
		printf("%ld\n", s);
	}

}