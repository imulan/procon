#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	int now=0;
	char c[7]="aoyeui";
	
	while(now < s.size()){
		if('A'<=s[now] && s[now]<='Z')
			s[now]=s[now]-'A'+'a';
		
		bool flag=true; //vowel
		for(int i=0; i<6; ++i){
			if(c[i]==s[now]){
				flag=false;	
			}
		}
		
		if(flag) cout << "." << s[now];
		now++;
	}
	cout<<endl;
}