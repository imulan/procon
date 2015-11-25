#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int ct[4]={0};
	int n;
	
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		char c;
		scanf(" %c", &c);
		ct[c-'0'-1]++;	
	}
	
	sort(ct, ct+4);
	
	printf("%d %d\n", ct[3], ct[0]);
}