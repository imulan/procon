#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n;
	long dist=0, point;
	long max=0;
	
	scanf(" %d", &n);
	
	for(int i=2; i<=n; ++i){
		long p;
		cout<<"? "<<1<<" "<<i<<endl;
		cin>>p;
		if(dist<p){
			dist=p;
			point=i;
		}
	}
	
	for(int i=1; i<=n; ++i){
		if(i==point) continue;
		
		long p;
		cout<<"? "<<point<<" "<<i<<endl;
		cin>>p;
		if(max<p) max=p;
	}	
	
	printf("! %ld\n", max);
}