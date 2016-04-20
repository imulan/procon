#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)
#define fi first
#define se second

class Autogame {
    public:
	//sをスタート地点としてkターン後にどこにいるか
	int dest(const vector<int> &a, int k, int s)
	{
		int n=a.size();
		int ret=-1;

		//訪問したタイミング
		vector<int> vis(n+1,-1);
		//訪問したルートを保存
		vector<int> r;

		vis[s]=0;
		r.pb(s);
		int now=a[s];
		int ct=1;
		while(vis[now]==-1)
		{
			vis[now]=ct++;
			r.pb(now);
			now=a[now];
		}

		if(k<vis[now])
		{//サイクルに入る前にkターン終了
			ret=r[k];
		}
		else
		{
			int b=vis[now];
			int cycle=ct-vis[now];

			ret=r[b+(k-b)%cycle];
		}

		return ret;
	}

    int wayscnt(vector<int> a, int K) {
		int n=a.size();

		a.insert(a.begin(),0);

		int ct[51]={0};
		for(int i=1; i<=n; ++i) ++ct[dest(a,K,i)];

		long ret=1;
		long mod=1e9+7;
		for(int i=1; i<=n; ++i)
		{
			ret*=ct[i]+1;
			ret%=mod;
		}

		return (int)ret;
    }
};

// CUT begin
ifstream data("Autogame.sample");

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

bool do_test(vector<int> a, int K, int __expected) {
    time_t startClock = clock();
    Autogame *instance = new Autogame();
    int __result = instance->wayscnt(a, K);
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
        vector<int> a;
        from_stream(a);
        int K;
        from_stream(K);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(a, K, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1458956744;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "Autogame (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
