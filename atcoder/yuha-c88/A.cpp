#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	scanf(" %d", &n);
	
	string ans = "";
	for(int i=0; i<n; ++i){
		string p, q, r;
		cin >> p >> q >> r;
		
		if(p=="BEGINNING") ans += r[0];
		else if(p=="MIDDLE") ans += r[r.size()/2];
		else if(p=="END") ans += r[r.size()-1];		
	}	
	
	cout << ans << endl;
}