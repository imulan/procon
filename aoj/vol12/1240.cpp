#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

//メッセージ復元
string back(string s, char c){
	string t="";
	if(c=='J'){
		char t1=s[s.size()-1];
		string t2=s.substr(0, s.size()-1);
		t+=t1+t2;
	}
	else if(c=='C'){
		char t1=s[0];
		string t2=s.substr(1, s.size()-1);
		t+=t2+t1;
	}
	else if(c=='E'){
		int size=s.size();
		char mid;
		if(size%2==1) mid=s[size/2];
		
		string t1=s.substr(0, size/2);
		string t2=s.substr((size+1)/2, size/2);
		
		t+=t2;
		if(size%2==1) t+=mid;
		t+=t1;
	}
	else if(c=='A'){
		t=s;
		reverse(t.begin(), t.end());
	}
	else if(c=='P'){
		for(int i=0; i<s.size(); ++i){
			if('0'<=s[i] && s[i]<='9'){
				if(s[i]=='0') t+='9';
				else t+=s[i]-1;
			}
			else t+=s[i];
		}
	}
	else if(c=='M'){
		for(int i=0; i<s.size(); ++i){
			if('0'<=s[i] && s[i]<='9'){
				if(s[i]=='9') t+='0';
				else t+=s[i]+1;
			}
			else t+=s[i];
		}	
	}
	return t;
}

int main(){
	long n;
	scanf(" %ld", &n);
	for(long i=0; i<n; ++i){
		string o; //order of the messenger	
		string m; //message given to the king
		cin >> o >> m;
		for(int j=o.size()-1; j>=0; --j)
			m=back(m, o[j]);		
		
		cout << m <<endl;
	}
	return 0;
}