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

class TheNicePair {
    public:
    int solve(vector<int> A) {
		int n=A.size();

		//全ての要素が1の時には失敗
		bool allone=true;
		rep(i,n) if(A[i]!=1) allone=false;
		if(allone) return -1;

		//素数を列挙
		bool p[1001];
		fill(p,p+1001,true);
		p[0]=p[1]=false;
		for(int i=2; i<=1000; ++i)
		{
			if(p[i]) for(int j=2; i*j<=1000; ++j) p[i*j]=false;
		}
		vector<int> v;
		rep(i,1001) if(p[i]) v.pb(i);

		int ret=0;
		for(const auto &x : v)
		{
			//素数xで割り切れるかを判定していく
			bool into=false;
			vector<bool> d(n);
			rep(i,n)
			{
				d[i]=(A[i]%x==0);
				into|=d[i];
			}

			if(into){
				rep(i,n)
				{
					for(int j=i; j<n; ++j)
					{
						int ct=0;
						int len=j-i+1;
						for(int k=i; k<=j; ++k) if(d[k]) ++ct;
						if(ct*2>=len) ret=max(ret,j-i);
					}
				}
			}
		}

        return ret;
    }
};

// CUT begin
ifstream data("TheNicePair.sample");

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

bool do_test(vector<int> A, int __expected) {
    time_t startClock = clock();
    TheNicePair *instance = new TheNicePair();
    int __result = instance->solve(A);
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
        vector<int> A;
        from_stream(A);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(A, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1460647233;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "TheNicePair (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
