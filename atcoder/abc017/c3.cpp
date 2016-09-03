#include <cstdio>
#include <iostream>
using namespace std;

const long MAX=100000;

int main(){
	long n, m;
	long l[MAX], r[MAX];
	int s[MAX];
	
	long sum=0;
	long imos[MAX+1]={0};
	
	//入力
	scanf(" %ld %ld", &n, &m);
	for(long i=0; i<n; ++i){
		scanf(" %ld %ld %d", &l[i], &r[i], &s[i]);
		imos[l[i]] += s[i];
		imos[r[i]+1] -= s[i];
		sum += s[i];
	}
	
	for(long i=1; i<m; ++i) imos[i+1] += imos[i];
	
	long min=sum;
	for(long i=1; i<=m; ++i){
		//printf("inos[%ld]=%ld\n", i, imos[i]);	
		if(min > imos[i]) min = imos[i];
	}
		
	printf("%ld\n", sum-min);
	
	return 0;
}