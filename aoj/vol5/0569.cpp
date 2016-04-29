#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int w, h;
	int f[100][100]; //field
		
	scanf(" %d %d", &w, &h);
	for(int i=0; i<h; ++i)
	for(int j=0; j<w; ++j)
	scanf(" %d", &f[j][i]);
	
	//建物に囲まれた空白か (これだと空白が１つの時しか判定できないのでダメ!!!!!!!)
	for(int i=1; i<w-1; ++i){
		for(int j=1; j<h-1; ++j){
			if(f[i][j]==0){
				bool inside=true;
				
				if(f[i-1][j]==0 || f[i+1][j]==0) inside=false;
				if(f[i][j-1]==0 || f[i][j+1]==0) inside=false;
				
				
				int d=1;
				if(j%2==1) d=-1;
				if(f[i+d][j-1]==0 || f[i+d][j+1]==0) inside=false;
				
				if(inside) {
					//printf("inside!!!!%d %d\n", i, j);
					f[i][j]=2;
				}
				
			}
			
		}
	}
	
	for(int i=0; i<h; ++i){
		for(int j=0; j<w; ++j){
			printf(" %d", f[j][i]);
		}
		printf("\n");
	}
	
	
	int ans=0;
	for(int i=0; i<w; ++i){
		for(int j=0; j<h; ++j){
			if(f[i][j]==1){
				ans+=6;
				
				if(i-1>=0) ans-=(f[i-1][j]!=0);
				if(i+1<w)ans-=(f[i+1][j]!=0);
				if(j-1>=0) ans-=(f[i][j-1]!=0);
				if(j+1<h) ans-=(f[i][j+1]!=0);
				int d=1;
				if(j%2==1) d=-1;
				if(j-1>=0 && i+d>=0 && i+d<w)ans-=(f[i+d][j-1]!=0);
				if(j+1<h && i+d>=0 && i+d<w)ans-=(f[i+d][j+1]!=0);
				
				printf("%d\n", ans);
			}		
		
		}
		printf("\n");
	}
	
	printf("%d\n", ans);
	
	return 0;
}