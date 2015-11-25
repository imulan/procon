#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
	long n;
	map<string, long> mp;
	
	cin >> n;
	for(long i=0; i<n; ++i){
		string s;
		cin >> s;
		
		if(mp.find(s) == mp.end()){
			mp[s]=1;	
			cout << "OK" << endl;
		}	
		else{
			cout << s << mp[s] << endl;
			mp[s]++;
		}
	}
}