#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main(){
	int txa, tya, txb, tyb, t, v, n, x, y;
	bool ans=false;
	double eps=1e-7;
	
	scanf(" %d %d %d %d %d %d", &txa, &tya, &txb, &tyb, &t, &v);
	scanf(" %d", &n);
	
	int limit = t*v;
	for(int i=0; i<n; ++i){
		scanf(" %d %d", &x, &y);
		double dist = sqrt( pow(txa-x, 2.0) + pow(tya-y, 2.0) ) + sqrt( pow(x-txb, 2.0) + pow(y-tyb, 2.0) );
	
		
		if(dist < limit+eps)ans=true;
	}
	
	if(ans) printf("YES\n");
	else printf("NO\n");
	
	return 0;
}