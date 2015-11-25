#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

int main(){
	int a[9]={25,39,51,76,163,111,128,133,138};
	int g[3]={0,58,136};
	set<int> ans;
	ans.insert(0);
	
	for(long i=1<<9; i>0; --i){ //正解不正解を全列挙
		int temp=0;
		for(int j=0; j<9; ++j){
			if(1 & (i>>j)) temp+=a[j];	
		}
		
		for(int j=0; j<3; ++j) ans.insert(temp+g[j]);	
	}
		
	for(set<int>::iterator it=ans.begin(); it!=ans.end(); it++) cout << *it << endl;
	
}