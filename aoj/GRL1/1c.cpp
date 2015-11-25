#include <cstdio>
#include <iostream>
using namespace std;

const int N=100;
const long long INF=(1LL<<32);

int main(){
	int V, E;
	long long d[N][N];
	
	scanf(" %d %d", &V, &E);
	
	//初期化
	for(int i=0; i<V; ++i){
		for(int j=0; j<V; ++j){
			d[i][j] = ((i==j) ? 0 : INF);		
		}
	}
	
	//辺の入力
	for(int i=0; i<E; ++i){
		int s, t;
		long u;
		scanf(" %d %d %ld", &s, &t, &u);
		d[s][t]=u; //ココ片方だけでいいの？？？
	}
	
	//Warshall-Floyd法
	for(int k=0; k<V; ++k){
		for(int i=0; i<V; ++i){
			if(d[i][k]==INF) continue; //なくてもいい？
			for(int j=0; j<V; ++j){
				if(d[k][j]==INF) continue; //なくてもいい？
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);		
			}
		}
	}
	
	bool negative=false;
	for(int i=0; i<V; ++i)
		if(d[i][i]<0) negative=true;
		
	if(negative) printf("NEGATIVE CYCLE\n");
	else{
		for(int i=0; i<V; ++i){
			for(int j=0; j<V; ++j){
				if(j>0) printf(" ");	
				
				if(d[i][j]==INF) printf("INF");
				else cout<<d[i][j];
			}
			printf("\n");
		}
	}
}