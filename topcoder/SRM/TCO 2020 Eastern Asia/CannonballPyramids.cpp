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

const vector<int> NG = vector<int>();
const ll LIM = 1e9;

const int N = 1442;

class CannonballPyramids {
   public:
    bool found = false;
    vector<int> p = vector<int>(N);
    vector<int> ans = NG;
    vector<int> v = vector<int>(6, -1);
    int tgt;

    void dfs(int d, int pre, int sum) {
        for (int i = pre; i > 0; --i) {
            int now = sum + p[i];
            if (now > LIM) continue;

            v[d] = i;
            if (now == tgt) {
                vector<int> tt;
                rep(j, d + 1) tt.pb(v[j]);
                ans = tt;
                found = true;
                return;
            }

            if (d < 5) dfs(d + 1, i, now);
            v[d] = -1;
            if (found) return;
        }
    }

    vector<int> build(int B) {
        p[1] = 1;
        for (int i = 2; i < N; ++i) {
            int add = i * i;
            p[i] = p[i - 1] + add;
            if (p[i] > LIM) {
                dbg(i);
                dbg(p[i]);
                break;
            }
        }

        tgt = B;
        dfs(0, N - 1, 0);

        int t = 0;
        for (int i : ans) t += p[i];
        dbg(t);
        dbg(B);

        return ans;
    }
};

// CUT begin
ifstream data("CannonballPyramids.sample");

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

bool do_test(int B, vector<int> __expected) {
    time_t startClock = clock();
    CannonballPyramids *instance = new CannonballPyramids();
    vector<int> __result = instance->build(B);
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
        int B;
        from_stream(B);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(B, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl
             << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1601098738;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs"
             << endl;
        cout << "Score  : "
             << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))
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
        cout << "CannonballPyramids (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
