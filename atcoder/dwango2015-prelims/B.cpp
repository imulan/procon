#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	long ans=0;
		
	cin >> s;
	
	for(int i=1; i<=s.size()/2; ++i){ //"25"が並ぶ個数
		string t="";
		for(int j=0; j<i; ++j) t = t+"25";
		
		for(int j=0; j+2*i<=s.size(); ++j){
			string u="";
			u.append(s, j, 2*i);
			if(u==t) ++ans;
		}
		
	}
	
	printf("%ld\n", ans);
	
	return 0;
}