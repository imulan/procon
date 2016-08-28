#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

class ProblemSets {
    public:
    long long maxSets(long long E, long long EM, long long M, long long MH, long long H) {
        ll l=0, r=2*1000000000000000000LL;

        while(r-l>1)
        {
            ll m=(l+r)/2;
            bool valid=true;

            ll easy=E;
            ll middle=M;
            ll hard=H;

            if(easy<m)
            {
                if(easy+EM<m) valid=false;
                else middle+=EM-(m-easy);
            }
            else middle+=EM;

            if(hard<m)
            {
                if(hard+MH<m) valid=false;
                else middle+=MH-(m-hard);
            }
            else middle+=MH;

            if(middle<m) valid=false;

            if(valid) l=m;
            else r=m;
        }

        return l;
    }
};

// CUT begin
ifstream data("ProblemSets.sample");

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

bool do_test(long long E, long long EM, long long M, long long MH, long long H, long long __expected) {
    time_t startClock = clock();
    ProblemSets *instance = new ProblemSets();
    long long __result = instance->maxSets(E, EM, M, MH, H);
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
        long long E;
        from_stream(E);
        long long EM;
        from_stream(EM);
        long long M;
        from_stream(M);
        long long MH;
        from_stream(MH);
        long long H;
        from_stream(H);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(E, EM, M, MH, H, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1472375886;
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
        cout << "ProblemSets (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
