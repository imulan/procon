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

const ll mod = 1e9+7;

const int N = 2002;
ll f[N], inv[N];

ll mod_pow(ll x, ll n){
    ll ret = 1;
    while(n){
        if(n&1) (ret *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return ret;
}

ll mod_inv(ll x){
    return mod_pow(x,mod-2);
}


ll C(int n, int x){
    if(n<0 || x<0 || n-x<0) return 0;
    ll ret = f[n];
    (ret *= inv[x]) %= mod;
    (ret *= inv[n-x]) %= mod;
    return ret;
}


class FamilySeatingArrangement {
    public:
    int countWays(vector<int> a, int k) {
        f[0] = 1;
        for(int i=1; i<N; ++i) f[i] = (f[i-1]*i)%mod;
        rep(i,N) inv[i] = mod_inv(f[i]);

        int n = a.size();

        ll ans = 0;
        for(int i=1; i<=k; ++i){
            ll m = 0;
            int mul = 1;

            for(int j=i; j>0; --j){
                ll add = C(i,j)*mod_pow(j,n);
                add %= mod;
                add = (add*mul+mod)%mod;

                (m += add) %= mod;

                mul *= -1;
            }

            rep(j,n){
                ll z = mod_pow(k-i+1, a[j]);
                m *= z;
                m %= mod;
            }

            ll t = m;
            (t *= C(k,i)) %= mod;

            // if(i<=20) printf(" %d: %lld m %lld\n",i,t, m);

            (ans += t) %= mod;
        }

        return (int)ans;
    }
};

// CUT begin
ifstream data("FamilySeatingArrangement.sample");

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

bool do_test(vector<int> a, int k, int __expected) {
    time_t startClock = clock();
    FamilySeatingArrangement *instance = new FamilySeatingArrangement();
    int __result = instance->countWays(a, k);
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
        int k;
        from_stream(k);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(a, k, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1562429110;
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
        cout << "FamilySeatingArrangement (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
