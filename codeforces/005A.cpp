#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	int num=0;
	long ans=0;
	string s;
	while(getline(cin,s)){
		if(s[0]=='+') num++;
		else if(s[0]=='-') num--;
		else{ //message
			int now=0;
			while(s[now]!=':') now++;
			ans+=(long)num*(s.size()-now-1);
		}
	}
	printf("%ld\n", ans);
}