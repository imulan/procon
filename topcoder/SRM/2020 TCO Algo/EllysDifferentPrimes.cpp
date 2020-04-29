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

class EllysDifferentPrimes {
   public:
    static const int N = 51000000;
    bool prime[N];
    vector<int> a;

    bool diff(int x) {
        int ct[10] = {};
        while (x > 0) {
            ++ct[x % 10];
            x /= 10;
        }
        rep(i, 10) if (ct[i] > 1) return false;
        return true;
    }

    int getClosest(int n) {
        fill(prime, prime + N, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i < N; ++i) {
            if (prime[i]) {
                for (int j = 2 * i; j < N; j += i) prime[j] = false;
            }
        }
        rep(i, N) if (prime[i] && diff(i)) { a.pb(i); }

        auto itr = lower_bound(all(a), n);
        int ans = *itr;
        if (itr != a.begin()) {
            --itr;
            int t = abs(n - *itr);
            if (t <= abs(n - ans)) ans = *itr;
        }
        return ans;
    }
};

// CUT begin
ifstream data("EllysDifferentPrimes.sample");

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

bool do_test(int N, int __expected) {
    time_t startClock = clock();
    EllysDifferentPrimes *instance = new EllysDifferentPrimes();
    int __result = instance->getClosest(N);
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
        int N;
        from_stream(N);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(N, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl
             << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1588073133;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs"
             << endl;
        cout << "Score  : "
             << 900 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))
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
        cout << "EllysDifferentPrimes (900 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
