#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	long n, m, a;
	
	scanf(" %ld %ld %ld", &n, &m, &a);
	
	long long x=n/a, y=m/a;
	if(n%a!=0) x++;
	if(m%a!=0) y++;
	
	cout << x*y <<endl;
}