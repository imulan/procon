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

const long INF=1500000000;

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

	int df[4]={1,0,-1,0}, ds[4]={0,1,0,-1};

	long left=1, right=INF;
	long mid;
	while(1){
		bool end=false;

		mid=(left+right)/2;

		if(right-left<=1){
			end=true;
			mid=right;
		}

		long c[12][12];
		for(int i=0; i<12; ++i)
		for(int j=0; j<12; ++j)
		c[i][j]=INF;

		queue< pair<int,int> > que;

		c[start.first][start.second]=0;
		que.push(start);
		while(!que.empty()){
			pair<int, int> v=que.front();
			que.pop();
			for(int i=0; i<4; ++i){
				int nf=v.first+df[i], ns=v.second+ds[i];
				if(nf>=0 && nf<h && ns>=0 && ns<w){
					if(f[nf][ns]=='#'){
						if(c[nf][ns]>c[v.first][v.second]+mid){
							pair<int, int> tmp;
							tmp.first=nf;
							tmp.second=ns;
							que.push(tmp);
							c[nf][ns]=c[v.first][v.second]+mid;
						}
					}
					else{
						if(c[nf][ns]>c[v.first][v.second]+1){
							pair<int, int> tmp;
							tmp.first=nf;
							tmp.second=ns;
							que.push(tmp);
							c[nf][ns]=c[v.first][v.second]+1;
						}
					}
				}
			}

		}

		//printf("left:%ld, mid:%ld, right:%ld\n", left, mid, right);

		if(end){
			if(c[goal.first][goal.second]>t) mid=left;
			break;
		}


		//printf("%ld, %ld;\n", mid, c[goal.first][goal.second]);

		if(c[goal.first][goal.second]>t) right=mid-1;
		else left=mid;

	}

	printf("%ld\n", mid);
}
