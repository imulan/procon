#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	int ans=0;
	string s;
	
	cin >> s;
	for(int i=0; i<s.size(); ++i){
		if(i%2==0) ans+=s[i]-'0';
		else ans-=s[i]-'0';	
	}	
	
	printf("%d\n", ans);
}