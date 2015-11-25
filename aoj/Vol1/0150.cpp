#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	bool isprime[10001];
	for(int i=0; i<10001; ++i) isprime[i]=true;

	for(int i=2; i<=10000; ++i){
		if(isprime[i]){
			for(int j=2; i*j<=10000; ++j) isprime[i*j]=false;
		}
	}

	while(1){
		int n;
		scanf(" %d", &n);
		if(n==0) break;
		if(n%2 == 0) n--;
		
		for(int i=n; i>=5; --i){
			if(isprime[i] && isprime[i-2]){
				printf("%d %d\n", i-2, i);
				break;
			}
		}
	}

	return 0;
}