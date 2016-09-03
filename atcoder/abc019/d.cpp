#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n;
	int a=1, b=2;
	long dist[51][51];
	long max=0;
	
	scanf(" %d", &n);
	
	for(int i=0; i<(n-1)*n/2; ++i){
		cout<<"? "<<a<<" "<<b<<endl;
		cin>>dist[a][b];
		if(max<dist[a][b]) max=dist[a][b];
		b++;
		if(b==n+1){
			a++;
			b=a+1;	
		}
	}
	printf("! %ld\n", max);
}