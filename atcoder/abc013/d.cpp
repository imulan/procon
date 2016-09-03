#include <cstdio>
#include <iostream>
#include <utility>
using namespace std;

int tt[31][100001]; //tによる写像2^k回分	
	
int main(){
	int n, m, d, t[100001], a[200000];
	
	for(int i=1; i<=100000; ++i) t[i]=i;
	
	scanf(" %d %d %d", &n, &m, &d);
	for(int i=0; i<m; ++i) scanf(" %d", &a[i]);

	for(int i=m-1; i>=0; --i) swap(t[a[i]],t[a[i]+1]);	
		
	//ダブリングのための写像を用意
	for(int i=1; i<=n; ++i) tt[0][i]=t[i];
			
	for(int j=1; j<=30; ++j){ 
		for(int i=1; i<=n; ++i){
			tt[j][i]=tt[j-1][tt[j-1][i]];
		}
	}	
	
	
	int ans[100001];
	for(int i=1; i<=n; ++i){
		ans[i]=i;
		for(int j=0; j<=30; ++j){
			if(d & (1<<j)){
				ans[i]=tt[j][ans[i]];	
			}		
		}
	}
	
	for(int i=1; i<=n; ++i) printf("%d\n", ans[i]);
	
}