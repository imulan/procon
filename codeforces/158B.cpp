#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	long n;
	long s[5];
	
	memset(s, 0, sizeof(s));
	scanf(" %ld", &n);
	for(long i=0; i<n; ++i){
		int a;
		scanf(" %d", &a);
		s[a]++;
	}
	
	long ans=s[4]; //4人のグループ
	
	ans+=s[3];
	s[1]-=s[3];
	
	ans+=s[2]/2;
	s[2]-=(s[2]/2)*2;
	
	if(s[2]){
		ans++;
		s[1]-=2;
	}
	
	if(s[1]>0){
		ans+=s[1]/4;
		s[1]-=(s[1]/4)*4;
		
		if(s[1]>0) ans++;
	}
	
	printf("%ld\n", ans);
}