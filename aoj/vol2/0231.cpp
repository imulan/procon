#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	while(1){
		int n, m[100]; 
		long a[100], b[100], merge[200];
		
		//入力
		scanf(" %d", &n);
		if(n==0) break;
		for(int i=0; i<n; ++i){
			scanf(" %d %ld %ld", &m[i], &a[i], &b[i]);
			merge[2*i] = a[i];
			merge[2*i+1] = b[i];
		}
		
		//a, b両方の数を合わせてソートし，座標圧縮する
		sort(merge, merge+(2*n));
		
		for(int i=0; i<n; ++i){
			for(int j=0; j<2*n; ++j){
				if(b[i] == merge[j]){
					b[i]=j;	
					merge[j]=-1;
					break;
				}
			}
		}
		
		for(int i=0; i<n; ++i){
			for(int j=0; j<2*n; ++j){
				if(a[i] == merge[j]){
					a[i]=j;	
					merge[j]=-1;
					break;
				}
			}
		}
		
		//for(int i=0; i<n; ++i) printf("%d; a=%ld, b=%ld\n", i, a[i], b[i]);
	
		//いもす法
		long imos[201]={0};
		for(int i=0; i<=200; ++i) imos[i]=0;
		
		for(int i=0; i<n; ++i){
			imos[a[i]] += m[i];
			imos[b[i]] -= m[i];
		}	
	
		for(int i=0; i<2*n; ++i) imos[i+1] += imos[i];
		//for(int i=0; i<2*n; ++i) printf("%d:%ld\n",i,imos[i]);	
		sort(imos, imos+(2*n), greater<long>());
		
		//printf("max=%ld\n", imos[0]);
		if(imos[0]>150) printf("NG\n");
		else printf("OK\n");
	}
	return 0;
}