#include <cstdio>
#include <iostream>
using namespace std;

const long mod=1000000007;

int main(){
	int r, c, x, y, d, l;
	
	scanf(" %d %d %d %d %d %d", &r, &c, &x, &y, &d, &l);
	
	//使う領域の種類数
	int area = (r-x+1)*(c-y+1);
	
	//枠の中の組み合わせ
	long pascal[901][901];
	pascal[0][0]=1;
	for(int i=1; i<=x*y; ++i){
		pascal[i][0] = pascal[i][i]=1;
		for(int j=1; j<i; ++j) pascal[i][j]=(pascal[i-1][j-1] + pascal[i-1][j])%mod;
	}
	
	printf("%ld\n", (area * pascal[d+l][d])%mod);
	return 0;
}