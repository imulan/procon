#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	long times;
	scanf(" %ld", &times);
	for(long t=0; t<times; ++t){
		int x, y, w, h;
		int n;
		scanf(" %d %d %d %d", &x, &y, &w, &h);
		scanf(" %d", &n);
		
		int ans=0;
		for(int i=0; i<n; ++i){
			int cx, cy;
			scanf(" %d %d", &cx, &cy);	
			
			if(x<=cx && cx<=x+w && y<=cy && cy<=y+h) ans++;
		}
		printf("%d\n", ans);
	}
}