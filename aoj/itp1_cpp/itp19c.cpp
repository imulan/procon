#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(){
	int n, taro=0, hana=0;

	cin >> n;
	for(int i=0; i<n; ++i){
		string s1, s2;
		cin >> s1 >> s2;
		
		if(s1>s2) 
			taro+=3;
		else if(s1<s2)
			hana+=3;
		else{
			++taro;
			++hana;
		}
		
	}
	printf("%d %d\n", taro, hana); 	
	
	return 0;
}