#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

typedef struct{
	int f;
	int s;
}point;

int main(){
	while(1){
		int m, n;
		int f[90][90];
		
		scanf(" %d %d", &m, &n);
		if(m==0) break;
		for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
		scanf(" %d", &f[i][j]);
		
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				if(f[i][j]==0) continue; //薄氷の上じゃないとダメ
				
				point start;
				start.f=i;
				start.s=j;
				
				int r[90][90];
				int d[90][90]; //distance from start
				for(int p=0; p<90; ++p)
				for(int q=0; q<90; ++q)
				dist[p][q]=0;
				memcpy(r, f, sizeof(f));
				
		
		
		
	}
}