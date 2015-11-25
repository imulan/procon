#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main(){
	int n,m;
	int a[100000]={0},b[100000]={0};
	
	cin >> n >> m;
	for(int i=0; i<n; ++i) scanf(" %d", &a[i]);
	for(int i=0; i<m; ++i) scanf(" %d", &b[i]);
	
	sort(a,a+n,greater<int>());
	sort(b,b+m,greater<int>());
	/*
	for(int i=0; i<n; ++i) printf(" %d", a[i]);
	printf("\n");
	for(int i=0; i<m; ++i) printf(" %d", b[i]);
	printf("\n");
	*/
	bool ans=true;
	
	if(n<m) ans=false;
	else{ //n>=mのとき
		//sortされた予約と部屋サイズを見て、それぞれが以上確認
		for(int i=0; i<n; ++i){
			if(a[i]<b[i]){
				ans=false;
				break;
			}
		}
	}
	
	if(ans) printf("YES\n");
	else printf("NO\n");
}