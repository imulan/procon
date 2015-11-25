#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

bool p[500000000];

int main(){
	long n, ans=0;
	long num[100000];
	
	scanf(" %ld", &n);

	for(long i=0; i<n; ++i){	
		long a;
		scanf(" %ld", &a);
		while(a%2==0) a/=2;
		a--;
		a/=2;
		//printf("a=%ld\n", a);
		if(!p[a]){
			p[a]=true;
			++ans;	
		}
	}
	
	printf("%ld\n", ans);
}