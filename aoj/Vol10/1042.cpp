#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	while(getline(cin, s)){
		if(s=="END OF INPUT") break;
		int a=0;
		
		while(a<s.size()){
			int count=0;
			while(a<s.size() && s[a] != ' '){
				++a;
				++count;
			}
			printf("%d", count);
			++a;
		}
		printf("\n");
	}
	return 0;
}