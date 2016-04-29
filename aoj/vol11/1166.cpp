#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

typedef struct{
	int f; //first
	int s; //second
}point;

int main(){
	while(1){	
		int w, h;
		int f[60][60];
		int field[30][30];
		int df[4]={0, -1, 0, 1}, ds[4]={1, 0, -1, 0};
		
		scanf(" %d %d", &w, &h);
		if(w==0) break;
		
		for(int i=0; i<2*h-1; ++i){
			int t;
			if(i%2==1) t=w;
			else t=w-1;
			for(int j=0; j<t; ++j) scanf("  %d", &f[i][j]);
		}
	
		for(int i=0; i<30; ++i)
		for(int j=0; j<30; ++j)
		field[i][j]=0;
		
		point start, goal;
		start.f=0;
		start.s=0;
		goal.f=h-1;
		goal.s=w-1;
		
		queue<point> que;
		field[start.f][start.s]=1;
		que.push(start);
		while(!que.empty()){
			point now=que.front();
			que.pop();
			
			int nf, ns;
			if(now.s+1<w &&f[2*now.f][now.s]==0 && field[now.f][now.s+1]==0){ //右側
				nf=now.f;
				ns=now.s+1;
				field[nf][ns]=field[now.f][now.s]+1;
				point tmp;
				tmp.f=nf;
				tmp.s=ns;
				que.push(tmp);
			}
			if(now.s-1>=0 &&f[2*now.f][now.s-1]==0 && field[now.f][now.s-1]==0){ //左側
				nf=now.f;
				ns=now.s-1;
				field[nf][ns]=field[now.f][now.s]+1;
				point tmp;
				tmp.f=nf;
				tmp.s=ns;
				que.push(tmp);
			}
			if(now.f-1>=0 &&f[2*now.f-1][now.s]==0 && field[now.f-1][now.s]==0){ //上側
				nf=now.f-1;
				ns=now.s;
				field[nf][ns]=field[now.f][now.s]+1;
				point tmp;
				tmp.f=nf;
				tmp.s=ns;
				que.push(tmp);
			}
			if(now.f+1<h &&f[2*now.f+1][now.s]==0 && field[now.f+1][now.s]==0){ //下側
				nf=now.f+1;
				ns=now.s;
				field[nf][ns]=field[now.f][now.s]+1;
				point tmp;
				tmp.f=nf;
				tmp.s=ns;
				que.push(tmp);
			}
		}
	
		printf("%d\n", field[goal.f][goal.s]);
	}
	return 0;
}