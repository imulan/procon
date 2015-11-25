#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

typedef long long llint;

int main(){
	llint a;
	cin >> a;
	
	llint ans=-1;
	for(llint i=10; i<=10000; ++i){
		llint f=0;
		int digit=0;
		
		llint t=i; 
		while(t!=0){
			f+=pow(i,digit)*(t%10);	
			t/=10;
			digit++;
		}
		if(f==a){
			ans=i;
			break;
		}
	}
	
	cout << ans << endl;
}