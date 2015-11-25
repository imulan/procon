#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main(){
	int n, a[100000];
	int mod = 1000000007;
	
	int floor[100000]={0}; //頂点1からの距離がiである頂点が何個あるか	

	int sq[100000]={0}; //2のi乗%mod
	long tri[100000]={0}; //2のi番目の三角数乗
		
	sq[0]=1;
	for(int i=1; i<100000; ++i) sq[i] = (sq[i-1]*2)%mod;	
	tri[0]=1;
	for(int i=1; i<100000; ++i) tri[i] = (tri[i-1]*sq[i])%mod;
	
	/*
	bool w=false;
	for(int i=1; i<100000; ++i){
		if(sq[i]==1) w=true;	
		printf(" %d\n", sq[i]);
	}	
	if(w) printf(" ooo\n");
	*/
				
	bool err=false;	
	
	//input
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		scanf(" %d", &a[i]);
		floor[a[i]]++;
		if(i>0 && a[i]==0) err=true;
	}
	if(a[0]>0) err=true;
	
	for(int i=0; i<n; ++i) printf(" floor[%d] = %d\n", i, floor[i]);
	
	
	//solve
	if(err) printf("0\n");
	else{
		long ans=1;
		
		for(int i=1; i<n; ++i){
			if(floor[i]>1){
					ans*=tri[i];
					ans%=mod;	
			}
		}
		printf("  ans%ld\n", ans);
		
		for(int i=1; i<n-1; ++i){
			long tmp=sq[floor[i]]-1;
			if(tmp==0) continue;
			
			for(int i=1; i<floor[i+1]; ++i){
				tmp*=tmp;
				tmp%=mod;	
			}
			
			printf("tmp=%ld\n", tmp);
			ans*=tmp;
			ans%=mod;
		}
		
		printf("%ld\n", ans);
	}	
	
}