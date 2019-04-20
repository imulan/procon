#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const double EPS = 1e-7;

const ll M = 101000000;
// const ll M = 8500;

class EllysTicketPrices {
    public:
    ll calc(ll p, int c){
        ll x = p*(100+c);
        x *= 10;
        x /= 100;

        int b = x%10;
        x /= 10;
        if(b>=5) ++x;
        return x;
    }

    double getPrice(int N, vector<int> C, int target) {
        ll T = target;
        T *= 100*N;

        // dbg(T);
        auto f = [&](int s){
            vector<ll> p(N);
            p[0] = s;
            for(int i=1; i<N; ++i) p[i] = calc(p[i-1], C[i-1]);

            ll sp = 0;
            rep(i,N) sp += p[i];
            return sp;
        };

        int ng = 0, ok = M;
        while(ok-ng>1){
            int mid = (ng+ok)/2;

            if(f(mid) >= T) ok = mid;
            else ng = mid;
        }

        dbg(ok);
        for(int i=-10; i<=10; ++i){
            int a = ok+i;
            if(a<0) continue;

            double vv = f(a)*1.0/N;
            vv = round(vv);
            if(abs(vv-target*100)<EPS){
                dbg(a);
                return a/100.0;
            }
        }
        return -1;
    }
};

// CUT begin
ifstream data("EllysTicketPrices.sample");

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

bool double_equal(const double &a, const double &b) { return b==b && a==a && fabs(b - a) <= 1e-9 * max(1.0, fabs(a) ); }

bool do_test(int N, vector<int> C, int target, double __expected) {
    time_t startClock = clock();
    EllysTicketPrices *instance = new EllysTicketPrices();
    double __result = instance->getPrice(N, C, target);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (double_equal(__expected, __result)) {
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
        int N;
        from_stream(N);
        vector<int> C;
        from_stream(C);
        int target;
        from_stream(target);
        next_line();
        double __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, C, target, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1555777403;
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
        cout << "EllysTicketPrices (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
