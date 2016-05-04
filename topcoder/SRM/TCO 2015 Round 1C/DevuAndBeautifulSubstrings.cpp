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

class DevuAndBeautifulSubstrings {
    public:
    int N,CNT;

    ll dp[51][51][2][1276];

    ll rec(int now, int con, int prev, int beauty)
    {
        if(dp[now][con][prev][beauty]>=0)
            return dp[now][con][prev][beauty];

        if(now==N)
        {
            if(beauty==CNT) return 1;
            return 0;
        }

        ll ret=0;
        //prevと同じものを選ぶ
        ret+=rec(now+1,1,prev,beauty+1);
        //prevと違うものを選ぶ
        ret+=rec(now+1,con+1,!prev,beauty+con+1);

        return dp[now][con][prev][beauty]=ret;
    }

    long long countBeautifulSubstrings(int n, int cnt) {
        N=n;
        CNT=cnt;

        memset(dp,-1,sizeof(dp));
        return rec(1,1,0,1)*2;
    }
};

// CUT begin
ifstream data("DevuAndBeautifulSubstrings.sample");

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

bool do_test(int n, int cnt, long long __expected) {
    time_t startClock = clock();
    DevuAndBeautifulSubstrings *instance = new DevuAndBeautifulSubstrings();
    long long __result = instance->countBeautifulSubstrings(n, cnt);
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
        int cnt;
        from_stream(cnt);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, cnt, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1462355265;
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
        cout << "DevuAndBeautifulSubstrings (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
