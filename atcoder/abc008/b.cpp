#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	int n, count = 0, vote[50] = {0};
	string name[50];
	
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		string s;
		cin >> s;
		bool flag = true;
		
		for(int j=0; j<count; ++j){
			if(name[j] == s){
				++vote[j];
				flag = false;
			}
		}
		
		if(flag){
			name[count] = s;	
			vote[count++] = 1;
		}
	}
	
	int max=0;
	string ans;
	for(int i=0; i<count; ++i){
		if(max < vote[i]){
			max = vote[i];
			ans = name[i];
		}
	}	
	
	cout << ans << endl;
	return 0;
}