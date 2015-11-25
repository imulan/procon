#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const unsigned long long N=1e7;

int f[N]={0};
unsigned long long warp[N]={0}; //この地点は前にもうコマが通ったのでそのコマの終点までワープできる

int main(){

	int n;
	unsigned long long s[100000],c[100000];
	printf("go\n");	
	cin >> n;
	for(int i=0; i<n; ++i) scanf(" %llu %llu", &s[i], &c[i]);
	
	//warp point
	map<unsigned long long,unsigned long long> w;
	//開始地点
	vector<unsigned long long> warp_st;
	
	
	for(int i=0; i<n; ++i){
		unsigned long long start=s[i];
		//まずスタート位置が黒いか判定
		vector<unsigned long long> it = lower_bound(warp_st.begin(),warp_st.end(), start);	
		
		while(c[i]>0){
			if(f[s[i]]==0){ //白
				c[i]--;
				f[s[i]]=1;
				if(c[i]==0) break;
			}
			else if(w[s[i]]!=0) s[i]=warp[s[i]];
			else s[i]++;	
		}
		
		w[start]=s[i]+1;
		warp_st.push_back(start);
		
		sort(warp_st.begin(),warp_st.end());
		
		printf("warp[%d] = %d\n", start, w[start]);
		/*
		for(int i=1; i<=12; ++i) printf("%d", f[i]);
		printf("\n");	
		*/		
	}
	
	for(int i=0; i<n; ++i) printf("%ld\n", s[i]);
}