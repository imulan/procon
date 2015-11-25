#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		int n, r;
		int card[51]; //1~nを使う
		
		scanf(" %d %d", &n, &r);
		if(n==0 && r==0) break; 
		for(int i=1; i<=n; ++i) card[i]=n+1-i;
	
		for(int i=0; i<r; ++i){
			int p, c;
			scanf(" %d %d", &p, &c);
			
			int tmp[50];
			for(int j=0; j<c; ++j) tmp[j]=card[p+j];
			for(int j=p-1; j>0; --j) card[j+c]=card[j];	
			for(int j=1; j<=c; ++j) card[j]=tmp[j-1];
			
			//for(int i=1; i<=n; ++i) printf(" %d",card[i]);
			//printf("\n");
		}
		printf("%d\n", card[1]);
	}
	return 0;
}