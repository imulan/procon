#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int a, b, c;
	int r[3];
	
	scanf(" %d %d %d", &a, &b, &c);
	r[0]=a; r[1]=b; r[2]=c;
	sort(r, r+3, greater<int>());
	
	for(int i=0; i<3; ++i){
		if(a==r[i]) printf("%d\n", i+1);	
	}
	for(int i=0; i<3; ++i){
		if(b==r[i]) printf("%d\n", i+1);	
	}
	for(int i=0; i<3; ++i){
		if(c==r[i]) printf("%d\n", i+1);	
	}
	
	return 0;
}