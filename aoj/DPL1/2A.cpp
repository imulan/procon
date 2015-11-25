#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	int V,E;	
	cin >> V >> E;
	
	int G[15][15];
	memset(G,-1,sizeof(G));
	
	for(int i=0; i<E; ++i){
		int s,t,d;
		scanf(" %d %d %d", &s, &t, &d);
		G[s][t]=d;	
	}
	
	
	
}