#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std;

typedef struct{
	long d;
	long t;
}island;

int main(){
	while(1){
		int n;
		island is[25];
		scanf(" %d", &n);
		if(n==0) break;
			
		for(int i=0; i<n; ++i) scanf(" %ld %ld", &is[i].t, &is[i].d);
		
		for(int i=0; i<n; ++i){
			for(int j=i; j<n; ++j){
				if(is[i].d>is[j].d) swap(is[i], is[j]);
				else if(is[i].d==is[j].d){
					if(is[i].t>is[j].t) swap(is[i], is[j]);
				}
			}
		}
		
		long ct=0;
		bool ans=true;
		for(int i=0; i<n; ++i){
			ct+=is[i].t;
			if(ct>is[i].d) ans=false;
			if(!ans) break;
		}
	
		if(ans) printf("Yes\n");
		else printf("No\n");
	}
}