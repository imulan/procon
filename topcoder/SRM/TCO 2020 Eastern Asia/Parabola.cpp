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

const int LIM = 1e9 + 7;
const ll INF = LLONG_MAX / 3;

class Parabola {
   public:
    vector<int> estimate(vector<int> Y) {
        int n = Y.size();

        ll best = INF;
        vector<int> ret;

        for (int a = 1; a <= 50; ++a) {
            for (int b = -50; b <= 50; ++b) {
                auto f = [&](int c) {
                    ll xx = 0;
                    rep(i, n) {
                        ll x = i;
                        ll val = x * x * a + x * b + c;
                        xx += abs(val - Y[i]);
                    }
                    return xx;
                };

                int L = -LIM, R = LIM;
                while (R - L > 8) {
                    int m1 = (2 * L + R) / 3;
                    int m2 = (L + 2 * R) / 3;
                    if (f(m1) <= f(m2))
                        R = m2;
                    else
                        L = m1;
                }

                ll res = INF;
                int bestc = L;
                for (int c = L; c <= R; ++c) {
                    ll v = f(c);
                    if (v < res) {
                        res = v;
                        bestc = c;
                    }
                }

                if (res < best) {
                    best = res;
                    ret = vector<int>({a, b, bestc});
                }
            }
        }

        return ret;
    }
};

// CUT begin
ifstream data("Parabola.sample");

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
void from_stream(vector<T> &ts) {
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

string to_string(string t) { return "\"" + t + "\""; }

template <typename T>
string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(vector<int> Y, vector<int> __expected) {
    time_t startClock = clock();
    Parabola *instance = new Parabola();
    vector<int> __result = instance->estimate(Y);
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
        vector<int> Y;
        from_stream(Y);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(Y, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl
             << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1601097130;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs"
             << endl;
        cout << "Score  : "
             << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))
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
        cout << "Parabola (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
