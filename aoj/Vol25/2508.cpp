#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string answer(string t, int a, int b[]){
	string r="";
	char station[53];
	for(int i=0; i<26; ++i) station[i]='a'+i;
	for(int i=26; i<53; ++i) station[i]='A'+(i-26);
	
	for(int i=0; i<t.size(); ++i){
		if('a'<=t[i])	 r+=station[ (t[i]-'a'-b[i%a]+52)%52 ]; //小文字の時
		else r+=station[ (t[i]-'A'+26-b[i%a]+52)%52 ]; //大文字の時	
	}
	return r;	
}

int main(){
	while(1){
		int n, k[100];
		string s;
		
		//入力
		scanf(" %d", &n);
		if(n==0) break;
		for(int i=0; i<n; ++i) scanf(" %d", &k[i]);
		cin >> s;
		
		cout << answer(s, n, k) << endl;
	}
	return 0;
}