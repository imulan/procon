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

class GreaterGame {
    public:
    double calc(vector<int> hand, vector<int> sothe) {
        int n = hand.size();
        sort(all(hand));

        vector<int> op;
        rep(i,n)if(sothe[i]!=-1) op.pb(sothe[i]);
        sort(all(op));

        vector<bool> use(2*n+1,false);
        rep(i,n) use[hand[i]]=true;
        rep(i,op.size()) use[op[i]]=true;

        vector<int> un;
        for(int i=1; i<=2*n; ++i)if(!use[i]) un.pb(i);

        double ret = 0;
        vector<bool> h_use(n,false);
        for(const auto &x:op)
        {
            int j = 0;
            while(j<n)
            {
                if(!h_use[j] && hand[j]>x) break;
                ++j;
            }

            if(j==n)
            {
                j=0;
                while(j<n && h_use[j]) ++j;
                h_use[j]=true;
            }
            else
            {
                h_use[j]=true;
                ret += 1;
            }
        }

        int UN = un.size();
        for(const auto &x:un)
        {
            rep(i,n)if(!h_use[i])
            {
                if(hand[i]>x) ret+=1.0/UN;
            }
        }

        return ret;
    }
};

// CUT begin
ifstream data("GreaterGame.sample");

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

bool do_test(vector<int> hand, vector<int> sothe, double __expected) {
    time_t startClock = clock();
    GreaterGame *instance = new GreaterGame();
    double __result = instance->calc(hand, sothe);
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
        vector<int> hand;
        from_stream(hand);
        vector<int> sothe;
        from_stream(sothe);
        next_line();
        double __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(hand, sothe, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1498488991;
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
        cout << "GreaterGame (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
