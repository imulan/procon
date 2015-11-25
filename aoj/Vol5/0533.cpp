#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int w[10], k[10];
	for(int i=0; i<10; ++i) scanf(" %d", &w[i]);
	for(int i=0; i<10; ++i) scanf(" %d", &k[i]);
	
	sort(w, w+10, greater<int>());
	sort(k, k+10, greater<int>());
	
	int p=0, q=0;
	for(int i=0; i<3; ++i) p+=w[i];
	for(int i=0; i<3; ++i) q+=k[i];
	
	printf("%d %d\n", p, q);
	return 0;
}