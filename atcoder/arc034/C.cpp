#include <cstdio>
#include <cmath>
#include <iostream>
#include <map>
#include <string>

using namespace std;

const long mod=1000000007;

int main(){
	long a, b;
	map<long, long> mp;
	
	scanf(" %ld %ld", &a, &b);
	
	for(long i=b+1; i<=a; ++i){
		long p=i;
		//printf("i=%ld\n", i);
		for(long j=2; j<=sqrt(i); ++j){
			while(p%j==0){
				p/=j;	
				//printf(" %ld\n", j);
				
				if(mp.find(j)!=mp.end()) mp[j]++;
				else mp[j]=1;
				
			}	
		}
		
		if(p!=1){
			if(mp.find(p)!=mp.end()) mp[p]++;
			else mp[p]=1;	
		}
	}
	
	long ans=1;
	
	for(map<long, long>::iterator itr=mp.begin(); itr!=mp.end(); ++itr){
		ans*=itr->second+1;
		ans%=mod;	
	}
	
	printf("%ld\n", ans);
}