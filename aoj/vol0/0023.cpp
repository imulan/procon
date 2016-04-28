#include <cmath>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std;

int main(){
	int n;
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		double xa, ya, ra, xb, yb, rb;
		scanf(" %lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
		double dist=pow(xb-xa, 2) + pow(yb-ya, 2);
		double p, q;
		bool biga=true;
		if(ra>rb){ p=ra; q=rb; }
		else { q=rb; p=ra; biga=false; }
		
		int ans;
		if(dist>pow(p+q, 2)) ans=0;
		else if(pow(p-q, 2)<=dist && dist<=pow(p+q, 2)) ans=1;
		else{
			if(biga) ans=2;
			else ans=-2;
		}
		
		printf("%d\n", ans);
	}
}