#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main(){
	int n, a[30];
	long ans=0;
	
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> a[i];
		ans += a[i]*pow(2,n-1-i);
	}
	
	printf("%ld\n", ans);
}