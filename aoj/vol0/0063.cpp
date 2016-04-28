#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
	int ans=0;
	string s;
	while(cin >> s){
		bool flag=true;
		for(int i=0; i<s.size(); ++i){
			if(s[i] != s[s.size()-i-1]){
				flag=false;
				break;
			}
		}
		
		if(flag) ++ans;
	}
	printf("%d\n", ans);
	return 0;
}