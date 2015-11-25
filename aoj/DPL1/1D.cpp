#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n, a[100000];
	//input
	scanf(" %d", &n);
	for(int i=0; i<n; ++i) scanf(" %d", &a[i]);
	
	const int INF = 1e9+1;
	//dp[i]:=長さがi+1であるような増加部分列における最終要素の最小値
	int dp[100000];
	//initialize
	fill(dp, dp+n, INF);
	for(int i=0; i<n; ++i){
		*lower_bound(dp, dp+n, a[i]) = a[i];
	}
	
	printf("%d\n", lower_bound(dp, dp+n, INF)-dp);
}