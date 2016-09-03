#include <iostream>
#include <cstdio>
using namespace std;

const int MAX=100;

int main(){
	int t, n, m, a[MAX], b[MAX];	
	
	scanf(" %d %d", &t, &n);
	for(int i=0; i<n; ++i) scanf(" %d", &a[i]);
	scanf(" %d", &m);
	for(int i=0; i<m; ++i) scanf(" %d", &b[i]);
	
	int x=0, y=0;
	bool ans;
	
	if(n<m) ans=false;
	else{
		
		while(y<m && x<n){
			
			while(x<n){
				if(a[x] <= b[y] && b[y] <= a[x]+t) break;
				++x;
			}	
		
			if(a[x] <= b[y] && b[y] <= a[x]+t){
				++x;
				++y;
			}
			//printf("x=%d, y=%d\n", x, y);
		}
		
	} 
	
	if(y==m) ans=true;
	else ans=false;
	
	if(ans) printf("yes\n");
	else printf("no\n");
	
	return 0;
}