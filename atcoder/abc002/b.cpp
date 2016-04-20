#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	for(int i=0; i<s.size(); ++i){
		if(s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o');
		else cout << s[i];
	}
	printf("\n");
	
	return 0;
}