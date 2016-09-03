#include <iostream>
#include <cstdio>
using namespace std;

long rightu[51][51];
long rectangle[50][50][50][50];
long deli[2501];

int main(){
	int n, q, d[50][50], p;
	
	for(int i=0; i<2501; ++i) deli[i]=0;
	
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			scanf(" %d", &d[i][j]);
		}
	}
	
	//右下まで必ず使う長方形を全通り列挙
	for(int i=0; i<=n; ++i){
		for(int j=0; j<=n; ++j){
			rightu[i][j]=0;
			
			for(int a=i; a<n; ++a){
				for(int b=j; b<n; ++b){
					rightu[i][j] += d[a][b];
				}
			}
			
			//printf("rightu[%d][%d]=%ld\n", i, j, rightu[i][j]);
		}
	}
	
	//全長方形を列挙，エリアの広さごとに最大値を記録
	for(int x=0; x<n; ++x){
		for(int y=0; y<n; ++y){
			for(int z=x; z<n; ++z){
				for(int w=y; w<n; ++w){
					rectangle[x][y][z][w] = rightu[x][y] - rightu[x][w+1] - rightu[z+1][y] + rightu[z+1][w+1];
					
					int area=(z-x+1)*(w-y+1);
					
					if(deli[area] < rectangle[x][y][z][w]) deli[area]=rectangle[x][y][z][w];
					
					//printf("rectangle[%d][%d][%d][%d]=%ld\n", x, y, z, w, rectangle[x][y][z][w]);
				}
			}
		}
	}
	
	//小さい方から順に，最大値を塗りつぶす
	long now=deli[1];
	for(int i=1; i<=n*n; ++i) {
		if(deli[i] < now) deli[i]=now;
		else now=deli[i];
		
		//printf("deli[%d]=%ld\n", i, deli[i]);
	}
	
	scanf(" %d", &q);
	for(int i=0; i<q; ++i){
		scanf(" %d", &p);	
		printf("%ld\n", deli[p]);
	}
	
	return 0;
}