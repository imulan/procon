#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	bool prime[10001];
	for(int i=2; i<=10000; ++i) prime[i]=true;
	prime[1]=false;
	for(int i=2; i<=10000; ++i)
		if(prime[i]) for(int j=2; i*j<=10000; ++j) prime[i*j]=false;
	
	int n;
	while(scanf(" %d", &n) != EOF){
		int ans=0;
		for(int i=1; i<=n; ++i)
			if(prime[i] && prime[n-i+1]) ++ans;
		
		printf("%d\n", ans);		
	}
	return 0;
}