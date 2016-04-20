#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

class OrderOfOperations {
    public:
    int minTime(vector<string> s) {
      int i,j;

      int n=s.size();
      int m=s[0].size();

      //最終状態
      int end_mask=0;
      //それぞれのプログラム
      int s_mask[50];

      rep(i,n){//n個のプログラム
        s_mask[i]=0;
        rep(j,m){
          if(s[i][j]=='1') s_mask[i]+=(1<<j);
        }
        end_mask |= s_mask[i];
      }

      int INF=10000;
      int dp[1234567];
      fill(dp,dp+1234567,INF);
      dp[0]=0;

      int mask;
      rep(mask,1<<m){//キャッシュ状態がmaskの時
        rep(j,n){
          //j番目のプログラム実行によりキャッシュの状態はnext_maskになる
          int next_mask = mask|s_mask[j];
          //新しくアクセスするメモリ数、つまり時間遅延
          //__builtin_popcount :立っているビット数を返す
          int k = __builtin_popcount(next_mask-mask);
          dp[next_mask]=min(dp[next_mask],dp[mask]+k*k);
        }
      }

      return dp[end_mask];
    }
};

// CUT begin
ifstream data("OrderOfOperations.sample");

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

bool do_test(vector<string> s, int __expected) {
    time_t startClock = clock();
    OrderOfOperations *instance = new OrderOfOperations();
    int __result = instance->minTime(s);
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
        vector<string> s;
        from_stream(s);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(s, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1456989212;
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
        cout << "OrderOfOperations (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
