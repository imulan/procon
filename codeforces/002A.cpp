#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
	int n, p[1000];
	string s[1000];
	map<string, long> mp;
	
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		cin >> s[i] >> p[i];	
		
		if(mp.find(s[i]) == mp.end()) mp[s[i]]=p[i];
		else mp[s[i]]+=p[i];
	}
	
	long max=0;
	for(map<string,long>::iterator itr=mp.begin(); itr!=mp.end(); itr++){
		//cout << itr->first << " :: " << itr->second << endl;
		if(max<itr->second) max=itr->second;
	}
	//printf("max=%ld\n", max);
	
	string candidate[1000];
	int ct=0;
	for(map<string,long>::iterator itr=mp.begin(); itr!=mp.end(); itr++){
		if(max==itr->second){
			candidate[ct]=itr->first;
			ct++;
		}
	}
	//printf("ct=%d\n", ct);
	
	if(ct==1) cout << candidate[0] << endl;
	else{ //複数人候補
		int lim=ct;
		map<string, long> mpp;
		
		for(int i=0; i<ct; ++i) mpp[candidate[i]]=0;
		
		for(int i=0; i<n; ++i){
			if(mpp.find(s[i]) == mpp.end()) mpp[s[i]]=p[i];
			else mpp[s[i]]+=p[i];
			
			bool flag=false;
			for(int j=0; j<ct; ++j){
				if(max<=mpp[candidate[j]]){
					cout << candidate[j] << endl;
					flag=true;	
					break;
				}
			}
			
			if(flag) break;
		}
			
	}
	
}