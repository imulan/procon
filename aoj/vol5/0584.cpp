#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int a[100000000];
	
int main(){
	long n;
	scanf(" %ld", &n);
	for(long i=0; i<n; ++i) scanf(" %d", &a[i]);
	sort(a, a+n);
	
	long p[300];
	int now=0;
	int limit=15;
	
	if(limit>n) limit=n;
	
	for(int i=0; i<limit; ++i){
		for(int j=0; j<limit; ++j){
			if(i==j) continue;
			stringstream tmp;
			tmp<<a[i];
			tmp<<a[j];
			//cout<<tmp.str()<<endl;
			tmp>>p[now++];		
		}
	}
	
	sort(p, p+now);
	
	printf("%ld\n", p[2]);
}