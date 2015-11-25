#include <cstdio>
#include <iostream>
#include <utility>
using namespace std;

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	if(a>b) swap(a,b); //a<b
	
	//aをbにする
	int ans=0;
	int c[11]={0,1,2,3,2,1,2,3,3,2,1};
	while(b-a>10){
		ans++;
		a+=10;	
	}
	
	ans+=c[b-a];
	
	printf("%d\n", ans);
}