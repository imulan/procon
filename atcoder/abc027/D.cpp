#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main(){
	string s;
	cin >>s;

	vector<int> v;

	int now=0;
	for(int i=s.size()-1; i>=0; --i){
		if(s[i]=='+') ++now;
		else if(s[i]=='-') --now;
		else v.push_back(now);
	}

	sort(v.begin(), v.end());

	int ans=0;
	for(int i=0; i<v.size()/2; ++i) ans-=v[i];
	for(int i=v.size()/2; i<v.size(); ++i) ans+=v[i];

	printf("%d\n", ans);
}
