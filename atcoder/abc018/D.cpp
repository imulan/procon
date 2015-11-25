#include <bitset>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

//数aがpビット立っているかどうか
bool full(long a, int p){
	bitset<18> bs(a);
	return (bs.count() == p);
}

int main(){
	int n, m, p, q, r;
	int hp[18][18]; //女子firstから男子secondに渡すときの幸福度
	
	for(int i=0; i<18; ++i)
	for(int j=0; j<18; ++j)
	hp[i][j]=0;
	
	scanf(" %d %d %d %d %d", &n, &m, &p, &q, &r);
	for(int i=0; i<r; ++i){
		int x, y, z;
		scanf(" %d %d %d", &x, &y, &z);
		hp[x-1][y-1]=z;
	}	
	
	long ans=0;
	for(long i=(1<<n)-1; i>0; --i){
		if(!full(i, p)) continue; //女子はp人いないとダメ
		
		for(long j=(1<<m)-1; j>0; --j){
			if(!full(j, q)) continue; //男子はq人いないとダメ
						
			long tmp=0;	
			for(int a=0; a<n; ++a){
				for(int b=0; b<m; ++b){
					if((i>>a)&1 && (j>>b)&1 ) tmp+=hp[a][b];
				}
			}
			//printf(" %ld %ld::::%ld\n", i, j, tmp);
			
			if(tmp>ans) ans=tmp;
		}	
	}
	
	printf("%ld\n", ans);
	return 0;
}