#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

bool isSameColor(string a){
	char b=a[0];
	int s=a.size();
	
	for(int i=0; i<s; ++i){
		if(a[i]!=b) return false;
	}
	
	return true;	
}

int main(){
	string s;
	while(cin>>s){
		if(s=="0") break;
		
		queue<string> que;
		map<string, long> mp;
		
		que.push(s);
		mp[s]=0;	
		
		bool found=false;
		while(!que.empty()){
			string v=que.front();
			que.pop();
			
			int size=v.size();
			for(int i=0; i<size-1; ++i){
				string tmp=v;
				
				if((tmp[i]=='r'&&tmp[i+1]=='g') || (tmp[i]=='g'&&tmp[i+1]=='r')) tmp[i]=tmp[i+1]='b';
				else if((tmp[i]=='r'&&tmp[i+1]=='b') || (tmp[i]=='b'&&tmp[i+1]=='r')) tmp[i]=tmp[i+1]='g';
				else if((tmp[i]=='b'&&tmp[i+1]=='g') || (tmp[i]=='g'&&tmp[i+1]=='b')) tmp[i]=tmp[i+1]='r';
				
				if(mp.find(tmp) == mp.end()){
					que.push(tmp);
					mp[tmp]=mp[v]+1;	
				}
				
				if(isSameColor(tmp)){
					cout << mp[tmp] << endl;	
					found=true;
					break;
				}	
			}	
			
			if(found) break;
		}
		
		if(!found) printf("NA\n");
		
	}
}