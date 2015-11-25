#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n, m, a[1000], b[1000], vote[1000]={0};
	scanf(" %d %d", &n, &m);
	for(int i=0; i<n; ++i) scanf(" %d", &a[i]);
	for(int i=0; i<m; ++i) scanf(" %d", &b[i]);
	
	sort(b,b+m, greater<int>());
	
	int now=0;
	for(int i=0; i<m; ++i){
		for(int j=now; j<n; ++j){
			if(a[j] <= b[i]){
				++vote[j];
				now=j;
				//printf("::%d\n",j);
				break;
			} 
		}
	}
	
	int ans=0, max=0;
	for(int i=0; i<n; ++i){
		if(max < vote[i]){
			max=vote[i];
			ans=i+1;
		}
	}
	
	printf("%d\n", ans);
		
	return 0;
}