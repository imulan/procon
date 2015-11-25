#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	int len=s.size();
	bool ans=true;
	int now=0;
	while(now<len){
		if(s[now]=='*' || s[len-now-1]=='*') now++;
		else{
			if(s[now]!=s[len-now-1]) ans=false;
			now++;	
		}	
		
		if(!ans) break;
	}
	
	if(ans) printf("YES\n");
	else printf("NO\n");
}