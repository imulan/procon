#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n;
	long a[1000];
	
	scanf(" %d", &n);
	for(int i=0; i<n; ++i) scanf(" %ld", &a[i]);
	
	sort(a, a+n);
	//for(int i=0; i<n; ++i) printf(" %ld\n", a[i]);
	
	int ans=1;
	long w=a[0];
	for(int i=1; i<n; ++i){
		if(a[i] > w){
			w += a[i];
			++ans;
		}
	}
	
	//printf("weight = %ld\n", w);
	printf("%d\n", ans);
	
	return 0;
}