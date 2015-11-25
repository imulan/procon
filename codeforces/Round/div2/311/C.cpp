#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	long n, len[100000], d[100000];
	
	scanf(" %d", &n);
	for(long i=0; i<n; ++i) scanf(" %ld", &len[i]);	
	for(long i=0; i<n; ++i) scanf(" %ld", &d[i]);	
	
	long longleg=n/2+1; //この数だけ最長の足が必要
	
}