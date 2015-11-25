#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n, r[3000];
	
	cin >> n;
	for(int i=0; i<n; ++i) scanf(" %d", &r[i]);
	
	vector<int> r1,r2;
	//x1 < x2 > x3 < x4 > ...の形
	bool large=true;
	
	int revtmp=0;
	for(int i=0; i<n-1; ++i){
		if(large && r[i]<r[i+1]){
			large=false;
			r1.push_back(r[i]);
		}
		else if(!large && r[i]>r[i+1]){
			large=true;
			r1.push_back(r[i]);
		}		
	} 
	//printf("large ? %d\n", large);
	if(r1.size()!=0){
		if(!large && r1[r1.size()-1]<r[n-1]) r1.push_back(r[n-1]);
		else if(large && r1[r1.size()-1]>r[n-1]) r1.push_back(r[n-1]);
	}
	
	//x1 > x2 < x3 > x4 < ...の形
	large=false;
	for(int i=0; i<n-1; ++i){
		if(large && r[i]<r[i+1]){
			large=false;
			r2.push_back(r[i]);
		}
		else if(!large && r[i]>r[i+1]){
			large=true;
			r2.push_back(r[i]);
		}
	} 
	if(r2.size()!=0){
		if(!large && r2[r2.size()-1]<r[n-1]) r2.push_back(r[n-1]);
		else if(large && r2[r2.size()-1]>r[n-1]) r2.push_back(r[n-1]);
	}
	/*
	for(int i=0; i<r1.size(); ++i){
		printf(" %d: %d\n", i, r1[i]);	
	}
	printf("\n");	
	for(int i=0; i<r2.size(); ++i){
		printf(" %d: %d\n", i, r2[i]);	
	}
	printf("\n");
	*/
	
	int ans=max(r1.size(),r2.size());
	if(ans<3) ans=0;
	printf("%d\n",ans);
}