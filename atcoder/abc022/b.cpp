#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	long n, ans=0;
	bool visit[100001];
	
	for(long i=0; i<=100000; ++i) visit[i]=false;
	
	scanf(" %ld", &n);
	for(long i=0; i<n; ++i){
		long a;
		scanf(" %ld", &a);
		
		if(visit[a]) ans++;
		else visit[a]=true;
	}
	
	printf("%ld\n", ans);
}