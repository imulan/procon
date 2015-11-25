#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int n, k, t[5][5];	
int nums[5000];
int ct=0;

void dfs(int a, int b){
	
	if(a==n-1)
		for(int i=0; i<k; ++i) nums[ct++]=b^t[a][i];
	else
		for(int i=0; i<k; ++i) dfs(a+1, b^t[a][i]);
	
}

int main(){

	scanf(" %d %d", &n, &k);
	for(int i=0; i<n; ++i)
	for(int j=0; j<k; ++j)
	scanf(" %d", &t[i][j]);
	
	dfs(0,0);
	
	bool ans=true;
	for(int i=0; i<pow(k, n); ++i){
		if(nums[i]==0){
			ans=false;
			break;
		}	
	}
	
	if(ans) printf("Nothing\n");
	else printf("Found\n");
	
	return 0;
}