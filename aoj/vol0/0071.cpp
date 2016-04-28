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
	int n;
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		char f[9][9];
		int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

		for(int j=1; j<=8; ++j)
		for(int k=1; k<=8; ++k)
		scanf(" %c", &f[j][k]);
		
		point s;
		scanf(" %d %d", &s.x, &s.y);
		
		//bfs
		f[s.y][s.x]='0'; //既に爆発した
		queue<point> que;
		que.push(s);
		while( !que.empty() ){
			point v=que.front();
			que.pop();
			
			for(int j=0; j<4; ++j){
				for(int k=1; k<=3; ++k){
					int nx=v.x+dx[j]*k, ny=v.y+dy[j]*k;
					
					if(nx>0 && nx<=8 && ny>0 && ny<=8 && f[ny][nx]=='1'){
						f[ny][nx]='0';			
						point tmp;
						tmp.x=nx; tmp.y=ny;
						que.push(tmp);
						//printf("push\n");
					}
				}	
			}
	
		}
		
		//出力
		printf("Data %d:\n", i+1);
		for(int j=1; j<=8; ++j){
			for(int k=1; k<=8; ++k) printf("%c", f[j][k]);
			printf("\n");
		}
		
	}
}