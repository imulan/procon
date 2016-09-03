#include <cstdio>
#include <iostream>
using namespace std;

const long INF=100000;

int main(){
	long n;
	long c[30000];
	long up[30001];

	scanf(" %ld", &n);
	
	//増加列
	up[0]=-INF;
	for(long i=1; i<=30001; ++i) up[i]=INF; 
	
	for(long i=0; i<n; ++i){
		scanf(" %ld", &c[i]);
		
		for(long j=1; j<=n; ++j){
			if(up[j]>c[i]){	
				up[j]=c[i];
				//printf("up[%ld] = c[%ld]\n", j, i);
				break;
			}
		}
	}
	
	for(long j=0; j<=30001; ++j){
		//printf("up[%ld] = %ld\n", j, up[j]);
		if(INF==up[j]){
			printf("%ld\n", n-j+1);
			break;	
		}
	}
	
	
	return 0;
}