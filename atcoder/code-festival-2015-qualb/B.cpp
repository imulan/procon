#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main(){
	int n,m;
	int a;
	int ans[100001]={0};
	
	cin >> n >> m;
	for(int i=0; i<n; ++i){
		scanf(" %d", &a);
		ans[a]++;
	}
	
	int ansnum;
	int tmp=0;
	for(int i=0; i<=100000; ++i){
		if(tmp<ans[i]){
			tmp=ans[i];
			ansnum=i;	
		}
	}
	
	int half = n/2;
	//printf("n=%d, h=%d\n",n, half);

	if(half<ans[ansnum]) printf("%d\n", ansnum);
	else printf("?\n");
}