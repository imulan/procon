#include <cstdio>
#include <iostream>
using namespace std;

typedef struct{
	int x;
	int y;
}point;

int h, w;
char f[21][21];
point now;
int nowdir;

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
char car[5]=">^<v";

void move(char c){
	//方向転換
	if(c=='R') nowdir=0;
	else if(c=='U') nowdir=1;
	else if(c=='L') nowdir=2;
	else if(c=='D') nowdir=3;
	f[now.y][now.x]=car[nowdir]; //とりあえずその方を向く
	
	//次に行く場所
	int nx=now.x+dx[nowdir];
	int ny=now.y+dy[nowdir];
	
	//移動可能なら移動
	if(0<=nx && nx<w && 0<=ny && ny<h && f[ny][nx]=='.'){
		f[ny][nx]=car[nowdir];
		f[now.y][now.x]='.';
		now.x=nx;
		now.y=ny;
	}
}

void printField(){
	for(int i=0; i<h; ++i){
		for(int j=0; j<w; ++j){
			printf("%c", f[i][j]);
		}
		printf("\n");
	}	
}

void shoot(){
	int t=1; //パラメータ

	while(1){
		int px=t*dx[nowdir]+now.x;	
		int py=t*dy[nowdir]+now.y;
		
		if(px<0 || w<=px || py<0 || h<=py) break;
		
		if(f[py][px]=='*'){
			f[py][px]='.';
			break;	
		}
		else if(f[py][px]=='#') break;	
			
		t++;			
	}
}

int main(){	
	int times;
	cin >> times;
	for(int t=0; t<times; ++t){
		if(t!=0) printf("\n");
		
		scanf(" %d %d", &h, &w);
		
		for(int i=0; i<h; ++i){
			for(int j=0; j<w; ++j){
				scanf(" %c", &f[i][j]);
				
				for(int k=0; k<4; ++k){
					if(f[i][j]==car[k]){	
						nowdir=k;
						now.x=j;
						now.y=i;		
					}
				}
			}
		}
		
		int n;
		string order;
		scanf(" %d", &n);
		cin >> order;
		
		for(int i=0; i<n; ++i){
			if(order[i]=='S') shoot();
			else move(order[i]);
			/*
			printf("nowdir=%d\n", nowdir);
			printField();
			printf("\n");
			*/
		}
		
		printField();
	
	}
}