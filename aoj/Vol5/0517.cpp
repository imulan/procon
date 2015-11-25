#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		long n, k;
		long a[100000];
		long b[100000]; //差を格納
		
		scanf(" %ld %ld", &n, &k);
		if(n==0) break;
		for(long i=0; i<k; ++i) scanf(" %ld", &a[i]);
		sort(a, a+k);
		
		bool w=false;
		if(a[0]==0) w=true;
		
		for(long i=0; i<k-1; ++i) b[i]=a[i+1]-a[i]-1;

		//for(long i=0; i<k; ++i) printf("a[%ld]=%ld\n",i,a[i]);
		//for(long i=0; i<k-1; ++i) printf("b[%ld]=%ld\n",i,b[i]);

		long ans=0;		
		for(long i=0; i<k-1; ++i){
			if(i!=0 && b[i-1]==0) continue;
			
			if(w && i==0) continue;
			
			long now=i;
			long diff=1;
			if(w) diff--;
			
			while(now<k-1 && diff<2){
				if(diff+b[now]>1) break;
				else diff+=b[now++];	
			}	
			//printf("%ld :: %ld\n", i, now);
			
			long tmp=now-i+1;
			if(w && diff>0) tmp++;
			
			if(ans<tmp) ans=tmp;
			//printf("  %ld\n", ans);
		}
		
		printf("%ld\n", ans);
	}
}