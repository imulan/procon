#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

long solve(string s, int n, int k){
	long ret=0;
	
	for(int i=0; i<=n-1-k; ++i){
		long tmp=1;
		for(int j=0; j<k; ++j){
			long p=s[j+i]-'0';
			tmp*=p;	
		}	
		
		if(ret<tmp) ret=tmp;	
	}
	
	return ret;	
}	

int main(){
	int t;
	scanf(" %d", &t);
	for(int i=0; i<t; ++i){
		int n, k;
		scanf(" %d %d", &n, &k);
		
		string s;
		cin >> s;
		
		printf("%ld\n", solve(s,n,k));
	}
}