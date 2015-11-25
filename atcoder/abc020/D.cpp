#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
using namespace std;

const long mod=1000000007;

long long gcd(long long x, long long y){
	if(x<y) swap(x,y);	
	while(x%y!=0){
		long z=x%y;
		x=y;
		y=z;
	}
	
	return y;
}

int main(){
	long n, k;
	cin >> n >> k;
	
	long long ans=0;
	for(long long i=1; i<=n; ++i){
		ans+=i*k/gcd(i,k);
		ans%=mod;
	}
	
	cout << ans <<endl;
}