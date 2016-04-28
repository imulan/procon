#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(){
	string a[]={"apple", "peach"};
	string s;
	
	getline(cin, s);
	for(int i=0; i<s.size()-4; ++i){
		if(s.substr(i,5)==a[0]){
			for(int j=0; j<5; ++j) s[i+j]=a[1][j];	
			i+=4;
		}
		if(s.substr(i,5)==a[1]){
			for(int j=0; j<5; ++j) s[i+j]=a[0][j];	
			i+=4;
		}
	}
	
	cout << s <<endl;
	return 0;
}