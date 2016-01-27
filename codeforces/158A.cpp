#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n, k, a[50];
	
	scanf(" %d %d", &n, &k);
	for(int i=0; i<n; ++i) scanf(" %d", &a[i]);
	
	int key=a[k-1];
	int ans=0;
	for(int i=0; i<n; ++i){
		if(a[i]>0 && a[i]>=key) ++ans;
	}
	
	printf("%d\n", ans);
}