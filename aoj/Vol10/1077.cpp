//WA

#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		int zero=0;
		long n[6];
		for(int i=0; i<6; ++i){
			scanf(" %ld", &n[i]);
			if(n[i]==0) zero++;
		}
		
		if(zero==6) break;
		
		long a=n[0]+n[3], b=n[1]+n[4], c=n[2]+n[5];
		long ans=0;
		
		//バランスのとれたやつを優先的に開催
		long m=min(a,min(b,c)); 
		ans+=m;
		a-=m;
		b-=m;
		c-=m;
		
		ans+=a/3+b/3+c/3;
	
		printf("%ld\n", ans);
	}
}