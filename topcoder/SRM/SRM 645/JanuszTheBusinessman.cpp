#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

class JanuszTheBusinessman {
    public:
    int makeGuestsReturn(vector<int> arrivals, vector<int> departures) {
        int n=arrivals.size();

        vector<pi> c(n);
        rep(i,n) c[i]=pi(departures[i], arrivals[i]);
        sort(all(c));
        rep(i,n) swap(c[i].fi,c[i].se);

        vector<bool> cover(n,false);

        int ret=0;

        rep(i,n)
        {
            if(cover[i]) continue;

            int idx=i;
            for(int j=n-1; j>=i; --j)
            {
                if(c[j].fi<=c[i].se)
                {
                    idx=j;
                    break;
                }
            }
            // printf("idx = %d\n", idx);
            rep(j,n)
            {
                if(cover[j]) continue;

                if(c[j].se>=c[idx].fi && c[idx].se>=c[j].fi) cover[j]=true;
            }

            ++ret;
        }

        return ret;
    }
};

// CUT begin
ifstream data("JanuszTheBusinessman.sample");

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

bool do_test(vector<int> arrivals, vector<int> departures, int __expected) {
    time_t startClock = clock();
    JanuszTheBusinessman *instance = new JanuszTheBusinessman();
    int __result = instance->makeGuestsReturn(arrivals, departures);
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
        vector<int> arrivals;
        from_stream(arrivals);
        vector<int> departures;
        from_stream(departures);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(arrivals, departures, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1482913462;
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
        cout << "JanuszTheBusinessman (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
