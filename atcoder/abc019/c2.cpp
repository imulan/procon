#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

int main(){
	long n, ans=0;
	long num[100000];
	set<long> se;
	
	scanf(" %ld", &n);

	for(long i=0; i<n; ++i){	
		long a;
		scanf(" %ld", &a);
		while(a%2==0) a/=2;
		
		if(se.find(a) == se.end()){
			se.insert(a);
			++ans;	
		}
	}
	
	printf("%ld\n", ans);
}