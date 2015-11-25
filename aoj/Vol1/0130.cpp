#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		string s;
		cin >> s;
		int now=0; //文字列の位置
		int p=26; //現在の車両位置
		
		char train[60];
		memset(train, '0', sizeof(train));
		
		while(now<s.size()){
			if('a'<=s[now] && s[now]<='z'){ //文字だったら
				train[p]=s[now++];	
			}
			else{ //矢印だったら
				if(s[now] == '-') p++;
				else if(s[now] == '<') p--;
				now+=2;
			}
		}
		
		int t=0;
		while(train[t]=='0') t++;
		while(train[t]!='0') printf("%c", train[t++]);
		printf("\n");			
	}
}