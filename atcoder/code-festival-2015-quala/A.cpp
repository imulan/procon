#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	s[s.size()-1] = '5';
	
	cout << s << endl;
}