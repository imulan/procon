#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		int n, w, bar[11];
		int mv=0; //maximum value
		for(int i=0; i<=10; ++i) bar[i]=0;
		
		scanf(" %d %d", &n, &w);
		if(n==0) break;
		for(int i=0; i<n; ++i){
			int v;
			scanf(" %d", &v);	
			bar[v/w]++;
			if(v>mv) mv=v;
		}
		
		int mw=mv/w; //max width
		int mb=0; //max bar
		for(int i=0; i<=10; ++i){
			if(bar[i]>mb) mb=bar[i];	
		}
		
		
		double ans=0.01;
		for(int i=0; i<=mw; ++i)
			ans+=( (double)(mw-i)/mw ) * ( (double)bar[i]/mb );
		printf("%.10lf\n", ans);
	}
}