#include <cstdio>
#include <iostream>
#include <string>
#include <codecvt>
using namespace std;

int main(){
	int n;
	string st[400];
	cin >> n;
	
	for(int i=0; i<n; ++i) cin >> st[i];

	for(int i=0; i<n; ++i) cout << st[i] << endl;
		
	for(int i=0; i<n; ++i){
		for(int j=0; j<2; ++j) cout <<st[i][j]<<endl;	
	}		
	
	
	
}