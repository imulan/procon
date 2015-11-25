#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main(){
	string s;
	cin >> s;
	int a[6]={0};
	for(int i=0; i<s.size(); ++i) a[s[i]-'A']++;	
	
	for(int i=0; i<6; ++i){
		printf("%d", a[i]);
		if(i<5) printf(" ");	
	}
	printf("\n");
}