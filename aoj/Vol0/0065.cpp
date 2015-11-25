#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
using namespace std;

int main(){
	string s;
	bool flag=false; //先月
	map<long,long> mp;
	set<long> thismonth; //今月取引があったか
	
	while(getline(cin,s)){	
		if(s==""){
			flag=true; //今月
			continue;	
		}
		
		int point=0;
		while(s[point]!=',') point++;
		//printf("point = %d\n", point);
		
		string tmp=s.substr(0,point);
		//string b=s.substr(point+1, s.size()-1-point);
		
		//cout << a << " " << b <<endl;
		
		stringstream ss;
		ss<<tmp;
		long a;
		ss>>a;
		
		if(!flag){
			if(mp.find(a) == mp.end()) mp[a]=1;	
			else mp[a]++;
		}
		else{
			thismonth.insert(a);
			
			if(mp.find(a) == mp.end()){} //先月の取引はないので無視	
			else mp[a]++;	
		}			
	}
	
	for(map<long,long>::iterator itr=mp.begin(); itr!= mp.end(); ++itr){
			if(thismonth.find(itr->first) != thismonth.end())
			cout << itr->first << " " << itr->second << endl;
	}
}