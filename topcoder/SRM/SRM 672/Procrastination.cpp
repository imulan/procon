#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

class Procrastination {
    public:
    //nの約数を返す
    vector<ll> factor(ll n){
      vector<ll> ret;
      ret.pb(1);
      for(ll i=2; i*i<=n; ++i){
        if(n%i==0) ret.pb(i);
      }

      int z=ret.size();
      for(int i=z-1; i>=0; --i) ret.pb(n/ret[i]);

      sort(ret.begin(),ret.end());
      ret.erase(unique(ret.begin(),ret.end()),ret.end());
      return ret;
    }

    long long findFinalAssignee(long long n) {
      if(n<=3) return n;

      //現在そのタスクを抱えている従業員
      ll ret=n;

      ll h=2;
      map<ll,vector<ll>> m;

      ll ct=0;
      while(h*2<=ret){
        vector<ll> now;
        vector<ll> pre;

        if(m.find(ret)==m.end()) now=m[ret]=factor(ret);
        else now=m[ret];

        if(m.find(ret-1)==m.end()) pre=m[ret-1]=factor(ret-1);
        else pre=m[ret-1];

        ll a = *lower_bound(now.begin(),now.end(),h);
        ll b = *lower_bound(pre.begin(),pre.end(),h);

        if(a<b){
          ++ret;
          h=a+1;
        }
        else{
          --ret;
          h=b+1;
        }

        //printf("ret= %lld, h= %lld\n",ret, h);
        //printf("a,b :%lld %lld\n",a,b);
      }

      return ret;
    }
};

// CUT begin
ifstream data("Procrastination.sample");

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

bool do_test(long long n, long long __expected) {
    time_t startClock = clock();
    Procrastination *instance = new Procrastination();
    long long __result = instance->findFinalAssignee(n);
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
        long long n;
        from_stream(n);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1456396245;
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
        cout << "Procrastination (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
