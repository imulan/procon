#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
using namespace std;

int main(){
	int n;
	string s;
	bool ap[26];
	
	for(int i=0; i<26; ++i) ap[i]=false;
	
	cin >> n >> s;
	for(int i=0; i<n; ++i){
		if('A'<=s[i] && s[i]<='Z') s[i]=s[i]-'A'+'a';
		ap[s[i]-'a']=true;
	}
	
	bool ans=true;
	for(int i=0; i<26; ++i){
		if(!ap[i]) ans=false;	
	}
	
	if(ans) printf("YES\n");
	else printf("NO\n");
}