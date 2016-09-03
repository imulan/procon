#include <cstdio>
#include <iostream>
#include <utility>
using namespace std;

int main(){
	int a, b;
	cin >>a >>b;	
	
	if(a>b) swap(a,b);
	
	int ans=b-a;
	if(ans>5) ans=10-ans;
	
	printf("%d\n", ans);
}