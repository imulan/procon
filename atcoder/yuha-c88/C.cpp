#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main(){
	int n;
	string s[20];
	pair<string, int> h[20];
	
	//input
	cin >> n;
	for(int i=0; i<n; ++i) cin >> s[i];
	for(int i=0; i<n; ++i){
		string is,a,v,venturer;
		cin >> h[i].first >> is >> a >> v >> venturer;
		if(v=="good") h[i].second=1;
		else if(v=="bad") h[i].second=-1;
	}
	
	//sort
	for(int i=0; i<n-1; ++i){
		for(int j=n-1; j>i; --j){
			if(s[j]<s[j-1]){
				swap(s[j],s[j-1]);
				swap(h[j],h[j-1]);	
			}
		}
	}
		
	string ans[20];
	int nums=0;
	
	//全探索
	for(int i=(1<<n)-1; i>0; --i){
		
		int t=0;
		for(int j=0; j<n; ++j){
			if(i>>j & 1) t++;
		}	
		if(t<nums) continue; //調べても無駄
				
		int gb[20]; //good=1, bad=-1
		bool valid=true;
		
		for(int j=0; j<n; ++j){
			if(i>>j & 1) gb[j]=1;
			else gb[j]=-1;	
		}
		
		//1人ずつ調べていく
		for(int j=0; j<n; ++j){
			
			string name = h[j].first;
			int ct=0;
			while(name != s[ct]) ct++;
			
			int vnt=h[j].second;
			if(i>>j & 1){ //j番目の冒険者を正直者と仮定する
				
				if(gb[ct]==1){
					if(vnt==-1) valid=false;	
				}
				else if(gb[ct]==-1){
					if(vnt==1) valid=false;	
				}
				
			}
			else{ //j番目の冒険者を嘘つきと仮定する

				if(gb[ct]==1){
					if(vnt==1) valid=false;	
				}
				else if(gb[ct]==-1){
					if(vnt==-1) valid=false;	
				}
				
			}	
			
			if(!valid) break;
		}
		
		if(valid){ //整合性があるので解の候補に入れる
			//printf("%d valid\n", i);
			int tmpnums=0;
			for(int j=0; j<n; ++j){
				if(i>>j & 1) tmpnums++;
			}	
		
			//人数が多いのでこちらが良い
			if(tmpnums > nums){
				nums = tmpnums;
				tmpnums=0;
			
				for(int j=0; j<n; ++j){
					if(i>>j & 1){
						ans[tmpnums++] = s[j];
					}
				}	
			
			}
			else if(tmpnums == nums){
				int a=0;
				string tmp[20];
			
				for(int j=0; j<n; ++j){
					if(i>>j & 1){
						tmp[a++] = s[j];
					}
				}	
				
				int change=0;
				for(int j=0; j<nums; ++j){
					if(ans[j] < tmp[j]) change=1;
					else if(ans[j] > tmp[j]) change=-1;
					
					if(change!=0) break;
				}			
				
				if(change==-1){
					for(int j=0; j<nums; ++j) ans[j]=tmp[j];			
				}
				
			}
			
		}
			
	}
	
	if(nums==0) printf("No answers\n");
	else{
		for(int i=0; i<nums; ++i) cout << ans[i] << endl;	
	}
	
}