#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	long long n;
	cin >> n;
	
	long long x=1;
	long long t=0;
	long long m=0; 
	while(x*2<=n){
		x*=2;
		t++;
		m=x-m;
	}
	
	/*
	cout << x << " t=" << t <<endl;
	cout << n-x << " =n-x"<<endl;
	cout << m << " =m" <<endl;
	*/
	
	string win;
	string ti="Takahashi", ai="Aoki";
	if(t%2==0){
		if(0<=n-x && n-x<m) win = ti;
		else win=ai;
	}
	else{
		if(0<=n-x && n-x<x-m) win = ai;
		else win=ti;
	}
	
	
	cout << win << endl;
}