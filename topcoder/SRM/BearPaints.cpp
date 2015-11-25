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

class BearPaints {
	public:
	long long maxArea(int W, int H, long long M) {
		ll a=min(W,H);
		ll b=max(W,H);
		ll ret=0;
		for(int i=1; i<=a; ++i){
			ll mul=min(b,M/i);
			ret = max(ret,mul*i);
		}
		return ret;
	}


};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
