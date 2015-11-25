#include <cstdio>
#include <iostream>
using namespace std;

//10点
int main(){
	int h[201][201]={0};
	int n, m;
	
	//input
	scanf(" %d %d", &n, &m);
	for(int i=0; i<m; ++i){
		int a, b, c; 
		scanf(" %d %d %d", &a, &b, &c);
		
		for(int j=1; j<=c; ++j){
			for(int k=1; k<=j; ++k){
				h[a+j-1][b+k-1]=1;		
			}
		}
	}
	
	int q;
	cin >> q;
	for(int i=0; i<q; ++i){
		int x, y, z;
		scanf(" %d %d %d", &x ,&y ,&z);	
		
		int count = 0;
		
		for(int j=1; j<=z; ++j){
			for(int k=1; k<=j; ++k){
				if(h[x+j-1][y+k-1]==0) ++count;
			}
		}
		
		printf("%d\n", count);
	}
	
	
	return 0;
}