#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
using namespace std;

typedef long long ll;
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

class SetPartialOrder {
	public:
	string compareSets(vector <int> a, vector <int> b) {
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		string ans="INCOMPARABLE";

		if(a.size()<b.size()){
			int ap=0;
			for(int i=0; i<b.size(); ++i)
				if(b[i]==a[ap]) ap++;

			if(ap==a.size()) ans="LESS";
		}
		else if(a.size()>b.size()){
			int bp=0;
			for(int i=0; i<a.size(); ++i)
				if(a[i]==b[bp]) bp++;

			if(bp==b.size()) ans="GREATER";
		}
		else{
			bool equal=true;
			for(int i=0; i<a.size(); ++i){
				if(a[i]!=b[i]){
					equal=false;
					break;
				}
			}
			if(equal) ans="EQUAL";
		}

		return ans;
	}


};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
