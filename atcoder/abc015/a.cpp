#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string a, b;
	cin >> a;
	cin >> b;
	
	if(a.size() < b.size()) cout << b <<endl;
	else cout << a << endl;
	return 0;
}