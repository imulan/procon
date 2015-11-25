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

class LiveConcert {
	public:
	int maxHappiness(vector <int> h, vector <string> s) {
		map<string, int> mp;

		for(int i=0; i<h.size(); ++i){
			if(mp.find(s[i])==mp.end()){
				mp[s[i]]=h[i];
			}
			else mp[s[i]] = max(mp[s[i]], h[i]);
		}

		int ret=0;
		foreach(it,mp) ret+=it->second;
		return ret;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10,5,6,7,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ciel","bessie","john","bessie","bessie","john"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 23; verify_case(0, Arg2, maxHappiness(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,3,4,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a","a","a","a","a"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, maxHappiness(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a","b","c","d","e","e","d","c","b","a","abcde"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 140; verify_case(2, Arg2, maxHappiness(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"oyusop"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; verify_case(3, Arg2, maxHappiness(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {100,100,100,100,100,100,100,100,100,100,100,100,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"haruka","chihaya","yayoi","iori","yukiho","makoto","ami","mami","azusa","miki","hibiki","takane","ritsuko"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1300; verify_case(4, Arg2, maxHappiness(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	LiveConcert ___test;
	___test.run_test(-1);
}
// END CUT HERE
