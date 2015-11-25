#include <algorithm> //sort
#include <cstdio>
#include <iostream>
#include <map>
#include <utility> //pair
#include <vector>
using namespace std;

int main(){
	long n;
	scanf(" %ld", &n);
	
	vector< pair<long,int> > p(n);
	map<long, long> leg;
	
	for(long i=0; i<n; ++i){
		scanf(" %ld", &p[i].first);
		
		if(leg.find(p[i].first)==leg.end()) leg[p[i].first]=1;
		else leg[p[i].first]++;
	}
	
	for(long i=0; i<n; ++i) scanf(" %d", &p[i].second);
	
	//これではダメ
	long suffixSum[100001]={0}; //i~n-1までの足を全部抜くのに必要なコスト
	for(long i=n-1; i>=0; --i) suffixSum[i]=p[i].second+suffixSum[i+1];		
	
	//firstが小さい順，次いでsecondが小さい順でソート
	sort(p.begin(), p.end());
	
	long ans=2000000000;
	long cnt[201]={0}; //既に見た足のうちコストがiの足の本数 
	
	for(map<long,long>::iterator it=leg.begin(); it!=leg.end(); ++it){
		long maxlen = it->first;	
		long cur=0;
		
		
		
		
		cnt[p[i].second]++;
		if(cur<ans) ans=cur;
	}
	
	printf("%ld\n", ans);
}