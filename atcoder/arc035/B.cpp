#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
using namespace std;

const long mod=1000000007;

unsigned long long fact(int p){
	if(p==0) return 1;
	else return p*fact(p-1)%mod;
}

int main(){
	int n;
	int t[10000];
	int m[10001];
	
	scanf(" %d", &n);
	
	memset(m, 0, sizeof(m));
	
	for(int i=0; i<n; ++i){
		scanf(" %d", &t[i]);
		m[t[i]]++;
	}
	sort(t, t+n);
	unsigned long long time=0;
	for(int i=0; i<n; ++i) time+=(unsigned long long)(n-i)*t[i];	
	
	unsigned long long ans=1;
	for(int i=1; i<=10000; ++i){
		ans*=fact(m[i]);
		ans%=mod;
	}
	
	printf("%llu\n%llu\n", time, ans);
}