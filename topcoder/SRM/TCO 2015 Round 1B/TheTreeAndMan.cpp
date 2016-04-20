#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

class TheTreeAndMan {
    public:

	const long mod=1e9+7;

	//グラフ
	vector<int> G[2000];
	//その頂点から到達可能な頂点数(自身も含む)
	int reach[2000];

	long dp[2000][3];
	//xをManのp(頭、首、腰)にする方法
	long rec(int x, int p)
	{
		if(dp[x][p]>=0) return dp[x][p];

		long ret=0;
		if(p==0)
		{
			//首の位置を探す
			rep(i,G[x].size()) ret=(ret+rec(G[x][i],1))%mod;
		}
		else if(p==1)
		{
			//手を2箇所と腰を1箇所選ぶ
			rep(i,G[x].size())rep(j,G[x].size())rep(k,j)
			{
				if(i==j || i==k) continue;

				long add=reach[G[x][j]]*reach[G[x][k]];
				add%=mod;
				add*=rec(G[x][i],2);
				add%=mod;

				ret+=add;
				ret%=mod;
			}
		}
		else if(p==2)
		{
			//足を2箇所選ぶ
			rep(i,G[x].size())rep(j,i)
			{
				ret+=reach[G[x][i]]*reach[G[x][j]];
				ret%=mod;
			}
		}

		return dp[x][p]=ret;
	}

    int solve(vector<int> parent) {
		//頂点数
		int n=parent.size()+1;

		//有向辺を張る
		rep(i,parent.size()) G[parent[i]].pb(i+1);

		memset(reach,-1,sizeof(reach));
		//頂点iから到達可能な頂点数を計算
		for(int i=n-1; i>=0; --i)
		{
			//まず自分自身を計上
			reach[i]=1;
			rep(j,G[i].size()) reach[i]+=reach[G[i][j]];
		}

		long ret=0;
		memset(dp,-1,sizeof(dp));

		rep(i,n) ret=(ret+rec(i,0))%mod;

        return (int)ret;
    }
};

// CUT begin
ifstream data("TheTreeAndMan.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<int> parent, int __expected) {
    time_t startClock = clock();
    TheTreeAndMan *instance = new TheTreeAndMan();
    int __result = instance->solve(parent);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<int> parent;
        from_stream(parent);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(parent, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1461063448;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "TheTreeAndMan (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
