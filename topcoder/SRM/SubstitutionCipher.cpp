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

class SubstitutionCipher {
	public:
	string decode(string a, string b, string y) {
		char p[27];
		for(int i=0; i<26; ++i) p[i]='?';

		int count=0;
		bool ac[26],bc[26];
		fill(ac,ac+26,false);
		fill(bc,bc+26,false);

		for(int i=0; i<b.size(); ++i){
			if(!bc[b[i]-'A']){
				p[b[i]-'A']=a[i];
				ac[a[i]-'A']=true;
				bc[b[i]-'A']=true;
				count++;
			}
		}

		if(count==25){ //後1文字なので自動的に決定
			int anot=-1, bnot=-1;
			for(int i=0; i<26; ++i){
				if(!ac[i]) anot=i;
				if(!bc[i]) bnot=i;
			}
			p[bnot]=anot+'A';
		}

		string x="";
		for(int i=0; i<y.size(); ++i){
			if(p[y[i]-'A']=='?'){
				x="";
				break;
			}
			x=x+p[y[i]-'A'];
		}
		return x;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "CAT"; string Arg1 = "DOG"; string Arg2 = "GOD"; string Arg3 = "TAC"; verify_case(0, Arg3, decode(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "BANANA"; string Arg1 = "METETE"; string Arg2 = "TEMP"; string Arg3 = ""; verify_case(1, Arg3, decode(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "THEQUICKBROWNFOXJUMPSOVERTHELAZYHOG"; string Arg1 = "UIFRVJDLCSPXOGPYKVNQTPWFSUIFMBAZIPH"; string Arg2 = "DIDYOUNOTICESKIPPEDLETTER"; string Arg3 = "CHCXNTMNSHBDRJHOODCKDSSDQ"; verify_case(2, Arg3, decode(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	SubstitutionCipher ___test;
	___test.run_test(-1);
}
// END CUT HERE
