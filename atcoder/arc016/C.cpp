#include <cstdio>
#include <iostream>
using namespace std;

const double INF=1000000000;

int main(){
	int n, m;
	double e[10]; //各アイドルを最適に買った時の金額の期待値
	
	for(int i=0; i<9; ++i) e[i]=INF;
	
	scanf(" %d %d", &n, &m);
	for(int i=0; i<m; ++i){
		int c, cost;
		scanf(" %d %d", &c, &cost);
		for(int j=0; j<c; ++j){
			int idol, p;
			scanf(" %d %d", &idol, &p);
			double tmp=(double)cost*100/p;
			if(e[idol-1]>tmp) e[idol-1]=tmp;
		}	
	}
	
	double ans=0;
	for(int i=0; i<n; ++i) ans+=e[i];
	printf("%lf\n", ans);
}