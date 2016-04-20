#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

class SubdividedSlimes {
    public:
    int needCut(int S, int M){
      int i,j;

      int lim=0;
      rep(i,S) lim+=i;

      //このサイズで得られる点数上限を超えている
      if(lim<M) return -1;

      int ans=0;
      for(i=1;i<=S;++i){//i回の分割に対してベストな方法
        vector<long> ends(i);
        rep(j,i) ends[j]=S/i;
        rep(j,S%i) ++ends[j];

        //printf("start %d\n",i);
        priority_queue<long,vector<long>,greater<long>> minpq;
        rep(j,i) minpq.push(ends[j]);

        long sc=0;
        while(minpq.size()>1){
          long x=minpq.top(); minpq.pop();
          long y=minpq.top(); minpq.pop();
          //printf("merge %ld %ld makes %ld\n",x,y,x*y);
          sc+=x*y;
          minpq.push(x+y);
        }

        if(sc>=M){
          ans=i-1;
          break;
        }
      }


      return ans;
    }
};

// CUT begin
ifstream data("SubdividedSlimes.sample");

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

bool do_test(int S, int M, int __expected) {
    time_t startClock = clock();
    SubdividedSlimes *instance = new SubdividedSlimes();
    int __result = instance->needCut(S, M);
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
        int S;
        from_stream(S);
        int M;
        from_stream(M);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(S, M, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1456913228;
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
        cout << "SubdividedSlimes (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
