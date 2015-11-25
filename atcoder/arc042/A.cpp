#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main(){
	int n, m, a[100000];
		
	scanf(" %d %d", &n, &m);
	for(int i=0; i<m; ++i) scanf(" %d", &a[i]);

	bool t[100001];
	for(int i=1; i<=n; ++i) t[i]=true; //未参照

	int ans[100000], ct=0;
	
	for(int i=m-1; i>=0; --i){
		if(t[a[i]]){
			ans[ct++]=a[i];
			t[a[i]]=false;	
		}
	}

	for(int i=1; i<=n; ++i){
		if(t[i]) ans[ct++]=i;
	}

	for(int i=0; i<n; ++i) printf("%d\n", ans[i]);

}