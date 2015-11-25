#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n; 
	long m, a[10000], b[10000];
	
	scanf(" %d %ld", &n, &m);
	for(int i=0; i<n; ++i) scanf(" %ld %ld", &a[i], &b[i]);

	long ans=m;

	for(int i=0; i<n; ++i){
		m+=a[i]-b[i];
		if(ans < m) ans=m;
		else if(m<0) {
			ans=0;
			break;
		}
	}		

	printf("%ld\n", ans);
	return 0;
}