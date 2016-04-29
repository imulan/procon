#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef struct{
	string product;
	int num;
	string stuff[100];
}recipe;

int n, m;
map<string, long> mp; //普通に買うときの値段
recipe r[100];

long rec(string a){
	long ret=0;	
	int p=-1;
	
	//合成可能か
	bool find=false;
	for(int i=0; i<m; ++i){
		if(r[i].product==a){
			find=true;
			p=i;
			break;
		}
	}
	
	if( !find ) ret=mp[a]; //無理だった		
	else{
		for(int i=0; i<r[p].num; ++i){
			ret+=rec(r[p].stuff[i]);
		}
		
		ret=min(ret, mp[a]);
	}
	
	return ret;
}

int main(){
	while(1){		
		//入力
		scanf(" %d", &n);
		if(n==0) break;
		for(int i=0; i<n; ++i){
			string s;
			long p;
			cin >> s >> p;
			mp[s]=p;
		}
		
		scanf(" %d", &m);
		for(int i=0; i<m; ++i){
			cin >> r[i].product;
			cin >> r[i].num;
			for(int j=0; j<r[i].num; ++j) cin >> r[i].stuff[j];
		}
		
		string want;
		cin >> want;
		
		//処理
		printf("%ld\n", rec(want));
	}	
}