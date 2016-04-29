#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

typedef struct{
	int x; //現在位置の横座標
	int y; //現在位置の縦座標
	int turn; //石を動かした回数
	int f[20][20]; //フィールドの状況
}info;

int main(){
	while(1){
		int w,h;
		info st; //初期状態
		
		//input
		scanf(" %d %d", &w, &h);
		if(w==0) break;
		for(int i=0; i<h; ++i){
			for(int j=0; j<w; ++j){
				scanf(" %d", &st.f[i][j]);	
				if(st.f[i][j]==2){
					st.y=i;
					st.x=j;	
				}	
			}
		}
		st.turn=0;
		
		//右、下、左、上
		int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
		
		int ans=-1;
		//BFS
		queue<info> que;
		que.push(st);
		while(!que.empty()){
			info p = que.front(); que.pop();
			
			//動ける方向についての吟味
			for(int i=0; i<4; ++i){
				info v = p;
				
				//この方向に盤面は無いので動かせない
				if(v.x+dx[i]<0 || v.x+dx[i]>=w) continue;
				if(v.y+dy[i]<0 || v.y+dy[i]>=h) continue;
				//障害物が進行方向に隣接していても動かせない
				if(v.f[v.y+dy[i]][v.x+dx[i]] == 1) continue;
				
				//これ以外の時その方向に動ける
				int nx=v.x, ny=v.y;
				for(int j=1; j<=20; ++j){
					nx=v.x+j*dx[i];
					ny=v.y+j*dy[i];
					
					//盤の外
					if(nx<0||nx>=w) break;
					if(ny<0||ny>=h) break;
					
					if(v.f[ny][nx]==3){ //ゴール到達
						ans=v.turn+1;
						break;
					}
					else if(v.f[ny][nx]==1){ //障害物
						v.f[ny][nx]=0; //障害物は消える
						//自分は一歩手前
						nx-=dx[i]; 
						ny-=dy[i];
						v.x=nx;
						v.y=ny;
						v.turn++;
						if(v.turn<10) que.push(v);
						break;		
					}	
				}	
						
			}
			if(ans>0) break;	
		}
		
		printf("%d\n", ans);	
	}
}