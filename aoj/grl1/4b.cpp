#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

const long MAX=100000;

vector<int> G[MAX];
list<int> ou;
bool V[MAX];
int N;
int indeg[MAX];

void bfs(int s){
	queue<int> que;
	que.push(s);
	V[s]=true; //訪問済
	
	while( !que.empty() ){
		int u=que.front();
		que.pop();
		ou.push_back(u); //答えとなるリストに追加
		
		for(int i=0; i<G[u].size(); ++i){
			int v=G[u][i]; //uから出ている有向辺の先のノード
			indeg[v]--; //出次数を１減らす
			
			if(indeg[v]==0 && !V[v]){
				V[v]=true;
				que.push(v);	
			}
		}
	}		
}

//topological sort
void tsort(){
	for(int i=0; i<N; ++i) indeg[i]=0;
	
	for(int i=0; i<N; ++i){
		for(int j=0; j<G[i].size(); ++j){
			int k=G[i][j];
			indeg[k]++;
		}
	}
	
	for(int i=0; i<N; ++i){
		if(indeg[i]==0 && !V[i]) bfs(i);	
	}
	
	for(list<int>::iterator it=ou.begin(); it!=ou.end(); ++it){
		cout << *it << endl;	
	}
}

int main(){
	long M;
	scanf(" %d %ld", &N, &M);
	
	for(int i=0; i<N; ++i) V[i]=false;
	
	for(long i=0; i<M; ++i){
		int s, t;
		scanf(" %d %d", &s, &t);
		G[s].push_back(t); //有向辺を追加		
	}	
	
	tsort();
}