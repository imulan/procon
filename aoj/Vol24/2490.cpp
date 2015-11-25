#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n;
	long st=0;
	bool ans=true;
	
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		char p;
		long x;
		scanf(" %c %ld", &p, &x);
		
		if(p=='(') st+=x;
		else if(p==')')st-=x;	
			
		if(st<0)ans=false;
	}
	
	if(st!=0) ans=false;
	
	if(ans) printf("YES\n");
	else printf("NO\n");
}