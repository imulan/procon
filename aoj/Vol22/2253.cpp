#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

typedef struct{
	int x;
	int y;
}point;

const int N=150;

int main(){
	while(1){
		int turn, n;
		int f[N+1][N+1], d[N+1][N+1];
		int dx[6]={1,1,0,-1,-1,0}, dy[6]={0,1,1,0,-1,-1};
		
		//初期化
		for(int i=0; i<=N; ++i){
			for(int j=0; j<=N ;++j){
				f[i][j]=0;
				d[i][j]=-1;
			}
		}
		
		//入力
		scanf(" %d %d", &turn, &n);
		if(turn==0) break;
		for(int i=0; i<n; ++i){
			int a, b;
			scanf(" %d %d", &a, &b);	
			f[a+70][b+70]=1;
		}
		
		point start;
		scanf(" %d %d", &start.x, &start.y);
		start.x+=70;
		start.y+=70;
	
		//BFS	
		queue<point> que;
		d[start.x][start.y]=0;
		que.push(start);
		
		while( !que.empty() ){
			point v=que.front();
			que.pop();	
			//printf(" pop\n");
						
			for(int i=0; i<6; ++i){
				int nx=v.x+dx[i], ny=v.y+dy[i];
								
				if(nx>=0 && nx<=N && ny>=0 && ny<=N && f[nx][ny]!=1 && d[nx][ny]==-1){
					d[nx][ny] = d[v.x][v.y]+1;
					point tmp;
					tmp.x=nx;
					tmp.y=ny;
					que.push(tmp);
					//printf("push\n");
				}
				
			}	
		}
		
		int ans=0;
		for(int i=0; i<=N; ++i){
			for(int j=0; j<=N; ++j){
				if(d[i][j]>=0 && d[i][j]<=turn) ++ans;
				//else printf("%d %d\n", i, j);
			}
		}
	
		printf("%d\n", ans);
	}
}