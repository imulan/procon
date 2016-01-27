#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

const long N=5000000;
long w[N+1]={0};

int main(){
	long n;
	
	//input
	cin >> n;
	for(long i=0; i<n; ++i){
		long a;
		scanf(" %ld", &a);
		w[a]++;
	}
	
	for(long i=0; i<N; ++i){
		w[i+1] += w[i]/2;
		w[i]=w[i]%2;			
	}
	
	long ans=0;
	for(long i=0; i<=N; ++i){
		//if(w[i]>0) printf("w[%ld] = %ld\n", i, w[i]); 
		
		ans+=w[i];
	}
	cout << ans << endl;
}