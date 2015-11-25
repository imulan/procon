#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n, a, b, k;
	int p[100];
	
	//input
	scanf(" %d", &n);
	scanf(" %d %d", &a, &b);
	scanf(" %d", &k);
	for(int i=0; i<k; ++i) scanf(" %d", &p[i]);
	
	bool ans=true;
	
	for(int i=0; i<k; ++i){
		for(int j=i+1; j<k; ++j){
			if(p[i]==p[j]){		
				ans=false;
				break;
			}
		}
		
		if(p[i]==a || p[i]==b) ans=false;
		
		if(!ans)break;
	}
	
	
	if(ans) printf("YES\n");
	else printf("NO\n");	
}