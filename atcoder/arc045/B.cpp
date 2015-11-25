#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n, m;
	int s[300000], t[300000];
	int room[300002]={0};
	
	cin >> n >> m;
	for(int i=0; i<m; ++i){
		scanf(" %d %d", &s[i], &t[i]);
		room[s[i]]++;
		room[t[i]+1]--;		
	}
	
	for(int i=0; i<=300000; ++i) room[i+1]+=room[i];
	//for(int i=0; i<=30; ++i) printf(" %d :: %d\n",i, room[i]);
	
	//部屋1~iの間でroom[]=1の数を数え上げる
	int ones[300002]={0};
	
	for(int i=0; i<=300000; ++i){
		ones[i+1] = ones[i];
		if(room[i+1]==1) ones[i+1]++; 
		//printf(" ones %d = %d\n", i+1, ones[i+1]); 	
	}
	
	vector<int> ans;
	for(int i=0; i<m; ++i){
		if(ones[t[i]] == ones[s[i]-1]) ans.push_back(i+1);	
	}
	
	cout << ans.size() << endl;
	for(int i=0; i<ans.size(); ++i) printf("%d\n", ans[i]);
}