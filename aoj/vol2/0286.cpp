#include <cstdio>
#include <iostream>
using namespace std;

const long N=51000;

int main(){
	int n, m, l;
	long s[N], t[N], e[N];
		
	//入力	
	scanf(" %d %d", &n ,&m);
	
	long count=0;
	while(1){	
		scanf(" %ld %ld %ld", &s[count], &t[count], &e[count]);
		if(s[count]==0 && t[count]==0 && e[count]==0) break;
		s[count]--;
		t[count]--;
		++count;
	}
	//printf("%ld\n", count);
	
	//計算
	scanf(" %d", &l);
	for(int i=0; i<l; ++i){
		long b[10000]; 
		long long c[10000];
		
		for(long j=0; j<n; ++j) c[j]=0; //初期化
		
		for(long j=0; j<m; ++j){
			scanf(" %ld", &b[j]);		
		}
		
		for(long j=0; j<count; ++j){
			c[s[j]] += e[j] * b[t[j]];
		}
		
		for(long j=0; j<n; ++j){
			if(j!=0) printf(" ");
			printf("%lld", c[j]);	
		}
		printf("\n");
	}	
	
	return 0;
}