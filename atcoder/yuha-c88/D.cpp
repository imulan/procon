#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	int n, m;
	string s[8];
	int br[8][8]={0}; //bridge
	
	//input
	cin >> n;
	for(int i=0; i<n; ++i) cin >> s[i];
	cin >> m;
	for(int i=0; i<m; ++i){
		string a, b;
		cin >> a >> b;
		
		int aa, bb;
		for(int j=0; j<n; ++j){
			if(a==s[j]) aa=j;
			else if(b==s[j]) bb=j;
		}
		
		br[aa][bb]=br[bb][aa]=1;
	}
	
	
	
}