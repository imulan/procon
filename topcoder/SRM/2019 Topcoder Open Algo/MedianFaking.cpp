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

const int N = 100;
using pi = pair<int,int>;

class MedianFaking {
    public:
    int med(vector<int> v, int n){
        // dbg(v);
        int x = 0;
        rep(i,N){
            rep(j,v[i]){
                ++x;
                if(x==(n+1)/2) return i;
            }
        }
        assert(false);
    }

    vector<int> minimize(int F, int M, vector<int> data, int goal) {
        int n = data.size();

        vector<int> ct(N);
        for(int i:data) ++ct[i];

        int m = med(ct,n);
        if(m == goal) return {0,0};

        bool big = (goal < m);

        vector<pi> p(F);
        rep(i,F){
            int x = 0;
            rep(j,M){
                int t = data[i*M+j];
                if(big){
                    if(t > goal) ++x;
                }
                else{
                    if(t < goal) ++x;
                }
            }
            p[i] = {x,i};
        }
        sort(all(p));
        reverse(all(p));
        // dbg(p);

        int x = 0, y = 0;
        rep(i,F){
            int idx = p[i].se;
            ++x;
            rep(j,M){
                int t = data[idx*M+j];
                if(big){
                    if(t <= goal) continue;
                }
                else{
                    if(t >= goal) continue;
                }

                ++y;
                --ct[t];
                ++ct[goal];
                if(med(ct,n) == goal) return {x,y};
            }
            // dbg(y);
        }

        return vector<int>();
    }
};

// CUT begin
ifstream data("MedianFaking.sample");

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

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(int F, int M, vector<int> data, int goal, vector<int> __expected) {
    time_t startClock = clock();
    MedianFaking *instance = new MedianFaking();
    vector<int> __result = instance->minimize(F, M, data, goal);
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
        int F;
        from_stream(F);
        int M;
        from_stream(M);
        vector<int> data;
        from_stream(data);
        int goal;
        from_stream(goal);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(F, M, data, goal, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1559660412;
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
        cout << "MedianFaking (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
