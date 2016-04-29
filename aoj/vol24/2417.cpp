#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	char c[12]="w kstnhmyr";
	map<char, char> mp;
	
	mp['T']='a';
	mp['L']='i';
	mp['U']='u';
	mp['R']='e';
	mp['D']='o';
	
	for(int i=0; i<s.size(); i+=2){
		if(s[i]=='0'){
			if(s[i+1]=='U') cout << "nn";
			else 	cout << c[s[i]-'0'] << mp[s[i+1]];
		}
		else if(s[i]=='1') cout << mp[s[i+1]];
		else 	cout << c[s[i]-'0'] << mp[s[i+1]];
	}
	cout << endl;
}	