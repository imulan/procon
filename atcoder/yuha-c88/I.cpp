#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	string c[1000];
		
	//input
	scanf(" %d", &n);	
	for(int i=0; i<n; ++i) cin >> c[i];	

	string key="monica";
	string ans="";
	int k=0;
	
	for(int i=0; i<n-1; ++i){
		for(int j=0; j<n; ++j){
			for(int k=0; k<6; ++k){
				if(key[k]==c[i][j]) ans+=c[i+1][j];	
			}
		}
	}
			
	cout << ans << endl;	
}