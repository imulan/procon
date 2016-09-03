#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	int n, a, b;
	scanf(" %d %d %d", &n, &a, &b);
	
	int pos=0;
	for(int i=0; i<n; ++i){
		string s;
		int d;
		
		cin >> s >> d;	
		if(d<a) d=a;
		else if(d>b) d=b;
		
		if(s=="West") d=-d;
		pos+=d;
	}
	
	if(pos<0) printf("West %d\n", -pos);
	else if(pos>0) printf("East %d\n", pos);
	else printf("0\n");
}