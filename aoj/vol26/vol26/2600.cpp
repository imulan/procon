#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const long N=100000;

int main(){
	long n, w, h;
	long tate[N+1], yoko[N+1];
	
	memset(tate, 0, sizeof(tate));
	memset(yoko, 0, sizeof(yoko));
	
	scanf(" %ld %ld %ld", &n, &w, &h);
	
	for(long i=0; i<n; ++i){
		long x, y, z;
		scanf(" %ld %ld %ld", &x, &y, &z);
		
		//tate direct
		long ta=x-z+1, tb=x+z;
		if(ta<1) ta=1;
		if(tb>w) tb=w;
		tate[ta]++;
		tate[tb+1]--;
		
		//yoko direct
		long ya=y-z+1, yb=y+z;
		if(ya<1) ya=1;
		if(yb>h) yb=h;
		yoko[ya]++;
		yoko[yb+1]--;
	}
	
	for(long i=0; i<=w; ++i) tate[i+1]+=tate[i];
	for(long i=0; i<=h; ++i) yoko[i+1]+=yoko[i];
	
	/*
	for(long i=0; i<=w; ++i) printf("tate[%ld]=%d\n", i, tate[i]);
	for(long i=0; i<=h; ++i) printf("yoko[%ld]=%d\n", i, yoko[i]);
	*/
	
	bool ans=true;
	for(long i=1; i<=w; ++i){
		if(tate[i]<=0){
			ans=false;
			break;	
		}	
	}
	
	if(!ans){
		ans=true;
		for(long i=1; i<=h; ++i){
			if(yoko[i]<=0){
				ans=false;
				break;	
			}	
		}
	}
	if(ans) printf("Yes\n");
	else printf("No\n");
	
}