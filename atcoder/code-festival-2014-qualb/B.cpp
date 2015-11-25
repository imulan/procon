#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n, k;
	int ans, sum=0;
	
	bool flag=true;
	
	scanf(" %d %d", &n, &k);
	for(int i=0; i<n; ++i){
		int a;
		scanf(" %d", &a);
		
		sum += a;
		if(flag && sum>=k){
			ans=i+1;
			flag=false;
		}
	}
	
	printf("%d\n", ans);
}