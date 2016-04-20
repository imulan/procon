#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

typedef pair<int,set<int>> pis;

class SmilesTheFriendshipUnicorn {
    public:
    string hasFriendshipChain(int N, vector<int> A, vector<int> B) {
      int i,j;

      vector<int> G[2000];
      rep(i,A.size()){
        G[A[i]].pb(B[i]);
        G[B[i]].pb(A[i]);
      }
      bool valid=false;

      rep(i,N){//i番目の人を先頭に
        set<int> s;
        s.insert(i);

        queue<pis> que;
        que.push(pis(i,s));
        set<pis> al;
        al.insert(pis(i,s));

        while(!que.empty()){
          pis v=que.front();
          que.pop();

          if(v.sc.size()==5){//完了
            valid=true;
            break;
          }

          rep(j,G[v.fi].size()){
            if(v.sc.find(G[v.fi][j])==v.sc.end()){
              //まだG[v.fi][j]には訪れていないので集合に追加
              set<int> tmp(v.sc);
              tmp.insert(G[v.fi][j]);
              if(al.find(pis(G[v.fi][j],tmp))==al.end()){
                que.push(pis(G[v.fi][j],tmp));
                al.insert(pis(G[v.fi][j],tmp));
              }
            }
          }
        }

        if(valid) break;
      }

      string ret=":(";
      if(valid) ret="Yay!";
      return ret;
    }
};

// CUT begin
ifstream data("SmilesTheFriendshipUnicorn.sample");

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

bool do_test(int N, vector<int> A, vector<int> B, string __expected) {
    time_t startClock = clock();
    SmilesTheFriendshipUnicorn *instance = new SmilesTheFriendshipUnicorn();
    string __result = instance->hasFriendshipChain(N, A, B);
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
        vector<int> A;
        from_stream(A);
        vector<int> B;
        from_stream(B);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, A, B, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1456192822;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "SmilesTheFriendshipUnicorn (300 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
