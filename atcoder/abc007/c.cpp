#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

typedef struct{
	int x;
	int y;
}point;

int main(){
	int r, c, sy, sx, gy, gx;
	int ans[50][50];
	int dx[4]={-1, 0 ,1, 0}, dy[4]={0, 1, 0, -1};
	char field[50][51];
	queue<point> que;
		
	//入力	
	scanf(" %d %d %d %d %d %d", &r, &c, &sy, &sx, &gy, &gx);
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			scanf(" %c", &field[i][j]);
		}
	}
	
	//答えテーブルの初期化
	for(int i=0; i<r; ++i)
		for(int j=0; j<c; ++j) ans[i][j]=-1;
	ans[sy-1][sx-1]=0;
	
	//幅優先探索
	point start;
	start.x=sy; start.y=sx;
	que.push(start);
	while(!que.empty()){
		point now=que.front();
		que.pop();
		
		for(int i=0; i<4; ++i){
			if(field[ now.x-1+dx[i] ][ now.y-1+dy[i] ] != '#' && ans[ now.x-1+dx[i] ][ now.y-1+dy[i] ] == -1){
				
				ans[ now.x-1+dx[i] ][ now.y-1+dy[i] ] = 	ans[now.x-1][now.y-1]+1;		
				point pp;
				pp.x=now.x+dx[i];
				pp.y=now.y+dy[i];
				que.push(pp);
			}
		}	
	}
	
	/*
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			printf("%3d", ans[i][j]);
		}
		printf("\n");
	}
	*/
	
	printf("%d\n", ans[gy-1][gx-1]);
	
	return 0;
}