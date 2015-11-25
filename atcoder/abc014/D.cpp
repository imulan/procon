//未完成
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
	int n;
	vector<int> G[100000]; //隣接リスト
		
	cin >> n;
	n;
	for(int i=0; i<n-1; ++i){
		int x, y;
		scanf(" %d %d", &x, &y);
		x--;
		y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	int depth[100000]; //頂点0を根とした時の頂点iの深さ
	depth[0]=0;
	bool visit[100000];
	fill(visit, visit+n, false);
	visit[0]=true;
	
	int d=0; //今いる位置の深さ
	//DFS
	stack<int> st;
	st.push(0);
	while(!st.empty()){
		int p = st.top();
		st.pop();
		for(int i=0; i<G[p].size(); ++i){
			if(!visit[ G[p][i] ]){
				st.push(G[p][i]);	
				//printf(" push %d\n", G[p][i]);
				visit[G[p][i]]=true;
				depth[G[p][i]]=d+1;
			}
		}	
		
		if(G[p].size()==0) d--;
		else d++;
	}
	
	for(int i=0; i<n; ++i) printf("depth[%d] = %d\n", i, depth[i]);
	
	int q;
	cin >> q;
	for(int i=0; i<q; ++i){
		int a,b;		
		scanf(" %d %d", &a, &b);
		
		//lowest common ancestorを使う


		
		
		
		printf("%d\n", depth[a-1]+depth[b-1]+1);
	}

}