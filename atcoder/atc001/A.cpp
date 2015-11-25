#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

typedef struct{
	int x;
	int y;
}point;

int main(){
	int w, h;
	char field[1000][1000];
	bool visit[500][500];
	int dx[4]={1,0,-1,0}, dy[4]={0,-1,0,1};
	point start, goal;
	
	
	for(int i=0; i<500; ++i)
	for(int j=0; j<500; ++j)
	visit[i][j]=false;
	
	scanf(" %d %d", &w, &h);
	for(int i=0; i<h; ++i){
		for(int j=0; j<w; ++j){
			scanf(" %c", &field[i][j]);
			if(field[i][j]=='s'){
				start.x=j;
				start.y=i;	
			}
			else if(field[i][j]=='g'){
				goal.x=j;
				goal.y=i;
			}
		}
	}
	
	stack<point> st;
	visit[start.y][start.x]=true;
	st.push(start);
	while( !st.empty() ){
		//printf("now size=%d\n", st.size());
		
		point v = st.top();
		st.pop();
		for(int i=0; i<4; ++i){
			int nx=v.x+dx[i], ny=v.y+dy[i];
			if(nx>=0 && nx<w && ny>=0 && ny<h && field[ny][nx]!= '#' && !visit[ny][nx]){
				point tmp;
				tmp.x=nx;
				tmp.y=ny;
				visit[ny][nx]=true;
				st.push(tmp);		
			}
		}	
		
	}
	
	if(visit[goal.y][goal.x]) printf("Yes\n");
	else printf("No\n");
}