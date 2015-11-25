//折り返しを右から行くか左から行くか考慮してないのでダメ

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main(){
	int n, m, x[100000];
	
	//input
	cin >> n >> m;
	for(int i=0; i<m; ++i) scanf(" %d", &x[i]);
	
	//二分探索(y分使う時にそれぞれの人を左からgreedyに動かしてどこまで見れるか判定)
	int low=0, high=2*n;
	int mid=0;
	
	bool last=true;
	
	while(high-low>1){
		mid = (low+high)/2;	
		//printf("low = %d, mid = %d, high = %d\n", low, mid, high);
		
		//左端から順に見ていく
		//printf("left simu start !!\n");
	
		int lim=0; //いまどこまで点検したか
		bool valid=true;
		
		for(int i=0; i<m; ++i){
			if(x[i]-lim>=2){ //一旦左に動く必要がある場合
				if(lim+1 < x[i]-mid){ //ずっと左に行っても届かない
					valid=false;	
				}
				else{ //lim+1まで行ってから折り返す
					int turn=(x[i]-lim-1)*2;
					//printf("(turn=%d)", turn);
					lim = x[i];
					if(turn<mid) lim = max(lim, x[i]+mid-turn); 
				}
				
			}	
			else{ //右につきすすむ
				lim = max(lim, x[i]+mid);
			}
		
			//printf(" %d ->", lim);	
					
			if(!valid || lim > n) break; 
		}
		/*
		if(valid) printf(" OK\n");
		else printf(" failed\n");
		*/
		
		//右端から順に見ていく
		if(!valid){
			//printf("right simu start !!\n");
			
			valid=true;
			lim = n+1;
			for(int i=m-1; i>=0; --i){
				if(lim-x[i]>=2){ //一旦右に動く必要がある場合
					if(x[i]+mid < lim-1){ //ずっと右に行っても届かない
						valid=false;	
					}
					else{ //lim-1まで行ってから折り返す
						int turn=(lim-1-x[i])*2;
						//printf("(turn=%d)", turn);
						lim = x[i];
						//歩数あまり,さらに左へ
						if(turn<mid) lim = min(lim, x[i]-(mid-turn)); 
					}
				}	
				else{ //左につきすすむ
					lim = min(lim, x[i]-mid);
				}
			
				//printf(" %d ->", lim);	
						
				if(!valid || lim < 1) break; 
			}
			/*
			if(valid) printf(" OK\n");
			else printf(" failed\n");
			*/
		}	
				
		if(valid){high=mid; last=true;}
		else{low=mid; last=false;}
	}
	/*
	printf("low = %d, mid = %d, high = %d\n", low, mid, high);
	
	if(last) printf("%d\n", mid);
	else printf("%d\n", mid+1);
	*/
	
	printf("%d\n", high);
}