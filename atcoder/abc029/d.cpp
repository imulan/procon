#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int ss=0;
	int tmp=n;
	while(tmp!=0){
		tmp/=10;	
		ss++;
	}
	int lim=pow(10, ss-1);
	//printf("lim = %d\n", lim);
	
	int cond = n/lim;
	
	long ans=0;
	
	if(cond == 1){
		for(int i=n; i>=lim; --i){
			int p=i;
			while(p!=0){
				if(p%10==1) ans++;
				p/=10;	
			}	
		}
	
		n=lim-1;
	}
	
	int z=0;
	while(n!=0){
		int p=n%10;
		n/=10;
		
		int t=0;
		if(p>1) t=1;
		
		ans += (n+t)*pow(10,z);
		z++;
	}
	
	printf("%ld\n", ans);
}