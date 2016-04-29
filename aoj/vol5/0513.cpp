#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n, m;
	int c[201], ans[201];
	
	scanf(" %d", &n);
	for(int i=1; i<=2*n; ++i) c[i]=i; //初期化
	scanf(" %d", &m);
	
	for(int i=0; i<m; ++i){
		int com;
		scanf(" %d", &com);
		
		if(com==0){
			for(int i=1; i<=2*n; ++i){
				ans[i]=(i%2==0) ? c[n+i/2] : c[i/2+1];
			}
		}
		else{
			int i;
			for(i=1; com+i<=2*n; ++i)
				ans[i]=c[com+i];
			//printf("i=%d\n", i);
			for(int j=i; j<=2*n; ++j)
				ans[j]=c[j-i+1];
		}
		
		for(int i=1; i<=2*n; ++i) c[i]=ans[i];
	}

	for(int i=1; i<=2*n; ++i)
		printf("%d\n", ans[i]);

	return 0;
}