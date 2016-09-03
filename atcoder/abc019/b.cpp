#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
using namespace std;

int main(){
	string s, t="";
	int a=0;
	
	cin >> s;
	while(a<s.size()){
		char p=s[a];
		int b=0;
		while(a+b<s.size() && s[a+b]==s[a]) b++;
		
		stringstream ss;
		ss << b;
		
		t+=p;
		t+=ss.str();
		a+=b;
		//printf("%d\n", a);
	}
	
	cout << t << endl;
}