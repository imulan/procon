#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

class SquareScores {
    public:
    double dp[1000][1000][26];
    double E[1001][26];

    double calcexpectation(vector<int> p, string s) {
        memset(dp,0,sizeof(dp));
        memset(E,0,sizeof(E));

        int P = p.size();
        int n = s.size();

        rep(i,n)
        {
            if(s[i]=='?')
            {
                rep(j,P) dp[i][i][j]=p[j]/100.0;
            }
            else dp[i][i][s[i]-'a']=1;
        }

        for(int b=1; b<n; ++b)
        {
            rep(i,n-b)
            {
                int j=i+b;
                if(s[j]=='?') rep(k,P) dp[i][j][k]=dp[i][j-1][k]*p[k]/100.0;
                else dp[i][j][s[j]-'a']=dp[i][j-1][s[j]-'a'];
            }
        }

        rep(i,n)
        {
            rep(j,P)
            {
                int L=i+1;
                E[i+1][j] += L * dp[0][i][j];
            }
        }

        for(int i=1; i<n; ++i)
        {
            double sumE=0;
            rep(j,26) sumE+=E[i][j];

            for(int j=i; j<n; ++j)
            {
                int L=j-i+1;
                rep(k,P) E[j+1][k] += (L+sumE-E[i][k]) * dp[i][j][k];
            }
        }

        // rep(i,n+1)rep(j,P) printf("E[%d][%d]= %lf\n", i,j,E[i][j]);

        double ret=0;
        rep(i,P) ret+=E[n][i];
        return ret;
    }
};

// CUT begin
ifstream data("SquareScores.sample");

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

bool do_test(vector<int> p, string s, double __expected) {
    time_t startClock = clock();
    SquareScores *instance = new SquareScores();
    double __result = instance->calcexpectation(p, s);
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
        vector<int> p;
        from_stream(p);
        string s;
        from_stream(s);
        next_line();
        double __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(p, s, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1473136998;
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
        cout << "SquareScores (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
