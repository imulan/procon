#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int x[5][5];
	int count[26]={0};
		
	for(int i=0; i<5; ++i){
		for(int j=0; j<5; ++j){
			scanf(" %d", &x[i][j]);
			count[x[i][j]]=1;	
		}
	}

	int nums[25]={0};
	int nn=0;

	for(int i=1; i<=25; ++i){
		if(count[i]==0) nums[nn++]=i; //まだ使われていない数	
	}
		
	long mod=1000000007;
	vector<int> v;
	for(int i=0; i<nn; ++i) v.push_back(nums[i]);
	
	long ans=0;
	
	//順列を全探索
	do{
		/*
		for(int i=0; i<nn; ++i) printf(" %d,", v[i]);
		printf("\n");
		*/
		
		//copy
		int ct=0;
		int y[5][5];
		for(int i=0; i<5; ++i){
			for(int j=0; j<5; ++j){
				if(x[i][j]==0) y[i][j]=v[ct++];
				else y[i][j]=x[i][j];		
			}
		}
		
		/*
		for(int i=0; i<5; ++i){
			for(int j=0; j<5; ++j){
				printf("%3d", y[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		*/
		
		bool ok=true;
		//判定
		for(int i=0; i<3; ++i){
			for(int j=0; j<5; ++j){
				if(y[i][j]<y[i+1][j] && y[i+1][j]<y[i+2][j]) ok=false;
				if(y[i][j]>y[i+1][j] && y[i+1][j]>y[i+2][j]) ok=false;	
			}
		}

		for(int j=0; j<3; ++j){
			for(int i=0; i<5; ++i){
				if(y[i][j]<y[i][j+1] && y[i][j+1]<y[i][j+2]) ok=false;
				if(y[i][j]>y[i][j+1] && y[i][j+1]>y[i][j+2]) ok=false;
			}
		}
		
		if(ok) ans++;
		ans%=mod;
	}while(next_permutation(v.begin(), v.end()));
	
	cout << ans <<endl;
}