#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n, a[10];
	int ans=0;
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> a[i];
	
		while(a[i]%2==0 || a[i]%3==2){
			a[i]--;
			ans++;	
		}
	
	}
	
	printf("%d\n", ans);
	return 0;
}