#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int main(){
	int n, k, r;
	bool bunny[51][51];
	map<int, int> b;
	
	for(int i=0; i<=50; ++i)
	for(int j=0; j<=50; ++j)
	bunny[i][j]=false;
	
	scanf(" %d %d", &n, &k);
	for(int i=0; i<k; ++i){
		int m;
		scanf(" %d", &m);
		for(int j=0; j<m; ++j){
			int p;
			scanf(" %d", &p);
			b[p]=i;
		}
				
	}
	
	int bad[51]={0};
	
	scanf(" %d", &r);
	for(int i=0; i<r; ++i){
		int p, q;
		scanf(" %d %d", &p, &q);
		if(b[p]==b[q]){
			bad[p]=1;	
			bad[q]=1;
		}
	}
	
	int ans=0;
	for(int i=1; i<=50; ++i) ans+=bad[i];
	printf("%d\n", ans);
}