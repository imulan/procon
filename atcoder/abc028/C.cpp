#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
using namespace std;

int main(){
	int a[5];
	for(int i=0; i<5; ++i) scanf(" %d", &a[i]);
	
	set<int> ss;
	ss.insert(a[0]+a[1]+a[2]);
	ss.insert(a[0]+a[1]+a[3]);
	ss.insert(a[0]+a[1]+a[4]);
	ss.insert(a[0]+a[2]+a[3]);
	ss.insert(a[0]+a[2]+a[4]);
	ss.insert(a[0]+a[3]+a[4]);
	ss.insert(a[1]+a[2]+a[3]);
	ss.insert(a[1]+a[2]+a[4]);
	ss.insert(a[1]+a[3]+a[4]);
	ss.insert(a[2]+a[3]+a[4]);
	
	int ct=0;
	int ans;
	for(set<int>::iterator it=ss.end(); it!=ss.begin(); it--){
		ans=*it;
		//printf(" %d\n", ans);
		ct++;
		if(ct==4) break;
	}
	
	printf("%d\n", ans);
}