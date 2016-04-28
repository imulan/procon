#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		int h, w;
		char f[102][102];
		
		scanf(" %d %d", &h, &w);
		if(h==0) break;
		
		for(int i=0; i<h; ++i)
		for(int j=0; j<w; ++j)
		scanf(" %c", &f[i][j]);
		
		int x=0, y=0;
		bool loop=false;
		while(!loop && f[y][x]!='.'){
			//printf("%c\n", f[y][x]);
			if(f[y][x]=='a') loop=true;
			else{
				int tx=x, ty=y;
				
				if(f[y][x]=='>') ++x;
				else if(f[y][x]=='<') --x;
				else if(f[y][x]=='^') --y;
				else if(f[y][x]=='v') ++y;			
				
				f[ty][tx]='a';
			}
			
			//printf("%d %d\n", x, y);
		}
		
		if(loop) printf("LOOP\n");
		else printf("%d %d\n", x, y);
	}
}