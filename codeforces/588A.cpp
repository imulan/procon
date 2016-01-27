#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n;
	int a[100001], p[100001];
	int mincost[100001]={0}; //その日時点の最小コスト
	
	mincost[0]=1000; //最初は大きくしとく
	
	cin >> n;
	for(int i=1; i<=n; ++i){
		scanf(" %d %d", &a[i], &p[i]);
		
		if(mincost[i-1]>p[i]) mincost[i]=p[i];
		else mincost[i] = mincost[i-1];		
	}
	
	//for(int i=1; i<=n; ++i) printf("T:: %d, minc:: %d\n", total[i], mincost[i]);
	
	long ans=0;
	
	for(int i=1; i<=n; ++i){
		ans += (long)mincost[i]*a[i];	
	}
	printf("%ld\n", ans);
}