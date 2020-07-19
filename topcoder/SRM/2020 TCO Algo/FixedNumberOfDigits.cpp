// clang-format off
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}
// clang-format on

class FixedNumberOfDigits {
   public:
    int digit(ll x) {
        int ct = 1;
        while (x >= 10) {
            x /= 10;
            ++ct;
        }
        return ct;
    }

    ll pw(ll x, ll n) {
        ll ret = 1;
        rep(i, n) ret *= x;
        return ret;
    }

    ll ans(ll x, ll t) {
        string s = to_string(x);
        return stoll(s.substr(0, t));
    }

    long long sum(int start, int step, long long numberOfDigits) {
        ll now = start;
        int d = digit(start);
        for (int i = d; i <= 18; ++i) {
            ll Y = pw(10, i);
            ll X = (Y - now - 1) / step;

            ll w = (X + 1) * i;

            if (numberOfDigits - w > 0) {
                numberOfDigits -= w;
                now += (X + 1) * step;
            } else {
                ll L = (numberOfDigits - 1) / i;
                numberOfDigits -= L * i;
                now += L * step;
                return ans(now, numberOfDigits);
            }
        }
        return 0;
    }
};

// CUT begin
ifstream data("FixedNumberOfDigits.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T>
void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) { s = next_line(); }

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) { return "\"" + t + "\""; }

bool do_test(int start, int step, long long numberOfDigits,
             long long __expected) {
    time_t startClock = clock();
    FixedNumberOfDigits *instance = new FixedNumberOfDigits();
    long long __result = instance->sum(start, step, numberOfDigits);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!"
             << " (" << elapsed << " seconds)" << endl;
        return true;
    } else {
        cout << "FAILED!"
             << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0) break;
        int start;
        from_stream(start);
        int step;
        from_stream(step);
        long long numberOfDigits;
        from_stream(numberOfDigits);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(start, step, numberOfDigits, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl
             << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1595088306;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs"
             << endl;
        cout << "Score  : "
             << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))
             << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if (string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "FixedNumberOfDigits (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
