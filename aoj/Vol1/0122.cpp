#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

typedef struct{
	int x;
	int y;
}point;

int main(){
	while(1){
		point start, pre[1000], nex[1000];
		int n, p=0, q=0;
		int dx[12]={2,2,2,1,0,-1,-2,-2,-2,-1,0,1};
		int dy[12]={1,0,-1,-2,-2,-2,-1,0,1,2,2,2};
		
		scanf(" %d %d", &start.x, &start.y);
		if(start.x==0 && start.y==0) break;
		scanf(" %d", &n);
		
		pre[p++]=start;
		
		for(int i=0; i<n; ++i){
			point s;
			scanf(" %d %d", &s.x, &s.y);
			
			q=0;
			
			for(int j=0; j<p; ++j){
				point t=pre[j];
				for(int k=0; k<12; ++k){
					int nx=t.x+dx[k], ny=t.y+dy[k];
					if(nx>=0 && nx<10 && ny>=0 && ny<10 && s.x-1<=nx && nx<=s.x+1 && s.y-1<=ny && ny<=s.y+1){
						point tmp;
						tmp.x=nx;
						tmp.y=ny;
						nex[q++]=tmp;	
					} 
				}
			}
			
			
			for(int j=0; j<q; ++j) pre[j]=nex[j];
			p=q;	
				
		}
		
		if(q==0) printf("NA\n");
		else printf("OK\n");
		
	}
}