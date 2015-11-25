#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int f[1000000]={0};
int warp[1000000]={0}; //この地点は前にもうコマが通ったのでそのコマの終点までワープできる

int main(){
	int n;
	long s[100000],c[100000];
	
	cin >> n;
	for(int i=0; i<n; ++i) scanf(" %ld %ld", &s[i], &c[i]);
	
	for(int i=0; i<n; ++i){
		int start=s[i];
		
		while(c[i]>0){
			if(f[s[i]]==0){ //白
				c[i]--;
				f[s[i]]=1;
				if(c[i]==0) break;
			}
			else if(warp[s[i]]!=0) s[i]=warp[s[i]];
			else s[i]++;	
		}
		
		if(start<s[i]) warp[start]=s[i];
		//printf("warp[%d] = %d\n", start, s[i]);
		/*
		for(int i=1; i<=12; ++i) printf("%d", f[i]);
		printf("\n");	
		*/		
	}
	
	for(int i=0; i<n; ++i) printf("%ld\n", s[i]);
}