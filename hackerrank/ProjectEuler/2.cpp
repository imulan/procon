#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	long long f[100];	
	f[0]=1;
	f[1]=2;
	
	for(int i=2; i<100; ++i) f[i]=f[i-1]+f[i-2];
			
	long t;
	scanf(" %ld", &t);
	for(long i=0; i<t; ++i){
		long n;
		scanf(" %ld", &n);
		
		long long ans=0;
		for(int j=0; j<100; ++j){
			if(f[j]>n) break;
			
			if(f[j]%2==0) ans+=f[j];	
		}
		
		cout << ans << endl;
	}
	
}