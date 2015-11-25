#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
using namespace std;

typedef struct{
	int bl;
	int wh;
	int pos;
}cost;

int main(){
	int h, w;
	long t;
	char f[12][12];
	
	pair<int, int> start, goal;
	
	//input
	scanf(" %d %d %ld", &h, &w, &t);
	for(int i=0; i<h; ++i){
		for(int j=0; j<w; ++j){
			scanf(" %c", &f[i][j]);
			
			if(f[i][j]=='S'){
				start.first=i;
				start.second=j;	
			}
			else if(f[i][j]=='G'){
				goal.first=i;
				goal.second=j;	
			}			
			
		}
	}
	
	int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
	cost c[12][12];
	cost can[12][12][1000];
	
	for(int i=0; i<h; ++i)
	for(int j=0; j<w; ++j)
	c[i][j].pos=0;
	
	queue< pair<int,int> > que;
	
	
	
}