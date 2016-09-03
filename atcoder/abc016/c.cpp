#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n, m;
	bool relate[10][10];
	int ans;
	
	//初期化
	for(int i=0; i<10; ++i)
	for(int j=0; j<10; ++j)
	relate[i][j]=false;
	
	//入力
	scanf(" %d %d", &n, &m);
	for(int i=0; i<m; ++i){
		int a, b;
		scanf(" %d %d", &a, &b);
		a--;
		b--;
		relate[a][b] = relate[b][a] = true;
	}
	
	//友達の友達をユーザーごとに全探索
	for(int i=0; i<n; ++i){ //iの友達の友達を探す
		ans=0;
		bool ff[10]; //友達の友達
		for(int j=0; j<n; ++j) ff[j]=false;
		
		for(int j=0; j<n; ++j){ //iの友達のj
			if(j == i) continue;		
			
			if(!relate[i][j]) continue; //iとjは友達じゃないならダメ
			else{
				for(int k=0; k<n; ++k){ //jの友達のk
					if(k == j || k==i) continue;
					if(!ff[k] && relate[j][k] && !relate[i][k]){
						++ans;
						ff[k]=true;	//重複して数えないように
					}
				}	
			}	
			
		}
		printf("%d\n", ans);
	}
	
	return 0;
}