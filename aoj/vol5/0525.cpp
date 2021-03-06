#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		int r, c;
		int a[10][10000];
		
		scanf(" %d %d", &r, &c);
		if(r==0) break;	
		
		for(int i=0; i<r; ++i)
		for(int j=0; j<c; ++j)
		scanf(" %d", &a[i][j]);
		
		long ans=0;
		//どの行をひっくり返すか全探索
		for(int i=(1<<r)-1; i>=0; --i){
			
			//元の状態をコピー
			int b[10][10000];
			for(int j=0; j<r; ++j)
			for(int k=0; k<c; ++k)
			b[j][k]=a[j][k];
			
			//j行目に注目
			for(int j=0; j<r; ++j){
				if(i>>j & 1){ //ひっくり返す
					for(int k=0; k<c; ++k)
						b[j][k]=(b[j][k]==1) ? 0 : 1;
					
				}
			}
			
			long tmp=0;
			//各列で1と0の多い方をtmpに追加
			for(int j=0; j<c; ++j){
				int x=0, y=0;	
				for(int k=0; k<r; ++k){
					if(b[k][j]==0) x++;
					else y++;	
				}
				
				tmp+=max(x,y);
			}
			
			ans=max(tmp,ans);	
		}
		
		printf("%ld\n", ans);
	}
}