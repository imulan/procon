#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int a, b;
	
	scanf(" %d %d", &a, &b);
	int ans = b-(a%b);
	if(a%b==0) ans=0;
	printf("%d\n", ans);

	return 0;
}