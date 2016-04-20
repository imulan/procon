/*p.48 貪欲法*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=1000;

int main(){
	while(1){
		int n, r;
		int x[MAX_N];
	
		scanf(" %d %d", &r, &n);
		if(r==-1) break;
		for(int i=0; i<n; ++i)
			scanf(" %d", &x[i]);
		
		sort(x, x+n);
	
		int i=0, ans=0;
		while(i<n){
			int s=x[i++]; //カバーされていない一番左の点
		
			while(i<n && x[i]<=s+r) ++i;
			int p=x[i-1]; //印のつく点
			while(i<n && x[i]<=p+r) ++i;
	
			++ans;
		}
	
		printf("%d\n", ans);
	}
	
	return 0;
}