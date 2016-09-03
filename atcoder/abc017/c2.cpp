#include <cstdio>
#include <iostream>
using namespace std;

const long MAX=100000;

int main(){
	long n, m;
	long l[MAX], r[MAX];
	int s[MAX];
	
	long ans=0;
	
	//入力
	scanf(" %ld %ld", &n, &m);
	for(long i=0; i<n; ++i) scanf(" %ld %ld %d", &l[i], &r[i], &s[i]);
	
	for(int i=1; i<=m; ++i){ //i番目の宝石だけ取らない
		long t=0;
		
		for(int j=0; j<n; ++j){
			if(i<l[j] || r[j]<i) t+=s[j];
		}
		
		if(t>ans) ans=t;
	}
		
	printf("%ld\n", ans);
	
	return 0;
}