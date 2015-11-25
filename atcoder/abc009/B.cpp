#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n, a[100];	
	
	scanf(" %d", &n);
	for(int i=0; i<n; ++i) scanf(" %d", &a[i]);
	sort(a, a+n, greater<int>());
	
	int ans=1;
	while(a[0] == a[ans]) ++ans;
	printf("%d\n", a[ans]);
	
	return 0;
}