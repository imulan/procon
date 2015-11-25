#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	long a;
	int k;
	
	scanf(" %ld %d", &a, &k);
	
	long ans=10000000;
	
	//総当り
	for(int i=1; i<=100000; ++i){
		int ct[10]={0};	
		
		int t=i;
		while(t!=0){
			ct[t%10]++;
			t/=10;	
		}
		
		int kind=0;
		for(int j=0; j<=9; ++j){
			if(ct[j]>0) kind++;	
		}
		
		int dif = i-a;
		if(dif<0) dif=-dif;
		
		if(kind<=k){
			if(dif<ans) ans=dif;
		}
	}
	
	printf("%ld\n", ans);
}