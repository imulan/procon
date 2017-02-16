#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const double PI = acos(-1);
const double eps = 1e-10;

class TrianglesContainOrigin {
    public:
    long long count(vector<int> x, vector<int> y) {
        int n = x.size();

        vector<double> ang(3*n);
        rep(i,n)
        {
            ang[i] = atan2(y[i],x[i]);
            ang[n+i] = ang[i] + 2*PI;
            ang[2*n+i] = ang[i] + 4*PI;
        }
        sort(all(ang));

        ll ret = 0;

        rep(i,n)rep(j,i)
        {
            double l1 = ang[i];
            double r1 = l1 + PI;
            double l2 = ang[j];
            double r2 = l2 + PI;

            for(int k=-1; k<=1; ++k)
            {
                if(l1 < ang[j]+k*2*PI && ang[j]+k*2*PI < r1)
                {
                    l1 += PI;
                    r1 += PI;
                    break;
                }
            }

            for(int k=-1; k<=1; ++k)
            {
                if(l2 < ang[i]+k*2*PI && ang[i]+k*2*PI < r2)
                {
                    l2 += PI;
                    r2 += PI;
                    break;
                }
            }

            if(fabs(l1-l2)>PI)
            {
                if(l1>l2)
                {
                    l2 += 2*PI;
                    r2 += 2*PI;
                }
                else
                {
                    l1 += 2*PI;
                    r1 += 2*PI;
                }
            }

            double L = max(l1,l2), R = min(r1,r2);
            ret += lower_bound(all(ang),R) - lower_bound(all(ang),L);
        }

        return ret/3;
    }
};

// CUT begin
ifstream data("TrianglesContainOrigin.sample");

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

bool do_test(vector<int> x, vector<int> y, long long __expected) {
    time_t startClock = clock();
    TrianglesContainOrigin *instance = new TrianglesContainOrigin();
    long long __result = instance->count(x, y);
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
        vector<int> x;
        from_stream(x);
        vector<int> y;
        from_stream(y);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(x, y, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1487255398;
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
        cout << "TrianglesContainOrigin (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
