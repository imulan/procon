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

const int A = 100;
int a[A];
bool one = true;

class DivisorSequences {
    public:

    void dfs(int now, int sum, int ct){
        if(sum>=A) return;
        if(a[sum] < ct){
            a[sum] = ct;
            if(!one){
                // dbg(sum);dbg(ct);
            }
        }
        for(int i=2; i<A; ++i){
            dfs(now*i, sum+now*i, ct+1);
        }
    }

    void dfs2(int now, int sum, vector<int> v){
        if(sum>=A) return;
        if(a[sum] == v.size()){
            printf(" %d: ", sum);dbg(v);
        }
        for(int i=2; i<A; ++i){
            vector<int> nv(v);
            nv.pb(now*i);
            dfs2(now*i, sum+now*i, nv);
        }
    }

    void test(){

        dfs(1,1,1);

        one = false;
        for(int i=2; i<A; ++i){
            dfs(i,i,1);
        }


        for(int i=1; i<A; ++i){
            dfs2(i,i,vector<int>({i}));
        }
    }

    vector<int> divisor(int n){
        vector<int> ret;
        for(int i=1; i*i<=n; ++i){
            if(n%i==0){
                ret.pb(i);
                if(n/i != i) ret.pb(n/i);
            }
        }
        sort(all(ret));
        return ret;
    }

    int longest(int N) {
        // test();
        int ans = 1;
        for(int x:divisor(N)){
            dbg(x);
            int ct = 1;
            ll r = N-x;
            ll c = x;
            while(r>0){
                dbg(c);
                ll nx;
                bool ok = true;
                for(int i=2; i<N; ++i){
                    if(r%(c*i) == 0){
                        nx = c*i;

                        if(r-nx < nx){
                            ok = false;
                        }
                        break;
                    }
                }
                if(!ok) break;
                ++ct;
                r -= nx;
                c = nx;
            }
            ans = max(ans, ct);
        }

        return ans;
    }
};

// CUT begin
ifstream data("DivisorSequences.sample");

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

bool do_test(int N, int __expected) {
    time_t startClock = clock();
    DivisorSequences *instance = new DivisorSequences();
    int __result = instance->longest(N);
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
        int N;
        from_stream(N);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1559662334;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "DivisorSequences (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
