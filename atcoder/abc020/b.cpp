#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
using namespace std;

int main(){
	int a, b;
	scanf(" %d %d", &a, &b);
	
	stringstream ss;
	ss<<a;
	ss<<b;
	
	long t;
	ss>>t;	

	printf("%ld\n", t*2);
}