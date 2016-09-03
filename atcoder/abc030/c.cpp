#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main(){
	int N,M,X,Y;
	int a[100000],b[100000];
	
	//input
	cin >> N >> M >> X >> Y;
	for(int i=0; i<N; ++i) scanf(" %d", &a[i]);
	for(int i=0; i<M; ++i) scanf(" %d", &b[i]);
	
	//solve
	
	int ans=0;
	int inA=0, inB=0;
	int now=0;
	
	while(1){
		now=a[inA];
		now+=X; //move
		
		//while(inB<M && b[inB]<now) inB++;
		inB = lower_bound(b, b+M, now)-b;
		//printf("inB = %d\n", inB);
		
		if(inB==M) break;
		now=b[inB];
		now+=Y;
		
		ans++;
		
		//while(inA<N && a[inA]<now) inA++;
		inA = lower_bound(a, a+N, now)-a;
		//printf("inA = %d\n", inA);

		if(inA==N) break;
	}
	
	printf("%d\n", ans);
}