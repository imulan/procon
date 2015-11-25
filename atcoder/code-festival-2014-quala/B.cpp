#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string a;
	int b;
	
	cin >> a;
	cin >> b;
	
	int size = a.size();
	int r = (b-1+size)%size;
	
	cout << a[r] << endl;
}