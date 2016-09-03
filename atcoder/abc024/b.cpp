#include <cstdio>
#include <iostream>
using namespace std;

const int N=1000000*2;

int main(){
	int n, t;
	int a[N]={0};
	
	scanf(" %d %d", &n, &t);
	for(int i=0; i<n; ++i){
		int p;
		scanf(" %d", &p);
		
		a[p]++;
		a[p+t]--;
	}
	
	for(int i=0; i<N-1; ++i) a[i+1]+=a[i];	
	
	int ans=0;	
	for(int i=0; i<N; ++i){
		if(a[i]>0) ans++;
	}
	
	printf("%d\n", ans);
}