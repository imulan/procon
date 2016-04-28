#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

map<vector<int> , int> mp;

bool solve(){
	vector<int> p(8);
	for(int i=0; i<8; ++i){
		if(scanf(" %d", &p[i]) == EOF) return false;	
	}
	
	cout << mp[p] << endl;
	
	return true;
}

int main(){
	int dir[4]={1,-1,4,-4};
	queue< vector<int> > que;
	
	vector<int> start(8);
	for(int i=0; i<8; ++i) start[i]=i;
	
	que.push(start);
	mp[start]=0;
	
	while(!que.empty()){
		vector<int> v=que.front();
		que.pop();
		
		int z;
		for(int i=0; i<8; ++i){
			if(v[i]==0){
				z=i;
				break;	
			}	
		}
		
		for(int i=0; i<4; ++i){
			int nz=z+dir[i];
			if(nz>=0 && nz<=7 && !(z==3&&nz==4) && !(z==4&&nz==3)){
				vector<int> tmp=v;	
				swap(tmp[z], tmp[nz]);
				
				if(mp.find(tmp) == mp.end()){
					que.push(tmp);
					mp[tmp]=mp[v]+1;	
				}
				
			}		
		}
			
	}
	
	while(solve());
}