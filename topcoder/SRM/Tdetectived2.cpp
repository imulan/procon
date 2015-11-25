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

class Tdetectived2 {
	public:
	int reveal(vector <string> s) {
		int ans[18]={0};
		int n=s.size();
		fill(ans,ans+n,100);

		//BFS
		queue<string> que;
		string start=s[0];
		start[0]='/'; //0番に対するインタビューは終了した
		que.push(start);
		while(!que.empty()){
			string v=que.front(); que.pop();

			//そこまでにインタビューした人数
			int turn=0;
			for(int i=0; i<v.size(); ++i){
				if(v[i]=='/') turn++;
			}
			//cout << v + " turn=" << turn << endl;

			//現時点でのsuspicion levelの最大値
			int sus=0;
			for(int i=0; i<n; ++i){
				sus=max(sus,v[i]-'0');
			}

			for(int i=0; i<n; ++i){
				if(v[i]-'0' == sus){ //i番にインタビュー
					ans[i]=min(ans[i],turn);

					string tmp=v;
					tmp[i]='/';
					//suspicion levelの更新
					for(int j=0; j<n; ++j){
						if(tmp[j]=='/') continue;
						tmp[j] = max(s[i][j]-'0', tmp[j]-'0')+'0';
					}
					que.push(tmp);

					//printf("pushed :: %d\n", i);
				}
			}
		}

		int ret=0;
		for(int i=1; i<n; ++i) ret+=i*ans[i];
		return ret;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"000","000","000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, reveal(Arg0)); }
	void test_case_1() { string Arr0[] = {"0224","2011","2104","4140"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(1, Arg1, reveal(Arg0)); }
	void test_case_2() { string Arr0[] = {"0886","8086","8801","6610"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(2, Arg1, reveal(Arg0)); }
	void test_case_3() { string Arr0[] = {"064675511","603525154","430262731","652030511","726302420","552020464","517544052","153126500","141104200"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 170; verify_case(3, Arg1, reveal(Arg0)); }
	void test_case_4() { string Arr0[] = {"0313131","3030020","1301132","3010031","1010003","3233003","1021330"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 37; verify_case(4, Arg1, reveal(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	Tdetectived2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
