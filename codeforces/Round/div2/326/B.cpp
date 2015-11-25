#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std;

bool islovely(long long a){
	long long p=(long long)sqrt(a);
	//printf("p~%d\n", p);
	if(p*p==a) return false;
	
	bool ret=true;
	for(long long i=2; i*i<=a; ++i){
		if(a%(i*i)==0){
			ret=false;
			break;	
		}
	}
	return ret;
}

int main(){
	long long n;
	cin >> n;
	
	long long ans=1;
	if(islovely(n)) ans=n;
	else{
		for(long long i=2; i<=(long long)sqrt(n); ++i){
			if(n%i==0){
				//printf("ch:: %ld, %ld\n", i, n/i);

				if(islovely(n/i)) ans=max(ans,n/i);
				if(islovely(i)) ans=max(ans,i);
			}	
		}
	} 
	
	cout << ans << endl;
}