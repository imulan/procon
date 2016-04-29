#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef struct{
	int a; //下限
	int b; //上限
	int c; //派手さ
}clothes;

int d, n;
int t[200];
clothes p[200];

long dp[202][201];

long rec(int x, int y){ //x日目,前の日にきてた服y
	if(dp[x][y]>=0) return dp[x][y];
	
	long ret=0;
	if(x==0){
		for(int i=0; i<n; ++i){
			if(p[i].a<=t[x] && t[x]<=p[i].b){
				int tmp=rec(x+1, i);	
				if(ret<tmp) ret=tmp;
			}
		}	
	}
	else if(x==d) return 0;	
	else{
		int mm=0;
		for(int i=0; i<n; ++i){
			if(p[i].a<=t[x] && t[x]<=p[i].b){
				int cc=p[i].c-p[y].c;
				if(cc<0) cc=-cc;
				
				int tmp=rec(x+1, i)+cc;	
				if(mm<tmp) mm=tmp;
			}
		}
		ret+=mm;	
	}
	
	return dp[x][y]=ret;
}

int main(){
	scanf(" %d %d", &d, &n);
	for(int i=0; i<d; ++i) scanf(" %d", &t[i]);
	for(int i=0; i<n; ++i) scanf(" %d %d %d", &p[i].a, &p[i].b, &p[i].c);
	
	memset(dp, -1, sizeof(dp));
	printf("%ld\n", rec(0,0));	
}