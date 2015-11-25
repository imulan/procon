#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	int n, ans=0;
	bool f[9]; //長押し
	
	for(int i=0; i<9; ++i) f[i]=false;
	
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		string s;	
		cin >> s;
		
		for(int j=0; j<9; ++j){
			if(f[j] && s[j]!='o') f[j]=false;	
				
			if(!f[j] && s[j]=='o'){
				++ans;
				f[j]=true;
			}
			else if(s[j]=='x') ++ans;
		}
	}
	
	printf("%d\n", ans);
}