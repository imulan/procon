#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

typedef pair<int,int> pii;

class BearFair2 {
    public:
    vector<pii> v;
    int lim;
    int B;

    //3k,3k+1,3k+2の数、前に選んだ数
    bool dp[18][18][18][1001];

    bool rec(int p, int q, int r, int n){
      int i;

      //すでに見つかっていればそれを返す
      if(dp[p][q][r][n]) return true;

      //この場合ムリなので打ち切る
      if(p>lim/3) return false;
      if(q>lim/3) return false;
      if(r>lim/3) return false;

      bool ret=false;
      if(p+q+r==lim){//終わり
        ret=(p==q && q==r && r==p);
      }
      else{
        int now=p+q+r;
        //上限
        int sup=B;
        //下限
        int inf=n+1;
        rep(i,v.size()-1){
          if(v[i].sc<=now&&now<v[i+1].sc){
            inf=max(inf,v[i].fi+1);
            sup=min(sup,v[i+1].fi);
            break;
          }
        }

        //printf("now %d: n=%d, %d~%d\n",now,n,inf,sup);

        for(i=inf; i<=sup; ++i){
          //printf("call %d\n",i);
          if(i%3==0) ret|=rec(p+1,q,r,i);
          else if(i%3==1) ret|=rec(p,q+1,r,i);
          else ret|=rec(p,q,r+1,i);

          if(ret) break;
        }
      }

      return dp[p][q][r][n]=ret;
    }

    string isFair(int n, int b, vector<int> upTo, vector<int> quantity) {
      int i;

      v.pb(pii(0,0));
      rep(i,upTo.size()) v.pb(pii(upTo[i],quantity[i]));
      v.pb(pii(b,n));
      sort(v.begin(),v.end());

      string ret="unfair";

      bool valid=true;

      rep(i,v.size()-1){
        if(v[i].fi<v[i+1].fi && v[i].sc>v[i+1].sc)
          valid=false;
      }

      if(valid){
        //再帰の前準備
        lim=n;
        B=b;
        memset(dp,0,sizeof(dp));

        if(rec(0,0,0,0)) ret="fair";
      }
      return ret;
    }
};

// CUT begin
ifstream data("BearFair2.sample");

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

bool do_test(int n, int b, vector<int> upTo, vector<int> quantity, string __expected) {
    time_t startClock = clock();
    BearFair2 *instance = new BearFair2();
    string __result = instance->isFair(n, b, upTo, quantity);
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
        int b;
        from_stream(b);
        vector<int> upTo;
        from_stream(upTo);
        vector<int> quantity;
        from_stream(quantity);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, b, upTo, quantity, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1455946062;
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
        cout << "BearFair2 (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
