#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	string s;
	getline(cin, s);
	transform (s.begin (), s.end (), s.begin (), ::toupper);
	cout << s << endl;

	return 0;
}