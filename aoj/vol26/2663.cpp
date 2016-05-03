#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

long long a[300000], b[300000], c[300000];
long long sums[300000]={0}; //a[0]~a[i]までの和

int main(){
	int n, m;
	
	scanf(" %d", &n);
	for(int i=0; i<n; ++i) scanf(" %lld", &a[i]);
	sort(a, a+n);
	
	sums[0]=a[0];
	for(int i=0; i<n-1; ++i) sums[i+1]=a[i+1]+sums[i]; 
		
	scanf(" %d", &m);
	for(int i=0; i<m; ++i) scanf(" %lld", &b[i]);	
	for(int i=0; i<m; ++i) scanf(" %lld", &c[i]);
	
	//参加者iに対する判定
	for(int i=0; i<m; ++i){
		bool ans;
		if(b[i]<a[0]){
			if(c[i]==0) ans=true;	
			else ans=false;
		}
		else if(a[n-1]<=b[i]){
			if(c[i]<=sums[n-1]) ans=true;
			else ans=false;	
		}
		else{
			//cout << upper_bound(a, a+n, b[i])-a-1 << " <-point" << endl;
			if(sums[upper_bound(a, a+n, b[i])-a-1] >= c[i]) ans=true;
			else ans=false;
		}		
		
		if(ans) printf("Yes\n");
		else printf("No\n");
	}
	
}