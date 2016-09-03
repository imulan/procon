#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s, t;
	int n;
	cin >> s;
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		t="";
		int left, right;
		scanf(" %d %d", &left, &right);
		
		t+=s.substr(0, left-1);
		string tmp=s.substr(left-1, right-left+1);
		reverse(tmp.begin(), tmp.end());
		t+=tmp;
		t+=s.substr(right, s.size()-right);
		s=t;
		
		//cout << t << endl;
	}
	
	cout << t << endl;
	
	return 0;
}