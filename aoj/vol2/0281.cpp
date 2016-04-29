#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int q;
	scanf(" %d", &q);
	for(int i=0; i<q; ++i){
		int c, a, n;
		scanf(" %d %d %d", &c, &a, &n);
		
		int ans=0;
		//greedy
		//canが組めるまで組む
		while(c>0 && a>0 && n>0){
			ans++;	
			c--;
			a--;
			n--;
		}	
	
		//ccaが組めるまで組む
		while(c>1 && a>0){
			ans++;	
			c-=2;
			a--;
		}
		
		//cccが組めるまで組む
		while(c>2){
			ans++;	
			c-=3;
		}
		
		printf("%d\n", ans);
	}
}