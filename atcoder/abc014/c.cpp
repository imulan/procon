#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

const int N=1000002;

int main(){
	int n, a, b;
	int color[N]={0};
	
	scanf(" %ld", &n);
	for(int i=0; i<n; ++i){
		scanf(" %d %d", &a, &b);
		color[a]++;
		color[b+1]--;		
	}
	
	for(int i=0; i<=1000000; ++i) color[i+1]+=color[i];
	
	sort(color, color+N-1, greater<int>());
	
	printf("%d\n", color[0]);	
}