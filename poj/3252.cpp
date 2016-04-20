#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

const int MAX_N=20000;

void swap(int *x, int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int main(){
	int n; 
	long L[MAX_N];
	
	scanf(" %d", &n);
	for(int i=0; i<n; ++i)
		scanf(" %ld", &L[i]);
	
	ll ans=0;
	
	while(n>1){ //板が1枚になるあではめていく
		int min1=0, min2=1; //1番短いmin1,次に短いmin2.
		
		if(L[min1] > L[min2]) swap(min1, min2);
		
		for(int i=2; i<n; ++i){
			if(L[i] < L[min1]){
				min2=min1;
				min1=i;
			}
			else if(L[i] < L[min2]){
				min2=i;
			}
		}
		//min1,min2が正しく求まった
		
		int t=L[min1]+L[min2];
		ans+=t; //min1とmin2に分けるためにかかるコスト
		
		if(min1 == n-1) swap(min1, min2);
		L[min1]=t;
		L[min2]=L[n-1]; //n-1が使われなくなるため，回避する
	
		--n; //nを減らす。(つまり配列のn-1部分が使われない)
	}
	
	printf("%lld\n", ans);

	return 0;
}