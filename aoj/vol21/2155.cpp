#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main(){
	while(1){
		int n, m;
		
		scanf(" %d %d", &n, &m);
		if(n==0) break;
		
		vector< pair<long, pair<int, int> > > d(m);
		
		for(int i=0; i<m; ++i){
			//pairをつかいたい
			scanf(" %ld %d %d", &d[i].first, &d[i].second.first, &d[i].second.second);
		}
		//pairのソート
		sort(d.begin(), d.end());
		
		bool infected[20001];
		for(int i=0; i<=n; ++i) infected[i]=false;
		infected[1]=true;
		
		for(int i=0; i<m; ++i){
			if(infected[ d[i].second.first ])
				infected[ d[i].second.second ]=true;			
		}
		
		int ans=0;
		for(int i=1; i<=n; ++i){
			if(infected[i]) ans++;
		}
		 
		printf("%d\n", ans); 
	}
}