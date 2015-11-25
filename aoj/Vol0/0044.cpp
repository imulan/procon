#include <iostream>
#include <cstdio>
using namespace std;

const long MAX_N=60000;
bool isPrime[MAX_N];

int main(){
	//素数テーブルの設定
	for(long i=2; i<=MAX_N; ++i)
		isPrime[i]=true;
		
	for(long i=2; i<=MAX_N; ++i){
		if(isPrime[i]){
			for(long j=2; i*j<=MAX_N; ++j) isPrime[i*j]=false;
		}
	}
	
	//実際の問題処理
	long n;
	
	while( scanf("%ld", &n) != EOF ){
		long i=n-1;
		while(1){
			if(isPrime[i]){
				printf("%ld ",i);
				break;
			}
			--i;
		}
		
		i=n+1;
		
		while(1){
			if(isPrime[i]){
				printf("%ld\n",i);
				break;
			}
			++i;
		}	
	} 

	return 0;
}