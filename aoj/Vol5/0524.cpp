#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef struct{
	long x;
	long y;
}point;

int main(){
	while(1){
		int m, n;
		point s[200], t[1000];
		point def;
		
		scanf(" %d", &m);
		if(m==0) break;
		for(int i=0; i<m; ++i) scanf(" %ld %ld", &s[i].x, &s[i].y);
		//平行移動
		def = s[0];
		for(int i=1; i<n; ++i){
			s[i].x -= s[0].x;	
			s[i].y -= s[0].y;
		}
		s[0].x=0;
		s[0].y=0;
		
		scanf(" %d", &n);
		for(int i=0; i<n; ++i) scanf(" %ld %ld", &t[i].x, &t[i].y);
		
		for(int i=0; i<n; ++i){ //t[i]中心に平行移動そてみる
			point r[1000];
			memcpy(r, t, sizeof(t));
			for(int j=0; j<n; ++j){
				if(j==i) continue;
				r[j].x -= r[i].x;	
				r[j].y -= r[i].y;
			}
			r[i].x=0;
			r[i].y=0;
			
			bool flag=true;
		}
		
	
	}
}