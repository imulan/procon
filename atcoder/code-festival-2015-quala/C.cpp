#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main(){
	int n, t;
	cin >> n >> t;
	
	vector< pair<int,int> > p(n);
	
	int min=0, max=0;
	for(int i=0; i<n; ++i){
		int a, b;
		scanf(" %d %d", &a, &b);
		p[i] = make_pair(a-b,a);
		
		max+=a;
		min+=b;
	}	
	
	//printf("min = %d, max= %d\n", min ,max);
	
	sort(p.begin(), p.end());
	/*
	for(int i=0; i<n; ++i){
		printf(" %d :  (%d , %d)\n", i, p[i].first, p[i].second);		
	}
	*/
	
	int ans=0;
	
	if(min>t) ans=-1;
	else{
		for(int i=n-1; i>=0; --i){
			if(max>t){
				++ans;
				max -= p[i].first;	
			}
			else break;
		}
	}
	printf("%d\n", ans);
}