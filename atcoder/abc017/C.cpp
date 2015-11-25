#include <cstdio>
#include <iostream>
using namespace std;

const long MAX=100000;

int main(){
	long n, m;
	long l[MAX], r[MAX];
	int s[MAX];
	
	long ans=0;
	
	//入力
	scanf(" %ld %ld", &n, &m);
	for(long i=0; i<n; ++i) scanf(" %ld %ld %d", &l[i], &r[i], &s[i]);
	
	
	//部分点とる(ビットで全探索)
	for(long a=(1<<n)-1; a>0; --a){
		//printf("a=%ld\n", a);
		
		long jewel[MAX+1]={0};
		long count=0, t=0;
		bool ok=true;
		
		for(long i=0; i<n; ++i){
			
			if((a>>i) & 1){	
				//printf("%ld ", i);
				for(long j=l[i]; j<=r[i]; ++j){
					if(jewel[j] == 0){
						jewel[j]=1; 
						++count;
					}	
				}
				t+=s[i];
			}	
			
			if(count==m) ok=false;	
		}
			
		if(ok && ans<t) ans=t;
	}
	
	printf("%ld\n", ans);
	
	return 0;
}