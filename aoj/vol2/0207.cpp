#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

typedef struct{
	int x;
	int y;
}point;

int main(){
	while(1){
		int f[101][101];
		int w, h, n;
		point s, g;
		
		memset(f, 0, sizeof(f));
		
		//入力
		scanf(" %d %d", &w, &h);
		if(w==0) break;
		
		scanf(" %d %d %d %d", &s.x, &s.y, &g.x, &g.y);
		scanf(" %d", &n);
		for(int i=0; i<n; ++i){
			int c, d, bx, by;
			scanf(" %d %d %d %d", &c, &d, &bx, &by);
			
			if(d==0){
				for(int j=0; j<2; ++j){
					for(int k=0; k<4; ++k){
						f[by+j][bx+k]=c;		
					}
				}
			}
			else {
				for(int j=0; j<4; ++j){
					for(int k=0; k<2; ++k){
						f[by+j][bx+k]=c;		
					}
				}
			}
		}
		
		//bfs
		int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
		int color=f[s.y][s.x]; //スタート地点のブロックの色
		queue<point> que;
		f[s.y][s.x]=6; //訪問済み
		que.push(s);
		
		while( !que.empty() ){
			point v=que.front();
			que.pop();
			for(int i=0; i<4; ++i){
				int nx=v.x+dx[i], ny=v.y+dy[i];
				
				if(nx>0 && nx<=w && ny>0 && ny<=h && f[ny][nx]==color){
					f[ny][nx]=6;
					point tmp;
					tmp.x=nx; tmp.y=ny;
					que.push(tmp);
				}
			}	
		}

		//ゴールにたどり着いているか判定
		if(f[g.y][g.x]==6) printf("OK\n");
		else printf("NG\n");	
	}	
}