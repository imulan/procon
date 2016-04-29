#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	long n;
	scanf(" %ld", &n);
	int ans=0;
	while(1){
		if(pow(3,ans-1)<n && n<=pow(3,ans)) break;
		++ans;
	}
	printf("%d\n", ans);
}