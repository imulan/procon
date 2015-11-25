#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		int n; //柿の木の数
		int w, h; //width,height
		int s, t; //土地の広さsが幅，tが高さ
		int field[100][100];
		
		scanf(" %d", &n);
		if(n==0) break;
		scanf(" %d %d", &w, &h);
		
		for(int i=0; i<h; ++i)
		for(int j=0; j<w; ++j)
		field[i][j]=0;
		
		for(int i=0; i<n; ++i){
			int x, y;
			scanf(" %d %d", &x, &y);
			field[y-1][x-1]=1;	
		}
		/*
		for(int i=0; i<h; ++i){
			for(int j=0; j<w; ++j){
				printf("%d ",field[i][j]);
			}
			printf("\n");
		}
		*/
		scanf(" %d %d", &s, &t);
		
		
		
		
		int ans=0;
		for(int i=0; i<=h-t; ++i){ //枠の左上端
			for(int j=0; j<=w-s; ++j){
				
				int tmp=0;
				for(int p=i; p<i+t; ++p){
					for(int q=j; q<j+s; ++q){
						tmp+=field[p][q];
					}
				}
				
				if(ans<tmp) {
					ans=tmp;
					//printf(" %d better::: %d, %d\n", ans, i, j);
				}
			}
		}
		printf("%d\n", ans); 
	}
	
	return 0;
}