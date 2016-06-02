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

class Undiv2 {
    public:
    inline ll lcm(ll x, ll y)
    {
        return x*y/__gcd(x,y);
    }

    pl s(ll x)
    {
        pl ret;
        int ct=0;
        for(ll i=1; i<=x+2; ++i)
        {
            if(x%i!=0)
            {
                if(ct==0) ret.fi=i;
                else
                {
                    ret.se=i;
                    return ret;
                }

                ++ct;
            }
        }
    }

    long long getsum(int n) {
        set<ll> f;
        queue<ll> que;
        que.push(1);
        while(!que.empty())
        {
            ll v=que.front();
            que.pop();

            if(v>n) continue;
            if(f.find(v)!=f.end()) continue;

            f.insert(v);

            pl S=s(v);
            que.push(lcm(v,S.fi));
            que.push(lcm(v,S.se));
        }

        vector<pl> d;
        for(const auto &x:f) d.pb(pl(x,s(x).se));

        sort(all(d));
        rep(i,d.size())for(int j=i+1; j<d.size(); ++j)
        {
            if(d[j].fi%d[i].fi==0) d[j].se-=d[i].se;
        }

        ll ans=0;
        rep(i,d.size()) ans+=(n/d[i].fi)*d[i].se;

        return ans;
    }
};

// CUT begin
ifstream data("Undiv2.sample");

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

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int n, long long __expected) {
    time_t startClock = clock();
    Undiv2 *instance = new Undiv2();
    long long __result = instance->getsum(n);
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
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1464862933;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 900 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "Undiv2 (900 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
