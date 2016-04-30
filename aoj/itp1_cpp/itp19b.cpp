#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
	while(1){
		string s;
		int m;
		
		cin >> s;
		if(s == "-") break;
		cin >> m;
		for(int i=0; i<m; ++i){
			int a;
			cin >> a;
			
			string add = s.substr(0,a);
			s = s+add;
			s = s.substr(a, s.size());
		}
		
		cout << s << endl;
	}
	return 0;
}