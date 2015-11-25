#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s[12];

	for(int i=0; i<12; ++i) cin >> s[i];
	
	int ans=0;
	for(int i=0; i<12; ++i){
		for(int j=0; j<s[i].size(); ++j){
			if(s[i][j]=='r'){
				ans++;
				break;	
			}	
		}
	}
	
	cout << ans << endl;
}