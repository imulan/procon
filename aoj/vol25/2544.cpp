#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	int n, q;
	int year[51];
	string name[51];
	
	year[0]=1;
	name[0]="kogakubu10gokan";
	
	scanf(" %d %d", &n, &q);
	for(int i=1; i<=n; ++i) cin >> year[i] >> name[i];
	
	bool st=true;
	for(int i=0; i<n; ++i){
			if(year[i+1]>q){
				st=false;
				cout<<name[i]<<endl;
				break;	
			}
	}
	
	if(st) cout<<name[n]<<endl;
}