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

typedef pair<ll,ll> pl;
typedef pair<ll,pl> pl1;
typedef pair<pl,ll> pl2;

class SettingShield {
    public:
    long long getOptimalCost(int n, int h, int t, vector<int> val0, vector<int> a, vector<int> b, vector<int> m) {
		vector<ll> protection(n);
		vector<ll> left(n);
		vector<ll> right(n);
		protection[0]=val0[0];
		for(int i=1; i<n; ++i) protection[i]=(a[0]*protection[i-1]+b[0])%m[0];
		left[0]=val0[1];
		right[0]=val0[2];
		for(int i=1; i<h; ++i)
		{
			left[i]=min(n-1,(a[1]*left[i-1]+b[1])%m[1]);
			ll dist=right[i-1]-left[i-1];
			right[i]=min(n-1,left[i]+(a[2]*dist+b[2])%m[2]);
		}

		ll r1=0, r2=0;

		//specialを使う場合
		ll m=0;
		rep(i,n) m=max(m,protection[i]);
		r1=m*t;

		//使わない場合
		vector<ll> p(n,0);

		vector<pl2> d(n);
		rep(i,n) d[i]=pl2(pl(left[i],right[i]),protection[i]);
		sort(all(d));

		vector<pl1> e(n);
		rep(i,n) e[i]=pl1(d[i].se,d[i].fi);

		priority_queue<pl1> pq;
		int now=0;
		int ct=0;
		while(ct<n && e[ct].se.fi==0) pq.push(e[ct++]);

		while(!pq.empty())
		{
			pl1 vp=pq.top();
			pq.pop();
			for(ll i=vp.se.fi; i<=vp.se.se; ++i) p[i]+=vp.fi;

			while(p[now]>=protection[now]) ++now;

			while(ct<n && e[ct].se.fi==0) pq.push(e[ct++]);
			++now;

		}


        return ret;
    }
};

// CUT begin
ifstream data("SettingShield.sample");

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

bool do_test(int n, int h, int t, vector<int> val0, vector<int> a, vector<int> b, vector<int> m, long long __expected) {
    time_t startClock = clock();
    SettingShield *instance = new SettingShield();
    long long __result = instance->getOptimalCost(n, h, t, val0, a, b, m);
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
        int n;
        from_stream(n);
        int h;
        from_stream(h);
        int t;
        from_stream(t);
        vector<int> val0;
        from_stream(val0);
        vector<int> a;
        from_stream(a);
        vector<int> b;
        from_stream(b);
        vector<int> m;
        from_stream(m);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, h, t, val0, a, b, m, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1460475765;
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
        cout << "SettingShield (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
