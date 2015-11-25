#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string IntToString(int a){
	stringstream ss;
	ss << a;	
	return ss.str();
}

int main(){
	while(1){
		int n;
		string s, t;
	
		cin >> n;
		if(n==0) break;
		cin >> s;
	
		for(int i=0; i<n; ++i){
			t="";
			int j=0;
			while(j<s.size()){
				char c=s[j++];
			
				int count=1;
				while(c == s[j]){
					count++;
					j++;
				}
				t+=IntToString(count);
				t+=c;
			}
			s=t;
			//cout << " " << s << endl;
		}
	
		cout << t << endl;
	}
	return 0;
}