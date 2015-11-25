#include <cstdio>
#include <iostream>
using namespace std;

long long s1(long a){
	long long ret=0;
	for(long i=1; i<=a; ++i){
		ret+=i*i;	
	}	
	return ret;
}

long long s2(long a){
	long long ret=0;
	for(long i=1; i<=a; ++i) ret+=i;
	return ret*ret;
}

int main(){
	int t;
	scanf(" %d", &t);
	for(int i=0; i<t; ++i){
		int n;
		scanf(" %d", &n);		
		cout << s2(n)-s1(n) << endl;
	}
}