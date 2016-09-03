#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	string ans;
	if(n==100) ans="Perfect";
	else if(n>=90) ans="Great";
	else if(n>=60) ans="Good";
	else ans="Bad";
	
	cout << ans <<endl;
}