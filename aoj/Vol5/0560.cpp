#include <cstdio>
#include <iostream>
using namespace std;

typedef struct{
	long jungle;
	long ocean;
	long ice;
}field;

int main(){
	int m, n;
	char f[1000][1001];
	long k;
	field s[1000][1000]; //左上からの数
	
	scanf(" %d %d", &m, &n);
	scanf(" %ld", &k);
	for(int i=0; i<m; ++i)
	for(int j=0; j<n; ++j)
	scanf(" %c", &f[i][j]);
	
	for(long i=0; i<k; ++i){
		int a, b, c, d;
		scanf(" %d %d %d %d", &a, &b, &c, &d);
		a--; b--; c--;	d--;	
		
	}
	
	
}