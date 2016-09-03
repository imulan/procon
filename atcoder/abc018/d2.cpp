#include <algorithm>
#include <bitset>
#include <cstdio>
#include <iostream>
using namespace std;

//数aがpビット立っているかどうか
bool full(long a, int p){
	bitset<18> bs(a);
	return (bs.count() == p);
}

int main(){
	int n, m, p, q, r;
	int x[400], y[400], z[400];
	
	scanf(" %d %d %d %d %d", &n, &m, &p, &q, &r);
	for(int i=0; i<r; ++i){
		scanf(" %d %d %d", &x[i], &y[i], &z[i]);
		--x[i];
		--y[i];
	}
	
	long ans=0;
	for(long i=(1<<n)-1; i>0; --i){
		if(!full(i, p)) continue; //女子はp人いないとダメ
		
		long male[18]={0};
		for(int j=0; j<r; ++j){
			if( (i>>x[j])&1 ){ //送る女子がいるなら
				male[y[j]] += z[j];
			}
		}
		//for(int j=0; j<m; ++j) printf("  %ld\n", male[j]);
		
		long tmp=0;
		sort(male, male+m, greater<long>());
		for(int j=0; j<q; ++j) tmp+=male[j];
		
		if(ans<tmp) ans=tmp;
	}
	
	printf("%ld\n", ans);
	return 0;
}